#include<stdio.h>
#include<conio.h>
#include<Windows.h>
//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//색상 지정
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//////////////////////////////////////////////////////
#define WALL 1
#define NULL 0
#define Y 0
#define X 1
#define CHARACTER 2
#define ENTRY_POTAL 10
#define EXIT_POTAL 20
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define WIDTH 10
#define HEIGHT 10
int map[HEIGHT][WIDTH] = {
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	2,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	10,	0,	0,	0,	0,	20,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 } };
// 전역함수 : 이 소스파일 전체에서 사용할 수 있는 변수

int character[2]; // 캐릭터의 위치를 저장할 변수
int Entry_Potal[2]; // 입구 포탈의 위치를 저장할 변수
int Exit_Potal[2]; // 출구 포탈의 위치를 저장할 변수
int LastObjectlndex = NULL; // 캐릭터가 이동할 때 기준이 필요한 것 / 임시공간으로 이동 시 좌표 저장 역할
void lnit()
{ // 캐릭터의 위치, 입구 포탈의 위치, 출구 포탈의 위치를 알아낼 함수
	// 굳이 따지자면 로딩에 해당되는 부분으로 미로게임이 실행될 시 캐릭터, 포탈들의 위치를 파악
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER)  // 2가 저장된 메모리 주소 == 캐릭터의 위치
			{
				character[X] = x; // X, Y는 character의 인덱스에 해당하는 부분으로 위치를 파악
				character[Y] = y;
			}
			else if (map[y][x] == ENTRY_POTAL) // 10이 저장된 메모리 주소 == 입구 포탈의 위치
			{
				Entry_Potal[X] = x;// X, Y는 Entry_Potal의 인덱스에 해당하는 부분으로 위치를 파악
				Entry_Potal[Y] = y;
			}
			else if (map[y][x] == EXIT_POTAL) // 20이 저장된 메모리 주소 == 출구 포탈의 위치
			{
				Exit_Potal[X] = x;// X, Y는 Exit_Potal의 인덱스에 해당하는 부분으로 위치를 파악
				Exit_Potal[Y] = y;

			}
		}
	}
}

void MapDraw() // 맵을 그릴 함수
{
	system("cls"); // 맵을 깨끗하게 초기화
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL) // y,x를 좌표계처럼 활용해서 테두리를 WALL == 1으로 1로 저장된 공간에 벽을 출력
				printf("▩");
			else if (map[y][x] == CHARACTER) //  CHARACTER의 map좌표에 캐릭터를 출력
			{
				RED
					printf("♧");
				ORIGINAL
			}
			else if (map[y][x] == ENTRY_POTAL) // ENTRY_POTAL의 map좌표에 입구 포탈을 출력
			{
				BLUE
					printf("◎");
				ORIGINAL
			}
			else if (map[y][x] == EXIT_POTAL) //EXIT_POTAL의 map좌표에 출구 포탈을 출력
			{
				YELLOW
					printf("●");
				ORIGINAL
			}
			else if (map[y][x] == NULL) // 남은 공간에는 NULL = 0으로 0으로 저장된 공간에 "  "를 출력
				printf("  ");			// 특수 부호나 한자, 한글은 2칸을 차지하므로 띄어쓰기 2칸을 출력해줘야 한다
		}
		printf("\n"); // 줄바꿈 == y축 증가
	}
}

void MoveCheck() // 캐릭터가 움직이기 전에 다른 방해물이 있는지 확인하기 위해 만들어진 함수
{ // 이번의 경우에는 switch문을 통해 캐릭터의 좌표가 
	// 변화 되었을 때 ENTRY_POTAL의 위치와 캐릭터의 위치가 동일할 경우 출구포탈로 순간이동시키기 위한 것
	if (map[character[Y]][character[X]] == ENTRY_POTAL)
		// 캐릭터의 좌표가 ENTYR_POTAL의 좌표와 동일할 경우 lnit에서 만들어진 Exit_Potal의 좌표로 이동하게 되는 것
	{
		character[X] = Exit_Potal[X];
		character[Y] = Exit_Potal[Y];
	}
	//여기서 출구포탈의 좌표는 캐릭터 좌표의 위치와 겹치기 때문에 쫓겨남
	//이것을 그대로 두면 캐릭터가 한번더 이동할 때 출구포탈의 위치는 사라지게 됨
	// 이를 막기 위한 것이 MoveCheck가 호출된 위치의 밑 코드
}

