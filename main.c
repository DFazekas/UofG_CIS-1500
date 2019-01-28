#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

enum Colors
{
    Black,DarkDlue,DarkGreen,DarkAqua,DarkRed,DarkPurple,DarkYellow,DarkWhite,Grey,Blue,Green,Aqua,Red,Purple,Yellow,White
};

void Color();               /** Controls text coloration. **/
void ClearDialogue();       /** Refreshes dialogue section. **/
void PlayGame();            /** Handles gameplay. **/
int StoredPositions();     /** Refreshes game board & Stores user's guesses. **/
int Dialogue();

int main()
{
        /// Variables.

    char Replay = '0';                                      /** Resets Replay loop to TRUE. **/

        /// Initiates gameplay.
    PlayGame();                                             /** Initiates gameplay. **/

        /// Prompts Replay option.
    while (Replay != 'y' && Replay != 'n')                  /** While user's Replay answer = Invalid. **/
    {
        system("cls");                                      /** Clears screen. **/
        Color(Yellow);                                      /** Changes text color to Yellow. **/
        printf("Would you like to play again? [y/n]: ");
        fflush(stdin);                                      /** Clears buffer. **/
        scanf(" %c", &Replay);                              /** Scans for Replay answer. **/
        if (Replay == 'n')                                  /** If user's Replay answer = No. **/
        {
            system("cls");                                  /** Clears screen. **/
            Color(Yellow);                                  /** Changes text color to Yellow. **/
            printf("Thank you for playing!\n");
            break;                                          /** Concludes main. **/
        }
        else if (Replay == 'y')                             /** If Replay answer = Yes. **/
        {
            Replay = '0';                                   /** Resets Replay loop. **/
            PlayGame();                                     /** Restarts game. **/
        }
        else                                                /** If Replay answer = Invalid. **/
        {
            system("cls");                                  /** Clears screen. **/
            Color(Red);                                     /** Changes text color Red. **/
            printf("Invalid. Try again!\n");
        }
    }
        /// Concludes program.
    Color(Grey);                                            /** Changes text color to Grey. **/
    return 0;                                               /** Terminates console window. **/
}

