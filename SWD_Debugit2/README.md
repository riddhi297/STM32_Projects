# SWD Debugging using STM32

This project explores SWD (Serial Wire Debug), a 2-wire debugging protocol used to access the ARM debug interface. SWD is an alternative to JTAG and is commonly used in STM32 microcontrollers for programming and debugging.

## SWD Interface

SWD mainly uses two pins:

* **SWDIO** → Bidirectional data line
* **SWCLK** → Clock signal driven by the host (ST-LINK debugger)

An additional optional pin is:

* **SWO (Serial Wire Output)**

SWO is used for **SWV (Serial Wire Viewer)**, which allows the microcontroller to send real-time debugging messages and trace information to the PC without using UART. In simple terms, SWV acts like a lightweight debugging console for viewing internal processor activity while the program is running.

## Internal Working

Inside the ARM Cortex processor, there is an ITM (Instrumentation Trace Macrocell) unit.

The ITM is a hardware debugging component used to send debugging information from the processor to the debugger. It helps developers monitor variables, messages, and execution flow in real time without heavily affecting program execution.

Inside the ITM unit, a FIFO buffer is connected to the SWO pin. Debug information written into this FIFO buffer is transmitted through the SWO line to the ST-LINK debugger and then forwarded to the PC.

## printf Redirection using SWV

In this project, `printf()` output was redirected to SWV using the ITM interface.

The flow works like this:

```text
printf()
   ↓
printf standard library
   ↓
_write() function in syscalls.c
   ↓
ITM_SendChar()
   ↓
ITM FIFO Buffer
   ↓
SWO Pin
   ↓
ST-LINK
   ↓
STM32CubeIDE SWV Console
```

The `_write()` function inside `syscalls.c` was modified to call `ITM_SendChar()` so that whenever `printf()` is used in the application, the data is transmitted through the SWO debugging interface instead of UART.



<img width="1920" height="1080" alt="Screenshot 2026-06-08 154948" src="https://github.com/user-attachments/assets/1483e3ae-0595-492b-b028-1eb45541cae9" />

