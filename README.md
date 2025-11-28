# FreeRTOS Practice on STM32F407

This repository contains my personal practice code and solutions for the exercises presented in the "Intro to FreeRTOS" YouTube series. The primary goal is to learn and apply FreeRTOS concepts on an STM32 microcontroller.

## Motivation

The purpose of this repository is to document my journey of learning FreeRTOS. By solving the exercises from the tutorial series and pushing the code to this repository, I aim to solidify my understanding of real-time operating systems and create a reference for future projects.

## Based On

All the exercises and theoretical concepts are based on the excellent YouTube playlist:

*   **Playlist:** [RTOS Training (including FreeRTOS)](https://youtube.com/playlist?list=PLEBQazB0HUyQ4hAPU1cJED6t3DU0h34bz)
*   **Creator:** Quantum Leaps

## Hardware and Software

*   **Microcontroller Board:** [STMicroelectronics STM32F407-Disc1](https://www.st.com/en/evaluation-tools/stm32f4discovery.html)
*   **RTOS:** FreeRTOS
*   **IDE:** Arduino IDE 2.3.6

### Serial Communication Setup
For debugging and viewing output, the default Arduino `Serial` object is used in the sketches. This has been configured to use `USART2` on the STM32F407 board.

*   **USART Port:** `USART2`
*   **TX Pin:** `PA2`
*   **RX Pin:** `PA3`

You will need a USB to Serial TTL converter to see the output. Connect the converter to your board as follows:
*   Converter **RX** ↔ Board **PA2 (TX)**
*   Converter **TX** ↔ Board **PA3 (RX)**
*   Converter **GND** ↔ Board **GND**

#### Putty Setup: (For Serial Connection you can use any serial monitor software, here i am using putty)
1.    You will need to check which com-port USB to serial is connected using device manager.
2.    Open Putty app > Click on `session` > Serial line: `COM9`; Speed: `4800` (Baud-rate); Connection type: `Serial`
3.    Click on `Terminal` > Line Dicipline Option:Local Echo: `Force on`; Local Line Editing: `Force on`
4.    Click on `Connection` > `Serial` > Data bits: `8`; Stop bits: `1`; Parity: `None`; Flow control:`None`

**Putty Issue you might face:**
1. You are getting garbage output on putty screen.
> _Solution_: refer Pt. #2 From Putty Setup.
2. You are able to see messages coming from board but you are not able to Enter message or message you are entering is not seen on display.
> _Solution_: refer Pt. #3 From Putty Setup.
3. You are Entering message, its displaying on screen as well, but board its not responding.
> _Solution_: refer Pt. #4 From Putty Setup.

### Key Difference from the Tutorial

It is important to note that the original tutorial series uses an **ESP32** board. This repository adapts and implements the concepts on an **STM32F407** board, with configurable `STM32FreeRTOSConfig.h` file for STM32. This may result in differences in hardware initialization, peripheral configuration, and toolchain setup.

## Step-by-Step Guide
### Setting up the Arduino IDE for STM32
1. Add STM32 Board Support: Go to File > Preferences in the Arduino IDE and paste the following URL into the "Additional Board Manager URLs" field:
    ```sh
    https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json
    ```
2. Go to Tools > Board > Boards Manager.
3. Search for STM32 and install the `STM32 MCU based boards` i.e `STM32duino`.
4. Go to Tools > Board > STM32 boards and select the appropriate board model in my case its `Discovery` (e.g., STM32F4 Discovery). 
5. Go to Tools > Board part number > `STM32F407G-DISC1`
6. Install Library: Go to Tools > Manage Libraries
7. Search for `STM32duino FreeRTOS` and install it. This library provides the FreeRTOS implementation for STM32 within the Arduino environment.
8. Clone the repository:
    ```sh
    git clone https://github.com/your-username/Intro-to-FreeRTOS-STM32.git
    ```
2.  Open the sketch file (`.ino`) for a lesson from its folder in the Arduino IDE.
6.  Click on `Verify` and then `Upload` button to compile and flash the code to your board.

---
