# Student Grades

_A Guelph University 2016 assignment_

**By Devon A. Fazekas**

Given an input file _grades.txt_ containing the terms grades, calculate the class average for each assignment, midterm and final in terms of a percent (i.e., 77%) rounded to the nearest percentage point.

The first line of the input file has a single integer specifying the number of students _N_ in the class. The second line contains what each item (there are 7 of them) is out of, and the final _N_ lines are the raw integer scores for each student as follows:

```
ass1_mark ass2_mark ass3_mark ass4_mark ass5_mark midterm final
```

If each assignment is out of 90, the midterm is out of 50, and the final is out of 100, an input file with 3 students may look like:

```
3
90 90 90 90 90 50 100
81 80 70 75 77 44 77
50 40 60 44 55 33 22
90 88 70 90 44 50 11
```

You may assume that the input file is correctly formatted (you do not need to test for validity of the data). The output to this program must be written to the file _averages.txt_ which for the above input would look like:

```
There are 3 students in this class.
The average for assignment #1 is 82%.
The average for assignment #2 is 77%.
The average for assignment #3 is 74%.
The average for assignment #4 is 77%.
The average for assignment #5 is 65%.
The average for the midterm is 85%.
The average for the final is 37%.
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
