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
///////////////////////////////////////////////////////
#define WALL 1
#define NULL 0
#define Y 0
#define X 1
#define HP 2
#define CHARACTER 2
#define POTAL_MAX 20 // ��Ż ����
#define ENTRY_START 10 // �Ա� ��Ż 10 ~ 29
#define EXIT_START 40 // �ⱸ ��Ż 40 ~59
#define DOOR_START 60 // �� 60 ~66
#define SWITCH_START 90 // ����ġ 90 ~ 96
#define DOOR_SWITCH_MAX 7 // ��,����ġ ����
#define OBSTACLE_START 30 // ���ع� 30 ~ 31
#define OBSTACLE_MAX 2 // ���ع� ����
#define OBSTACLE_HP 3 // ���ع� ü��
#define WEAPON_START 35 // ����
#define WEAPON_MAX 3 // ���� �ִ� ����
#define ATTACK_COUNT 2 // ���� ������ ���� ������ Ƚ��
#define SPECIAL_WEAPON 9999 // Ư�� ����
#define SPECIAL_GAGE WEAPON_MAX // Ư�� ���� ��Ÿ���� ����
#define WALL_CRUSH 30 // Ư�� ���� ȿ��
#define MOVE_ITEM 100 // �̵� Ƚ�� �߰� ������
#define MOVE_PLUS 20 // �̵� Ƚ�� �߰� ������ ������
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define WIDTH 20
#define HEIGHT 20
#define ESC 999 // ���� ����
int map[HEIGHT][WIDTH] = {
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	},
	{ 1,	2,	1,	0,	0,	0,	1,	0,	0,	0,	1,	10,	65,	0,	0,	0,	0,	60,	13,	1,	},
	{ 1,	0,	1,	11,	1,	0,	0,	0,	1,	0,	1,	1,	1,	0,	0,	0,	0,	1,	1,	1,	},
	{ 1,	0,	1,	1,	1,	1,	1,	1,	1,	42,	1,	0,	0,	0,	56,	51,	0,	0,	0,	1,	},
	{ 1,	0,	0,	12,	1,	14,	0,	0,	54,	0,	1,	0,	0,	0,	50,	55,	0,	0,	0,	1,	},
	{ 1,	0,	1,	1,	1,	0,	1,	62,	1,	1,	1,	0,	0,	0,	0,	0,	0,	1,	30,	1,	},
	{ 1,	0,	0,	44,	1,	0,	1,	0,	1,	52,	1,	0,	35,	0,	0,	0,	0,	1,	15,	1,	},
	{ 1,	0,	1,	1,	1,	0,	1,	0,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	},
	{ 1,	0,	0,	0,	0,	0,	1,	16,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	},
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	17,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	},
	{ 1,	18,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	47,	0,	0,	0,	61,	999,1,  },
	{ 1,	1,	1,	1,	1,	36,	0,	0,	45,	0,	46,	1,	1,	1,	1,	1,	1,	1,	1,	1,	},
	{ 1,	19,	100,0,	31,	0,	0,	0,	1,	53,	1,	1,	1,	40,	0,	0,	66,	100,90,	1,  },
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	20,	1,	1,	1,	1,	1,	1,	21,	1,	},
	{ 1,	1,	1,	1,	1,	22,	91,	0,	64,	0,	1,	0,	1,	43,	1,	23,	0,	1,	1,	1,	},
	{ 1,	0,	0,	92,	1,	1,	1,	1,	1,	93,	1,	94,	1,	0,	1,	1,	57,	1,	95,	1,	},
	{ 1,	0,	0,	24,	1,	0,	0,	0,	1,	1,	1,	0,	63,	0,	1,	25,	0,	1,	0,	1,	},
	{ 1,	0,	1,	1,	1,	0,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	49,	1,	},
	{ 1,	0,	0,	0,	0,	0,	1,	41,	1,	48,	0,	37,	0,	96,	0,	0,	26,	1,	27,	1,	},
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	},	};
int character[2];
int Entry_Potal[POTAL_MAX][2]; // �Ա� ��Ż
int Exit_Potal[POTAL_MAX][2]; // �ⱸ ��Ż
int Door[DOOR_SWITCH_MAX][2]; // ��
int Switch[DOOR_SWITCH_MAX][2]; // ���� �� ����ġ
int Obstacle[OBSTACLE_MAX][3]; // �ı������� ��ֹ� ����, ������ index���� ü�°���
int Befor_Character_Coordinate[2]; //��ֹ��� ������ ��ֹ� ������ �� ��ġ�� ����� ��ǥ�� ���� ���ּ� ��ֹ� ��ǥ�� �̵��� ĳ���� ��ǥ�� �ٽ� ������ ������ ���� ���
int Weapon[WEAPON_MAX][2]; // ����
int Attack_Possible = 0; // ���� ������ Ƚ��
int Special_Coordinate[2] = { ((int)(HEIGHT * 0.5)), ((int)(WIDTH * 0.5)) }; // Ư�� ���� ��Ÿ�� ��ǥ
int Special_Sequence[WEAPON_MAX] = { 37, 35, 36 };
int Special_Sequence_Index = 0;
// Ư�� ������� ������ Ư������ �����ǵ��� �����ϰ� ���� ���, ���� SPECIAL_GAGE�� �Ǹ� Ư�� ���� ����
int Wall_Crush = 0;// Ư������ ������ �� �μ��� ������ Ƚ��
int Special_WeaPon_Printf = 0; // Ư�� ���� ���� ���ڿ��� ȿ�� �� ���ڿ� ����ҷ���...
int Fail_Count = 0; // �ܺ��� �μ��� �μ���ŭ �˷��ְ� ���� ����
int Number_Of_Moves = 0; // �̵�Ƚ�� ���� (���� ����� ��ŭ Ƚ�� �־���)
int Move_Count = 0; // �̵�Ƚ�� ���������� �����Ǵ� �� ����
int End[2]; // ���� ����
int LastObjectlndex = NULL;

