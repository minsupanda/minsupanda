#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#define PROGRESS 1

typedef struct Stack
{
	int Date;
	struct Stack* Link;
}Stack;

void Menu();
Stack* Push(Stack* Top);
Stack* Pop(Stack* Top);
void Exit(Stack* Top);

void Menu()
{
	printf("===Stack System===\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Exit\n");
	printf("==================\n");
	printf("입력 : ");
}

Stack* Push(Stack* Top)
{
	if (Top == NULL)
	{
		Top = (Stack*)malloc(sizeof(Stack));
		Top->Link = NULL;
	}
	else
	{
		Stack* Temp = Top;
		Top = (Stack*)malloc(sizeof(Stack));
		Top->Link = Temp;
	}
	printf("데이터 입력 : ");
	scanf("%d", &Top->Date);
	return Top;
}

Stack* Pop(Stack* Top)
{
	if (Top != NULL)
	{
		Stack* Temp = Top;
		printf("Pop : %d", Top->Date);
		Top = Top->Link;
		free(Temp);
		Temp = NULL;
	}
	else
		printf("삭제할 데이터가 없습니다.\n");
	system("pause");
	return Top;
}

void Exit(Stack* Top)
{
	while (Top != NULL)
	{
		Stack* Temp = Top;
		Top = Top->Link;
		free(Temp);
	}
}

void main()
{
	Stack* Top = NULL;
	int Input_Num;
	while (PROGRESS)
	{
		system("cls");
		Menu();
		scanf("%d", &Input_Num);
		switch (Input_Num)
		{
		case 1:
			Top = Push(Top);
			break;
		case 2:
			Top = Pop(Top);
			break;
		case 3:
			Exit(Top);
			return;
		}
	}
}