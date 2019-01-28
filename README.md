# Fantasy Sports

_A Guelph University 2016 assignment_

**By Devon A. Fazekas**

Your parents have been swept up in the Fantasy Sports craze. Their favourite
sport is basketball, and they think they have a strategy for picking the best fantasy players. Statistics for basketball players are usual sorted by Points Per Game (PPG). As an example, the list below contains the top 15 players in the NBA sorted by this statistic:

```
Player            PPG  REB  AST  STL  BLK
Stephen Curry    30.1  5.4  6.5  2.1  0.2
James Harden     28.5  6.3  7.4  1.8  0.6
Kevin Durant     27.8  8.3  5.0  0.9  1.3
DeMarc Cousins   27.1 11.6  3.3  1.5  1.4
Damian Lillard   25.7  4.2  6.9  0.9  0.4
LeBron James     25.0  7.4  6.6  1.4  0.6
Anthony Davis    24.3 10.3  1.9  1.3  2.0
DeMar DeRozan    23.7  4.4  3.9  1.0  0.3
Russ Westbrook   23.6  7.7 10.4  2.1  0.3
Paul George      23.4  7.0  4.2  1.9  0.3
Klay Thompson    22.2  3.9  2.1  0.8  0.6
Isaiah Thomas    22.2  3.0  6.4  1.1  0.1
Kyle Lowry       21.9  5.0  6.4  2.2  0.4
Carmelo Anthony  21.9  7.9  4.2  0.8  0.5
Jimmy Butler     21.4  5.2  4.5  1.7  0.6
```

where: `PPG` = Points, `REB` = Rebounds, `AST` = Assists, `STL` = Steals, and `BLK` = Blocks, on a per game basis.

Your parents believe the best fantasy player will maximize the value FAN given by the following formula:

![Alt text](Formula.PNG?raw=true "Formula")

Help your parents out by reordering such a list of players by this new statistic.

Your task is to write a program that takes an input file **nba.txt** (formatted as above) containing a list of players and to output the data sorted by the new statistic FAN. You may assume:
* The file **nba.txt** is formatted as above and contains between 1 and 999 players,
* Each player's first name and last name contains at most 10 characters,
* Each statistic (including the new one) will total less than 100, and
* The FAN statistic will be greater than 10 for each player in the file.

The output for your program should look exactly as follows for the sample data given.

```
   Player            FAN   PTS   REB   AST  STL  BLK
====================================================
 1 Westbrook, Russ  57.6  23.6   7.7  10.4  2.1  0.3
 2 Cousins, DeMarc  56.8  27.1  11.6   3.3  1.5  1.4
 3 Harden, James    55.7  28.5   6.3   7.4  1.8  0.6
 4 Curry, Stephen   54.7  30.1   5.4   6.5  2.1  0.2
 5 Durant, Kevin    53.0  27.8   8.3   5.0  0.9  1.3
 6 James, LeBron    51.4  25.0   7.4   6.6  1.4  0.6
 7 Davis, Anthony   50.5  24.3  10.3   1.9  1.3  2.0
 8 George, Paul     46.5  23.4   7.0   4.2  1.9  0.3
 9 Lowry, Kyle      46.4  21.9   5.0   6.4  2.2  0.4
10 Lillard, Damian  45.9  25.7   4.2   6.9  0.9  0.4
11 Anthony, Carmelo 43.4  21.9   7.9   4.2  0.8  0.5
12 Butler, Jimmy    42.2  21.4   5.2   4.5  1.7  0.6
13 DeRozan, DeMar   39.8  23.7   4.4   3.9  1.0  0.3
13 Thomas, Isaiah   39.8  22.2   3.0   6.4  1.1  0.1
15 Thompson, Klay   34.8  22.2   3.9   2.1  0.8  0.6
```

**Note:**
* The players names given last name first,
* The rank of the player relative to FAN (observe the tie for 13th). 

Recall that determining whether 2 floating point numbers are equal is very difficult for a computer. Since we are rounding to one decimal place, we can convert the 4 characters in the FAN statistic (e.g., 57.6) to a string using the function `sprintf` and then compare the strings for equality. For this assignment you must perform this conversion and use a function that sorts strings.

**HINT:** While you are sorting the FAN list, at the same time sort a separate array representing the index of sorted items in the original player list. E.g., If Russ Westbrook is indexed by 9 in your original data, then you want 9 to be in the first position of this new array of indexes.

### Logic:

![Alt text](Logic.png?raw=true "Logic")

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
