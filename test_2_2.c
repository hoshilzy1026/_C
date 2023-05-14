#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int day_of_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main(void) {

	//int year1, month1, day1,year2,month2,day2;
	int year1, month1, day1, year2, month2, day2;

	scanf("%d %d %d\n%d %d %d", &year1, &month1, &day1, &year2, &month2, &day2);

	int ret=days_apart(year1, month1, day1, year2, month2, day2);
	printf("两个日期相差%d\n", ret);

	//int a_day_of_the_week = (ret + 4) % 7;
	//printf("%d", a_day_of_the_week);

	return 0;
}
int  judgeIsLeaoYear(int year) {  //判断是不是闰年，

	return((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	
}

void day_of_feb(int year) {

	if (judgeIsLeaoYear(year)) {

		day_of_month[2] = 29;

	}else {

		day_of_month[2] = 28;

	}

}

int days_apart(int year1, int month1, int day1, int year2, int month2, int day2) {

	int days = 0;
	day_of_feb(year1);
	days += day_of_month[month1] - day1;

	for (int i = month1 + 1; i <= 12; i++) {

		days += day_of_month[i];
	}

	for (int i = year1 + 1; i < year2; i++) {

		days += 365;
		if (judgeIsLeaoYear(i)) {

			days++;

		}

	}

	day_of_feb(year2);

	for (int i = 1; i < month2; i++) {

		days += day_of_month[i];

	}

	days += day2;
	if (year1 == year2) {
		days -= 365;
		if (judgeIsLeaoYear(year1)) {
			days--;
		}

	}
	return days;
}
