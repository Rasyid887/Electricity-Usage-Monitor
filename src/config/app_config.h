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
    #define DEBUG_PRINT(x) Serial.print(x)
    #define DEBUG_PRINTLN(x) Serial.println(x)
#else
    #define DEBUG_PRINT(x)
    #define DEBUG_PRINTLN(x)
#endif

/**
 * @brief Application-wide settings
 */

namespace cfg
{
    constexpr int LOOP_INTERNAL_MS = 10;
    constexpr int LOOP_INTERNAL_TESTING = 1000;
}