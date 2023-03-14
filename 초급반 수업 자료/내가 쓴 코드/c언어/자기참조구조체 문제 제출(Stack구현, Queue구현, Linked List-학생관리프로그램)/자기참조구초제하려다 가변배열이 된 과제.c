#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define PROGRESS 1

void Menu()
{
	printf("===Stack System===\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Exit\n");
	printf("==================\n");
	printf("입력 : ");
}

int* Push(int* Date, int* Index)
{
	(*Index)++;
	int* Temp_Date = (int*)malloc((*Index) * sizeof(int));
	if (Date != NULL)
	{
		for (int i = 0; i < (*Index) - 1; i++)
			Temp_Date[i + 1] = Date[i];
		free(Date);
	}
	printf("데이터 입력 : ");
	scanf("%d", &Temp_Date[0]);
	return Temp_Date;
}

int* Pop(int* Date, int* Index)
{
	if (*Index > 0)
	{
		printf("Pop : %d\n", Date[0]);
		system("pause");
		(*Index)--;
		int* Temp_Date = (int*)malloc((*Index) * sizeof(int));
		for (int i = 0; i < *Index; i++)
			Temp_Date[i] = Date[i + 1];
		free(Date);
		return Temp_Date;
	}
	else
		printf("삭제할 데이터가 없습니다.\n");
	system("pause");
	return Date;
}

void Exit(int* Date)
{
	free(Date);
}

void main()
{
	int* Date;
	Date = NULL;
	int Index = 0;
	int Input_Num;
	while (PROGRESS)
	{
		system("cls");
		Menu();
		scanf("%d", &Input_Num);
		switch (Input_Num)
		{
		case 1:
			Date = Push(Date, &Index);
			break;
		case 2:
			Date = Pop(Date, &Index);
			break;
		case 3:
			Exit(Date);
			return;
		}
	}
}