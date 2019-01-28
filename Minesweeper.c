/*
	By: Devon A. Fazekas
	Created: 12/29/2015

	A spinoff of the classical Minesweeper game. Drawn with ASCII characters within the console window, the user
	navigates the grid using the arrow-keys and makes selections with ENTER. Not unlike the original, the user must
    uncover all the zones while avoiding the bombs. However, the game does not end when a bomb is hit, instead, the user
	loses 50% of their earned points, whereas each successful guess earns only 5-points.
*/

#pragma warning(disable : 4996)

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>

#define BOARD_HEIGHT 20
#define BOARD_WIDTH 40

enum Colors {
	Black,
	DarkDlue,
	DarkGreen,
	DarkAqua,
	DarkRed,
	DarkPurple,
	DarkYellow,
	DarkWhite,
	Grey,
	Blue,
	Green,
	Aqua,
	Red,
	Purple,
	Yellow,
	White
};
enum ItemTypes {
	topLeftCorner = -38,
	topRightCorner = -65,
	bottomLeftCorner = -64,
	bottomRightCorner = -39,
	yBorder = -77,
	xBorder = -60,
	bomb = -72,
	empty = ' ',
	box = -37
};
enum Movements {
	Default,    /// (0)
	Down,       /// (1)
	Up,         /// (2)
	Right,      /// (3)
	Left,       /// (4)
	Wall,       /// (5)
	Bomb,       /// (6)
	Invalid,    /// (7)
	Repeat      /// (8)
};
enum Statuses {
	inactive,
	active
};
enum Difficulties {
	Daddy = 1,
	Bedwetter = 3,
	Thumb_sucker = 5,
	Noob = 20,
	Glutton = 40,
	Asian = 60,
	A_sian = 90
};
typedef struct zone_struct {
	int X;
	int Y;
	int bombLoc;
	int userLoc;
	char skin;
	int status;
	int adjBombs;
} zone;

int bombLocate[BOARD_WIDTH][BOARD_HEIGHT];
int userLocate[BOARD_WIDTH][BOARD_HEIGHT];
char zoneSkin[BOARD_WIDTH][BOARD_HEIGHT];
int zoneStatus[BOARD_WIDTH][BOARD_HEIGHT];
int adjacBombs[BOARD_WIDTH][BOARD_HEIGHT];


void ResetGame(int difficulty);
void Color(enum Colors ChosenColor);
void MoveCursor(int x, int y);
int  SetDifficulty(int difficulty);
void GenBombs(int *bombCount, int *emptyZCount, int difficulty);
void ComputeAdjBombs(void);
void Menu(void);
void PrintZone(int x, int y);
void ColorZone(int x, int y);
void BombDetect(int x, int y, int *userScore, int *bombCount, int *emptyZCount);
void UserControl(int x, int y, int userScore, int bombCount, int emptyZCount, int *difficulty);


