# PushButton

## An Arduino Library for single-pole Momentary-contact Switches

### Description

The library implements the Class PushButton. A PushButton object encapsulates a momentary-contact, normally open switch attached to a digital input pin at one side and to Gnd on the other. At its simplest a PushButton "clicks" when the switch is closed and then opened. It can be configured to "autorepeat," meaning that if the switch is closed for a period, the PushButton clicks repeatedly until the switch is opened. Alternatively, if auto repeat isn't needed, PushButton detects that a "long press" has happened when the switch is closed and remains closed for a period.

The configuration of a PushButton is determined by the parameters passed to its begin() member function. These set three instance variables: millisForAuto, millisForClick and millisForLong. If millisForAuto is 0, the PushButton detects clicks and long presses. If millisForAuto is > 0, the PushButton is configured for autorepeat.

If configured for autorepeat, a click happens when the switch is closed for at least millisForClick millis() but less than millisForAuto millis(). A click also happens when the switch closes and remains closed for at least millisForAuto millis(). If the switch remains closed, a click happens every millisForAuto millis() thereafter until the switch is opened.

If not configured for autorepeat, a click happens when the switch opens sooner than millisForLong millis() after having been closed for at least millisForClick millis(). If, instead, it stays closed for more than millisForLong millis(), a long press occurs. After a long press occurs, no subsequent clicks or long presses will occur until the switch has opened.

### Copyright and License

Copyright (C) 2023 D.L. Ehnebuske

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: 

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software. 

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 