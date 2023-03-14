#include<stdio.h>
#define Max 9
void main()
{
	for (int c = 2; c <= Max; c++)
		printf("%4d단\t\t", c);
	printf("\n");
	for (int b = 1; b <= Max; b++)
	{
		for (int a = 2; a <= Max; a++)
			printf("%d * %d = %2d\t", a, b, a * b);
		printf("\n");
	}


	//2번 문제
	int Num;
	printf("정수 입력 : ");
	scanf("%d", &Num);
	for (int y = 1; y <= Num; y++)
	{
		for (int x = 1; x <= y; x++)
			printf("★");
		printf("\n");
	}
	printf("\n\n");


	//3번 문제
	int width, height;
	printf("가로, 세로 입력 : ");
	scanf("%d%d", &width, &height);
	for (int y = 1; y <= height; y++)
	{
		for (int x = 1; x <= width; x++)
		{
			if (y == 1 || y == height || x == 1 || x == width)
				printf("★");
			else
				printf("  ");
		}
		printf("\n");
	}
	return;
}
