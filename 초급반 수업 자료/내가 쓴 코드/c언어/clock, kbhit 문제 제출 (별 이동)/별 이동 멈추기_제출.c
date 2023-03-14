#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#define WIDTH 10
#define HEIGHT 10
#define NULL 0
#define MOVE_STAR 1// 움직이는 별
#define STOP_STAR 2// 멈춘 별
#define RIGHT_DIRECTION 1 // 일렬로 된 별이 우측으로 이동하도록 하기 위해
#define LEFT_DIRECTION -1 // 일렬로 된 별이 좌측으로 이동하도록 하기 위해
#define TURN_LEFT WIDTH  //우측 마지막 공간을 만나면 좌측으로 이동하도록
#define TURN_RIGHT -1 //좌측 마지막 공간을 만나면 우측으로 이동하도록
#define SPEED 200 // 별이 움직일 속도
#define STOP_KEY 32 //별을 멈추게 할 키


void Draw(int Map[WIDTH][HEIGHT])//맵 그리는 함수
{
	system("cls");
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == MOVE_STAR)
				printf("☆");
			else if (Map[y][x] == STOP_STAR)
				printf("★");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("별 멈추기 = SP");
}



int Update(int Map[HEIGHT][WIDTH], int direction, int Stop_y)//별의 좌표를 변경할 함수
{
	for (int x = 0; x < WIDTH; x++)
	{
		if (Map[0][x] == MOVE_STAR)// for문 반복을 최적화하기 위해 x좌표의 별을 먼저 찾아주고 y반복을 돌린다
		{
			if (x + RIGHT_DIRECTION == TURN_LEFT)
				direction = LEFT_DIRECTION;
			// 현재 x값 즉, 별이 있는 좌표에서 오른쪽으로 한번 더 이동할시 마지막 공간이면 방향을 바꿔준다

			else if (x + LEFT_DIRECTION == TURN_RIGHT)
				direction = RIGHT_DIRECTION;
			// 현재 x값 즉, 별이 있는 좌표에서 왼쪽으로 한번 더 이동할시 마지막 공간이면 방향을 바꿔준다

			for (int y = 0; y <= Stop_y; y++)// y는 Stop_y까지 돌려야 멈춘 별은 간섭받지 않음
			{
				Map[y][x] = NULL; //현재 그려져있는 별을 초기화
				Map[y][x + direction] = MOVE_STAR;//위에서 저장된 방향으로 별이 이동한다
			}
			break;
		}
	}
	return direction;//위에서 저장된 방향 값을 반환한다.
}


int Stop(int Map[HEIGHT][WIDTH], int Stop_y)// 별을 멈추게 할 함수
{
	if (kbhit())  // 입력버퍼에 값이 들어오면
	{
		char ch = getch();
		if (ch == STOP_KEY)// define해둔 키를 입력할 시
		{
			for (int x = 0; x < WIDTH; x++)
			{
				if (Map[Stop_y][x] == MOVE_STAR)// 현재 y좌표의 별을 찾고
					Map[Stop_y][x] = STOP_STAR; // 현재  y좌표에 있는 별을 멈춘 별로 저장
			}
			Stop_y--; // 저장한 별은 움직이지 않도록 하기 위해
		}
	}
	return Stop_y; // Update함수에서 멈춘 별은 for문 범위에서 빼기 위함
}

void main()
{
	int Direction = LEFT_DIRECTION;// 별이 처음 진행할 방향
	int Stop_Y = HEIGHT - 1;  // 키를 입력할 시 가장 밑의 별부터 멈추게 할 것이고 차례대로 올라오게 할 것
	int OldClock = clock(); // 별이 자동적으로 일정한 속도로 움직이게 하기 위해
	int Map[HEIGHT][WIDTH] = { NULL };
	printf("별을 보시겠습니까?\n");
	system("pause");

	for (int y = 0; y < HEIGHT; y++)
		Map[y][WIDTH - 1] = MOVE_STAR;// 가장 우측부터 움직일 별의 좌표를 저장

	while (1)
	{
		Stop_Y = Stop(Map, Stop_Y);
		if (clock() - OldClock >= SPEED)
			//현재 코드를 만나기까지이 시간에서 가장 처음 호출한 clock함수에서의 시간을 뺀 값이  define한 값과 크거나 같을 때 실행
			//clock함수 시작부터 이 코드를 만나기까지의 클럭값에서 가장 clock함수의 시작 클럭값을 빼는 것
			// 만약 while문을 들어올 때 SPEED보다 빠르면 그냥 while문 루프 돌리다 SPEED값과 일정해질 때 들어오게 되고, 밑에서 다시 clock저장하는 이유는 그래야만 일정한 속도로 while문을 반복할 수 있기 때문이다
		{
			Direction = Update(Map, Direction, Stop_Y);
			Draw(Map);
			OldClock = clock();
			// 처리할 코드를 다 끝내고 다시 현재 clock값을 저장
			// 그래야 일정한 속도로 반복문을 돌릴수 있기 때문
			// 물론 컴퓨터의 성능에 따라 아무리 빨라도 SPEED값과 같을 때까지의 클럭값까지는 걸리지만, 처리속도가 느리면 그보다 늦어질수는 있다. But 각 컴퓨터의 처리속도(반북몬을 돌리는 속도)는 일정하다
		}
	}
}