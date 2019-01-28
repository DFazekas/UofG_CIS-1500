# Students Class Performance

_A Guelph University 2016 assignment_

**By Devon A. Fazekas**

For this problem you will be given a CSV file **grades.txt** containing assignment grades for every student in a given class. As an example, a CSV file for a class with 4 students and 3 assignments may look like:

```
8.5, 10.5, 90.5
50, 99, 97
88, 88, 100
88.5, 99, 0
```

Your task is to write 3 functions to compute and return:
* The average grade
* The maximum grade
* The number of students who failed (< 50%) (use 49.9 in your comparison!)

For a given assignment (passed as one of the parameters). You may assume:
* Every assignment is out of 100,
* Each mark in the input file is rounded to the nearest half mark,
* There are between 1 and 100 assignments in the course,
* There are between 1 and 1000 students in the class,
* The file is formatted correctly.

To simplify reading the input file, your executable must take two command line parameters specifying the number of students and the number of assignments in the class. If the executable is **a.out**, and the input file has 4 students and 3 assignments as above, you would call your program as: `./a.out 4 3`. If an incorrect number of command line arguments is given, your program should output: `usage: ./a.out num students num assignments`

**NOTE:** If the command line arguments do not match the input file, then your program is not expected to work, and appropriate error messaging is not required.

To store the grades, declare a global variable as follows: `float grades[1001][101];` (Using 1001 instead of 1000 allows you to start your indices at 1 if you wish). Since this 2-dimensional array is global, you do not have to pass it into your functions. This should be your only global variable. As an example, you may want to store the grade of the 4th assignment of the 9th student in `grades[9][4]`.

Finally, you must output grades data back to the screen in CSV format to verify you read the file correctly. Given the earlier CSV data, your output should be formatted as follows. Be mindful of the nice alignment of the values. The average should be rounded to one decimal place.

```
==================================
Student grades from the input file
==================================
 8.5, 10.5,  90.5
50.0, 99.0,  97.0
88.0, 88.0, 100.0
88.5, 99.0,   0.0

==============
Ass # 1 stats
==============
avg  = 58.8
max  = 88.5
fail =    1

==============
Ass # 2 stats
==============
avg  = 74.1
max  = 99.0
fail =    1

==============
Ass # 3 stats
==============
avg  =  71.9
max  = 100.0
fail =     1
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
