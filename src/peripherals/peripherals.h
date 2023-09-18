/* Copyright 2022 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


Portenta I2S UNTESTED
   I2S1 GPIO Configuration
    PB5     ------> I2S1_SDO   [serial data]
    PG10     ------> I2S1_WS   [word-select, left=0, right=1]
    PG11     ------> I2S1_CK   [serial clock]
    PC4     ------> I2S1_MCK   [master clock output if codex needs it]

Nicla Vision untested

constexpr PinName kI2S_BIT_CLK = PA_15;   
constexpr PinName kI2S_LR_CLK =  PC_10;    
constexpr PinName kI2S_DATA_IN = PC_11;       
constexpr PinName kI2S_DATA_OUT = PB_2;    

==============================================================================*/

#ifndef PERIPHERALS_H_
#define PERIPHERALS_H_


#include <Arduino.h>

// Temporary fix, see buganizer #268498682, arduino-examples issue #169
#undef abs



#include "utility.h"



#if defined(ARDUINO_ARDUINO_NANO33BLE)   ||  defined (YOUR_BOARD1) 
#include <cstdint>

#include <Wire.h>

#include "button.h"
#include "led.h"
#include "ws_wm8960_audio_hat_nrf52840.h"

#define AUDIO_DEVICE_WS_WM8960_AUDIO_HAT \
  &peripherals::WS_WM8960_AudioHat_NRF52840::Instance()

namespace peripherals {

constexpr PinName kI2S_BIT_CLK = P0_27;   // D9
constexpr PinName kI2S_LR_CLK = P1_2;     // D10
constexpr PinName kI2S_DATA_IN = P1_12;   // D3
constexpr PinName kI2S_DATA_OUT = P1_11;  // D2
constexpr uint32_t kI2S_IRQ_PRIORITY = 7;

constexpr uint32_t kI2C_CLOCK = 100000;

constexpr pin_size_t kBUTTON_GPIO = D8;

constexpr pin_size_t kLED_DEFAULT_GPIO = D13;

}  // namespace peripherals


#elif  defined (CORE_CM7)  || defined (CORE_CM4)  || defined (ARDUINO_PORTENTA_H7_M7) || defined (ARDUINO_PORTENTA_H7_M4) || defined (ARDUINO_PORTENTA_X8)  || defined (TEENSYDUINO)  ||  defined (YOUR_BOARD1) 
#include <cstdint>


namespace peripherals {

constexpr uint32_t kI2C_CLOCK = 100000;

constexpr pin_size_t kBUTTON_GPIO = D8;

constexpr pin_size_t kLED_DEFAULT_GPIO = D13;

}  // namespace peripherals




 // Note:  NANO_33_BLE deprecated as MBED of 1.30, new name: ARDUINO_NANO33BLE  
 // Note:  CORE_CM4 MBED of 1.30, moved above  
 #elif   defined (NANO_33_BLE)   ||  defined (YOUR_BOARD2)  // very old nano33Ble code might be useful for other boards
 
     #define DEBUG_SERIAL_OBJECT (Serial) 

     extern "C" void DebugLog(const char* s) {
        static bool is_initialized = false;
        if (!is_initialized) {
           DEBUG_SERIAL_OBJECT.begin(9600);
           is_initialized = true;
        }
        DEBUG_SERIAL_OBJECT.print(s);
     }

 #elif defined (__SAM3X8E__)  ||  defined (YOUR_BOARD3) // Arduino UNO style boards

     #define DEBUG_SERIAL_OBJECT (SerialUSB) 

     extern "C" void DebugLog(const char* s) {
        static bool is_initialized = false;
        if (!is_initialized) {
           DEBUG_SERIAL_OBJECT.begin(9600);
           is_initialized = true;
        }
        DEBUG_SERIAL_OBJECT.print(s);
     }
 #elif defined (SEEED_XIAO_M0)  ||  defined (YOUR_BOARD4) // The new $5 USD Seeeduino XIAO board

     #define CFG_TUSB_DEBUG




#else  
   #error "unsupported board"

#endif  // ARDUINO_ARDUINO_NANO33BLE



#endif  // PERIPHERALS_H_