//���漱�� : F12�� ������ �ٷ� �ش��Լ��� �̵�����, ����������(� �Լ��� ����ߴ���)
lnit();
MapDraw();
Get_Weapon();
Special_Weapon();
MoveCheck();
Obstacle_Check();
Move();

void lnit()
{
	int Width = (WIDTH * 2) + 1; // �ܼ� â ���α���
	int Height = HEIGHT + 8; // �ܼ� â ���� ����
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
			else if (map[y][x] >= DOOR_START && map[y][x] < DOOR_START + DOOR_SWITCH_MAX)
			{
				Door[map[y][x] - DOOR_START][X] = x;
				Door[map[y][x] - DOOR_START][Y] = y;
			}
			else if (map[y][x] >= SWITCH_START && map[y][x] < SWITCH_START + DOOR_SWITCH_MAX)
			{
				Switch[map[y][x] - SWITCH_START][X] = x;
				Switch[map[y][x] - SWITCH_START][Y] = y;
			}
			else if (map[y][x] >= OBSTACLE_START && map[y][x] < OBSTACLE_START + OBSTACLE_MAX)
			{
				Obstacle[map[y][x] - OBSTACLE_START][X] = x;
				Obstacle[map[y][x] - OBSTACLE_START][Y] = y;
				Obstacle[map[y][x] - OBSTACLE_START][HP] = OBSTACLE_HP;
			}
			else if (map[y][x] >= WEAPON_START && map[y][x] < WEAPON_START + WEAPON_MAX)
			{
				Weapon[map[y][x] - WEAPON_START][Y] = y;
				Weapon[map[y][x] - WEAPON_START][Y] = x;
			}
			else if (map[y][x] == ESC)
			{
				End[X] = x;
				End[Y] = y;
			}
		}
	}
}

