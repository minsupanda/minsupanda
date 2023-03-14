#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define MAX_NUM 10
#define DESC 1
#define ASC 2

void NumberCreate(int Num[MAX_NUM])
{
	for (int i = 0; i < MAX_NUM; i++)
		Num[i] = rand() % 100 + 1;
}

void Sort(int Num[MAX_NUM], int Type)
{
	for (int i = MAX_NUM - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if ((Type == ASC && Num[j] > Num[j + 1]) || (Type == DESC && Num[j] < Num[j + 1]))
			{
				int tmp = Num[j];
				Num[j] = Num[j + 1];
				Num[j + 1] = tmp;
			}
		}
	}
}

void main()
{
	srand(time(NULL));
	int Num[MAX_NUM] = { 0 };
	int select = 0;
	while (1)
	{
		system("cls");
		for (int i = 0; i < MAX_NUM; i++)
			printf("%d ", Num[i]);
		printf("\n");
		printf("1. 번호 생성\n");
		printf("2. 오름차순 정렬\n");
		printf("3. 내림차순 정렬\n");
		printf("4. 종료\n");
		printf("선택 : ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			NumberCreate(Num);
			break;
		case 2:
			Sort(Num, ASC);
			break;
		case 3:
			Sort(Num, DESC);
			break;
		case 4:
			return;
		}
	}
}