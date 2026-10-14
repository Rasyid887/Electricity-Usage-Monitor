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
#include <DisplaySerial/DisplaySerial.h>
#include <EnergyMeter/EnergyMeter.h>

/**
 * @brief Setup function
 */
void setup() {
  Serial.begin(115200);

  DEBUG_PRINTLN("Setting up the Electricity Usage Monitor...");

  pinMode(LED_PIN, OUTPUT);

  configASSERT((data_q = xQueueCreate(3, sizeof(bool))) != nullptr);
  delay(50);
  configASSERT((data_m = xSemaphoreCreateMutex()) != nullptr);
  delay(50);
  configASSERT(xTaskCreatePinnedToCore(EnergyMeterTask::run, "Energy Meter Task", ENERGY_METER_STACK, nullptr, PRIOR_ENERGY_METER, &energyMeter_t, 0) == pdPASS);
  delay(50);
  configASSERT(xTaskCreatePinnedToCore(DisplaySerialTask::run, "Display Serial Task", DISPLAY_SERIAL_STACK, nullptr, PRIOR_DISPLAY_SERIAL, &displaySerial_t, 0) == pdPASS);
  delay(50);

  DEBUG_PRINTLN("Setup complete. Tasks are running.");
}

/**
 * @brief Deletes the loop task to allow FreeRTOS tasks to run independently.
 */
void loop() {
  vTaskDelete(NULL);
}