void MapDraw()
{
	system("cls");
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
				BLUE_GREEN
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] >= DOOR_START && map[y][x] < DOOR_START + DOOR_SWITCH_MAX)
			{
				GOLD
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] >= SWITCH_START && map[y][x] < SWITCH_START + DOOR_SWITCH_MAX)
			{
				YELLOW
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] >= OBSTACLE_START && map[y][x] < OBSTACLE_START + OBSTACLE_MAX)
			{
				PUPPLE
					switch (Obstacle[map[y][x] - OBSTACLE_START][HP])
					{
					case OBSTACLE_HP:
						printf("��");
						break;
					case OBSTACLE_HP - 1:
						printf("��");
						break;
					case OBSTACLE_HP - 2:
						printf("��");
						break;
					case NULL:
						printf("  ");
						break;
					}
				ORIGINAL
			}
			else if (map[y][x] >= WEAPON_START && map[y][x] < WEAPON_START + WEAPON_MAX)
			{
				PLUM
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] == SPECIAL_WEAPON)
			{
				RED
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] == MOVE_ITEM)
			{
				GREEN
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] == ESC)
			{
				DARK_BLUE
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] == NULL)
			{
				printf("  ");
				if (Move_Count == 0) 
				{
					Number_Of_Moves++; // �� ���� ��ŭ �̵� Ƚ�� �ֱ� ����
				}

			}
		}
		printf("\n");
	}
	Move_Count++;

	BLUE
		printf("   �Ա� : ��");
	ORIGINAL
		BLUE_GREEN
		printf("   �ⱸ : ��");
	GOLD
		printf("      �� : ��\n\n");
	ORIGINAL
		PLUM
		printf("   ���� : ��");
	ORIGINAL
		PUPPLE
		printf("  ���ع� : ��");
	ORIGINAL
		YELLOW
		printf("   ����ġ : ��\n\n");
	ORIGINAL
		printf("���� ���� Ƚ�� : %d", Attack_Possible);
	RED
		if (Wall_Crush == 0)
		{
			if (Special_Sequence_Index < SPECIAL_GAGE)
				printf("  Ư�� ���� ������ : %d ", Special_Sequence_Index); 
			else if (Special_WeaPon_Printf == 0) 
				printf("  Ư�� ���� ����");
			else if (Special_WeaPon_Printf == 1)
				printf("  Ư�� ���� ȿ�� ��");
		}
		else if (Wall_Crush != 0)
			printf(" �� �ı� ���� Ƚ�� : %d", Wall_Crush);
	printf("\n");
	ORIGINAL
		SKY_BLUE
		printf("\t  �̵� ���� Ƚ�� : %d", Number_Of_Moves);
	ORIGINAL

}


int Get_Weapon() // ���� ������ Ƚ�� ���� ����ϰ�, ���� Ƚ�� �����ϴ� �Լ�
{
	int index = map[character[Y]][character[X]];
	if (index >= WEAPON_START && index < WEAPON_START + WEAPON_MAX)
	{
		Attack_Possible += ATTACK_COUNT; // ���� ������ Ƚ�� ����
		map[character[Y]][character[X]] = NULL; // ���� ���� �����

		if (index == Special_Sequence[Special_Sequence_Index]) // Ư�� ������� ���� ������ Ư�� ���� ������ ����
			Special_Sequence_Index++; // �ε���++�ϸ鼭 Special_Sequence_Index�� index�������(0~2) �Ծ����
		if (Special_Sequence_Index == SPECIAL_GAGE) // Ư�� ���� �ε��� == ������ ���� �Ǹ�ŭ ���� Ư���������
			map[Special_Coordinate[Y]][Special_Coordinate[X]] = SPECIAL_WEAPON; // Ư����ǥ�� Ư������ Draw���� ����
	}
}


