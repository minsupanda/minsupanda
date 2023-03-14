#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define MAX_NUM 10

void NumberCreate(int Num[MAX_NUM])
{
	int i = 0;
	while (i < MAX_NUM)
	{
		Num[i] = rand() % 20;
		for (int j = 0; j < i; j++)
		{
			if (Num[j] == Num[i])
			{
				i--;
				break;
			}
		}
		i++;
	}
}

void Sort_Ascending(int Num[MAX_NUM])
{
	for (int i = 0; i < MAX_NUM - 1; i++)
	{
		for (int j = i + 1; j < MAX_NUM; j++)
		{
			if (Num[i] > Num[j])
			{
				int tmp = Num[i];
				Num[i] = Num[j];
				Num[j] = tmp;
			}
		}
	}
}

void Sort_descending(int Num[MAX_NUM])
{
	for (int i = 0; i < MAX_NUM - 1; i++)
	{
		for (int j = i + 1; j < MAX_NUM; j++)
		{
			if (Num[i] < Num[j])
			{
				int tmp = Num[i];
				Num[i] = Num[j];
				Num[j] = tmp;
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
			Sort_Ascending(Num);
			break;
		case 3:
			Sort_descending(Num);
			break;
		case 4:
			return;
		}
	}
}