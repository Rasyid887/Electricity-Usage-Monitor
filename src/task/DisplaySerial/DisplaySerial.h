/**
 * MIT License
 * 
 * @brief Display serial configuration parameters
 * @file DisplaySerial.h
 * @author Aulia Rasyid Pratama (rasyidpratama@gmail.com)
 * @date 2026-10-13
 * 
 * @copyright Copyright (c) 2026 Aulia Rasyid Pratama
 * 
 */

#pragma once

class DisplaySerialTask {
private:
    static void initialize();
public:
    static void run(void* pvParameters);
};