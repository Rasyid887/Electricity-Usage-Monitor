/**
 * MIT License
 * 
 * @brief Main file for the Electricity Usage Monitor project
 * @file main.cpp
 * @author Aulia Rasyid Pratama (rasyidpratama@gmail.com)
 * @date 2026-10-13
 * 
 * @copyright Copyright (c) 2026 Aulia Rasyid Pratama
 * 
 */

#include <app_config.h>

/**
 * @brief Constant definitions for task stack sizes and priorities
 */
constexpr int LISTENER_STACK = 2048;
constexpr int HANDLER_STACK  = 4096;

constexpr UBaseType_t PRIOR_LISTENER = 1;
constexpr UBaseType_t PRIOR_HANDLER  = 2;

/**
 * @brief Global RTOS handles and queues
 */
TaskHandle_t listener_t = nullptr;
TaskHandle_t handler_t  = nullptr;

/**
 * @brief Task function declarations
 */
void listenerTask(void* pvParameters);
void handlerTask(void* pvParameters);

void setup() {
  Serial.begin(115200);

  DEBUG_PRINTLN("Setting up the Electricity Usage Monitor...");

  configASSERT(xTaskCreatePinnedToCore(listenerTask, "Listener Task", LISTENER_STACK, nullptr, PRIOR_LISTENER, &listener_t, 0) == pdPASS);
  delay(50);
  configASSERT(xTaskCreatePinnedToCore(handlerTask, "Handler Task", HANDLER_STACK, nullptr, PRIOR_HANDLER, &handler_t, 0) == pdPASS);
  delay(50);

  DEBUG_PRINTLN("Setup complete. Tasks are running.");
}

void loop() {
  vTaskDelete(NULL);
}

void listenerTask(void* pvParameters) {
  TickType_t lastWakeTime = xTaskGetTickCount();
  while (true) {
    DEBUG_PRINTLN("Listener Task: Listening for data...");
    vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(cfg::LOOP_INTERNAL_TESTING));
  }
}

void handlerTask(void* pvParameters) {
  TickType_t lastWakeTime = xTaskGetTickCount();
  while (true) {
    DEBUG_PRINTLN("Handler Task: Handling data...");
    vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(100));
  }
}