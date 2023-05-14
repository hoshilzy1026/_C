#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int day_of_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main(void) {
    void printCalendar();
	//int year1, month1, day1,year2,month2,day2;
	//int year1, month1, day1, year2, month2, day2;

	//scanf("%d %d %d\n%d %d %d", &year1, &month1, &day1, &year2, &month2, &day2);

	//int ret = distance(year1, month1, day1, year2, month2, day2);
	//printf("两个日期相差%d\n", ret);

	//int a_day_of_the_week = (ret + 4) % 7;
	//printf("%d", a_day_of_the_week);
    int year;
    printf("Please input the year whose calendear you want to know?\n");
    scanf("%d", &year);
    // 打印日历
    printCalendar(year);


	return 0;
}
int  judgeIsLeaoYear(int year) {  //判断是不是闰年，

	return((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

}

void day_of_feb(int year) {

	if (judgeIsLeaoYear(year)) {

		day_of_month[2] = 29;

	}
	else {

		day_of_month[2] = 28;

	}

}

int weekday(int year, int month, int day) {
    int days = distance(1970, 1, 1, year, month, day);
    return (4 + days) % 7;
}
int distance(int year1, int month1, int day1, int year2, int month2, int day2) {

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

void printCalendar(year) {
    printf("|=====================The Calendar of Year %d====================|\n", year);

    for (int i = 1; i <= 6; i++) {
        printf(": %2d  SUN MON TUE WED THU FRI SAT  %2d  SUN MON TUE WED THU FRI SAT :\n", i, i + 6);
        // 打印每个月的第一行
        printf(":    ");
        int wd1 = weekday(year, i, 1);
        int day1 = 1;
        // 打印前置空白字符
        for (int j = 0; j < wd1; j++) {
            printf("    ");
        }
        // 打印日期，到下一个周天为止
        while (day1 == 1 || wd1 != 0) {
            printf("%4d", day1++);
            wd1 = (wd1 + 1) % 7;
        }
        // 打印两个月份之间的空白字符
        printf("     ");

        int wd2 = weekday(year, i + 6, 1);
        int day2 = 1;
        for (int j = 0; j < wd2; j++) {
            printf("    ");
        }
        while (day2 == 1 || wd2 != 0) {
            printf("%4d", day2++);
            wd2 = (wd2 + 1) % 7;
        }
        printf(" :\n");

        // 打印每个月的剩余行
        while (day1 <= day_of_month[i] || day2 <= day_of_month[i + 6]) {
            printf(":    ");
            // 计算剩余天数
            int d1 = day_of_month[i] - day1 + 1;
            if (d1 <= 0) { // 如果剩余天数<=0，打印空行
                printf("                            ");
            }
            else if (d1 < 7) { // 如果剩余天数<7
                for (int k = 1; k <= d1; k++) {
                    printf("%4d", day1++);
                }
                for (int k = 1; k <= 7 - d1; k++) {
                    printf("    ");
                }
            }
            else { //如果剩余天数>=7
                for (int k = 1; k <= 7; k++) {
                    printf("%4d", day1++);
                }
            }

            printf("     ");

            int d2 = day_of_month[i + 6] - day2 + 1;
            if (d2 <= 0) {
                printf("                            ");
            }
            else if (d2 < 7) {
                for (int k = 1; k <= d2; k++) {
                    printf("%4d", day2++);
                }
                for (int k = 1; k <= 7 - d2; k++) {
                    printf("    ");
                }
            }
            else {
                for (int k = 1; k <= 7; k++) {
                    printf("%4d", day2++);
                }
            }
            printf(" :\n");
        }
    }
    printf("|==================================================================|\n");
}