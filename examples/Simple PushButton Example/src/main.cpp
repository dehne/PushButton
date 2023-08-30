/****
 * @file main.cpp
 * @version 1.0.0
 * @date August 28, 2023
 * 
 * Simple PushButton Example -- A sketch to show and test the function provided by the PushButton 
 * library.
 * 
 * Hardware setup
 * ==============
 * 
 * There are two momentary-contact button switches, SW1 and SW2, attached on one side to a GPIO 
 * pin and on the other to Gnd. 
 * 
 * Operation
 * =========
 * 
 * Both switches will "click" if pushed briefly and then released. SW1 is configured as "autorepeat," 
 * meaning that if it's held down, it "clicks" repeatedly. SW2 is configured to report a "long press" 
 * if held down.
 * 
 *****
 * 
 * Copyright (C) 2023 D.L. Ehnebuske
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 * 
 ****/

#include <Arduino.h>
#include <PushButton.h>

#define SW1_PIN         (4)             // GPIO pin to which switch 1 is attached
#define SW2_PIN         (5)             // GPIO pin to which switch 2 is attached

#define BANNER          F("Simple PushButton Example v1.0.0")
#define SERIAL_DELAY    (500)           // millis() to delay while waiting for Serial to init
#define AUTO_MILLIS     (800)           // Autorepeat interval in millis()

PushButton sw1 {SW1_PIN};
PushButton sw2 {SW2_PIN};

/**
 * @brief The Arduino setup function -- called once at power-on and reset
 * 
 */
void setup() {
    Serial.begin(9600);
    while (!Serial) {
        delay(SERIAL_DELAY);
    }

    sw1.begin(AUTO_MILLIS);         // Set sw1 up to autorepeat "clicks" every AUTO_MILLIS millis() when held down
    sw2.begin();                    // No autorepeat for sw1, instead it detects "long presses"
    Serial.println(BANNER);
}

/**
 * @brief The Arduino loop function -- called repeatedly after setup finishes
 * 
 */
void loop() {
    if (sw1.clicked()) {
        Serial.println(F("sw1 says \"click!\""));
    }
    if (sw2.clicked()) {
        Serial.println(F("sw2 says \"click!\""));
    }
    if (sw2.longPressed()) {
        Serial.println(F("sw2 says \"long press!\""));
    }
}
