﻿#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#define GAMESTART 1
#define MAXORMIN 1
#define SETTING 2
#define MAXTURN 2
#define EXIT 3
#define MIN 0
#define MAX 1
#define MAX_TURN 2
#define OPTION_MAX 3


int GameMenu()
{
	int Select;
	system("cls");
	printf("=========UpDown=========\n");
	printf("\t1.게임시작\n");
	printf("\t2.범위설정\n");
	printf("\t3.종료\n");
	printf("입력 : ");
	scanf("%d", &Select);
	return Select;
}

void GamePlay(int Option[OPTION_MAX])
{
	int RandomNum = (rand() % ((Option[MAX] + 1) - Option[MIN])) + Option[MIN];
	for (int Turn = 1; Turn <= Option[MAX_TURN]; Turn++)
	{
		system("cls");
		printf("범위  : %d ~ %d\n", Option[MIN], Option[MAX]);
		printf("제한 Turn : %d\n", Option[MAX_TURN]);
		printf("========%d턴========\n", Turn);
		printf("입력 : ");
		int Num;
		scanf("%d", &Num);
		if (Num < Option[MIN] || Num > Option[MAX])
		{
			printf("범위를 벗어났습니다.");
			Turn--;
		}
		else if (Num > RandomNum)
			printf("Down!!\n");
		else if (Num < RandomNum)
			printf("Up!!\n");
		else
		{
			system("cls");
			printf("정답!!\t턴수 : %d\n", Turn);
			system("pause");
			return;
		}
		system("pause");
	}
	system("cls");
	printf("GameOver : Trun수 초과!!\n");
	system("pause");
	return;
}

int SetMin(int Min)
{
	printf(" (현재 : %d)최소 값 변경 : ", Min);
	scanf("%d", &Min);
	return Min;
}
int SetMax(int Max, int Min)
{
	printf(" (현재 : %d)최대 값 변경 : ", Max);
	scanf("%d", &Max);
	if (Max <= Min)
	{
		return -1;
	}
	return Max;
}

int SetMaxTurn(int MaxTurn)
{
	printf(" (현재 : %d)최대 Turn 값 변경 : ", MaxTurn);
	scanf("%d", &MaxTurn);
	if (MaxTurn <= 0)
		return 0;
	return MaxTurn;
}

void OptionSet(int Option[OPTION_MAX]) // 혹시 while말고 do while쓴게 최적화면에서 더 좋아서쓴건가..? 아니면 취향?
{
	int Select;
	int TmpMin, TmpMax, TmpMaxTurn;
	do
	{
		system("cls");
		printf("=======게임 설정=======\n");
		printf("  1.최대,최소범위 설정\n");
		printf("  2.최대 Turn수 설정\n");
		printf("  3.돌아가기\n");
		printf("입력 : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case MAXORMIN:
			while (1)
			{
				system("cls");
				TmpMin = SetMin(Option[MIN]);
				TmpMax = SetMax(Option[MAX], TmpMin);
				if (TmpMax == -1) // 오류 발생시 다시 반복문 돌려 값 입력하기 위함 (보통 0이나 -1으로 잡는다.)
					printf("오류 : 최소값이 최대값 보다 큽니다 다시 입력하세요.\n");
				else
				{
					Option[MIN] = TmpMin;
					Option[MAX] = TmpMax;
					break;
				}
				system("pause");
			}
			break;
		case MAXTURN:
			while (1)
			{
				system("cls");
				TmpMaxTurn = SetMaxTurn(Option[MAX_TURN]);
				if (TmpMaxTurn != 0)
				{
					Option[MAX_TURN] = TmpMaxTurn;
					break;
				}
				printf("오류 : 최대 턴수가 0보다 작거나 같습니다 다시입력하세요.\n");
				system("pause");
			}
			break;
		}
	} while (Select != 3);
}

void main()
{
	int Option[3] = { 1,100,10 };
	int Select;
	srand(time(NULL));
	while (1)
	{
		switch (GameMenu())
		{
		case GAMESTART:
			GamePlay(Option);
			break;
		case SETTING:
			OptionSet(Option);
			break;
		case EXIT:
			return;
		}
	}
}
