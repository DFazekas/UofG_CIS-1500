# Age

_A Guelph University 2016 assignment_

**By Devon A. Fazekas**

As you get older, it gets harder to do math in your head. But in your current job, you must routinely determine a person's age relative to the current date. To make your life easy you decide to write a program that will take a person's birthday as input, and output a sentence like the following:

```
You were born on Apr 4, 2000 and you are 15 years old.
```

The birthday should be entered as 3 separate fields (year, month, day), and the input must be checked for validity. The month should be input as an integer in the range `1...12` and then output as its 3-character abbreviation. You may assume the current day is hard-coded to Fed 12, 2016. If an invalid date has been entered you must produce the following output:

```
An invalid birthdate has been entered.
```

To simplify the checking, you amy assume that every year is divisible by 4 is a leap-year. The following are examples of invalid birth dates:

```
2000 2 30    (not 30 days in Feb)
1997 2 29    (not a leap year)
2016 2 17    (date in future)
2011 13 7    (13 is not a valid month)
2000 7 -2	 (-2 is not a valid day)
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
