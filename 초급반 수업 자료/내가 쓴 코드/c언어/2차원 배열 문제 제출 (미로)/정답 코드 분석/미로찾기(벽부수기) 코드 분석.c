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
#define WEPONCOUNT 2
#define WEPON 5
#define LIFE 2
#define WALL 1
#define NULL 0
#define Y 0
#define X 1
#define CHARACTER 2
#define POTAL_MAX 2//포탈 갯수
#define ENTRY_START 10
#define EXIT_START 20
#define BLEAK_WALL 3
#define BLEAK_WALL_MAX 4
#define WALL_LIFE_MAX 3
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define WIDTH 10
#define HEIGHT 10
int map[HEIGHT][WIDTH] = {
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
	{ 1,	0,	0,	0,	3,	0,	0,	0,	0,	1 },
	{ 1,	0,	10,	0,	0,	5,	0,	11,	0,	1 },
	{ 1,	0,	0,	0,	3,	0,	0,	0,	0,	1 },
	{ 1,	0,	3,	0,	0,	2,	0,	5,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	0,	0,	5,	0,	3,	0,	0,	1 },
	{ 1,	0,	21,	0,	0,	0,	0,	20,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 } };
int character[3];
int Entry_Potal[POTAL_MAX][2];
int Exit_Potal[POTAL_MAX][2];
int Break_Wall[BLEAK_WALL_MAX][3];

int Find_BreakWall(int x, int y)
{
	for (int i = 0; i < BLEAK_WALL_MAX; i++) // 파괴가능한 벽 최대갯수만큼
	{
		if (Break_Wall[i][LIFE] != 0 && Break_Wall[i][Y] == y && Break_Wall[i][X] == x)
			// 해당 인덱스 번쨰의 벽의 체력이 0이 아니고 && 해당 인덱스 번쨰의 파괴가능한 벽의 X,Y좌표 값이 매개변수로 들어온 값 (전역변수에서 장애물로 넣어준 값)과 같을 떄 즉, 현재 좌표에 벽이 있을때
			return i; // 현재 벽의 인덱스 번째 값을 반환
	}
	return -1; // 벽을 만나지 않았으면 -1 반환
}

int Find_Entry(int x, int y)
{
	for (int i = 0; i < POTAL_MAX; i++)
	{
		if (Entry_Potal[i][Y] == y && Entry_Potal[i][X] == x)
			return i;
	}
	return -1;
}
int Find_Exit(int x, int y)
{
	for (int i = 0; i < POTAL_MAX; i++)
	{
		if (Exit_Potal[i][Y] == y && Exit_Potal[i][X] == x)
			return i;
	}
	return -1;
}
void Init()
{
	int BleakWallCount = 0;
	int Width = (WIDTH * 2) + 1;
	int Height = HEIGHT + 1;
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
				character[WEPONCOUNT] = 0;// 뒤 인덱스를 2까지 저장해서 마지막 인덱스에서 무기관리
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX)
			{
				Entry_Potal[map[y][x] - ENTRY_START][X] = x;
				Entry_Potal[map[y][x] - ENTRY_START][Y] = y;
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX)
			{
				Exit_Potal[map[y][x] - EXIT_START][X] = x;
				Exit_Potal[map[y][x] - EXIT_START][Y] = y;
			}
			else if (map[y][x] == BLEAK_WALL)
			{
				Break_Wall[BleakWallCount][X] = x; //BleakWallCount는 벽을 따로 관리하기 위해서
				Break_Wall[BleakWallCount][Y] = y;
				Break_Wall[BleakWallCount][LIFE] = WALL_LIFE_MAX; // 뒤 인덱스를 2까지 저장해서 마지막 인덱스에서 체력관리
				BleakWallCount++; // 처음엔 0번째 벽에서 ++해서 다음 번째 벽이 되는 것으로 벽 구분
			}
		}
	}
}
void MapDraw()
{
	int index;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			index = Find_BreakWall(x, y); // 체력이 있는 벽을 만나면 벽 모양 관리를 위한 코드
			if (map[y][x] == WALL)
				printf("▩");
			else if (map[y][x] == CHARACTER)
			{
				RED
					printf("♧");
				ORIGINAL
			}
			else if (map[y][x] == WEPON)
			{
				RED
					printf("メ");
				ORIGINAL
			}
			else if (Find_Entry(x, y) != -1)
			{
				BLUE
					printf("◎");
				ORIGINAL
			}
			else if (Find_Exit(x, y) != -1)
			{
				YELLOW
					printf("●");
				ORIGINAL
			}
			else if (index != -1) 
			{
				PUPPLE
					switch (Break_Wall[index][LIFE]) // 해당번쨰 인덱스(벽)의 라이프값에 따라 모양 변화
					{
					case 3:
						printf("▦");
						break;
					case 2:
						printf("▤");
						break;
					case 1:
						printf("□");
						break;
					}
				ORIGINAL
			}
			else if (map[y][x] == NULL)
				printf("  ");
		}
		printf("\n");
	}
	printf("무기 갯수 : %d", character[WEPONCOUNT]);
}

void MoveCheck()
{
	int index = Find_Entry(character[X], character[Y]);
	if (index != -1)
	{
		character[X] = Exit_Potal[index][X];
		character[Y] = Exit_Potal[index][Y];
	}
	if (map[character[Y]][character[X]] == WEPON) // 무기 먹으면 무기 카운트 n만큼 증가
		character[WEPONCOUNT] += 2; // 여기는 2
}

int BreakWall(int x, int y) // 여기도 바뀐 캐릭터 좌표값이 매개변수로 들어옴
{
	int index = Find_BreakWall(x, y);
	if (index != -1)
	{ // 벽을 만남
		if (character[WEPONCOUNT] != 0) // 무기를 먹어 카운트가 있을 때
		{
			Break_Wall[index][LIFE]--; // 체력감소
			if (Break_Wall[index][LIFE] == 0) // 장애물 체력이 0이 되면
				map[Break_Wall[index][Y]][Break_Wall[index][X]] = NULL; // 전역변수에서 선언한 해당 번째의 벽이 있는 좌표를 0으로 전환시켜 빈공간 출력
			character[WEPONCOUNT]--; // 무기 카운트 감소
		}
	}
	return index; // 해당 번째의 인덱스(n번째 벽)값을 반환
}

int ObjectCheck(int x, int y) // 캐릭터 좌표값에 선언된 값을 가져옴
{
	if (map[y][x] == WALL) // 좌표값에 벽이 있으면
		return FALSE; // FALSE반환해서 이동 안됨
	else if (BreakWall(x, y) != -1) //index값이 오게되면 이동 안됨
		return FALSE;
	else // 나머지 경우는 모두 이동
		return TRUE;
}

void Move()
{
	char ch;
	ch = getch();
	if (ch == -32)
		ch = getch();
	system("cls");
	map[character[Y]][character[X]] = NULL;
	switch (ch)
	{
	case LEFT:
		if (ObjectCheck(character[X] - 1, character[Y]) == TRUE)
			character[X]--;
		break;
	case RIGHT:
		if (ObjectCheck(character[X] + 1, character[Y]) == TRUE)
			character[X]++;
		break;
	case UP:
		if (ObjectCheck(character[X], character[Y] - 1) == TRUE)
			character[Y]--;
		break;
	case DOWN:
		if (ObjectCheck(character[X], character[Y] + 1) == TRUE)
			character[Y]++;
		break;
	}
	MoveCheck();
	map[character[Y]][character[X]] = CHARACTER;
}
void main()
{
	Init();
	while (1)
	{
		MapDraw();
		Move();
	}
}