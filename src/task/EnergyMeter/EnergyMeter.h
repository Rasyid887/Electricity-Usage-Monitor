/**
 * MIT License
 * 
 * @brief Energy meter sensor configuration parameters
 * @file EnergyMeter.h
 * @author Aulia Rasyid Pratama (rasyidpratama@gmail.com)
 * @date 2026-10-13
 * 
 * @copyright Copyright (c) 2026 Aulia Rasyid Pratama
 * 
 */

#pragma once

class EnergyMeterTask {
private:
    static void initialize();
public:
    static void run(void* pvParameters);
};