int Special_Weapon() // Ư�� ���� Ƚ�� ���� �� �μ���
{
	int index = map[character[Y]][character[X]];
	if (Special_Sequence_Index == SPECIAL_GAGE) // Ư�� ������ ��� ä���� ��
	{
		if (index == map[Special_Coordinate[Y]][Special_Coordinate[X]] && map[Special_Coordinate[Y]][Special_Coordinate[X]] == SPECIAL_WEAPON) // ���� �԰�, �� �μ� �� ��ǥ���� ���� : �� �ڵ尡 ������ ����� �̵��Ҷ����� �ٽ� Ƚ�� ������
		{
			map[character[Y]][character[X]] = NULL; // Ư�� ���� ������ �������
			Wall_Crush = WALL_CRUSH; // �ɷ� Ƚ�� ����
			Number_Of_Moves += WALL_CRUSH; // ���� �̵�Ƚ���� �� �μ��� ������ Ƚ����ŭ �� �߰�
			Special_WeaPon_Printf++; // ���� �Ա� ��, ���� �� ���ڿ� ��� �ϱ� ���� ���� �ڵ�
		}
		if (index == WALL)
		{
			map[character[Y]][character[X]] = NULL; // ���̶� �ε����� �� �� �������� �ٲٱ�
			if (character[Y] == 0 || character[Y] == HEIGHT - 1 || character[X] == 0 || character[X] == WIDTH - 1) // �ܺ��� �μ��� ����ī��Ʈ ����
				Fail_Count++; // 1�̶� �����Ǹ� ���� (�������� �� �ܺ� � �μ̴��� �˷��ٷ���)
			Wall_Crush--; // �ɷ� Ƚ�� ����
		}
	}
}


void MoveCheck()
{
	int index = map[character[Y]][character[X]];
	if (index >= ENTRY_START && index < ENTRY_START + POTAL_MAX)
	{
		character[X] = Exit_Potal[index - ENTRY_START][X];
		character[Y] = Exit_Potal[index - ENTRY_START][Y];
	}
	if (index >= SWITCH_START && index < SWITCH_START + DOOR_SWITCH_MAX)
	{
		map[character[Y]][character[X]] = NULL; // ����ġ ������� �ϱ�
		map[Door[index - SWITCH_START][Y]][Door[index - SWITCH_START][X]] = NULL; // ����ġ�� ��ȣ�� �����ϴ� ���� ������� �ϴ� ��
	}
	if (index == MOVE_ITEM) // �̵����� �����۸����� Ƚ�� ����
	{
		Number_Of_Moves += MOVE_PLUS;
		map[character[Y]][character[X]] = NULL;
	}

	Number_Of_Moves--; // �̵�Ƚ�� ����


	Get_Weapon(); // Attack �Լ����� int Attack�� ��ȯ�ؼ� ���� ������ Ƚ�� ������Ű��
	Special_Weapon(); // Ư�� ����
}


void Obstacle_Check() // ��ֹ��� �ִ��� Ȯ���ϰ�, ������ ĳ���͸� ��� ���� ����, ��ֹ� ü�� ����
{
	int index = map[character[Y]][character[X]];
	if (index >= OBSTACLE_START && index < OBSTACLE_START + OBSTACLE_MAX)
	{
		if (Attack_Possible > 0) // ���� Ƚ�� ���� �� �����ϸ�, ���� Ƚ�� ����, ��ֹ� ü�°���
		{
			Obstacle[index - OBSTACLE_START][HP]--;
			Attack_Possible--;
		}
		if (Obstacle[index - OBSTACLE_START][HP] != NULL) // ��ֹ��� �������� ���� �� ������ �������� ����
		{
			character[Y] = Befor_Character_Coordinate[Y]; // ���� ���� ���� ĳ���� ��ǥ�� �����ϸ� ĳ������ ��ǥ�� ��ֹ��� ������ ������ �̵��ϰ� �ȴ� => �Լ� ���������� ĳ���� ��ֹ� ������ ����ġ�� ��µ�
			character[X] = Befor_Character_Coordinate[X];
			map[Obstacle[index - OBSTACLE_START][Y]][Obstacle[index - OBSTACLE_START][X]] = index; // �̵��� ĳ���� ��ǥ���� ��ֹ��� �ִ� ��ǥ�̹Ƿ� �� ��ǥ�� �ٽ� ��ֹ� ��ǥ�� �־���
		}
	}
}

