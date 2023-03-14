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
// �����Լ� : �� �ҽ����� ��ü���� ����� �� �ִ� ����

int character[2]; // ĳ������ ��ġ�� ������ ����
int Entry_Potal[2]; // �Ա� ��Ż�� ��ġ�� ������ ����
int Exit_Potal[2]; // �ⱸ ��Ż�� ��ġ�� ������ ����
int LastObjectlndex = NULL; // ĳ���Ͱ� �̵��� �� ������ �ʿ��� �� / �ӽð������� �̵� �� ��ǥ ���� ����
void lnit()
{ // ĳ������ ��ġ, �Ա� ��Ż�� ��ġ, �ⱸ ��Ż�� ��ġ�� �˾Ƴ� �Լ�
	// ���� �����ڸ� �ε��� �ش�Ǵ� �κ����� �̷ΰ����� ����� �� ĳ����, ��Ż���� ��ġ�� �ľ�
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER)  // 2�� ����� �޸� �ּ� == ĳ������ ��ġ
			{
				character[X] = x; // X, Y�� character�� �ε����� �ش��ϴ� �κ����� ��ġ�� �ľ�
				character[Y] = y;
			}
			else if (map[y][x] == ENTRY_POTAL) // 10�� ����� �޸� �ּ� == �Ա� ��Ż�� ��ġ
			{
				Entry_Potal[X] = x;// X, Y�� Entry_Potal�� �ε����� �ش��ϴ� �κ����� ��ġ�� �ľ�
				Entry_Potal[Y] = y;
			}
			else if (map[y][x] == EXIT_POTAL) // 20�� ����� �޸� �ּ� == �ⱸ ��Ż�� ��ġ
			{
				Exit_Potal[X] = x;// X, Y�� Exit_Potal�� �ε����� �ش��ϴ� �κ����� ��ġ�� �ľ�
				Exit_Potal[Y] = y;

			}
		}
	}
}

void MapDraw() // ���� �׸� �Լ�
{
	system("cls"); // ���� �����ϰ� �ʱ�ȭ
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL) // y,x�� ��ǥ��ó�� Ȱ���ؼ� �׵θ��� WALL == 1���� 1�� ����� ������ ���� ���
				printf("��");
			else if (map[y][x] == CHARACTER) //  CHARACTER�� map��ǥ�� ĳ���͸� ���
			{
				RED
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] == ENTRY_POTAL) // ENTRY_POTAL�� map��ǥ�� �Ա� ��Ż�� ���
			{
				BLUE
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] == EXIT_POTAL) //EXIT_POTAL�� map��ǥ�� �ⱸ ��Ż�� ���
			{
				YELLOW
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] == NULL) // ���� �������� NULL = 0���� 0���� ����� ������ "  "�� ���
				printf("  ");			// Ư�� ��ȣ�� ����, �ѱ��� 2ĭ�� �����ϹǷ� ���� 2ĭ�� �������� �Ѵ�
		}
		printf("\n"); // �ٹٲ� == y�� ����
	}
}

void MoveCheck() // ĳ���Ͱ� �����̱� ���� �ٸ� ���ع��� �ִ��� Ȯ���ϱ� ���� ������� �Լ�
{ // �̹��� ��쿡�� switch���� ���� ĳ������ ��ǥ�� 
	// ��ȭ �Ǿ��� �� ENTRY_POTAL�� ��ġ�� ĳ������ ��ġ�� ������ ��� �ⱸ��Ż�� �����̵���Ű�� ���� ��
	if (map[character[Y]][character[X]] == ENTRY_POTAL)
		// ĳ������ ��ǥ�� ENTYR_POTAL�� ��ǥ�� ������ ��� lnit���� ������� Exit_Potal�� ��ǥ�� �̵��ϰ� �Ǵ� ��
	{
		character[X] = Exit_Potal[X];
		character[Y] = Exit_Potal[Y];
	}
	//���⼭ �ⱸ��Ż�� ��ǥ�� ĳ���� ��ǥ�� ��ġ�� ��ġ�� ������ �Ѱܳ�
	//�̰��� �״�� �θ� ĳ���Ͱ� �ѹ��� �̵��� �� �ⱸ��Ż�� ��ġ�� ������� ��
	// �̸� ���� ���� ���� MoveCheck�� ȣ��� ��ġ�� �� �ڵ�
}