void PlayGame()                                                             /** Handles gameplay. **/
{
        /// Variables.
    int SavingPosition[10][10] = {{0}};                                         /** Resets guessed positions. **/
    int GuessedPosition[2] = {0};
    int xGuess = 10;                                                        /** Resets user's guessed X coordinate value. **/
    int yGuess = 10;                                                        /** Resets user's guessed Y coordinate value. **/
    int BombPosition[10][10] = {{0}};                                         /** Resets bomb positions. **/
    int xBomb;                                             /** Randomly generates X coordinate value for Bomb. **/
    int yBomb;                                             /** Randomly generates Y coordinate value for Bomb. **/
    BOOL NextRound = TRUE;                                                  /** Resets PlayGame loop. **/
    int Reply = 0;                                                          /** Resets duplcated guess replies. **/
    int BombHits = 0;
    int Hit = 0;
    int AdjBombs[10][10] = {{0}};
    int i = 0, j = 0;

        /// Generates bombs.
    for (yBomb=0; yBomb<10; yBomb++)
    {
        for (xBomb=0; xBomb<10; xBomb++)
        {
            int i = (rand() % 100);
            if (i <= 18)
            {
                (BombPosition)[xBomb][yBomb] = 1;
                for (j = yBomb+1; j > yBomb-1; j--)
                {
                    for (i = xBomb-1; i < xBomb+1; i++)
                    {
                        if((BombPosition)[i][j] != 1){(AdjBombs)[i][j]++;}
                        printf("[%d][%d]=%d  ", i, j , AdjBombs[i][j]);
                    }
                    printf("\n");
                }

            }
        }
        //printf("\n");

    }
        /// ------------------------------------------------------------------------------ ///
    int AxisLabels[10] = {0,1,2,3,4,5,6,7,8,9};                 /** Declares game board axis labels. **/
    char Grid[10];
    printf("  "); for(i = 0; i < 10; i++)            /** Loops X axis labels. **/
    {
        Color(Yellow);                                              /** Changes text color to White. **/
        printf("%d ", AxisLabels[i]);                          /** Display horizontal coordinate. **/
    }
    printf("\n");
    for(j = 0; j < 10; j++)                          /** Loops Y axis labels. **/
    {
        Color(Yellow);                                              /** Changes text color to White. **/
        printf("%d", AxisLabels[j]);                           /** Display vertical coordinate. **/
        for(i = 0; i < 10; i++) {                     /** Loops horizontal grid display until horizontal limit reached. **/
            Grid[i] = AdjBombs[i][j];
            if(BombPosition[i][j] == 1){Color(Green); printf(" %d", Grid[i]);}
            else if(AdjBombs[i][j] == 0){Color(Red); printf(" %d", Grid[i]);}
            else{                                  /** Inserts symbol in j-th horizontal position of grid. **/
                Color(Grey);                                        /** Change text color to Grey. **/
                printf(" %d", Grid[i]);
                                    }/** Display symbol. **/
            }

        printf("\n");                                               /** Display new line. **/
    }
        /// ------------------------------------------------------------------------------ ///
    /*switch(AdjBombs[i][Y])
    {
        case 0:
            Grid[xCount] = '0';
            break;
        case 1:
            Grid[xCount] = '1';
            break;
        case 2:
            Grid[xCount] = '2';
            break;
        case 3:
            Grid[xCount] = '3';
            break;
        case 4:
            Grid[xCount] = '4';
            break;
        case 5:
            Grid[xCount] = '5';
            break;
        case 6:
            Grid[xCount] = '6';
            break;
        case 7:
            Grid[xCount] = '7';
            break;
        case 8:
            Grid[xCount] = '8';
            break;
    }*/
    getchar();
    system("cls");
    StoredPositions(xGuess, yGuess, SavingPosition, BombPosition, BombHits);                        /** Prints initial gameboard. **/
    ClearDialogue();                                                    /** Prints initial dialogue. **/
    while (NextRound)                                                       /** Loops game until quit sequence chosen. **/
    {

        while ((xGuess < 0 || xGuess > 9) || (yGuess < 0 || yGuess > 9))    /** While user's guess = Invalid. **/
        {
            Color(Yellow);                                                  /** Changes text color to Yellow. **/
            printf ("Enter ## to guess, or qq to quit: ");
            xGuess = getchar()-48;
            yGuess = getchar()-48;
            getchar();

            //scanf(" %d %d", &xGuess, &yGuess);                              /** Scans for X & Y guessed coordinate values. **/
            fflush(stdin);                                                  /** Clears buffer. **/
            if ((xGuess < 0 || xGuess > 9) || (yGuess < 0 || yGuess > 9))   /** If user's guess = Invalid. **/
            {
                ClearDialogue();                                            /** Clears dialogue. **/
                Color(Red);                                                 /** Changes text color to Red. **/
                printf("Invalid. Try again!\n");
                if (xGuess == 'q'-48)                                           /** If user's guess = Quitting sequence. **/
                {
                    ClearDialogue();                                        /** Clears dialogue. **/
                    return;                                                 /** Return to main. **/
                }
            }
        }
        if (SavingPosition[xGuess][yGuess] == 1)                            /** Handles dialogue of repeated coordinates. **/
        {
            ClearDialogue();                                                /** Clears dialogue. **/
            Color(Red);                                                     /** Changes text color to Red. **/
            switch (Reply)                                                  /** Alternates dialogue. **/
            {
                case 0:
                    printf("Are you blind? You've already chosen there!\n");
                    Reply++;
                    break;
                case 1:
                    printf("Seriously? Try opening your eyes before choosing!\n");
                    Reply++;
                    break;
                case 2:
                    printf("...SIGH.... Try again!\n");
                    Reply++;
                    break;
                case 3:
                    printf("If you don't stop choosing the same spots, I'm going volunteer you as a test subject at Aperture Laboratories.\n");
                    Reply++;
                    break;
                default:
                    printf("I'm sorry, you must have missed the signs somewhere - This game isn't for children. Goodbye.\n");
                    getchar();
                    return;
            }
            xGuess = 10; yGuess = 10;
        }
        else
        {
            BombHits = StoredPositions(xGuess, yGuess, SavingPosition, BombPosition, BombHits);
            ClearDialogue();
            //StoredPositions(xGuess, yGuess, SavingPosition, BombPosition, BombHits);
            Hit = Dialogue(BombHits, Hit);
            //printf("[%d][%d]=...\n", xGuess, yGuess);
            xGuess = 10; yGuess = 10;                                           /** Resets user's guess. **/
        }
    }
}

void ClearDialogue()                                    /** Handles dialogue section below game board. **/
{
    COORD coord;                                        /** Declares coord for future cursor alterations. **/
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  /** Declares handle for future console text alterations. **/
    int i;                                              /** Vertical dialogue clearing count. **/
    int j;                                              /** Horizontal dialogue clearing count. **/
    coord.X = 0;                                        /** Redefines cursor's X coordinate value. **/
    coord.Y = 11;                                       /** Redefines cursor's Y coordinate value. **/
    SetConsoleCursorPosition(hConsole, coord);          /** Refreshes cursor's position. **/
    for(i=0; i<=3; i++)                                 /** Loops Y dialogue clearer. **/
    {
        for(j=0; j<160; j++)                            /** Loops X dialogue clearer. **/
        {
            printf(" ");
        }
        printf("\n");
    }
    coord.X = 0;                                        /** Redefines cursor's X coordinate value. **/
    coord.Y = 12;                                       /** Redefines cursor's Y coordinate value **/
    SetConsoleCursorPosition(hConsole, coord);          /** Refreshes cursor's position. **/
}

