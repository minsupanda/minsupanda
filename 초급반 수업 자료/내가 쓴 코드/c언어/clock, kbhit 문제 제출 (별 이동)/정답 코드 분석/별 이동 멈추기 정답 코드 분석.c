#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include<time.h>
#define LEFT -1
#define RIGHT 1
#define WIDTH 10
#define HEIGHT 10
#define MOVESTAR 1
#define STOPSTAR 2
#define SPEED 100

void Draw(int Map[][WIDTH])
{
	system("cls");
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == MOVESTAR || Map[y][x] == STOPSTAR)
				printf("☆");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("별 멈추기 = d");
}

int DirectionCheck(int Map[][WIDTH], int Direction)
{ // 별이 진행하다 맵의 양쪽 끝을 만나게 되면 진행방향을 바꾸기 위해
	if (Map[0][0] == MOVESTAR && Direction == LEFT) 
		// 0만 확인하는 이유는 어차피 별을 일렬이기 때문에 반복문을 최소화 시켜준 것
		Direction = RIGHT;
	else if (Map[0][WIDTH - 1] == MOVESTAR && Direction == RIGHT)
		Direction = LEFT;
	return Direction; // 반환되는 값에 따라 별의 진행방향이 바뀐다
}

void Update(int Map[][WIDTH], int Derection)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == MOVESTAR)
			{
				Map[y][x] = 0;
				Map[y][x + Derection] = MOVESTAR;
				break; // 별을 찾으면 굳이 반복문을 더 돌릴필요가 없기 때문
			}
		}
	}
}

void Stop(int Map[][WIDTH], int y)
{
	for (int x = 0; x < WIDTH; x++)
	{
		if (Map[y][x] == MOVESTAR)
		{
			Map[y][x] = STOPSTAR;
			return;
		}
	}
}
ㄴ
void main()
{
	int Stop_y = HEIGHT;
	int Map[HEIGHT][WIDTH] = { 0 };
	int Derection = LEFT; //처음 시작할 때 방향을 왼쪽으로
	for (int y = 0; y < HEIGHT; y++)
		Map[y][WIDTH - 1] = MOVESTAR;
	int MoveClock = clock(); // clock함수 시작, 시작 값 저장
	while (Stop_y) // if((kbhit)) 에서 --한값이 0이 되면 탈출
	{
		if (clock() - MoveClock >= SPEED)
			//clock함수 시작부터 이 코드를 만나기까지의 클럭값에서 가장 clock함수의 시작 클럭값을 빼는 것
			// 만약 while문을 들어올 때 SPEED보다 빠르면 그냥 while문 루프 돌리다 SPEED값과 일정해질 때 들어오게 되고, 밑에서 다시 clock저장하는 이유는 그래야만 일정한 속도로 while문을 반복할 수 있기 때문이다
		{
			Update(Map, Derection); // 현재 별이 생성된 좌표를 초기화하고, Deretion 값에 따라 방향 이동
			Derection = DirectionCheck(Map, Derection);
			Draw(Map);
			MoveClock = clock(); 
			// 처리할 코드를 다 끝내고 다시 현재 clock값을 저장
			// 그래야 일정한 속도로 반복문을 돌릴수 있기 때문
			// 물론 컴퓨터의 성능에 따라 아무리 빨라도 SPEED값과 같을 때까지의 클럭값까지는 걸리지만, 처리속도가 느리면 그보다 늦어질수는 있다. But 각 컴퓨터의 처리속도(반북몬을 돌리는 속도)는 일정하다
		}
		if (kbhit()) // 입력버퍼에 값이 들어가면 실행
		{
			char ch = getch();
			if (ch == 'd' || ch == 'D')
				Stop(Map, --Stop_y); 
		}
	}
	getch();
}