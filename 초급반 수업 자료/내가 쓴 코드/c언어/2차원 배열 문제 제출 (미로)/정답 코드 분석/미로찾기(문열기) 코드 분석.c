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
#define FLAG 2 // 문 스위치 온오프
#define ENTRY_MAX 18 //입구 갯수
#define EXIT_MAX 18 // 출구 갯수
#define CHARACTER 2
#define ENTRY_START 10
#define EXIT_START 30
#define DOOR_MAX 7 // 문 갯수
#define DOOR_START 60
#define SWITCH_MAX 7// 스위치 갯수
#define SWITCH_START 50
#define EXIT 99
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define WIDTH 20
#define HEIGHT 20
int map[HEIGHT][WIDTH] = {
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
	{ 1,	0,	1,	0,	0,	0,	1,	0,	0,	0,	1,	21,	62,	0,	0,	0,	0,	64,	23,	1 },
	{ 1,	0,	1,	12,	1,	0,	0,	0,	1,	0,	1,	1,	1,	0,	0,	0,	0,	1,	1,	1 },
	{ 1,	0,	1,	1,	1,	1,	1,	1,	1,	31,	1,	0,	0,	0,	44,	42,	0,	0,	0,	1 },
	{ 1,	0,	0,	11,	1,	10,	0,	0,	33,	0,	1,	0,	0,	0,	40,	38,	0,	0,	0,	1 },
	{ 1,	0,	1,	1,	1,	0,	1,	61,	1,	1,	1,	0,	0,	0,	0,	0,	0,	1,	0,	1 },
	{ 1,	0,	0,	30,	1,	0,	1,	0,	1,	46,	1,	0,	0,	0,	0,	0,	0,	1,	25,	1 },
	{ 1,	0,	1,	1,	1,	0,	1,	0,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
	{ 1,	0,	0,	0,	0,	0,	1,	14,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	27,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
	{ 1,	19,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	0,	47,	0,	0,	60,	0,	99 },
	{ 1,	1,	1,	1,	1,	0,	0,	0,	0,	45,	0,	34,	1,	1,	1,	1,	1,	1,	1,	1 },
	{ 1,	15,	0,	0,	0,	0,	0,	0,	1,	37,	1,	1,	1,	41,	0,	0,	63,	0,	54,	1 },
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	24,	1,	1,	1,	1,	1,	1,	22,	1 },
	{ 1,	1,	1,	1,	1,	26,	50,	0,	66,	0,	1,	0,	1,	43,	1,	17,	0,	1,	1,	1 },
	{ 1,	0,	2,	51,	1,	1,	1,	1,	1,	55,	1,	56,	1,	0,	1,	1,	36,	1,	52,	1 },
	{ 1,	0,	0,	13,	1,	0,	0,	0,	1,	1,	1,	0,	65,	0,	1,	18,	0,	1,	0,	1 },
	{ 1,	0,	1,	1,	1,	0,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	35,	1 },
	{ 1,	0,	0,	0,	0,	0,	1,	32,	1,	39,	0,	0,	0,	53,	0,	0,	20,	1,	16,	1 },
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 } };
int character[2];
int Entry_Potal[ENTRY_MAX][2];
int Exit_Potal[EXIT_MAX][2];
int Exit[2];
int Door[DOOR_MAX][3];
int Switch[SWITCH_MAX][3];
int GameClear = 0;
void Init()
{
	int Width = (WIDTH * 2) + 1;
	int Height = HEIGHT + 2;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER)
			{
				character[X] = x;
				character[Y] = y;
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_MAX + ENTRY_START)
			{
				Entry_Potal[map[y][x] - ENTRY_START][X] = x;
				Entry_Potal[map[y][x] - ENTRY_START][Y] = y;
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_MAX + EXIT_START)
			{
				Exit_Potal[map[y][x] - EXIT_START][X] = x;
				Exit_Potal[map[y][x] - EXIT_START][Y] = y;
			}
			else if (map[y][x] >= DOOR_START && map[y][x] < DOOR_START + DOOR_MAX)
			{
				Door[map[y][x] - DOOR_START][X] = x;
				Door[map[y][x] - DOOR_START][Y] = y;
				Door[map[y][x] - DOOR_START][FLAG] = 1; // FLAG인덱스에서는 1을 넣어준다. 넣은 1값 그대로일때가 문이 닫힌 상태
			}
			else if (map[y][x] >= SWITCH_START && map[y][x] < SWITCH_START + SWITCH_MAX)
			{
				Switch[map[y][x] - SWITCH_START][Y] = y;
				Switch[map[y][x] - SWITCH_START][X] = x;
				Switch[map[y][x] - SWITCH_START][FLAG] = 1;
			}
			else if (map[y][x] == EXIT)
			{
				Exit[X] = x;
				Exit[Y] = y;
			}
		}
	}
}

