#include <stdio.h>

void main()
{

//1번 문제
	int Kor, Eng, Math, sum;
	float Avg;
	char grade;
	printf("1번 문제\n");
	printf("세 과목의 점수를 입력하시오\n");
	printf("국어 점수 : ");
	scanf("%d", &Kor);
	printf("수학 점수 : ");
	scanf("%d", &Math);
	printf("영어 점수 : ");
	scanf("%d", &Eng);
	sum = Kor + Eng + Math;
	Avg = (float)sum / 3.0f;

	if (Avg >= 90)
	{
		grade = 'A';
	}
	else if (Avg >= 80)
	{
		grade = 'B';
	}
	else if (Avg >= 70)
	{
		grade = 'C';
	}
	else if (Avg >= 60)
	{
		grade = 'D';
	}
	else
	{
		grade = 'F';
	}

	printf("\n국어 점수 : %d\t수학 점수 : %d\t영어 점수 : %d\n", Kor, Math, Eng);
	printf("총합 점수 : %d\t평균 점수 : %.2f\t등급 : %c\n\n", sum, Avg, grade);



//2번 문제
int money2, time, plustime, Num2;
printf("승마 이용시간을 입력하시오 : ");
scanf("%d", &time);
plustime = (time - 30);
if (time <= 30)
{
	money2 = 3000;
}
else if (time > 30 && plustime % 10 ==0)
{
	money2 = (plustime / 10 * 500) + 3000;
}

else if (time > 30 && plustime % 10 != 0)
{
	money2 = (plustime / 10 * 500) + 3500;
}

printf("%d분 탑승요금 : %d원\n\n", time, money2);



//3번 문제
int Num3, money3, discountmoney, sum3;
money3 = 2500;
printf("구매할 도시락 갯수를 입력하시오 : ");
scanf("%d", &Num3);

if (Num3 <= 10)
{
	sum3 = money3 * Num3;
}
else if (Num3 > 10)
{
	discountmoney = money3 - 100;
	sum3 = (money3 * 10) + (discountmoney * (Num3-10));
}

printf("도시락 %d개 가격 : %d원\n\n", Num3, sum3);



//4번문제
int Num4, money4, sum4;
printf("구매할 디스켓 갯수를 입력하시오 : ");
scanf("%d", &Num4);
if (Num4 < 10)
{
	money4 = 5000;
	sum4 = Num4 * money4;
}
else if (Num4 >= 10 && Num4 < 100)
{
	money4 = 5000 * (1 - 0.1);
	sum4 = (money4 * Num4);
}
else if (Num4 >= 100)
{
	money4 = 5000 * (1 - 0.12);
	sum4 = (money4 * Num4);
}

printf("디스크 %d개 가격 : %d원\n", Num4, sum4);

return;
}