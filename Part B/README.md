# Digit Frequencies

_A Guelph University 2016 assignment_

**By Devon A. Fazekas**

Given an input file *data.txt* containing random text (letters, numbers, special characters), count the number of occurrences of each digit `0,1,...,9` that appear in the file before the special phrase `END` appears as 3 consecutive characters. If no such substring exists, then just count the number of occurrences in the entire file.

If the input file contains the following data (with no substring END):

```
23ED42end;h23E\#\#\$4b2;234324EN99999E
N88
EN
D77
```

Then the output should be:

```
Number of 0: 0
Number of 1: 0
Number of 2: 6
Number of 3: 4
Number of 4: 4
Number of 5: 0
Number of 6: 0
Number of 7: 2
Number of 8: 2
Number of 9: 5
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
