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
///////////////////////////////////////////////////////
#define WALL 1
#define NULL 0
#define Y 0
#define X 1
#define HP 2
#define CHARACTER 2
#define POTAL_MAX 20 // 포탈 갯수
#define ENTRY_START 10 // 입구 포탈 10 ~ 29
#define EXIT_START 40 // 출구 포탈 40 ~59
#define DOOR_START 60 // 문 60 ~66
#define SWITCH_START 90 // 스위치 90 ~ 96
#define DOOR_SWITCH_MAX 7 // 문,스위치 갯수
#define OBSTACLE_START 30 // 방해물 30 ~ 31
#define OBSTACLE_MAX 2 // 방해물 갯수
#define OBSTACLE_HP 3 // 방해물 체력
#define WEAPON_START 35 // 무기
#define WEAPON_MAX 3 // 무기 최대 갯수
#define ATTACK_COUNT 2 // 무기 먹으면 공격 가능한 횟수
#define SPECIAL_WEAPON 9999 // 특수 무기
#define SPECIAL_GAGE WEAPON_MAX // 특수 무기 나타나는 조건
#define WALL_CRUSH 30 // 특수 무기 효과
#define MOVE_ITEM 100 // 이동 횟수 추가 아이템
#define MOVE_PLUS 20 // 이동 횟수 추가 아이템 증가량
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define WIDTH 20
#define HEIGHT 20
#define ESC 999 // 게임 종료
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
int Entry_Potal[POTAL_MAX][2]; // 입구 포탈
int Exit_Potal[POTAL_MAX][2]; // 출구 포탈
int Door[DOOR_SWITCH_MAX][2]; // 문
int Switch[DOOR_SWITCH_MAX][2]; // 문을 열 스위치
int Obstacle[OBSTACLE_MAX][3]; // 파괴가능한 장애물 갯수, 마지막 index에는 체력관리
int Befor_Character_Coordinate[2]; //장애물을 만나면 장애물 만나기 전 위치가 저장된 좌표를 따로 뺴둬서 장애물 좌표로 이동한 캐릭터 좌표를 다시 전으로 돌리기 위해 사용
int Weapon[WEAPON_MAX][2]; // 무기
int Attack_Possible = 0; // 공격 가능한 횟수
int Special_Coordinate[2] = { ((int)(HEIGHT * 0.5)), ((int)(WIDTH * 0.5)) }; // 특수 무기 나타낼 좌표
int Special_Sequence[WEAPON_MAX] = { 37, 35, 36 };
int Special_Sequence_Index = 0;
// 특정 순서대로 먹으면 특수무기 출현되도록 구분하게 위해 사용, 값이 SPECIAL_GAGE가 되면 특수 무기 생성
int Wall_Crush = 0;// 특수무기 먹으면 벽 부수기 가능한 횟수
int Special_WeaPon_Printf = 0; // 특수 무기 생성 문자열과 효과 끝 문자열 출력할려고...
int Fail_Count = 0; // 외벽을 부수면 부순만큼 알려주고 게임 실패
int Number_Of_Moves = 0; // 이동횟수 제한 (맵의 빈공간 만큼 횟수 주어짐)
int Move_Count = 0; // 이동횟수 무제한으로 증가되는 거 방지
int End[2]; // 게임 종료
int LastObjectlndex = NULL;

//전방선언 : F12를 누르면 바로 해당함수로 이동가능, 가독성편리함(어떤 함수를 사용했는지)
lnit();
MapDraw();
Get_Weapon();
Special_Weapon();
MoveCheck();
Obstacle_Check();
Move();

