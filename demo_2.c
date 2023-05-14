#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void NextDay(int year_, int month_, int day_)
{
	if (day_ + 1 > MonthDay(year_, month_)) {

		day_ = 1;


		if (month_ + 1 > 12) {
			month_ = 1;

			year_++;


		}
		else {
			month_++;


		}

	}
	else {
		day_++;

	}
	printf("下一天时间为：%d %d %d\n", year_, month_, day_);


}
int DaysApart(int year_, int month_, int day_, int year_2, int month_2, int day_2) {
	int i = 0;

	/*while (day_a == day_2 && month_a == month_2 && year_a == year_2)
			{

			   NextDay(year_, month_, day_);

			   i++;
		   }*/
	while ((day_ != day_2) || (month_ != month_2) || (year_ != year_2)) {
		NextDay(year_, month_, day_);
		i++;

	}


	return i;
}

int main(void) {
	int year_1;
	int month_1;
	int day_1;
	int year2;
	int month2;
	int day2;

	printf("请输入日期的年月日：");
	scanf("%d %d %d", &year_1, &month_1, &day_1);
	//scanf("%d %d %d", &year_1, &month_1, &day_1);

	NextDay(year_1, month_1, day_1);
	/*int t = DaysApart(year_1, month_1, day_1, year2, month2, day2);
	printf("两次日期相差%d天", t);*/

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

