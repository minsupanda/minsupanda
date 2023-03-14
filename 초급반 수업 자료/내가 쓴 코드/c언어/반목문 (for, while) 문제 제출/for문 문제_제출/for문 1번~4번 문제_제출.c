#include<stdio.h>

void main()
{
	//1번 문제
	printf("1-1번문제\n");
	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
			continue;
		printf("%d.Hello\n", i);
	}
	printf("\n");

	printf("1-2번문제\n");
	for (char ch = 'A'; ch <= 'Z'; ch++)
	{
		printf("%c", ch);
		if (ch == 'M' || ch == 'Z')
		{
			printf("\n");
			continue;
		}
		printf(",");
	}
	printf("\n");

	printf("1-3번문제\n");
	int j, sum3 = 0;
	for (j = 1; j <= 9; j++)
	{
		if (j % 3 == 0)
		{
			sum3 += j;
			printf("%d+", j);
			if (j == 9)
				printf("\b=");
		}
	}
	printf("%d\n", sum3);

	int k, sum4 = 0;
	for (k = 1; k <= 9; k++)
	{
		if (k == 9)
		{
			printf("%d=", k);
			sum4 += k;
		}
		else if (k % 3 == 0)
		{
			sum4 += k;
			printf("%d+", k);
		}
	}
	printf("%d\n\n", sum4);



	//2번 문제
	printf("2번문제\n");
	int money = 1, Sum2 = 1;
	for (int day = 2; day <= 30; day++)
	{
			Sum2 += (money *= 2);
	}
	printf("30일동안 저축한 금액 : %d\n\n", Sum2);


	//3번 문제
	printf("3번문제\n");
	int Sum3 = 0;
	for (int Num3 = 1; Num3 <= 1000; Num3++)
	{
		if (Num3 % 3 == 0)
		{
			if (Num3 % 5 == 0)
			{
				Sum3 += Num3;
			}
			continue;
		}
		Sum3 += Num3;
	}
	printf("1 ~ 1000사이의 합 : %d\n(3의 배수는 제외하며 3과 5의 공배수는 제외하지 않는다)\n\n", Sum3);


	//4번 문제
	printf("4번문제 10000을 넘기 직전의 수\n");
	int l, Sum4 = 0;
	for (l = 1; l % 1 == 0; l++)
	{
		if (l % 2 != 0)
		{
			Sum4 += l;
			if (Sum4 >= 10000)
				break;
		}
	}
	printf("l : %d,\tSum : %d\n\n", l, (Sum4 - l));
	return;
}