int FindDoor(int x, int y)
{
	for (int i = 0; i < DOOR_MAX; i++)
	{
		if (Door[i][X] == x && Door[i][Y] == y && Door[i][FLAG]) 
			//Door[i][FLAG] 이 조건은 lnit에서 넣은 1값 그대로일때 실행한다는 뜻
			// Door[i][FLAG] == 1 과 같은 뜻
			//컴퓨터는 0을 제외한 모든 값은 참 / 0은 거짓
			//그래서 0이 들어오면 이 문장은 거짓으로 실행안됨
			return i;
	}
	return -1;
}
int FindSwitch(int x, int y)
{
	for (int i = 0; i < SWITCH_MAX; i++)
	{
		if (Switch[i][X] == x && Switch[i][Y] == y && Switch[i][FLAG])
			return i;
	}
	return -1;
}
int FindEntryPotal(int x, int y) // 들고오는 int x, y값(Draw에서 가져오는 x,y값)이 lnit에서 Entry_Potal 인덱스에 저장한 x,y값과 동일할 때 if문 종속문장 실행
{
	for (int i = 0; i < ENTRY_MAX; i++)
	{//lnit에서 각 변수의 인덱스에 X,Y 좌표를 저장 => 0부터 MAX까지 돌리면서 Entry_Potal[i][X], Entry_Potal[i][Y]에 저장된 값과 들고온 값이 동일하면 i값을 반환
		// 그럼 차례대로 MAX값까지 for문 돌리므로 맵에 어디생성할지 숫자 찍을 때 맘대로 해도 상관없음
		if (Entry_Potal[i][X] == x && Entry_Potal[i][Y] == y)
			return i; // 그럼 -1을 제외한 값을 반환해서 호출부분에서 if문 조건이 참이 되므로 맵에 해당 오브젝트를 그리게 됨
		//i값을 반환하는 것은 Check함수에서 i번째 오브젝트를 사용해야하기 때문
	}
	return -1; // -1을 리턴하면서 Draw함수에서 호출한 조건문은 거짓이 되므로 실행안함
}
int FindExitPotal(int x, int y)
{
	for (int i = 0; i < EXIT_MAX; i++)
	{
		if (Exit_Potal[i][X] == x && Exit_Potal[i][Y] == y)
			return i;
	}
	return -1;
}

void MapDraw()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL)
				printf("▩");
			else if (map[y][x] == CHARACTER)
			{
				RED
					printf("♠");
				ORIGINAL
			}
			else if (map[y][x] == EXIT)
				printf("☞");
			else if (FindEntryPotal(x, y) != -1) // -1을 제외한 값이 반환된 다는 것은 해당함수에서 for문 돌리면서 현재 그릴 좌표에 해당오브젝트를 그리는 것
			{
				BLUE
					printf("◎");
				ORIGINAL
			}
			else if (FindExitPotal(x, y) != -1)
			{
				YELLOW
					printf("●");
				ORIGINAL
			}
			else if (FindDoor(x, y) != -1)
			{
				GOLD
					printf("▒");
				ORIGINAL
			}
			else if (FindSwitch(x, y) != -1)
			{
				PUPPLE
					printf("⊙");
				ORIGINAL
			}
			else
				printf("  ");
		}
		printf("\n");
	}
	BLUE printf("입구 : ◎  ");
	YELLOW printf("출구 : ●\n");
	GOLD printf("문 : ▒  ");
	PUPPLE printf("스위치 : ⊙");
	ORIGINAL
}

