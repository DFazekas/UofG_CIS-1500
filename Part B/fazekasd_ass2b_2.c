# include <stdio.h>

int main () {

	int bYear        = 0;
	int bMonth       = 0;
	int bDay         = 0;
	int yearsLived   = 0;
	int monthsLived  = 0;
	const int cYear  = 2016;
	const int cMonth = 2;
	const int cDay   = 12;
	int months[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char monName[14][4] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	int i = 0;

	while(1) {
		printf("Enter your birthday (YYYY,MM,DD): ");
		scanf("%d,%d,%d", &bYear, &bMonth, &bDay);
		getchar();

		// Check negative numbers, invalid days/months/years.
		if ((bYear < 1000) || (bYear > cYear) || (bMonth < 1) || (bMonth > 12) || (bDay < 1) || (bDay > 31)) {
			printf("An invalid birthdate has been entered.\n");
			return;
		}

		// Check for leap year.
		if (((bYear % 4) != 0) && (bMonth == 2) && (bDay>28)) {
			printf("An invalid birthdate has been entered.\n");
			return;
		}
		months[1] += 1;

		// Check # of days in month.
		if ((months[bMonth-1] - bDay) < 0) {
			printf("An invalid birthdate has been entered.\n");
			return;
		}

		// Check birthdate.
		if ((cMonth - bMonth <= 0) && (cDay - bDay < 0)) {
			yearsLived = (cYear - bYear) -1;
		} else {
			 yearsLived = (cYear - bYear);
		}

		if (yearsLived < 0) {
			printf("An invalid birthdate has been entered.\n");
			return;
		}

	printf("You were born on %s %d, %d and you are %d years old.\n\n", monName[bMonth-1], bDay, bYear, yearsLived);

	}
	return 0;
}