void lnit()
{
	int Width = (WIDTH * 2) + 1; // 콘솔 창 가로길이
	int Height = HEIGHT + 8; // 콘솔 창 세로 길이
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
				printf("▩");
			else if (map[y][x] == CHARACTER)
			{
				RED
					printf("☆");
				ORIGINAL
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX)
			{
				BLUE
					printf("◎");
				ORIGINAL
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX)
			{
				BLUE_GREEN
					printf("●");
				ORIGINAL
			}
			else if (map[y][x] >= DOOR_START && map[y][x] < DOOR_START + DOOR_SWITCH_MAX)
			{
				GOLD
					printf("▒");
				ORIGINAL
			}
			else if (map[y][x] >= SWITCH_START && map[y][x] < SWITCH_START + DOOR_SWITCH_MAX)
			{
				YELLOW
					printf("⊙");
				ORIGINAL
			}
			else if (map[y][x] >= OBSTACLE_START && map[y][x] < OBSTACLE_START + OBSTACLE_MAX)
			{
				PUPPLE
					switch (Obstacle[map[y][x] - OBSTACLE_START][HP])
					{
					case OBSTACLE_HP:
						printf("▦");
						break;
					case OBSTACLE_HP - 1:
						printf("▤");
						break;
					case OBSTACLE_HP - 2:
						printf("□");
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
					printf("†");
				ORIGINAL
			}
			else if (map[y][x] == SPECIAL_WEAPON)
			{
				RED
					printf("‡");
				ORIGINAL
			}
			else if (map[y][x] == MOVE_ITEM)
			{
				GREEN
					printf("↔");
				ORIGINAL
			}
			else if (map[y][x] == ESC)
			{
				DARK_BLUE
					printf("▷");
				ORIGINAL
			}
			else if (map[y][x] == NULL)
			{
				printf("  ");
				if (Move_Count == 0) 
				{
					Number_Of_Moves++; // 빈 공간 만큼 이동 횟수 주기 위해
				}

			}
		}
		printf("\n");
	}
	Move_Count++;

	BLUE
		printf("   입구 : ◎");
	ORIGINAL
		BLUE_GREEN
		printf("   출구 : ●");
	GOLD
		printf("      문 : ▒\n\n");
	ORIGINAL
		PLUM
		printf("   무기 : †");
	ORIGINAL
		PUPPLE
		printf("  방해물 : ▦");
	ORIGINAL
		YELLOW
		printf("   스위치 : ⊙\n\n");
	ORIGINAL
		printf("공격 가능 횟수 : %d", Attack_Possible);
	RED
		if (Wall_Crush == 0)
		{
			if (Special_Sequence_Index < SPECIAL_GAGE)
				printf("  특수 무기 게이지 : %d ", Special_Sequence_Index); 
			else if (Special_WeaPon_Printf == 0) 
				printf("  특수 무기 생성");
			else if (Special_WeaPon_Printf == 1)
				printf("  특수 무기 효과 끝");
		}
		else if (Wall_Crush != 0)
			printf(" 벽 파괴 가능 횟수 : %d", Wall_Crush);
	printf("\n");
	ORIGINAL
		SKY_BLUE
		printf("\t  이동 가능 횟수 : %d", Number_Of_Moves);
	ORIGINAL

}


int Get_Weapon() // 무기 만나면 횟수 숫자 출력하고, 공격 횟수 증가하는 함수
{
	int index = map[character[Y]][character[X]];
	if (index >= WEAPON_START && index < WEAPON_START + WEAPON_MAX)
	{
		Attack_Possible += ATTACK_COUNT; // 공격 가능한 횟수 증가
		map[character[Y]][character[X]] = NULL; // 먹은 무기 사라짐

		if (index == Special_Sequence[Special_Sequence_Index]) // 특정 순서대로 무기 먹으면 특수 무기 게이지 증가
			Special_Sequence_Index++; // 인덱스++하면서 Special_Sequence_Index의 index순서대로(0~2) 먹어야함
		if (Special_Sequence_Index == SPECIAL_GAGE) // 특수 순서 인덱스 == 게이지 값이 되만큼 차면 특수무기생성
			map[Special_Coordinate[Y]][Special_Coordinate[X]] = SPECIAL_WEAPON; // 특수좌표에 특수무기 Draw에서 생성
	}
}