void Color(enum Colors ChosenColor)                     /** Handles console text colorations. **/
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  /** Declares handle for future console text alterations. **/
    SetConsoleTextAttribute(hConsole, ChosenColor);     /** Refreshes console text coloration. **/
}

int StoredPositions(int X, int Y, int Guesses[10][10], int Bombs[10][10], int BombHit)         /** Handles game board and stored guesses. **/
{
        /// Variables.
    int xCount = 0;                                             /** Resets horizontal counter. **/
    int yCount = 0;                                             /** Resets vertical counter. **/
    int AxisLabels[10] = {0,1,2,3,4,5,6,7,8,9};                 /** Declares game board axis labels. **/
    char Grid[10];                                              /** Sets size of grid array. **/
    BombHit = 0;
    int HitDialogue = 0;
       /// Resets # of adjacent bombs.
    int i = 0;          /// Resets Y AdjBomb counter.
    int j = 0;          /// Resets X AdjBomb counter.


        /// Repeated coordinates.
    //printf("X[%d] Y[%d]\n", X, Y);
    //getchar();
    //if((X != 10)&&(Y != 10))
    //{
        if((Guesses)[X][Y] == 1) { /*printf("Guesses[%d][%d] = %d", X, Y, Guesses[X][Y]); getchar();*/ return 0; }                    /** Checks if coordinates have already been chosen. **/
        //printf("Guesses[%d][%d] = %d", X, Y, Guesses[X][Y]); getchar();
            /// New coordinates.
        system("cls");                                              /** Clears screen. **/
        (Guesses)[X][Y] = 1;                                        /** Saves guessed location. **/
    //}
    printf("  "); for(xCount = 0; xCount < 10; xCount++)            /** Loops X axis labels. **/
    {
        Color(Yellow);                                              /** Changes text color to White. **/
        printf("%d ", AxisLabels[xCount]);                          /** Display horizontal coordinate. **/
    }
    printf("\n");
    for(yCount = 0; yCount < 10; yCount++)                          /** Loops Y axis labels. **/
    {
        Color(Yellow);                                              /** Changes text color to White. **/
        printf("%d", AxisLabels[yCount]);                           /** Display vertical coordinate. **/
        for(xCount = 0; xCount < 10; xCount++)                      /** Loops horizontal grid display until horizontal limit reached. **/
        {
                /// Handles guessing bombs.
            if ((Guesses[xCount][yCount] == 1) && (Bombs[xCount][yCount] == 1))         /** Handles hitting bombs. **/
            {
                Grid[xCount] = -2;                                  /** Inserts symbol in j-th horizontal position of grid. **/
                BombHit++;                                          /** Records hitting bomb. **/
                HitDialogue = 1;                                    /** Increments hitting bomb dialogue. **/
                Color(Red);                                         /** Change text color to Red. **/
                printf(" %c", Grid[xCount]);                        /** Display symbol. **/
            }
                /// Handles guessing non-bombs.
            else if ((Guesses[xCount][yCount] == 1) && (Bombs[xCount][yCount] == 0))    /** Handles hitting save tiles. **/
            {
                Color(Green);                                       /** Change text color to Red. **/
                Grid[xCount] = -2;
                printf(" %c", Grid[xCount]);                        /** Display symbol. **/
            }
            else                                                    /** Default symbols if guessed coordinates haven't been reached. **/
            {
                Grid[xCount] = -2;                                  /** Inserts symbol in j-th horizontal position of grid. **/
                Color(Grey);                                        /** Change text color to Grey. **/
                printf(" %c", Grid[xCount]);                        /** Display symbol. **/
            }
        }
        printf("\n");                                               /** Display new line. **/
    }
    return BombHit;
}

int Dialogue(int BombHits, int Hit, int AdjBombs[10][10], int xCount, int yCount)
{
    Color(Red);
    if (BombHits != Hit)
    {
        switch(Hit)
        {
            default:
                printf("...[faint crying from behind the screen]...\n");
                Hit++;
                break;
            case 0:
                printf("I believe the objective here is to avoid those... But do it your way.\n");
                Hit++;
                break;
            case 1:
                printf("Have you tried not being terrible?\n");
                Hit++;
                break;
            case 2:
                printf("You're embarrassing me.\n");
                Hit++;
                break;
            case 3:
                printf("Please, for the love of god, give the controls to someone else.\n");
                Hit++;
                break;
            case 4:
                printf("You're starting to seem like the kind of person to punch toddlers in the face, just 'cause.\n");
                Hit++;
                break;
            case 5:
                printf("If I had hands, I'd do more than just face palm you right now.\n");
                Hit++;
                break;
        }
    }
    else
    {
        ClearDialogue();
    }
    return Hit;
}
