#include<stdio.h>

int Sum(int Num1, int SumNum)
{
	if (SumNum < Num1)
		SumNum = Sum(Num1 - 1, SumNum);
	else
		return;
	return SumNum += Num1;
}

void Binary(int Num2)
{
	if (Num2 / 2 >= 1)
		Binary(Num2 / 2);
	else
	{
		printf("%d", Num2);
		return;
	}
	printf("%d", Num2 % 2);
}


void main()
{
	int Num1;
	int SumNum = 0;
	printf("1. 정수 입력 : ");
	scanf("%d", &Num1);
	printf("1 ~ %d : %d\n", Num1, Sum(Num1, SumNum));

	int Num2;
	int BinaryNum = 0;
	printf("2. 정수 입력 : ");
	scanf("%d", &Num2);
	printf("%d -> ", Num2);
	Binary(Num2);
}