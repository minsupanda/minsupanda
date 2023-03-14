#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define QUIZ_MAX 10
#define FALSE 0
#define TURE 1
#define O 79
#define X 88


typedef struct question
{
	//구조체의 주소는 가장먼저 선언된 변수의 시작주소와 동일하다.
	char Quiz[256];
	int Answer;
	//구조체의 크기는 선언된 변수 중 가장 큰 변수의 규격을 따라 정해지고 그에 따라 빈 공간이 생길 수도 있다.
}Question;


//전방선언 : 함수의 위치에 따라 뜨는 오류(재정의..) 방지
char* Create_Quiz(Question Quiz[QUIZ_MAX], int Use_Quiz[QUIZ_MAX], int i);
void Show_Quiz(Question Quiz[QUIZ_MAX], int* score, int* plus_score, int* present_score);
void Correct_Answer(Question Quiz[QUIZ_MAX], int i, int* score, int* plus_score, int* present_score);
void Score(int* score, int* plus_score, int* present_score, int answer);

char* Create_Quiz(Question Quiz[QUIZ_MAX], int Use_Quiz[QUIZ_MAX], int i) // 퀴즈 순서 랜덤으로 만드는 함수
//배열은 포인터로 활용할 수 있다. 
//리턴값이 단일문자가 아니라(단일문자면 char 그대로 사용) 문자열이므로 시작주소 받아서 NULL갑싱 나올 때 까지 출력해야함
//포인터를 활용해서 (배열처럼 활용할 수 있으므로) 시작주소를 받아서 NULL값까지 출력하면 가능하다
{
	while (1)
	{
		int Quiz_Number = rand() % QUIZ_MAX;
		if (Use_Quiz[Quiz_Number] == FALSE)
		{
			Use_Quiz[Quiz_Number] = TURE;
			//문제중복 방지를 위한것
			switch (Quiz_Number)
			{
			case 0:
				Quiz[i].Answer = O;
				return "1 + 2 는 3입니다.";
			case 1:
				Quiz[i].Answer = O;
				return "2 + 3 는 5입니다.";
			case 2:
				Quiz[i].Answer = X;
				return "3 + 4 는 100입니다.";
			case 3:
				Quiz[i].Answer = X;
				return "5 + 6 는 100입니다.";
			case 4:
				Quiz[i].Answer = O;
				return "6 + 7 는 13입니다.";
			case 5:
				Quiz[i].Answer = O;
				return "7 + 8 는 15입니다.";
			case 6:
				Quiz[i].Answer = X;
				return "8 + 9 는 100입니다.";
			case 7:
				Quiz[i].Answer = O;
				return "9 + 10 는 19입니다.";
			case 8:
				Quiz[i].Answer = O;
				return "10 + 11 는 21입니다.";
			case 9:
				Quiz[i].Answer = X;
				return "지금까지 나온 모든 수의 합은 612입니다.";
			}
		}
	}
}


void Show_Quiz(Question Quiz[QUIZ_MAX], int* score, int* plus_score, int* present_score) // 퀴즈 출력하는 함수
{
	for (int i = 0; i < QUIZ_MAX; i++)
	{
		printf("%s\n", Quiz[i].Quiz);
		Correct_Answer(Quiz, i, score, plus_score, present_score);
	}
}

void Correct_Answer(Question Quiz[QUIZ_MAX], int i, int* score, int* plus_score, int* present_score) // 정답확인하는 함수
{
	int answer;
	char Input_Answer;
	//scanf("%c", &Input_Answer);
	//scanf를 사용하면 입력버퍼에 Enter값 까지 들어가서 입력버퍼에 값이 남아 자동으로 오답처리 됨
	//입력버퍼를 비워줘야함 : scanf("%*c");
	scanf(" %c", &Input_Answer);
	//Input_Answer = getch();
	if ((int)Input_Answer == Quiz[i].Answer || (int)Input_Answer == Quiz[i].Answer + 32)
		// 소문자,대문자 둘다 사용하기 위함
	{
		printf("정답!!\n");
		answer = TURE;
	}
	else
	{
		printf("오답..\n");
		answer = FALSE;
	}

	Score(score, plus_score, present_score, answer);
}

void Score(int* score, int* plus_score, int* present_score, int answer) // 점수 증가 함수
{
	if (answer == TURE)
	{
		*present_score = (*plus_score)++; //괄호안치면 주소값이 증가된다
		*score += *present_score;
	}
	else
		*plus_score = 1;
	//정답일떄는 1점씩 증가, 연속정답은 +1 씩 더 증가, 틀리면 +1씩 증가되던 값을 0으로 초기화﻿
}

void main()
{
	srand(time(NULL));
	Question Quiz[QUIZ_MAX];
	//Question* Quiz[QUIZ_MAX] : 이거는 포인터 변수가 10개 만들어지는 것
	//이렇게 포인터 변수로 만들어야 애로우 연산자가 사용 가능하다
	int score = 0;
	int Plus_score = 1;
	int present_score = 0;
	int Use_Quiz[QUIZ_MAX] = { FALSE };

	for (int i = 0; i < QUIZ_MAX; i++)
		strcpy(Quiz[i].Quiz, Create_Quiz(Quiz, Use_Quiz, i));
	//처음에 ->(애로우 연산자)를 썼는데 오류
	//지금 Quiz는[i]는 데이터를 들고 있는데 애로우 연산자는 주소를 따라가는 것이므로 오류가 나는 것
	//그러므로 주소값을 저장하고 있으면 애로우 연산자, 데이터를 가지고 있으면 멤버연산자를 사용하면 된다.

	Show_Quiz(Quiz, &score, &Plus_score, &present_score);
	printf("점수 : %d", score);
	system("pause");
}