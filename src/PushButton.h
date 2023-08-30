/****
 * @file pushbutton.h
 * @version 1.0.0
 * @date August 30, 2023
 * 
 * This file is a portion of the package UserInput, a library that encapsulates a momentary-
 * contact, normally open switch attached to a digital input pin at one side and to Gnd on 
 * the other. At its simplest a PushButton "clicks" when the switch is closed and then opened. 
 * It can be configured to "autorepeat," meaning that if the switch is closed for a period, the 
 * PushButton clicks repeatedly until the switch is opened. Alternatively, if auto repeat isn't 
 * needed, PushButton detects that a "long press" has happened when the switch is closed and 
 * remains closed for a period.
 * 
 * The configuration of a PushButton is determined by the parameters passed to its begin() member 
 * function. These set three instance variables: millisForAuto, millisForClick and millisForLong. 
 * If millisForAuto is 0, the PushButton detects clicks and long presses. If millisForAuto is > 0, 
 * the PushButton is configured for autorepeat.
 * 
 * If configured for autorepeat, a click happens when the switch is closed for at least 
 * millisForClick millis() but less than millisForAuto millis(). A click also happens when the 
 * switch closes and remains closed for at least millisForAuto millis(). If the switch remains 
 * closed, a click happens every millisForAuto millis() thereafter until the switch is opened.
 * 
 * If not configured for autorepeat, a click happens when the switch opens sooner than 
 * millisForLong millis() after having been closed for at least millisForClick millis(). If, 
 * instead, it stays closed for more than millisForLong millis(), a long press occurs. After a 
 * long press occurs, no subsequent clicks or long presses will occur until the switch has 
 * opened.
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
#pragma once

#include <Arduino.h>

#define PB_RPT_BTN_INTERVAL     (0)         // Default autorepeat interval (millis()); 0 ==> detect long press instead of autorepeat
#define PB_MIN_BTN_INTERVAL     (100)       // Default minimum millis() a PushButton switch must be closed to count as having been closed
#define PB_MIN_LONG_INTERVAL    (1500)      // Default minimum millis() a Pushbutton switch must be closed to cause a long press
#define PB_CLOSED               (LOW)       // The value of digitalRead(pin) when the attached switch is closed
#define PB_OPEN                 (HIGH)      // The value of digitalRead(pin) when the attached switch is open

class PushButton {
  public:

  /**
   * @brief Construct a new PushButton object whose switch is attached to the specified GPIO pin
   * 
   * @param inputPin    The GPIO pin to which the switch is attached
   */
  PushButton(uint8_t inputPin);

  /**
   * @brief   Initialize the PushButton. Call once, typically in setup(). If the autoRepeat 
   *          parameter is 0, the PushButton does not autorepeat but instead detects long presses. 
   *          A reasonable value for autoRepeat is 800 millis().
   * 
   * @param autoRepeat  The auto-repeat interval in millis().
   * @param minClicked  The minimum millis() the switch needs to stay closed to count as having closed.
   * @param minLong     The minimum millis() the switch needs to stay closed to detect a long press.
   */
  void begin (uint16_t autoRepeat = PB_RPT_BTN_INTERVAL,uint16_t minClicked = PB_MIN_BTN_INTERVAL, uint16_t minLong = PB_MIN_LONG_INTERVAL);

  /**
   * @brief         Report whether the button was "clicked" since the last call to clicked(). 
   *                Call this or longPressed() (or both) often.
   * 
   * @return true   The PushButton "clicked" since the last call to clicked().
   * @return false  The PushButton did not "click".
   */
  bool clicked();

  /**
   * @brief         Determine whether a "long press" has happened since the last call to 
   *                longPressed(). Call this or clicked() (or both) often.
   *                
   * 
   * @return true   The PushButton had a "long press" since the last call to longPressed().
   * @return false  The PushButton diid not have a "long press".
   */
  bool longPressed();


  private:

  uint8_t pin;                              // Digital pin to which switch is attached
  uint16_t millisForClick;                  // Number of millis() the button needs to be down to trigger click
  uint16_t millisForAuto;                   // Number of millis() between auto-repeat clicks. 0 = no repeat clicks
  uint16_t millisForLong;                    // Number of millis() before a long-press is declared

  uint16_t clickCount;                      // Number of click events not dealt with by calls to clicked()
  uint16_t autoCount;                       // Number of clicks generated by auto clicking while switch is closed
  bool longPress;                           // True if a long press was detected but not dealt with by a call to longPressed()
  bool didLongPress;                        // True if long press already reported; reset when switch opens.
  unsigned long closedMillis;               // millis() when swtich transitioned from open to closed, 0 if its open

  /**
   * @brief Utility function to update the state of affairs. Called by the public member functions 
   *        whenever we get a chance to do so.
   * 
   */
  void updateState();
};
