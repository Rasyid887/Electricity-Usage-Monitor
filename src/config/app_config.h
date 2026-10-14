/**
 * MIT License
 * 
 * @brief Application configuration parameters
 * @file app_config.h
 * @author Aulia Rasyid Pratama (rasyidpratama@gmail.com)
 * @date 2026-10-13
 * 
 * @copyright Copyright (c) 2026 Aulia Rasyid Pratama
 * 
 */

#pragma once

#include <Arduino.h>

#define DEBUGGING true

#if DEBUGGING == true
    #define DEBUG_PRINT(x) Serial.print("[DEBUG LOG] " x)
    #define DEBUG_PRINTLN(x) Serial.println("[DEBUG LOG] " x)
#else
    #define DEBUG_PRINT(x)
    #define DEBUG_PRINTLN(x)
#endif

#define LED_PIN 2

/**
 * @brief Application-wide settings
 */
namespace cfg
{
    constexpr int LOOP_INTERNAL_TESTING1 = 1000;
    constexpr int LOOP_INTERNAL_TESTING2 = 5000;
}

/**
 * @brief Constant definitions for task stack sizes and priorities
 */
constexpr int ENERGY_METER_STACK    = 2048;
constexpr int DISPLAY_SERIAL_STACK  = 4096;

constexpr UBaseType_t PRIOR_ENERGY_METER    = 1;
constexpr UBaseType_t PRIOR_DISPLAY_SERIAL  = 2;

/**
 * @brief Global variables
 */
extern bool LED_STATUS;

/**
 * @brief Global RTOS queue handles
 */
extern xQueueHandle data_q;

/**
 * @brief Global RTOS mutex handles
 */
extern SemaphoreHandle_t data_m;

/**
 * @brief Global RTOS task handles
 */
extern TaskHandle_t energyMeter_t;
extern TaskHandle_t displaySerial_t;