int main(void) {
	/// Initiate game:
	int difficulty = Bedwetter;
	Menu();
	ResetGame(difficulty);

	/// Conclude game:
	system("cls");
	Color(Aqua);
	printf("Ended. Press ENTER.");
	getchar();
	return 0;
}
void ResetGame(int difficulty) {
	int bombCount;
	int userScore;
	int emptyZCount;
	int x = 0, y = 0;

	/// Resets all content:
	system("cls");
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			bombLocate[j][i] = 0;
			userLocate[j][i] = 0;
			zoneSkin[j][i]   = box;
			zoneStatus[j][i] = inactive;
			adjacBombs[j][i] = 0;
		}
	}
	userScore = 0;
	bombCount = 0;
	emptyZCount = 0;
	difficulty = SetDifficulty(difficulty);

	/// Generates bomb, count bombs, count empty zones:
	GenBombs(&bombCount, &emptyZCount, difficulty);

	/// Compute adjacent bombs per zone:
	ComputeAdjBombs();

	/// Prints initial gameboard:
	userLocate[1][1] = 1;  /// Sets user's initial location.
	for (y = 0; y < BOARD_HEIGHT; y++) {
		for (x = 0; x < BOARD_WIDTH; x++) {
			PrintZone(x, y);
		}
	}

	/// Sets user's starting coordinates and initiates game controls:
	x = 1, y = 1;
	UserControl(x, y, userScore, bombCount, emptyZCount, &difficulty);
	return;
}
void Color(enum Colors ChosenColor) {
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, ChosenColor);
	return;
}
int SetDifficulty(int difficulty) {
	switch (difficulty) {
	case '1':	difficulty = Daddy;			break;
	case '2':	difficulty = Bedwetter;		break;
	case '3':	difficulty = Thumb_sucker;	break;
	case '4':	difficulty = Noob;			break;
	case '5':	difficulty = Glutton;		break;
	case '6':	difficulty = Asian;			break;
	case '7':	difficulty = A_sian;		break;
	default:								break;
	}

	return difficulty;
}
void MoveCursor(int x, int y) {
	COORD coor;
	coor.X = x;
	coor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
}
void GenBombs(int *bombCount, int *emptyZCount, int difficulty) {

	srand((int)time(0));
	for (int y = 1; y < (BOARD_HEIGHT - 1); y++) {
		for (int x = 1; x < (BOARD_WIDTH - 1); x++) {
			if ((rand() % 100) < difficulty) {
				bombLocate[x][y] = 1;   /// Place bomb in zone.
				*bombCount += 1;           /// Add bomb to counter.
			}
			*emptyZCount += 1;         /// Add empty zone to counter.
		}
	}
	*emptyZCount -= *bombCount;
	return;
}
void ComputeAdjBombs(void) {
	int bombCount = 0;

	/// Cycle through all zones:
	for (int y = 1; y < (BOARD_HEIGHT - 1); y++) {
		for (int x = 1; x < (BOARD_WIDTH - 1); x++) {

			/// Skips zones that contain bombs:
			if (bombLocate[x][y] == 1) {
				continue;
			}

			/// Cycle through adjacent zones:
			for (int j = -1; j <= 1; j++) {
				for (int i = -1; i <= 1; i++) {

					/// Count adjacent bombs:
					if (bombLocate[x + i][y + j] == 1) {
						bombCount++;
					}
				}
			}
			adjacBombs[x][y] = bombCount;
			bombCount = 0;
		}
	}

	return;
}
void Menu(void) {
	char userInput = '-';
	int x = 0, y = 0;

	/// Menu options:
	system("cls");
	do {
		/// Options:
		Color(Yellow);
		MoveCursor(15, y = 0);  printf("OPTIONS:");
		MoveCursor(x, ++y);     printf("(%d) Return to game", y);
		MoveCursor(x, ++y);     printf("(%d) Rules", y);
		MoveCursor(x, ++y);     printf("(%d) Controls", y);
		MoveCursor(x, ++y);     printf("(%d) Difficulty", y);
		MoveCursor(x, ++y);     printf("(%d) Quit game", y);
		userInput = getch();

		if ((userInput == '2') || (userInput == '3') || (userInput == '4')) {
			system("cls");  MoveCursor(x = 0, y = 0);  Color(Yellow);  printf("(Any key) Back");  Color(Purple);
		}

		if (userInput == '2') {         /// Rules.
			MoveCursor(15, y = 1);  printf("RULES:");
			MoveCursor(0, y += 2);  printf("Avoid as many bombs as possible while making selections.");
			MoveCursor(0, ++y);     printf("Game ends when all empty zones have been selected.");
			MoveCursor(0, ++y);     printf("Five (5) pts are rewarded for every bomb avoided.");
			MoveCursor(0, ++y);     printf("Half (1/2) your pts lost for every bomb hit.");
			getch();
		}
		else if (userInput == '3') {  /// Controls.
			MoveCursor(15, y = 1);  printf("CONTROLS:");
			MoveCursor(0, y += 2);  printf("(arrows) Navigation");
			MoveCursor(0, ++y);     printf("(ENTER) Select");
			MoveCursor(0, ++y);     printf("(m) Menu");
			MoveCursor(0, ++y);     printf("(q) Quit");
			getch();
		}
		else if (userInput == '4') {  /// Difficulty.
			MoveCursor(15, y = 1);  printf("DIFFICULTY:");
			MoveCursor(0, y += 2);  printf("(%d) Can I play, daddy?", y - 2);
			MoveCursor(0, ++y);     printf("(%d) Bedwetter", y - 2);
			MoveCursor(0, ++y);     printf("(%d) Thumb-sucker", y - 2);
			MoveCursor(0, ++y);     printf("(%d) Noob", y - 2);
			MoveCursor(0, ++y);     printf("(%d) Glutton for punishment", y - 2);
			MoveCursor(0, ++y);     printf("(%d) Asian", y - 2);
			MoveCursor(0, ++y);     printf("(%d) [A+]sian", y - 2);
			MoveCursor(0, y += 2);  Color(Red);  printf("WARNING: ");
			Color(White);           printf("Changing the difficulty will reset your progress.");

			/// Option validation:
			char c = getch();
			if ((isdigit(c) >= 1) && (isdigit(c) <= 7)) {
				ResetGame(c);
			}
		}
		else if (userInput == '5') {  /// Quit.
			exit(0);
		}

		if ((userInput == '2') || (userInput == '3') || (userInput == '4')) {
			system("cls");
		}
	} while (userInput != '1');         /// Return.

										/// Reprint current game:
	system("cls");
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			PrintZone(x, y);
		}
	}
	return;
}
void PrintZone(int x, int y) {
	MoveCursor(x, y);

	/// Assigns zones their appropriate skins.
	if ((x == 0) || (x == (BOARD_WIDTH - 1)) || (y == 0) || (y == (BOARD_HEIGHT - 1))) {
		if ((x == 0) && (y == 0)) {                                           /// Top-left corner.
			zoneSkin[x][y] = topLeftCorner;
		}
		else if ((x == 0) && (y == (BOARD_HEIGHT - 1))) {                   /// Bottom-left corner.
			zoneSkin[x][y] = bottomLeftCorner;
		}
		else if ((x == (BOARD_WIDTH - 1)) && (y == 0)) {                    /// Top-right corner.
			zoneSkin[x][y] = topRightCorner;
		}
		else if ((x == (BOARD_WIDTH - 1)) && (y == (BOARD_HEIGHT - 1))) {   /// Bottom-right corner.
			zoneSkin[x][y] = bottomRightCorner;
		}
		else if ((y == 0) || (y == (BOARD_HEIGHT - 1))) {                   /// Top/Bottom borders.
			zoneSkin[x][y] = xBorder;
		}
		else if ((x == 0) || (x == (BOARD_WIDTH - 1))) {                    /// Left/Right borders.
			zoneSkin[x][y] = yBorder;
		}
	}
	else if (zoneStatus[x][y] == 1) {         /// If zones are active.
		if (bombLocate[x][y] == 1) {            /// Bomb.
			zoneSkin[x][y] = bomb;
		}
		else if (adjacBombs[x][y] > 0) {      /// Has adjacent bombs.
			switch (adjacBombs[x][y]) {
			case 1:   zoneSkin[x][y] = '1';   break;
			case 2:   zoneSkin[x][y] = '2';   break;
			case 3:   zoneSkin[x][y] = '3';   break;
			case 4:   zoneSkin[x][y] = '4';   break;
			case 5:   zoneSkin[x][y] = '5';   break;
			case 6:   zoneSkin[x][y] = '6';   break;
			case 7:   zoneSkin[x][y] = '7';   break;
			case 8:   zoneSkin[x][y] = '8';   break;
			}
		}
		else {                                /// Empty.
			zoneSkin[x][y] = box;
		}
	}
	else {                                    /// Inactive.
		zoneSkin[x][y] = box;
	}

	/// Prints zone:
	ColorZone(x, y);
	printf("%c", zoneSkin[x][y]);
	return;
}
void ColorZone(int x, int y) {
	/// Skin coloration:
	if (userLocate[x][y] == 1) {                                        /// Player.
		Color(Green);
	}
	else if (zoneSkin[x][y] == bomb) {                                /// Bombs.
		Color(Red);
	}
	else if ((zoneSkin[x][y] <= '1') && (zoneSkin[x][y] >= '8')) {     /// Boxes.
		Color(Aqua);
	}
	else if ((zoneSkin[x][y] == box) && (zoneStatus[x][y] == 0)) {    /// Inactive empties.
		Color(Grey);
	}
	else if ((zoneSkin[x][y] == box) && (zoneStatus[x][y] == 1)) {    /// Active empties.
		Color(Black);
	}
	else {                                                            /// Borders.
		Color(Grey);
	}
	return;
}
void BombDetect(int x, int y, int *userScore, int *bombCount, int *emptyZCount) {
	if (bombLocate[x][y] == 1) {    /// If bomb hit.
		*userScore /= 2;
		*bombCount -= 1;
	}
	else {                        /// If bomb avoided.
		*userScore += 5;
		*emptyZCount -= 1;
	}
	return;
}
void UserControl(int x, int y, int userScore, int bombCount, int emptyZCount, int *difficulty) {
	char userInput = '-';
	char movement[9][20] = { " ", "Up", "Down", "Right", "Left", "Blocked", "BOMB!!!", "Invalid", "Already opened" };
	char diffTitles[8][40] = { "Can I play, daddy?", "Bedwetter", "Thumb-sucker", "Noob", "Glutton for punishment", "Asian", "[A+]sian" };
	int moveValue = 0;
	int diffValue = 3;
	int a = 0, b = 0;

	while ((emptyZCount != 0) || (bombCount != 0)) {  /*FIX ME!*/

													  /// Prints score:
		MoveCursor((BOARD_WIDTH + (a + 1)), b = 0);   Color(Yellow);   printf("Difficulty: %s\t\t", diffTitles[diffValue]);
		MoveCursor((BOARD_WIDTH + (a + 1)), b = 2);   printf("Score: %d\t\t", userScore);
		MoveCursor((BOARD_WIDTH + (a + 1)), ++b);     printf("Empty zones remaining: %d\t\t", emptyZCount);
		MoveCursor((BOARD_WIDTH + (a + 1)), ++b);     printf("Bombs remaining: %d\t\t", bombCount);
		MoveCursor(a, (BOARD_HEIGHT + 1));            printf("(m) Menu\n(q) Quit");
		MoveCursor((BOARD_WIDTH + (a + 1)), ++b);     printf("Movement: ");

		/// Illustrates invalid movement:
		if ((moveValue == Invalid) || (moveValue == Wall) || (moveValue == Repeat)) {
			Color(Red);
		}

		/// Bomb detection:
		else if (bombLocate[x][y] == 1) {
			if (zoneStatus[x][y] == 1) {
				moveValue = Bomb;
				Color(Aqua);
			}
		}

		/// Prints dialogue:
		printf("* %s *\t\t\t", movement[moveValue]);
		userInput = getch();

		/// Set difficulty's title:
		switch (*difficulty) {
		case Daddy:			diffValue = 0;	break;
		case Bedwetter:		diffValue = 1;	break;
		case Thumb_sucker:	diffValue = 2;	break;
		case Noob:			diffValue = 3;	break;
		case Glutton:		diffValue = 4;	break;
		case Asian:			diffValue = 5;	break;
		case A_sian:		diffValue = 6;	break;
		}

		/// Player's secondary controls and input validationwert:
		switch (userInput) {
		case 'q':               /// Quit.
			exit(0);
		case 'm':               /// Menu.
			moveValue = Default;
			Menu();
			continue;
		case 13:                /// Enter.
			if (zoneStatus[x][y] == inactive) {     /// Validate repeated detection.
				BombDetect(x, y, &userScore, &bombCount, &emptyZCount);
				zoneStatus[x][y] = active;
				PrintZone(x, y);
			}
			else {
				moveValue = Repeat;
			}
			continue;
		case -32:               /// Arrow keys.
			break;
		default:                /// Else.
			moveValue = Invalid;
			continue;
		}

		/// Erases user's cursor from previous zone:
		userLocate[x][y] = 0;
		PrintZone(x, y);

		/// User's movement controls:
		switch (getch()) {
		case 80:                /// Up-arrow.
			if (y == (BOARD_HEIGHT - 2)) {
				moveValue = Wall;
				break;
			}
			y += 1;
			moveValue = Up;
			break;
		case 77:                /// Right-arrow.
			if (x == (BOARD_WIDTH - 2)) {
				moveValue = Wall;
				break;
			}
			x += 1;
			moveValue = Right;
			break;
		case 75:                /// Left-arrow.
			if (x == 1) {
				moveValue = Wall;
				break;
			}
			x -= 1;
			moveValue = Left;
			break;
		case 72:                /// Down-arrow.
			if (y == 1) {
				moveValue = Wall;
				break;
			}
			y -= 1;
			moveValue = Down;
			break;
		default:                /// Else.
			moveValue = Default;
			break;
		}

		/// Assign user's new position:
		userLocate[x][y] = 1;
		PrintZone(x, y);
	}
	return;
}
