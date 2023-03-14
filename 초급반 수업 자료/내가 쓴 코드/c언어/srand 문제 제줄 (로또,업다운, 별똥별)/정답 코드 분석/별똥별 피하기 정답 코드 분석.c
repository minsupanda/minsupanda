﻿#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#define NULL 0
#define WALL 1
#define CHARACTER 2
#define STAR 3
#define X 1
#define Y 0
#define WIDTH 10
#define HEIGHT 20
#define LEFT 'a'
#define RIGHT 'd'
#define UPGRADE 10
#define EASY 1
#define NORMAL 2
#define HARD 3
#define HELL 4
#define DOWN_MOVE_SPEED 50
#define DOWN_CREATE_SPEED 30

void ShowDifficulty(int Difficulty);
void Init(int Map[][WIDTH], int character[]);
void MapDraw(int Map[][WIDTH], int Score, int Difficulty);
void Input(int Map[][WIDTH], int character[]);
void CreateStar(int Map[][WIDTH], int  StarCount, int StarCreatePercent);
int Update(int Map[][WIDTH], int score);
int Menu();
int SetDifficulty(int Difficulty);
void ShowDifficulty(int Difficulty);
void GamePlay(int Difficulty);
void Init(int Map[][WIDTH], int character[])
{
	srand(time(NULL));
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (x == 0 || x == WIDTH - 1)
				Map[y][x] = WALL;
			else
				Map[y][x] = NULL;
		}
	}

	character[X] = WIDTH / 2;
	character[Y] = HEIGHT - 1;
	Map[character[Y]][character[X]] = CHARACTER;
}
void MapDraw(int Map[][WIDTH], int Score, int Difficulty)
{
	system("cls");
	ShowDifficulty(Difficulty);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == CHARACTER)
				printf("옷");
			else if (Map[y][x] == STAR)
				printf("☆");
			else if (Map[y][x] == WALL)
				printf("│");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("Score = %d", Score);
}

void Input(int Map[][WIDTH], int character[])
{
	char ch = getch();
	Map[character[Y]][character[X]] = NULL;
	switch (ch)
	{
	case LEFT:
		if (Map[character[Y]][character[X] - 1] != WALL)
			character[X]--;
		break;
	case RIGHT:
		if (Map[character[Y]][character[X] + 1] != WALL)
			character[X]++;
		break;
	}
	Map[character[Y]][character[X]] = CHARACTER;
}

void CreateStar(int Map[][WIDTH], int  StarCount, int StarCreatePercent)
{
	for (int i = 0; i < StarCount; i++) // 별이 생성될 최대 갯수
	{
		if (rand() % StarCreatePercent == 0) 
		{
			int x = (rand() % 8) + 1; // 생성될 x축도 랜덤으로 정해짐
			Map[0][x] = STAR;
		}
	}
}

int Update(int Map[][WIDTH], int score)
{
	for (int y = HEIGHT - 1; y >= 0; y--)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == STAR)
			{
				Map[y][x] = NULL;
				if (Map[y + 1][x] == CHARACTER)
					return -1;
				else if (y + 1 < HEIGHT)
					Map[y + 1][x] = STAR;
				else
					score++;
			}
		}
	}

	return score;
}


int Menu()
{
	int Select;
	printf("=====별똥별 피하기===\n");
	printf("     1.게임 시작\n");
	printf("     2.난이도 조절\n");
	printf("     3.종료\n");
	printf("     입력 : ");
	scanf("%d", &Select);
	return Select;
}

void GamePlay(int Difficulty)
{
	int Map[HEIGHT][WIDTH];
	int character[2];
	int Score = 0;
	int LastScore = 0;
	int GameOver = FALSE;
	int SpeedClock = clock();
	int CreateClock = clock();
	int MapDrawState = FALSE;
	int StarCount = 2;
	int StarCreatePercent = 10;
	int StarSpeed = 1000;
	int CreateStarSpeed = 1500;

	switch (Difficulty)
	{
	case EASY:
		StarCount = 2;
		StarCreatePercent = 4;
		break;
	case NORMAL:
		StarCount = 3;
		StarCreatePercent = 3;
		break;
	case HARD:
		StarCount = 4;
		StarCreatePercent = 2;
		break;
	case HELL:
		StarCount = 5;
		StarCreatePercent = 1;
		break;
	}

	srand(time(NULL));
	Init(Map, character);
	CreateStar(Map, StarCount, StarCreatePercent);
	MapDraw(Map, Score, Difficulty);

	while (!GameOver)
	{
		if (MapDrawState)
			MapDraw(Map, Score, Difficulty);

		MapDrawState = FALSE;
		if (LastScore <= Score)
		{
			LastScore += 10; // 스코어 증가 10을 기준으로 스피드 증가
			if (CreateStarSpeed - DOWN_CREATE_SPEED > DOWN_CREATE_SPEED)
				CreateStarSpeed -= DOWN_CREATE_SPEED;
			if (StarSpeed - DOWN_MOVE_SPEED > DOWN_MOVE_SPEED)
				StarSpeed -= DOWN_MOVE_SPEED;
		}
		if (kbhit())
		{
			Input(Map, character);
			MapDrawState = TRUE;
		}
		if (clock() - CreateClock >= CreateStarSpeed)
		{
			CreateClock = clock();
			CreateStar(Map, StarCount, StarCreatePercent);
			MapDrawState = TRUE;
		}
		if (clock() - SpeedClock >= StarSpeed)
		{
			SpeedClock = clock();
			Score = Update(Map, Score);
			if (Score == -1)
				GameOver = TRUE;
			MapDrawState = TRUE;
		}
	}
	printf("게임 종료\n");
	system("pause");
}

int SetDifficulty(int Difficulty)
{
	int Select;
	system("cls");
	ShowDifficulty(Difficulty);
	printf("=======난이도 조절=======\n");
	printf("1.Easy\n");
	printf("2.Normal\n");
	printf("3.Hard\n");
	printf("4.Hell\n");
	printf("5.Return\n");
	printf("입력 : ");
	scanf("%d", &Select);
	return Select;
}

void ShowDifficulty(int Difficulty)
{
	switch (Difficulty)
	{
	case EASY:
		printf("====Easy====\n");
		break;
	case NORMAL:
		printf("====Normal====\n");
		break;
	case HARD:
		printf("====Hard====\n");
		break;
	case HELL:
		printf("====Hell====\n");
		break;
	}
}

void main()
{
	int Difficulty = EASY;
	int Input;
	while (1)
	{
		system("cls");

		switch (Menu())
		{
		case 1:
			GamePlay(Difficulty);
			break;
		case 2:
			do
			{
				Input = SetDifficulty(Difficulty);
				switch (Input)
				{
				case EASY:
				case NORMAL:
				case HARD:
				case HELL:
					Difficulty = Input;
				}
			} while (Input != 5);
			break;
		case 3:
			return;
		}

	}
}
