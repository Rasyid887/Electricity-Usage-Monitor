/**
 * MIT License
 * 
 * @brief Application configuration parameters
 * @file app_config.cpp
 * @author Aulia Rasyid Pratama (rasyidpratama@gmail.com)
 * @date 2026-10-13
 * 
 * @copyright Copyright (c) 2026 Aulia Rasyid Pratama
 * 
 */

#include <app_config.h>

/**
 * @brief Global variables
 */
bool LED_STATUS = false;

/**
 * @brief Global RTOS queue handles
 */
xQueueHandle data_q = nullptr;

/**
 * @brief Global RTOS mutex handles
 */
SemaphoreHandle_t data_m = nullptr;

/**
 * @brief Global RTOS task handles
 */
TaskHandle_t energyMeter_t    = nullptr;
TaskHandle_t displaySerial_t  = nullptr;