void Move() // 캐릭터를 움직일 함수
{
	char ch; // 단일 문자
	ch = getch(); // 콘솔입력함수로 입력버퍼에 저장되는 값을 바로 출력
		// 방향키를 활용해 움직일 것 ==> 방향키는 입력 시 입력버퍼에 2가지 값이 저장됨 
		// getch를 한 번 활용하면 가장 먼저 저장되는 -32 (방향키)를 출력시킴
	    // 이때 남은 하나의 값은 그대로 입력버퍼에 저장되어 있기 때문에 다음 반복문을 돌릴 때 남은 값으로 출력됨
		// 이를 방지하기 위한 것이 if문

	if (ch == -32) // 방향키를 누르면 무조건 처음 저장되는 값이 -32이기 때문에 방향키 입력시 무조건 실행되는 조건문

		ch = getch(); // 위의 getch에서 -32이 값이 입력버퍼에서 가져오고 이번 getch에서 남은 방향키 값을 출력해서 
						//내가 입력한 키보드 방향대로 움직임

	map[character[Y]][character[X]] = LastObjectlndex;
	 // 현재 캐릭터가 가지고 있는 좌표를 NULL값(빈공간)으로 초기화
	 // ==> 초기화하지 않으면 캐릭터가 복사되는 버그
	//캐릭터가 옮겨지는 것이 아니라 내가 입력한 방향대로 바뀌는 좌표에 캐릭터를 출력하기 때문에 변화 전의 좌표를 초기화 해줘야함
	//***반복문을 한 번 반복할시 169번쨰 줄에 저장된 Last 좌표값을 현재 캐릭터가 있는 좌표에 넣는것***
	// ==> 잠시 빼두었던 값을 원래 위치로 복귀시키는 것으로 출구 포탈이 완전히 사라지는 것을 방지하기 위함

	switch (ch) // WALL을 만날 때를 제외하고 각 메뉴얼에 맞게 charcater의 좌표가 바뀌는 조건문
		//이때 캐릭터의 위치가 바뀐다라는 것만 컴퓨터에 알려주게 되는 것이고 실제적으로 character의 위치가 바뀌는 것이 아니다
		//lnit에서 저장한 캐릭터의 좌표를 변화시켜줌
	{
	case LEFT: //ch에서 받은 값이 좌측 방향키 일때 LEAT 케이스가 돌아가면서 왼쪽으로 좌표 변환
		if (map[character[Y]][character[X] - 1] != WALL) 
			character[X]--;
		break;
	case RIGHT:
		if (map[character[Y]][character[X] + 1] != WALL)
			character[X]++;
		break;
	case UP:
		if (map[character[Y] - 1][character[X]] != WALL)
			character[Y]--;
		break;
	case DOWN:
		if (map[character[Y] + 1][character[X]] != WALL)
			character[Y]++;
		break;
	}
	MoveCheck();
	LastObjectlndex = map[character[Y]][character[X]];
	// 방향키를 눌러 변한 캐릭터의 좌표를 Last~Index에 저장
	// 잠시간 캐릭터가 들어갈 좌표위치를 Last에 저장하고 캐릭터가 또 이동할 시 Last에 저장된 값을 다시 불러옴
	//이렇게 하면 사라졌던 출구포탈은 캐릭터 위치가 이동하면 다시 생기게 되는 것
	
	map[character[Y]][character[X]] = CHARACTER;
	//CHARACTER의 값 2(캐릭터)를 switch문을 통해 바뀐 좌표 map[character[Y]][character[X]]에 넣음으로써 완전히 캐릭터가 이동되는 것
}
void main()
{
	lnit();
	while (1)
	{
		MapDraw();
		Move();
	}
}