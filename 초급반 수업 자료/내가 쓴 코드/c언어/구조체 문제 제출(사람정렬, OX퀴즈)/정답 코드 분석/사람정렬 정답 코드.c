﻿#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#define MAX 5
typedef struct people
{
	char Name[10];
	int Age;
	float Height;
}People;

char* CreateFirstName()
{
	switch (rand() % 7)
	{
	case 0:
		return "김민지";
	case 1:
		return "이승현";
	case 2:
		return "박민주";
	case 3:
		return "최형석";
	case 4:
		return "정수리";
	case 5:
		return "조광일";
	case 6:
	default:
		return "강동혁";
	}
}

void SetPeople(People* P, int i)
{
	strcpy(P->Name, CreateFirstName());
	P->Age = rand() % 4 + 20;
	P->Height = (float)(rand() % 400 + 1500) / 10.0f;
	//rand로 소수점을 뽑기위해선 뽑으려는 자리수에 맞춰서 float or double로 나누어 주면 된다
	//0~399 + 1500 = 1500.000000 ~ 1899.000000 / 10.0f = 150.000000 ~ 189.000000
}

void ShowPeople(People P)
{
	printf("이름 : %s\t", P.Name);
	printf("나이 : %d\t", P.Age);
	printf("키 : %.2f\n", P.Height);
}

void Sort_Arr(People* P)
{
	People tmp;
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (P[i].Age < P[j].Age || (P[i].Age == P[j].Age && P[i].Height < P[j].Height))
			{
				tmp = P[i];
				P[i] = P[j];
				P[j] = tmp;
			}
		}
	}
}

void main()
{
	srand(time(NULL));
	People P_List[MAX];
	while (1)
	{
		system("cls");
		for (int i = 0; i < MAX; i++)
			SetPeople(&P_List[i], i);

		printf("정렬 전 정보 \n");
		for (int i = 0; i < MAX; i++)
			ShowPeople(P_List[i], i);
		printf("=====================\n\n");
		system("pause");

		Sort_Arr(P_List);

		for (int i = 0; i < MAX; i++)
			ShowPeople(P_List[i], i);
		system("pause");
	}
}