void Move() // ĳ���͸� ������ �Լ�
{
	char ch; // ���� ����
	ch = getch(); // �ܼ��Է��Լ��� �Է¹��ۿ� ����Ǵ� ���� �ٷ� ���
		// ����Ű�� Ȱ���� ������ �� ==> ����Ű�� �Է� �� �Է¹��ۿ� 2���� ���� ����� 
		// getch�� �� �� Ȱ���ϸ� ���� ���� ����Ǵ� -32 (����Ű)�� ��½�Ŵ
	    // �̶� ���� �ϳ��� ���� �״�� �Է¹��ۿ� ����Ǿ� �ֱ� ������ ���� �ݺ����� ���� �� ���� ������ ��µ�
		// �̸� �����ϱ� ���� ���� if��

	if (ch == -32) // ����Ű�� ������ ������ ó�� ����Ǵ� ���� -32�̱� ������ ����Ű �Է½� ������ ����Ǵ� ���ǹ�

		ch = getch(); // ���� getch���� -32�� ���� �Է¹��ۿ��� �������� �̹� getch���� ���� ����Ű ���� ����ؼ� 
						//���� �Է��� Ű���� ������ ������

	map[character[Y]][character[X]] = LastObjectlndex;
	 // ���� ĳ���Ͱ� ������ �ִ� ��ǥ�� NULL��(�����)���� �ʱ�ȭ
	 // ==> �ʱ�ȭ���� ������ ĳ���Ͱ� ����Ǵ� ����
	//ĳ���Ͱ� �Ű����� ���� �ƴ϶� ���� �Է��� ������ �ٲ�� ��ǥ�� ĳ���͸� ����ϱ� ������ ��ȭ ���� ��ǥ�� �ʱ�ȭ �������
	//***�ݺ����� �� �� �ݺ��ҽ� 169���� �ٿ� ����� Last ��ǥ���� ���� ĳ���Ͱ� �ִ� ��ǥ�� �ִ°�***
	// ==> ��� ���ξ��� ���� ���� ��ġ�� ���ͽ�Ű�� ������ �ⱸ ��Ż�� ������ ������� ���� �����ϱ� ����

	switch (ch) // WALL�� ���� ���� �����ϰ� �� �޴��� �°� charcater�� ��ǥ�� �ٲ�� ���ǹ�
		//�̶� ĳ������ ��ġ�� �ٲ�ٶ�� �͸� ��ǻ�Ϳ� �˷��ְ� �Ǵ� ���̰� ���������� character�� ��ġ�� �ٲ�� ���� �ƴϴ�
		//lnit���� ������ ĳ������ ��ǥ�� ��ȭ������
	{
	case LEFT: //ch���� ���� ���� ���� ����Ű �϶� LEAT ���̽��� ���ư��鼭 �������� ��ǥ ��ȯ
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
	// ����Ű�� ���� ���� ĳ������ ��ǥ�� Last~Index�� ����
	// ��ð� ĳ���Ͱ� �� ��ǥ��ġ�� Last�� �����ϰ� ĳ���Ͱ� �� �̵��� �� Last�� ����� ���� �ٽ� �ҷ���
	//�̷��� �ϸ� ������� �ⱸ��Ż�� ĳ���� ��ġ�� �̵��ϸ� �ٽ� ����� �Ǵ� ��
	
	map[character[Y]][character[X]] = CHARACTER;
	//CHARACTER�� �� 2(ĳ����)�� switch���� ���� �ٲ� ��ǥ map[character[Y]][character[X]]�� �������ν� ������ ĳ���Ͱ� �̵��Ǵ� ��
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