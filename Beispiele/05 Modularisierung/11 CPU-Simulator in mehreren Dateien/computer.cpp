/***********************************************************************************************
 * Implementierung: computer.cpp
 * =============================
 * 
 * Dies ist die Implementierung zu den Deklarationen in der Header-Datei "computer.hpp". Da es
 * sich hierbei um eine *.cpp-Datei handelt, übersetzt sie der Compiler in ein eigenes Objekt-
 * Modul mit der Dateiendung *.o. Der Linker setzt dann aus allen Objektmodulen das fertige
 * Programm zusammen und löst die gegenseitigen Verwendungen auf.
 * 
 * Logischerweise muss hier die Header-Datei "computer.hpp" inkludiert werden, damit der Compiler
 * die Deklarationen kennt, zu denen wir hier die Implementierung liefern.
 ***********************************************************************************************/
#include "computer.hpp" // Eigene Header-Datei

#include <cstdint>      // Plattformunabhängige Ganzzahlen
#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...

using namespace std;

// Ausführung eines Taktzyklus des simulierten Computers. Liest die nächste Instruktion
// aus dem Speicher, erhöht den Program Counter entsprechend, führt die Datentransporte
// sowie den Opcode der Instruktion aus und aktualisiert das Flag-Register.
void execute(computer_t &computer) {
    computer.cpu.pc = min(computer.cpu.pc, (uint16_t) (computer.ram.size() - 1));
    computer.cpu.sp = min(computer.cpu.sp, (uint16_t) (computer.ram.size() - 1));

    uint16_t    instruction = computer.ram[computer.cpu.pc++];
    opcode_t    opcode      = (opcode_t)    (instruction >> 8 & 0x00FF);    // 1tes Byte: Opcode
    parameter_t parameter1  = (parameter_t) (instruction >> 4 & 0x000F);    // 3tes Halb-Byte: Parameter 1
    parameter_t parameter2  = (parameter_t) (instruction      & 0x000F);    // 2tes Halb-Byte: Parameter 2

    uint16_t value1 = load(computer, parameter1);
    uint16_t value2 = load(computer, parameter2);

    switch(opcode) {
        // Allgemeine Instruktionen
        case NOOP:   break;
        case HALT:   computer.cpu.flags |= FLAG_HLT;  break;
        case CLRF:   computer.cpu.flags  = 0;         break;
    
        // Memory und I/O
        case MOVE:   value1 = value2;  break;
        case READ:   value1 = read(computer, (io_port_t) value2);  break;
        case WRITE:  write(computer, (io_port_t) value1, value2);  break;
        case PUSH:   computer.ram[computer.cpu.sp--] = value1;     break;
        case POP:    value1 = computer.ram[computer.cpu.sp++];     break;

        // ALU-Operationen
        case NOT:    value1 = ~value1;  break;
        case AND:    value1 &= value2;  break;
        case OR:     value1 |= value2;  break;
        case XOR:    value1 ^= value2;  break;
        case ADD:    value1 += value2;  break;
        case SUB:    value1 -= value2;  break;
        case MUL:    value1 *= value2;  break;
        case DIV:    value1 /= value2;  break;

        // Unterprogramme
        case CALL:   computer.ram[computer.cpu.sp--] = computer.cpu.pc;  break;
        case RET:    computer.cpu.pc = computer.ram[computer.cpu.sp++];  break;

        // Konditionale Sprunganweisungen
        default:
            if ((opcode & 0b11'11'0000) == 0b11'00'0000) {
                if (computer.cpu.flags & opcode & 0x0F) {
                    computer.cpu.pc = value1;
                }
            }
    }

    switch (opcode & 0b11'00'0000) {
        // Memory & I/O, ALU-Operationen: Flags setzen
        case 0b01'00'0000:
        case 0b10'00'0000:
            computer.cpu.flags = 0;
            if      (value1 == 0) computer.cpu.flags |= FLAG_ZRO;
            else if (value1 <  0) computer.cpu.flags |= FLAG_LTZ;
            else if (value1 >  0) computer.cpu.flags |= FLAG_GTZ;
    }

    store(computer, parameter1, value1);
}

// Datenwert aus Programmcode, Register oder Speicher lesen
uint16_t load(computer_t &computer, parameter_t mode) {
    switch (mode) {
        case VAL:    return computer.ram[computer.cpu.pc++];
        case REG_A:  return computer.cpu.a;
        case REG_B:  return computer.cpu.b;
        case PTR:    return computer.ram[computer.ram[computer.cpu.pc++]];
        case PTR_A:  return computer.ram[computer.cpu.a];
        case PTR_B:  return computer.ram[computer.cpu.b];
        default:     return 0;
    }
}

// Datenwert in Register oder Speicher schreiben
uint16_t store(computer_t &computer, parameter_t mode, uint16_t value) {
    switch (mode) {
        case REG_A:  return computer.cpu.a = value;
        case REG_B:  return computer.cpu.b = value;
        case PTR:    return computer.ram[computer.ram[computer.cpu.pc++]] = value;
        case PTR_A:  return computer.ram[computer.cpu.a] = value;
        case PTR_B:  return computer.ram[computer.cpu.b] = value;
        default:     return 0;
    }
}

// I/O-Port lesen
uint16_t read(computer_t &computer, io_port_t port) {
    switch (port) {
        case IO_TTY:
            // Tastatur: Blockiert die Ausführung, bis ein Zeichen gelesen wurde
            char value;
            cin >> value;
            return value;
        default:
            return 0;
    }

}

// I/O-Port schreiben
uint16_t write(computer_t &computer, io_port_t port, uint16_t value) {
    switch (port) {
        case IO_TTY:
            // Zeichen auf der Textkonsole ausgeben
            cout << (char) value << flush;
            break;
    }

    return value;
}

// String zur Anzeige der der Register und des RAMs erzeugen
string status(computer_t &computer) {
    string flags = {};
    if (computer.cpu.flags & FLAG_HLT) flags.append("HLT ");
    if (computer.cpu.flags & FLAG_ZRO) flags.append("ZRO ");
    if (computer.cpu.flags & FLAG_LTZ) flags.append("LTZ ");
    if (computer.cpu.flags & FLAG_GTZ) flags.append("GTZ ");

    string ram, left_side, right_side = {};
    char buffer[10];
    int i = 0;

    for (uint16_t c : computer.ram) {
        sprintf(buffer, "%04x", c);
        left_side += string(buffer) + string(" ");
        right_side.push_back(c >= 32 && c <= 126 ? c : '.');
        
        if (i == 7) {
            left_side  += string(" ");
            right_side += string(" ");
        } else if (i == 15) {
            ram += left_side + string(" ") + right_side + string("\n");
            left_side = right_side = {};
        }

        i = (i + 1) % 16;
    }

    return string("PC......: ") + to_string(computer.cpu.pc) + string("\n")
        + string("SP......: ") + to_string(computer.cpu.sp) + string("\n")
        + string("A.......: ") + to_string(computer.cpu.a)  + string("\n")
        + string("B.......: ") + to_string(computer.cpu.b)  + string("\n")
        + string("Flags...: ") + flags + string("\n\n")
        + ram;
}