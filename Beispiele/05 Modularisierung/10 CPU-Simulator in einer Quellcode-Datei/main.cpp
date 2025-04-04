/***********************************************************************************************
 * Beispiel: CPU-Simulator in einer Quellcode-Datei
 * ================================================
 *
 * Dieses Beispiel verdeutlicht die Prinzipien zur Strukturierung mittelgroßer Programme anhand
 * eines realen Anwendungsfalls: Der Simulation (auch Emulation oder Virtualisierung genannt)
 * eines einfachen 16-Bit Computers. Emuliert werden die CPU, RAM und ein simples Textterminal.
 * 
 * Das Herzstück ist dabei die Funktion execute() mit gerade mal 60 Codezeilen. Der Algorithmus
 * wird auch "CPU-Simulator" oder "CPU-Interpreter" genannt, da die innere Funktionsweise der
 * CPU rudimentär in Software nachgebildet wird, soweit dies für die Simulation notwendig ist.
 * Timing-Abhängigkeiten werden beispielsweise nicht berücksichtigt. Und es findet auch keine
 * Code-Generierung für die Host-CPU statt, um die Performance zu steigern. Doch gerade das
 * macht den Algorithmus so einfach und kompakt.
 * 
 * Die Emulation ist dabei ziemlich vollständig. Es fehlen lediglich Interrupts, die aber auch
 * einfach zu implementieren wären. Wenn Sie Ihr Informatik-Verständnis vertiefen wollen,
 * versuchen Sie, das Assembler-Programm in der main()-Funktion zu ändern und die simulierte
 * CPU einen anderen Algorithmus ausführen zu lassen.
 ***********************************************************************************************/

#include <cstdint>      // Plattformunabhängige Ganzzahlen
#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...
#include <vector>       // std::vector

using namespace std;

// Globale Strukturen und Konstanten
struct computer_t {
    struct cpu {                            // Emulierte CPU
        uint16_t pc;                        // Program Counter
        uint16_t sp;                        // Stack Pointer
        uint16_t a;                         // Register A
        uint16_t b;                         // Register B
        uint8_t  flags;                     // Flags
    } cpu;

    vector<uint16_t> ram;                   // Hauptspeicher
};

enum opcode_t: uint8_t {
    // 0b00'xx'xxxx: Allgemeine Instruktionen
    NOOP  = 0b00'00'0000,                   // No Operation
    HALT  = 0b00'00'0001,                   // Halt
    CLRF  = 0b00'00'0010,                   // Clear Flags
    
    // 0b01'xx'xxxx: Memory und I/O
    MOVE  = 0b01'00'0000,                   // Memory Access
    READ  = 0b01'00'0010,                   // I/O Read
    WRITE = 0b01'00'0011,                   // I/O Write
    PUSH  = 0b01'01'0000,                   // Push to Stack
    POP   = 0b01'01'0001,                   // Pop from Stack

    // 0b10'xx'xxxx: ALU-Operationen
    NOT   = 0b10'00'0000,                   // Binary NOT
    AND   = 0b10'00'0001,                   // Binary AND
    OR    = 0b10'00'0010,                   // Binary OR
    XOR   = 0b10'00'0011,                   // Binary XOR
    ADD   = 0b10'00'0100,                   // Integer Addition
    SUB   = 0b10'00'0101,                   // Integer Subtraction
    MUL   = 0b10'00'0110,                   // Integer Multiplication
    DIV   = 0b10'00'0111,                   // Integer Division

    // 0b11'xx'xxxx: Sprunganweisungen (xxxx = zu prüfende Flags)
    JMP   = 0b11'00'1110,                   // Unconditional Jump
    JZR   = 0b11'00'0010,                   // Jump if Zero
    JNZ   = 0b11'00'1100,                   // Jump if not Zero
    JLT   = 0b11'00'0100,                   // Jump if Less-Than Zero
    JLE   = 0b11'00'0110,                   // Jump if Less-Than or Equal to Zero
    JGT   = 0b11'00'1000,                   // Jump if Greater-Than Zero
    JGE   = 0b11'00'1010,                   // Jump if Greater-Than or Equals Zero
    CALL  = 0b11'01'0000,                   // Call Subroutine
    RET   = 0b11'01'0001,                   // Return From Subroutine
};

enum parameter_t: uint8_t {
    NONE   = 0b0000,                        // No Data
    VAL    = 0b1000,                        // Immediate Value nach Opcode
    PTR    = 0b1001,                        // Speicheradresse (Pointer) nach Opcode
    REG_A  = 0b1100,                        // Register A
    PTR_A  = 0b1101,                        // Pointer in Regster A
    REG_B  = 0b1110,                        // Register B
    PTR_B  = 0b1111,                        // Pointer in Register B
};

