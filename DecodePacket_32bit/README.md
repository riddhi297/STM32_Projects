# 32-bit Packet Decoder using Bit Manipulation

This project demonstrates decoding of a 32-bit packet using bit masking and bit shifting in Embedded C.

The packet is divided into multiple fields such as:

* CRC
* Status
* Payload
* Battery Information
* Sensor Information
* Address Fields

Each field is extracted using:

* Bitwise AND (`&`)
* Bitwise Shift (`>>`)

## Concepts Used

* Bit Manipulation
* Packet Decoding
* Structures in C
* Embedded C Programming
* Fixed Width Integer Types (`stdint.h`)

## Technologies Used

* STM32CubeIDE
* C Programming
* GCC Compiler

## Learning Outcome

This project helped in understanding how embedded systems decode communication packets at low level using masks and shifts, which is commonly used in protocols, device drivers, and firmware development.
