#include<stdio.h>

int Show(int Num1, int Num2)
{
	int Sum = 0;
	while (Num1 <= Num2)
	{
		Sum += Num1;
		printf("%d\n", Sum);
		Num1++;
	}
	return Sum;
}

void main()
{
	int Num1, Num2;
	printf("Num1 정수 입력 : ");
	scanf("%d", &Num1);
	printf("Num2 정수 입력 : ");
	scanf("%d", &Num2);
	printf("Sum : %d", Show(Num1, Num2));
}