#include <stdio.h>

void main()
{

//1�� ����
	int Kor, Eng, Math, sum;
	float Avg;
	char grade;
	printf("1�� ����\n");
	printf("�� ������ ������ �Է��Ͻÿ�\n");
	printf("���� ���� : ");
	scanf("%d", &Kor);
	printf("���� ���� : ");
	scanf("%d", &Math);
	printf("���� ���� : ");
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

	printf("\n���� ���� : %d\t���� ���� : %d\t���� ���� : %d\n", Kor, Math, Eng);
	printf("���� ���� : %d\t��� ���� : %.2f\t��� : %c\n\n", sum, Avg, grade);



//2�� ����
int money2, time, plustime, Num2;
printf("�¸� �̿�ð��� �Է��Ͻÿ� : ");
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

printf("%d�� ž�¿�� : %d��\n\n", time, money2);



//3�� ����
int Num3, money3, discountmoney, sum3;
money3 = 2500;
printf("������ ���ö� ������ �Է��Ͻÿ� : ");
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

printf("���ö� %d�� ���� : %d��\n\n", Num3, sum3);



//4������
int Num4, money4, sum4;
printf("������ ���� ������ �Է��Ͻÿ� : ");
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

printf("��ũ %d�� ���� : %d��\n", Num4, sum4);

return;
}