#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#define FALSE 0
#define TURE 1
#define PROGRESS 1
#define PERSONNEL 5
#define MIN_AGE 20
#define MAX_AGE 24
#define MIN_HEIGHT 15000
#define MAX_HEIGHT 18000
#define ESC 27


typedef struct people
{
	char Name[10];
	int Age;
	float Height;
}People;

void SetName(People* P_Information);
void SetAge(People* P_Information);
void SetHeight(People* P_Information);
void Sort(People P[PERSONNEL]);
void ShowPeople(People P[PERSONNEL]);

void SetName(People* P_Information)//이름을 랜덤으로 뽑는 함수
{
	char set_Name[PERSONNEL][10] = { "조광일", "이민수", "최형석", "이승현", "강동혁", };
	int Input_Name = rand() % PERSONNEL;
	strcpy((*P_Information).Name, set_Name[Input_Name]);
}

void SetAge(People* P_Information)// 나이를 랜덤으로 뽑는 함수
{
	int Input_Age = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;
	//1을 더하는 것은 rand를 사용하면 0부터 시작하기 때문에 1부터 시작해야하므로 1을 더함
	//최대나이에서 최소나이를 빼면 내가 구할 나이값들의 범위를 구할수 있고 마지막에 최소 나이를 더하면 내가 구하고자하는 나이 범위를 정확하게 뽑을수 있다
	(*P_Information).Age = Input_Age;
	// 배열을 포인터로 사용해서 포인터로 받은 구조체를 따라간 값의 Name멤버에 문자열을 복사
}

void SetHeight(People* P_Information) // 키를 랜덤으로 뽑는 함수
{
	float Input_Height = (float)(rand() % (MAX_HEIGHT - MIN_HEIGHT + 1) + MIN_HEIGHT) / 100.00f;
	// (float)으로 명시적형변환을 시켜주고 마지막에 100.00f를 나누어서 소수를 rand로 뽑는다(rand는 정수만 가능)
	// f를 사옹해 명시적 형변환을 안하면 double로 계산하게 된다( 계산 낭비)
	(*P_Information).Height = Input_Height;
}

void Sort(People P[PERSONNEL]) // 내림차순으로 정렬하는 함수
{
	for (int i = 0; i < PERSONNEL - 1; i++)
	{
		for (int j = i + 1; j < PERSONNEL; j++)
		{
			if (P[i].Age < P[j].Age || (P[i].Age == P[j].Age && P[i].Height < P[j].Height))
			{
				People Sort_Information = P[i];
				P[i] = P[j];
				P[j] = Sort_Information;
			}
		}
	}
}

void ShowPeople(People P[PERSONNEL]) // 출력하는 함수
{
	for (int i = 0; i < PERSONNEL; i++)
		printf("이름 : %s\t나이 : %d\t키 : %.2f\n", P[i].Name, P[i].Age, P[i].Height);
}

void main()
{
	srand(time(NULL));
	People P_Information[PERSONNEL];
	while (PROGRESS)
	{
		for (int i = 0; i < PERSONNEL; i++)
		{
			SetName(&P_Information[i]);
			SetAge(&P_Information[i]);
			SetHeight(&P_Information[i]);
		}
		printf("정렬 전 정보\n");
		ShowPeople(P_Information);
		system("pause");

		Sort(&P_Information);

		printf("정렬 후 정보\n");
		ShowPeople(P_Information);
		system("pause");
		system("cls");

		if (getch() == ESC)
			return;
	}
}
