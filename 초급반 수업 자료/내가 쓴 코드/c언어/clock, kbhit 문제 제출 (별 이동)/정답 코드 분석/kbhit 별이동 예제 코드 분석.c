#include<stdio.h>
#include<Windows.h>
#include<time.h>
#define WIDTH 10
#define HEIGHT 10
#define MOVE_STAR 1
#define STOP_STAR 2
#define NULL 0
#define SPEED 100

void Draw(int Map[HEIGHT][WIDTH]) // 맵 그리는 것
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
}

void Update(int Map[HEIGHT][WIDTH], int Stop_y) // 별 좌표 이동 함수
{
	for (int x = 0; x < WIDTH; x++)
	{
		if (Map[0][x] == MOVE_STAR) 
		// x축을 먼저 탐색하는 이유는 y축 먼저 탐색하게 되면 n의 제곱만큼 탐색하므로 처리할 값이 많아진다
		// 지금 별을 |자로 출력하므로 가장 처음 y좌표의 별의 위치만 확인하면 되기 때문이에 그 x좌표를 찾고 y축 반복문 돌리면 된다.
			// 그럼 아무리 많이 돌려도 n * 2 만큼 반복문 돌리게 되므로  처리 횟수가 줄어듬
		{
			for (int y = 0; y <= Stop_y; y++)
			{
				Map[y][x] = NULL; 
				// 현재 별이 위치한 좌표를 NULL값으로 바꿔줌
				if (x == 0) 
					// 별이 가장 왼쪽으로 가면 다시 처음 위치로 돌려주는 것
					Map[y][WIDTH - 1] = MOVE_STAR; 
				else
					// 별을 왼쪽으로 한 칸 이동 시켜준 것
					Map[y][x - 1] = MOVE_STAR; 
			}
			break;
		}
	}
}

int Stop(int Map[HEIGHT][WIDTH], int y) // 맵의 크기와 Stop_Y값을 가져옴
// Stop_Y값을 가져오는 것은 그 당시의 y좌표에 있는 별을 STOP_STAR로 바꿔 별을 멈추게하고 검은 별로 출력하기 위해
{
	if (kbhit())
	// kbhit는 입력버퍼에 값이 들어있는 지 없는 지 확인하는 것
	// 없으면 바로 getch를 만나게 되는데 getch는 입력버퍼에 있는 값을 가져오기 때문에 값이 들어올 때 까지 기다리게 된다
	// 그러므로 키보드를 입력할 때까지 프로그램이 멈추게 되며 반복문이 작동안하게 됨
	// 그래서 kbhit가 필요한 것
	// 그럼 아예 Stop함수 호출을 가장 밑으로 내리면 안되냐?
	// 이건 컴퓨터 사양에 따라 달라진다 (설명은 main함수에서 설명) 
	{
		char ch = getch();
		if (ch == 'd' || ch == 'D')
		{
			// 입력버퍼에 D,d값이 들어오면 for 시작
			for (int x = 0; x < WIDTH; x++)
				// y값 좌표를 들고왔으므로 y축은 안찾아도 되지만 x좌표는 하나 씩 돌리면서 STAR을 찾아야함
			{
				if (Map[y][x] == MOVE_STAR)
					// STAR가 있는 x좌표를 찾으면
				{
					Map[y][x] = STOP_STAR; // 함수 호출 시 들고오 y좌표에 있는 별을 STOP_STAR로 바꿔줌
					break; // 나머지 x축은 돌릴 필요 없으므로 break문으로 탈출
				}
			}
			y--; 
			// y축을 감소시켜 STOP_STAR값은 거기서 멈추고 더이상 Update 함수 반복문에 관여하지 않도록 설정하는 것
			// 여기서 멈추기만 할거면 굳이 if문은 필요없다. if문을 쓴 이유는 다른 색으로 출력하기 위함
		}
	}
	return y; //감소된 y값은 반환해서 Update함수의 for문 탐색 범위를 줄이는 것
}


void main()
{
	int OldClock = clock();
	int Stop_Y = HEIGHT - 1; 
	// 밑에서 부터 위로 올라올 것이기 때문에 Y축 마지막 인덱스를 저장하고
	// 멈출 때 마다 1씩 감소시켜 업데이트 함수에서 탐색범위를 줄이면서 별을 멈추게 하려고 쓰는 변수
	int Map[HEIGHT][WIDTH] = { NULL };
	for (int y = 0; y < HEIGHT; y++)
	{
		Map[y][WIDTH - 1] = MOVE_STAR; 
		// 모든 y축에서 마지막 x좌표에는 MOVE_STAR저장
		// MOVE_STAR값이 저장되면 Update함수에서 1씩 감소되면서 별이 왼쪽으로 이동하게 된다.
	}
	while (1)
	{
		Stop_Y = Stop(Map, Stop_Y); 
		if (clock() - OldClock >= SPEED)
		{
			Update(Map, Stop_Y);
			Draw(Map);
			OldClock = clock();
		}
		// (설명은 main함수에서 설명) Stop_Y = Stop(Map, Stop_Y) kbhit를 뺏을 때;  이거를 여기로 내린다는 뜻인데
		// 이건 프레임과 비슷한 맥락
		// if문을 만날 때까지 걸린 클락이 SPEED 보다 크거나 같으면 if문을 돌리고 출력은 되겠지만 어차피 다음 돌릴때 Stop함수를 만나게 되서 멈춤
		// 다만 컴퓨터 처리 속도가 SPEED 빠르면 바로 만나 바로 멈추게 될 것 
	}
}
