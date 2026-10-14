/**
 * MIT License
 * 
 * @brief Energy meter implementation for the Electricity Usage Monitor project
 * @file EnergyMeter.cpp
 * @author Aulia Rasyid Pratama (rasyidpratama@gmail.com)
 * @date 2026-10-13
 * 
 * @copyright Copyright (c) 2026 Aulia Rasyid Pratama
 * 
 */

#include <app_config.h>
#include <EnergyMeter/EnergyMeter.h>

/**
 * @brief Initializes the energy meter task
 */
void EnergyMeterTask::initialize() {
    vTaskDelay(pdMS_TO_TICKS(cfg::LOOP_INTERNAL_TESTING1));
}

/**
 * @brief Energy meter task method
 * 
 * @param pvParameters Pointer to task parameters (unused)
 */
void EnergyMeterTask::run(void* pvParameters) {
    initialize();

    TickType_t lastWakeTime = xTaskGetTickCount();
    while (true) {
        if (xQueueSend(data_q, &LED_STATUS, 0) == pdPASS) {
            DEBUG_PRINTLN("Success: Data sent successfully");
        } else {
            DEBUG_PRINTLN("Failed: Queue is full");
        }

        vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(cfg::LOOP_INTERNAL_TESTING2));
    }
}