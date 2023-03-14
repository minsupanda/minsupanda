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
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//���� ����
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
#define POTAL_MAX 4 // ��Ż ����
#define ENTRY_START 10
#define EXIT_START 20
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define WIDTH 10
#define HEIGHT 10
int map[HEIGHT][WIDTH] = {
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	10,	0,	12,	0,	0,	11,	0,	1 },
	{ 1,	23,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	0,	0,	0,	2,	0,	0,	0,	1 },
	{ 1,	22,	0,	0,	0,	0,	0,	13,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	21,	0,	0,	0,	0,	20,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 } };

int character[2];
int Entry_Potal[POTAL_MAX][2];
int Exit_Potal[POTAL_MAX][2];
int LastObjectlndex = NULL;
void lnit()
{
	int Width = (WIDTH * 2) + 1;
	int Height = HEIGHT + 1;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	//buf���°� �׳� â �۰� �Ϸ���? Width, Height ���� ������ �͵� ��������?
	system(buf); // ���ϴ� ���?
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER)
			{
				character[X] = x;
				character[Y] = y;
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX) 
			{
				Entry_Potal[map[y][x] - ENTRY_START][X] = x;
				Entry_Potal[map[y][x] - ENTRY_START][Y] = y;
			}
			// [0] => [2] => [1] ������ ����Ǵµ� �� �׷�����?
			// ��Ż�� ���� ���̹Ƿ� ������ ��Ż�� ��ġ�� �ٸ��� �����������
			//-- > ������ ��ġ���� �Ա����� ���� ���� ���ʴ�� 0, 1, 2, 3 �� ������
			//[0][1] / [1][1] / [2][1] / [3][1]�� x��ǥ
			//[0][0] / [1][0] / [2][0] / [3][0]�� y��ǥ
			// Entry_Potal [0,0y��ǥ�� ������ y���� ����] [0,1x��ǥ�� ������ y���� ����]
			//{ 1, 0 } { 1, 1 }
			//{ 2, 0 } { 2, 1 }
			//{ 3, 0 } { 3, 1 }
			//�̷������� �Ա�, �ⱸ ��Ż�� ��ǥ�� ������
			// ��ǥ�� ������ �� ������� �غ��� ����Ǵ� ������ �迭 �״�� [0] -> [1] -> [2] -> [3] �̷� ������ ����Ǵ� �� �˾���
			//-- > But[0] ->[2] ->[1] ->[3] ������ �����
			//�ֳ��ϸ�, �����迭���� �� ������ ���� 10 -> 12 -> 11 -> 13 �̱� ������ �������[0][0] ->[0][1] -> ... ->[1][0] ������ ������� �Ǳ� ������ ���� �������� ���� ������ ������� �����
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX)
			{
				Exit_Potal[map[y][x] - EXIT_START][X] = x;
				Exit_Potal[map[y][x] - EXIT_START][Y] = y;

			}
		}
	}
}

void MapDraw()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL)
				printf("��");
			else if (map[y][x] == CHARACTER)
			{
				RED
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX)
			{
				BLUE
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX)
			{
				YELLOW
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] == NULL) 
				printf("  ");			
		}
		printf("\n"); 
	}
}

void MoveCheck()
{
	int index = map[character[Y]][character[X]];
	if (index >= ENTRY_START && index < ENTRY_START + POTAL_MAX)
	{														//	Y��	X��
		character[X] = Exit_Potal[index - ENTRY_START][X];//  {0.0}{0.1}
		character[Y] = Exit_Potal[index - ENTRY_START][Y]; // {1.0}{1.1}
	}														//{2.0}{2.1}
}

void Move() 
{
	char ch; 
	ch = getch(); 
	if (ch == -32) 
		ch = getch(); 
	system("cls"); //���⼭ ���쳪 ������ ���쳪 ������?
	map[character[Y]][character[X]] = LastObjectlndex;
	switch (ch)
	{
	case LEFT:
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

	map[character[Y]][character[X]] = CHARACTER;
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