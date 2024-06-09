/***********************************************************************************************
 * Header: Computer.hpp
 * ====================
 * 
 * Diese Datei beinhaltet die Deklarationen für das Objektmodul "computer.o", das der Compiler
 * aus der Quelldatei "compiler.cpp" erzeugt. Hier finden sich nur Deklarationen von Datentypen
 * und Funktionssignaturen, aber bis auf die Inline-Funktion op() keine Implementierungen.
 * 
 * Denn der Compiler benötigt die Implementierung nicht, um die anderen Module übersetzen zu
 * können. Er muss nur die Deklarationen kennen und in die Objektdateien übernehmen. Der Linker
 * setzt diese dann zu einem vollständigen Programm zusammen und löst die durch das Einbinden
 * der Header-Datei entstandenen Verweise auf.
 ***********************************************************************************************/
#pragma once            // Ignorieren, wenn die Datei mehrfach eingebunden wird

#include <cstdint>      // Plattformunabhängige Ganzzahlen
#include <vector>       // std::vector
#include <string>       // std::string, std::getline, ...

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
// beiden 4-Bit-Werte spezifizieren Datentransporte für die Parameter des Opcodes,
inline uint16_t op(opcode_t opcode, parameter_t parameter1 = NONE, parameter_t parameter2 = NONE) {
    return opcode << 8 | parameter1 << 4 | parameter2;
}

// Vorwärtsdeklaration aller anderen öffentlichen Funktionen
void     execute(computer_t &computer);
uint16_t load   (computer_t &computer, parameter_t mode);
uint16_t store  (computer_t &computer, parameter_t mode, uint16_t value);
uint16_t read   (computer_t &computer, io_port_t port);
uint16_t write  (computer_t &computer, io_port_t port, uint16_t value);
string   status (computer_t &computer);