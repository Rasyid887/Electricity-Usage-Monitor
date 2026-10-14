/**
 * MIT License
 * 
 * @brief Display serial implementation for the Electricity Usage Monitor project
 * @file DisplaySerial.cpp
 * @author Aulia Rasyid Pratama (rasyidpratama@gmail.com)
 * @date 2026-10-13
 * 
 * @copyright Copyright (c) 2026 Aulia Rasyid Pratama
 * 
 */

#include <app_config.h>
#include <DisplaySerial/DisplaySerial.h>

/**
 * @brief Initializes the display serial task
 */
void DisplaySerialTask::initialize() {
    vTaskDelay(pdMS_TO_TICKS(cfg::LOOP_INTERNAL_TESTING1));
}

/**
 * @brief Display serial task method
 * 
 * @param pvParameters Pointer to task parameters (unused)
 */
void DisplaySerialTask::run(void* pvParameters) {
    initialize();

    TickType_t lastWakeTime = xTaskGetTickCount();
    while (true) {
        bool received_data;

        if (xQueueReceive(data_q, &received_data, 0) == pdPASS) {
            DEBUG_PRINTLN("LED status = " + String(LED_STATUS ? "ON" : "OFF"));
            digitalWrite(LED_PIN, LED_STATUS);
            if (xSemaphoreTake(data_m, 0) == pdTRUE) {
                LED_STATUS = !LED_STATUS;
                xSemaphoreGive(data_m);
            }
        }

        vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(cfg::LOOP_INTERNAL_TESTING1));
    }
}