void SwitchOnCheck() // 스위치. 문 사용 함수
{// 여기 들어올때는 스위치에서 변한 좌표가 들어옴
	int index = FindSwitch(character[X], character[Y]);
	// 현재 캐릭터 x,y좌표값을 가져가서 if문 실행하면서 Switch의 x,y좌표의 값과 동일하면 그 당시의 인덱스값이 반화되는 형태이므로 현재 캐릭터 위치인 n번째 인덱스를 들고오게 된다.
	// -1이 반환되면 for문을 돌리면서 해당 좌표에 스위치가 없는 것이기 때문, -1을 제외한 값이 반환되면 해당 좌표에 스위치가 있는 것이므로 종속문장 실행
	if (index != -1)
	{
		Switch[index][X] = -1; // 현재 좌표 스위치 X좌표 값 -1
		// 원래는 lnit에서 이 좌표값에 전역변수에서 선언한 스위치값이 있는 x,y 좌표값을 넣어준 것, 필요할 때 조건문이나 반복문 돌리면서 그 좌표값이 나오면 해당 좌표값이 저장된 스위치 위치를 쓰는 것
		// 근데 여기서 x, y좌표에 -1을 저장해주게 되므로 전역변수에 있는 좌표값이 아닌 다른 곳에서도 전혀 쓰지않을 엉뚱한 값을 넣어주어 해당 index번째의 스위치를 기능하지 못하도록 하는 것
		//즉, 전역변수에서 사용되는 좌표값만 아니면 무슨 값이든 바꿔도 정상적으로 작동한다.
		Switch[index][Y] = -1; //현재 좌표 스위치 Y좌표 값 - 1
		Switch[index][FLAG] = 0; // 현재 좌표 스위치 FLAG값을 0으로 바꿈
		//lnit에서 1으로 저장한 값을 0으로 바꿔 
		Door[index][X] = -1; // 현재 스위치 좌표와 공유하는 문의 X좌표 값 - 1
		Door[index][Y] = -1;// 현재 스위치 좌표와 공유하는 문의 Y좌표 값 - 1
		Door[index][FLAG] = 0;// 현재 스위치 좌표와 공유하는 문의 FLAG값을 0으로 바꿈
	}
}

void MoveCheck() // 포탈 사용 함수
{ // 여기 들어올때는 스위치에서 변한 좌표가 들어옴
	int index = FindEntryPotal(character[X], character[Y]);
	if (index != -1)
		// -1이 반환되면 for문을 돌리면서 해당 좌표에 입구포탈이 없는 것이기 때문, -1을 제외한 값이 반환되면 해당 좌표에 입구포탈이 있는 것이므로 종속문장 실행
	{
		character[X] = Exit_Potal[index][X]; // 캐릭터 좌표를 출구포탈로 좌표 변경
		character[Y] = Exit_Potal[index][Y];
	}
}

void ExitCheck() // 출구 사용 함수
{// 여기 들어올때는 스위치에서 변한 좌표가 들어옴
	if (map[character[Y]][character[X]] == EXIT)
		//현재 변환된 좌표가 출구값일 때 종속문장 실행
		GameClear = 1; // 게임클리어값을 1넣어줌
}

void Move()
{
	char ch;
	ch = getch();
	system("cls");
	map[character[Y]][character[X]] = NULL;
	switch (ch)
	{
	case LEFT:
		if (map[character[Y]][character[X] - 1] != WALL && FindDoor(character[X] - 1, character[Y]) == -1)
			// FindDoor함수에서 return값이 == -1이라는 건 FindDoor함수에서 if조건에 들어맞지 않은것 => 움직일 좌표에 Door가 없다는 뜻, -1이 아닐때(if문이 실행된 i값이 반환될 때) 문이 없음
			character[X]--;
		break;
	case RIGHT:
		if (map[character[Y]][character[X] + 1] != WALL && FindDoor(character[X] + 1, character[Y]) == -1)
			character[X]++;
		break;
	case UP:
		if (map[character[Y] - 1][character[X]] != WALL && FindDoor(character[X], character[Y] - 1) == -1)
			character[Y]--;
		break;
	case DOWN:
		if (map[character[Y] + 1][character[X]] != WALL && FindDoor(character[X], character[Y] + 1) == -1)
			character[Y]++;
		break;
	}
	MoveCheck();
	SwitchOnCheck();
	ExitCheck();
	map[character[Y]][character[X]] = CHARACTER;
}
void main()
{
	Init();
	while (!GameClear)
	{
		MapDraw();
		Move();
	}
	system("cls");
	printf("탈출성공!!");
}