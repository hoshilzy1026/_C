#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int  NextDay(int *y, int *m, int *d)
{
	
	if ((*d) + 1 > MonthDay(*y, *m)) {

		(*d) = 1;

		if ((*m)+ 1 > 12) {
			
			(*m) = 1;
			
			(*y)++;


		}
		else {
		
			(*m)++;

		}

	}
	else {
		
		(*d)++;

	}
	//printf("下一天时间为：%d %d %d\n", *y, *m, *d);

	return 0;

}
int DaysApart(int *y1, int *m1, int *d1, int *y2, int *m2, int *d2) {
	int i = 0;
	
	while ((*d1!= *d2) || (*m1!=*m2) || (*y1!= *y2)) {

		NextDay(y1, m1, d1);
		i++;

	}

	return i;

}

int main(void) {
	int year_1=1970;
	int month_1=1;
	int day_1=1;
	int year2;
	int month2;
	int day2;

	printf("请输入日期的年月日：\n");
	//scanf("%d %d %d\n%d %d %d", &year_1, &month_1, &day_1 ,& year2, &month2, &day2);
	scanf("%d %d %d", &year2, &month2, &day2);

	//NextDay(&year_1, &month_1, &day_1);
	int ret=DaysApart(&year_1, &month_1, &day_1, &year2, &month2, &day2);
	printf("两次日期相差%d天", ret);

	//int a_day_of_the_week = (ret + 4) % 7;
	//printf("%d\n", ret);
	//printf("%d", a_day_of_the_week);
	//if (a_day_of_the_week == 0) {

	//	a_day_of_the_week = 7;

//	}
	//printf("这一天是星期%d", a_day_of_the_week);
	

	return 0;
}
int  judgeIsLeaoYear(int year) {  //判断是不是闰年，

	return((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

}
int MonthDay(int year_, int month_) {

	switch (month_)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		return 31;
	}


	case 2:
	{

		{
			if (judgeIsLeaoYear(year_))
				return 29;
		}

		return 28;

	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		return 30;
	}

	default:
		break;
	}

}

