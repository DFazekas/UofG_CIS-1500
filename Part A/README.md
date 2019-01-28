# Annual-Rainfall

_A Guelph University 2016 assignment_

**By Devon A. Fazekas**

Is global warming real? To help answer this question, we want to study the trend of annual rainfall in various locations. The amount of annual rainfall is measured in centimetres (rounded to the nearest centimetre). However, the report will go directly to Barrack Obama, so the measurements need to be converted to inches (1cm = 0.3937 in).

This program will read as input the measurements for the past 5 years (entered by user). It should then output the total rainfall back in inches rounded to one decimal place. Furthermore, the average amount of rainfall should be calculated for the 5 years (in inches) along with the standard deviation. Both values should be reported to two decimal places. Finally, if the amount of rainfall is either strictly increasing or strictly decreasing year over year, then report an additional message stating _"Barrack - global warming is for real!"_.

To calculate the standard deviation, include math.h and use the formula:
![Alt text](Formula.PNG?raw=true "Logic")
where `x1, ..., x5` are the 5 years of rainfall in inches, and `avg` is their average.

## Test Cases
### Varying increasing & decreasing
If rainfall for the past 5 years in Guelph was 749, 790, 762, 772, 777 respectively, then your program should output:

```
In 2011, there was 294.9 inches of rainfall.
In 2012, there was 311.0 inches of rainfall.
In 2013, there was 300.0 inches of rainfall.
In 2014, there was 303.9 inches of rainfall.
In 2015, there was 305.9 inches of rainfall.

The average rainfall was 303.15 inches, with standard deviation 5.45.
```

### Strictly inscreasing / decreasing
If rainfall for the past 5 years in Guelph was 790, 777, 772, 762, 749 respectively, then your program should output:

```
In 2011, there was 311.0 inches of rainfall.
In 2012, there was 305.9 inches of rainfall.
In 2013, there was 303.9 inches of rainfall.
In 2014, there was 300.0 inches of rainfall.
In 2015, there was 294.9 inches of rainfall.

The average rainfall was 303.15 inches, with standard deviation 5.45.
Barrack - global warming is for real!
```

```
Copyright (C) 2016 by Devon A. Fazekas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
```