void Move()
{
	Befor_Character_Coordinate[Y] = character[Y];
	Befor_Character_Coordinate[X] = character[X];
	char ch;
	ch = getch();
	if (ch == -32)
		ch = getch();
	map[character[Y]][character[X]] = LastObjectlndex;
	switch (ch) // ����ġ������ ��ǥ�� �̵��ؼ� �̵��� ��ǥ�� ��ֹ��� ��ƾ� �ϱ� ������ ����ġ ������ �ǵ��� ����
	{
	case LEFT:
		if (map[character[Y]][character[X] - 1] < DOOR_START || map[character[Y]][character[X] - 1] >= DOOR_START + DOOR_SWITCH_MAX) // ���� ����
		{
			if (map[character[Y]][character[X] - 1] != WALL && Special_Sequence_Index <= SPECIAL_GAGE) // �� �ı� ȿ�� ���� ��
				character[X]--;
			else if (Wall_Crush > 0) // �� �ı� ȿ�� ���� ��
				character[X]--;
		}
		break;

	case RIGHT:
		if (map[character[Y]][character[X] + 1] < DOOR_START || map[character[Y]][character[X] + 1] >= DOOR_START + DOOR_SWITCH_MAX)
		{
			if (map[character[Y]][character[X] + 1] != WALL && Special_Sequence_Index <= SPECIAL_GAGE)
				character[X]++;
			else if (Wall_Crush > 0)
				character[X]++;
		}
		break;

	case UP:
		if (map[character[Y] - 1][character[X]] < DOOR_START || map[character[Y] - 1][character[X]] >= DOOR_START + DOOR_SWITCH_MAX)
		{
			if (map[character[Y] - 1][character[X]] != WALL && Special_Sequence_Index <= SPECIAL_GAGE)
				character[Y]--;
			else if (Wall_Crush > 0)
				character[Y]--;
		}
		break;

	case DOWN:
		if (map[character[Y] + 1][character[X]] < DOOR_START || map[character[Y] + 1][character[X]] >= DOOR_START + DOOR_SWITCH_MAX)
		{
			if (map[character[Y] + 1][character[X]] != WALL && Special_Sequence_Index <= SPECIAL_GAGE)
				character[Y]++;
			else if (Wall_Crush > 0)
				character[Y]++;
		}
		break;
	}

	MoveCheck();
	Obstacle_Check();
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
		if (LastObjectlndex == ESC && Fail_Count == 0)
		{
			if (LastObjectlndex == ESC || Fail_Count == 0)
			{
				system("cls");
				SKY_BLUE
					printf("GAME CLEAR!!\n\n");
				ORIGINAL
					break;
			}
		}
		else if (LastObjectlndex == ESC && Fail_Count != 0 || Number_Of_Moves == 0)
		{
			system("cls");
			RED
				printf("GAME FAIL...\n\n");
			ORIGINAL
				if (Fail_Count != 0 && Number_Of_Moves != 0)
				{
					printf("�ܺ��� %d�� �μ̽��ϴ�.\n", Fail_Count);
					printf("������ �μ��ּ���\n\n.");
				}
				else if (Number_Of_Moves == 0)
				{
					printf("���� �̵� Ƚ�� : %d\n", Number_Of_Moves);
					printf("�̵� Ƚ���� ��� �����ϼ̽��ϴ�. \n\n");
					if (Fail_Count != 0)
					{
						printf("�ܺ��� %d�� �μ̽��ϴ�.\n", Fail_Count);
						printf("������ �μ��ּ���\n\n.");
					}
				}
			break;
		}
	}
}