int Special_Weapon() // 특수 공격 횟수 동안 벽 부수기
{
	int index = map[character[Y]][character[X]];
	if (Special_Sequence_Index == SPECIAL_GAGE) // 특수 게이지 모두 채웠을 때
	{
		if (index == map[Special_Coordinate[Y]][Special_Coordinate[X]] && map[Special_Coordinate[Y]][Special_Coordinate[X]] == SPECIAL_WEAPON) // 무기 먹고, 벽 부술 때 좌표감소 목적 : 뒷 코드가 없으면 빈공간 이동할때마다 다시 횟수 충전됨
		{
			map[character[Y]][character[X]] = NULL; // 특수 무기 먹으면 사라지게
			Wall_Crush = WALL_CRUSH; // 능력 횟수 충전
			Number_Of_Moves += WALL_CRUSH; // 남은 이동횟수를 벽 부수기 가능한 횟수만큼 더 추가
			Special_WeaPon_Printf++; // 무기 먹기 전, 먹은 후 문자열 출력 하기 위해 넣은 코드
		}
		if (index == WALL)
		{
			map[character[Y]][character[X]] = NULL; // 벽이랑 부딪히면 벽 빈 공간으로 바꾸기
			if (character[Y] == 0 || character[Y] == HEIGHT - 1 || character[X] == 0 || character[X] == WIDTH - 1) // 외벽을 부수면 실패카운트 증가
				Fail_Count++; // 1이라도 증가되면 실패 (실패했을 때 외벽 몇개 부셨는지 알려줄려고)
			Wall_Crush--; // 능력 횟수 차감
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
		map[character[Y]][character[X]] = NULL; // 스위치 사라지게 하기
		map[Door[index - SWITCH_START][Y]][Door[index - SWITCH_START][X]] = NULL; // 스위치와 번호를 공유하는 문을 사라지게 하는 것
	}
	if (index == MOVE_ITEM) // 이동증가 아이템먹으면 횟수 증가
	{
		Number_Of_Moves += MOVE_PLUS;
		map[character[Y]][character[X]] = NULL;
	}

	Number_Of_Moves--; // 이동횟수 감소


	Get_Weapon(); // Attack 함수에서 int Attack값 반환해서 공격 가능한 횟수 증가시키기
	Special_Weapon(); // 특수 공격
}


void Obstacle_Check() // 장애물이 있는지 확인하고, 있으면 캐릭터를 어떻게 할지 결정, 장애물 체력 감소
{
	int index = map[character[Y]][character[X]];
	if (index >= OBSTACLE_START && index < OBSTACLE_START + OBSTACLE_MAX)
	{
		if (Attack_Possible > 0) // 공격 횟수 있을 때 공격하며, 공격 횟수 차감, 장애물 체력감소
		{
			Obstacle[index - OBSTACLE_START][HP]--;
			Attack_Possible--;
		}
		if (Obstacle[index - OBSTACLE_START][HP] != NULL) // 장애물이 없어졌을 때는 그 공간을 지나가기 위해
		{
			character[Y] = Befor_Character_Coordinate[Y]; // 따로 빼둔 값을 캐릭터 좌표에 저장하면 캐릭터의 좌표가 장애물을 만나기 전으로 이동하게 된다 => 함수 빠져나가서 캐릭터 장애물 만나기 전위치로 출력됨
			character[X] = Befor_Character_Coordinate[X];
			map[Obstacle[index - OBSTACLE_START][Y]][Obstacle[index - OBSTACLE_START][X]] = index; // 이동된 캐릭터 좌표값이 장애물이 있는 좌표이므로 그 좌표를 다시 장애물 좌표에 넣어줌
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
	switch (ch) // 스위치문에서 좌표가 이동해서 이동한 좌표가 장애물과 닿아야 하기 때문에 스위치 조건은 건들지 않음
	{
	case LEFT:
		if (map[character[Y]][character[X] - 1] < DOOR_START || map[character[Y]][character[X] - 1] >= DOOR_START + DOOR_SWITCH_MAX) // 공통 조건
		{
			if (map[character[Y]][character[X] - 1] != WALL && Special_Sequence_Index <= SPECIAL_GAGE) // 벽 파괴 효과 없을 때
				character[X]--;
			else if (Wall_Crush > 0) // 벽 파괴 효과 있을 때
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
					printf("외벽을 %d개 부셨습니다.\n", Fail_Count);
					printf("내벽만 부셔주세요\n\n.");
				}
				else if (Number_Of_Moves == 0)
				{
					printf("남은 이동 횟수 : %d\n", Number_Of_Moves);
					printf("이동 횟수를 모두 소진하셨습니다. \n\n");
					if (Fail_Count != 0)
					{
						printf("외벽을 %d개 부셨습니다.\n", Fail_Count);
						printf("내벽만 부셔주세요\n\n.");
					}
				}
			break;
		}
	}
}