enum flag_t: uint8_t {
    FLAG_HLT = 0b0000'0001,                 // CPU Halted
    FLAG_ZRO = 0b0000'0010,                 // Zero Value
    FLAG_LTZ = 0b0000'0100,                 // Less-Then Zero Value
    FLAG_GTZ = 0b0000'1000,                 // Greater-Than Zero Value
};

enum io_port_t: uint8_t {
    IO_TTY = 0,                             // Teletype Terminal
};

// Erzeugen einer vollständigen CPU-Instruktion. Diese besteht immer aus einem 16-Bit
// Wert in folgendem Format: 8-Bit Opcode, 4-Bit Parameter 1, 4-Bit Parameter 2. Die
// beiden 4-Bit-Werte spezifizieren Datentransporte für die Parameter des Opcodes.
inline uint16_t op(opcode_t opcode, parameter_t parameter1 = NONE, parameter_t parameter2 = NONE) {
    return opcode << 8 | parameter1 << 4 | parameter2;
}

// Vorwärtsdeklaration aller anderen Funktionen
void     execute(computer_t &computer);
uint16_t load   (computer_t &computer, parameter_t mode);
uint16_t store  (computer_t &computer, parameter_t mode, uint16_t value);
uint16_t read   (computer_t &computer, io_port_t port);
uint16_t write  (computer_t &computer, io_port_t port, uint16_t value);
string   status (computer_t &computer);

// Hauptfunktion des Programms
int main(int argc, char **argv) {
    struct computer_t computer = {};

    computer.ram = {
        // Programmcode
        op(MOVE, REG_A, VAL), 12,           // Lade in Register A den Wert 12 (Speicheradresse mit Textdaten)
        op(MOVE, REG_B, PTR_A),             // Lade in Register B den Wert an der Speicheradresse aus Register A
        op(JZR, VAL), 11,                   // Springe zur HLT-Anweisung in Speicherstelle 11, wenn der gelesene Wert null ist
        op(WRITE, VAL, REG_B), IO_TTY,      // Gebe das Zeichen in Register B auf dem Bildschirm aus
        op(ADD, REG_A, VAL), 1,             // Erhöhe den Wert in Register A (Speicheradresse mit Textdaten) um eins
        op(JMP, VAL), 2,                    // Springe zurück zur zweiten Anweisung (Speicherstelle 2)
        op(HALT),                           // Halte das Programm an

        // Daten
        '\n',
        'M', 'e', 'i', 'n', ' ',
        'v', 'i', 'r', 't', 'u', 'e', 'l', 'l', 'e', 'r', ' ',
        'C', 'o', 'm', 'p', 'u', 't', 'e', 'r', ' ',
        's', 'a', 'g', 't', ' ',
        'H', 'a', 'l', 'l', 'o', '!', '\n', 0,
    };

    computer.ram.resize(128);
    computer.cpu.sp = computer.ram.size() - 1;

    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    while ((computer.cpu.flags & FLAG_HLT) == 0) {
        execute(computer);
    }

    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl << "Virtuelle CPU angehalten." << endl;
    cout << endl;
    cout << status(computer);
    cout << endl;
}

// Ausführung eines Taktzyklus des simulierten Computers. Liest die nächste Instruktion
// aus dem Speicher, erhöht den Program Counter entsprechend, führt die Datentransporte
// sowie den Opcode der Instruktion aus und aktualisiert das Flag-Register.
void execute(computer_t &computer) {
    computer.cpu.pc = min(computer.cpu.pc, (uint16_t) (computer.ram.size() - 1));
    computer.cpu.sp = min(computer.cpu.sp, (uint16_t) (computer.ram.size() - 1));

    uint16_t    instruction = computer.ram[computer.cpu.pc++];
    opcode_t    opcode      = (opcode_t)    (instruction >> 8 & 0x00FF);    // 1tes Byte: Opcode
    parameter_t parameter1  = (parameter_t) (instruction >> 4 & 0x000F);    // 3tes Halb-Byte: Parameter 1
    parameter_t parameter2  = (parameter_t) (instruction      & 0x000F);    // 4tes Halb-Byte: Parameter 2

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
            if      ((int16_t) value1 == 0) computer.cpu.flags |= FLAG_ZRO;
            else if ((int16_t) value1 <  0) computer.cpu.flags |= FLAG_LTZ;
            else if ((int16_t) value1 >  0) computer.cpu.flags |= FLAG_GTZ;
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
