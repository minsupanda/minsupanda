#include<stdio.h>
#include<Windows.h>
#include<time.h>
#define WIDTH 10
#define HEIGHT 10
#define STAR 1
#define NULL 0
#define SPEED 500

void Draw(int Map[HEIGHT][WIDTH]) // 맵 크기 그대로 매개변수로 가져옴
{
	system("cls");
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == STAR) // Draw함수에 들어오기 전 main함수에서 x좌표 마지막 인덱스에 별 값을 저장했으므로 그 좌표에만 별들이 쭉 출력
				printf("☆");
			else // 나머지는 빈공간 출력
				printf("  ");
		}
		printf("\n"); // 별을 일렬로 줄세우려고.
	}
}

void Update(int Map[HEIGHT][WIDTH]) // 맵 크기 그대로 매개변수로 가져옴
{
	for (int x = 0; x < WIDTH; x++)
	{
		if (Map[0][x] == STAR)		// x축을 먼저 탐색하는 이유는 y축 먼저 탐색하게 되면 n의 제곱만큼 탐색하므로 처리할 값이 많아진다
		// 지금 별을 |자로 출력하므로 가장 처음 y좌표의 별의 위치만 확인하면 되기 때문이에 그 x좌표를 찾고 y축 반복문 돌리면 된다.
			// 그럼 아무리 많이 돌려도 n * 2 만큼 반복문 돌리게 되므로  처리 횟수가 줄어듬
		{
			for (int y = 0; y < HEIGHT; y++)
			{
				Map[y][x] = NULL; //여기서 들어오는 인덱스 x값은 if문에서 충족된 x값이 들어오게 된다. 그리고 그 x값의 좌표들은 모든 y값의 좌표에서 전부 NULL값으로 초기화 
				if (x == 0) // x ==0이라는 것은 별이 x좌표가 0값일때까지 왔을 때 다시 가장 처음위치로 돌아가기 위해서임
					Map[y][WIDTH - 1] = STAR; // 마지막 인덱스를 다시 별로 바꿔줌
				else // y좌표가 0일때부터 끝까지 현재 별이 그려져있던(지금은 NULL값으로 초기화 된상탸)  좌표에서 -1을 해서 모든 별을 좌표를 왼쪽으로 이동시킨다. 
					Map[y][x - 1] = STAR; // 여기서 계속 좌표값을 -1로 바꿔주고 x좌표가 0이 되면 위의 if문 실행
			}
			break; // x좌표가 별이 있는 좌표일 때만 실행해야 하므로 찾은 x좌표까지만 돌리고 나머지는 break로 탈출해서 for문 안돌림
		}
	}
}


void main()
{
	int OldClock = clock(); // 가장 처음 만난 clock함수이므로 이 지점부터 clock함수 값이 증가하기 시작한다.
	// 처음 시작하는 clock값을 OldClock 변수에 저장
	int Map[HEIGHT][WIDTH] = { NULL }; // 맵의 모든 공간에 NULL값을 저장
	for (int y = 0; y < HEIGHT; y++)
	{
		Map[y][WIDTH - 1] = STAR;
		//모든 y좌표에서 x좌표의 마지막 인덱스값에만 별 값을 저장
	}
	Draw(Map);
	while (1)
	{
		if (clock() - OldClock >= SPEED) // 1초에 1000밀리세컨드, 500이면 0.5초마다 출력하겠다는 뜻
		// OldClock변수 선언시 clock부터 while문의 clock함수까지 만나기 까지 걸린 시간이 SPEED랑 같거나 크면 종속문장 실행
		// *****************그럼 만약, 위에 Draw까지 했는데 SPEED보다 작으면 어케 되는거지? 그냥 while문에서 기다리는 건가??********************
			//while문에서 혼자서 반복 계속돌리면서 시간될 때까지 반복문 돌림
			// 만약 초과하면 어케하냐
			// 차라리 범위를 잡아줌 0.5초로 잡고 싶은데 0.7초가 되면 아예 0.3~0.7로 범위잡아서 기능하게
			//밀리세컨드까지 세세하게 범위를 지정하는 것은 어렵기 때문 (반복문 한번만 삐끗나도 0.01초 지나니까 완전 들어맞는 것은 어렵다)
		{
			Update(Map);
			Draw(Map);
			OldClock = clock(); //별을 다 그리고 나서 시간을 다시 측정해야 하기 때문에 다시 시작하는 시간을 OldClock 넣어준 것 (여기서 들어간 값을 해당 if문에서 계산하는 것)
		}
	}
}
