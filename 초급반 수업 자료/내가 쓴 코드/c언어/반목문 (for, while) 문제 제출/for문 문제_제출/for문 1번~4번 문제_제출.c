#include<stdio.h>

void main()
{
	//1�� ����
	printf("1-1������\n");
	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
			continue;
		printf("%d.Hello\n", i);
	}
	printf("\n");

	printf("1-2������\n");
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

	printf("1-3������\n");
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



	//2�� ����
	printf("2������\n");
	int money = 1, Sum2 = 1;
	for (int day = 2; day <= 30; day++)
	{
			Sum2 += (money *= 2);
	}
	printf("30�ϵ��� ������ �ݾ� : %d\n\n", Sum2);


	//3�� ����
	printf("3������\n");
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
	printf("1 ~ 1000������ �� : %d\n(3�� ����� �����ϸ� 3�� 5�� ������� �������� �ʴ´�)\n\n", Sum3);


	//4�� ����
	printf("4������ 10000�� �ѱ� ������ ��\n");
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