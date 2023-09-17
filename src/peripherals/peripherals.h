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

#ifdef ARDUINO
#include <Arduino.h>
#include <Wire.h>

// Temporary fix, see buganizer #268498682, arduino-examples issue #169
#undef abs

#else  // ARDUINO
#error "unsupported framework"
#endif  // ARDUINO

#include "utility.h"

#ifdef ARDUINO

#if defined(ARDUINO_ARDUINO_NANO33BLE)  || defined (NICLA_VISION)   || defined (NANO_RP2040_CONNECT)        || defined (SAMD_NANO_33_IOT)  || defined (__SAM3X8E__)  ||  defined (SEEED_XIAO_M0)    ||   defined (CORE_CM7)   || defined (CORE_CM4)  || defined (TEENSYDUINO) ||  defined (ARDUINO_NANO33BLE) ||  defined (YOUR_BOARD1) 
#include <cstdint>

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

#else  // ARDUINO_ARDUINO_NANO33BLE
#error "unsupported board"

#endif  // ARDUINO_ARDUINO_NANO33BLE

#endif  // ARDUINO

#endif  // PERIPHERALS_H_
