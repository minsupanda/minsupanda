#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#define WIDTH 10
#define HEIGHT 20
#define RIGHT 1
#define LEFT -1
#define STOP 0 // 게임 정지 값
#define PROGRESS 1 // 게임 진행 값
#define FALSE 0 // 맵 다시 안그림, 캐릭터 안움직임 값
#define TURE 1 // 맵 다시 그림, 캐릭터 움직임 값
#define DROP_INDEX 0 // 떨어지는 속도 인덱스
#define CREATE_INDEX 1 // 만들어지는 속도 인덱스
#define CHARGE 0 // 스킬 게이지 인덱스
#define SKILL_ON_OFF 1 // 스킬 온오프 인덱스
#define OFF 0 // 쉴드, 스킬 오프 값
#define ON 1 // 쉴드, 스킬온 값
#define CAST 2 // 스킬 발동 값
#define X 0 // 캐릭터 X좌표 인덱스
#define SHIELD_ON_OFF 1 // 쉴드 온오프 인덱스
#define BEFORE_X 2 // 캐릭터 움직이기 전 좌표 (맵 다시 그릴껀지 확인하기위해) 인덱스
#define PRESENT 0 // 현재 스코어 인덱스
#define BEFORE 1 // 전 스코어 인덱스
#define EXCEED 2 // 초과된 스코어 인덱스
#define STAR_DROP 1 // 별 떨어지는 확률값
#define SHIELD_DROP 2 // 쉴드 떨어지는 확률값
#define EASY 1 // 난이도 값
#define NORMAL 2// 난이도 값
#define HARD 3// 난이도 값
#define HELL 4// 난이도 값
#define NULL 0 // 빈공간 값
#define WALL 1 // 벽 값
#define STAR 2 // 별 값
#define CHARACTER 3 // 캐릭터 값
#define SHIELD 4 // 쉴드 값
#define STAR_PER 0 // 별 만들어질 확률 인덱스
#define SHIELD_PER 1 // 쉴드 만들어질 확률 인덱스
#define PLUS_SPEED 2 // 레벨에 따라 증가될 스피드 인덱스
#define LEVEL 3 // 레벨 난이도 인덱스
#define LEVEL_OPTION_INDEX 4 // 레벨과 관련된 인덱스 갯수
#define UP_SPEED_SCORE 5 // 스피드가 증가될 스코어 상승 값
#define DROP_SPEED 500 // 떨어지는 스피드 값
#define CREATE_SPEED 500 // 만들어지는 스피드 값
#define SKILL_SPEED 300 // 스킬 올라가는 스피드 값
#define EASY_PLUS_SPEED 3 // 기본 이지난이도 증가되는 스피드값
#define EASY_STAR_PER 20 // 기본 이지 난이도 별 만들어지는 확률값
#define SHIELD_CREATE_PER 30 // 쉴드 만들어지는 확률값
#define SPACE 32 // 스킬 발동할 키
#define SKILL_READY 10 // 스킬 조건 충족 값, 스코어점수가 해당 define에 도달하면 스킬 발동 조건 충족
#define SKILL_EFFECT 33 // 스킬 맵 표시 값, 스킬모양을 맵에 표시



void Level_Change(int level_option[LEVEL_OPTION_INDEX]);
void Skill_Effect(int Map[HEIGHT][WIDTH]);
int Skill_Cast(int Map[HEIGHT][WIDTH], int skill_Y, int skill[2], int score[3]);
void Score_Speed_Increase(int Map[HEIGHT][WIDTH], int level_option[LEVEL_OPTION_INDEX], int speed[2], int skill[2], int score[3], int character[3]);
int Move_Check(int Map[HEIGHT][WIDTH], int progress, int x, int y, int direction, int move, int skill[2], int character[3]);
int Collision(int Map[HEIGHT][WIDTH], int progress, int skill[2], int character[3]);
int Character_Move(int Map[HEIGHT][WIDTH], int Map_change, int progress, int skill[2], int character[3]);
int Drop(int Map[HEIGHT][WIDTH], int progress, int skill[2], int character[3]);
void Create(int Map[HEIGHT][WIDTH], int level_option[LEVEL_OPTION_INDEX]);
void Map_Draw(int Map[HEIGHT][WIDTH], int level_option[LEVEL_OPTION_INDEX], char level_name[], int skill[2], int score[3], int character[3]);
void Game_Start(int Map[HEIGHT][WIDTH], int level_option[LEVEL_OPTION_INDEX]);
void Menu(int Map[HEIGHT][WIDTH]);


void Level_Change(int level_option[LEVEL_OPTION_INDEX]) // 레벨 조절 함수
{
	int Progress = PROGRESS;
	do
	{
		system("cls");
		int InputNum;
		if (level_option[LEVEL] == EASY)
			printf("===== EASY =====\n");
		else if (level_option[LEVEL] == NORMAL)
			printf("===== NORMAL =====\n");
		else if (level_option[LEVEL] == HARD)
			printf("===== HARD =====\n");
		else if (level_option[LEVEL] == HELL)
			printf("===== HELL =====\n");
		printf("=== 난이도 조절 ===\n");
		printf("1. Easy\n");
		printf("2. Normal\n");
		printf("3. Hard\n");
		printf("4. Hell\n");
		printf("5. Return\n");
		printf("입력 : ");
		scanf("%d", &InputNum);
		switch (InputNum)
		{
		case 1:
			level_option[STAR_PER] = EASY_STAR_PER; // 레벨에 따라 별 생성 확률과
			level_option[SHIELD_PER] = SHIELD_CREATE_PER; // 쉴드 생성확률과
			level_option[PLUS_SPEED] = EASY_PLUS_SPEED; // 스피드를 조절
			level_option[LEVEL] = EASY;
			break;
		case 2:
			level_option[STAR_PER] = EASY_STAR_PER - 10; // 낮아질수록 생성될 확률 증가
			level_option[SHIELD_PER] = SHIELD_CREATE_PER;
			level_option[PLUS_SPEED] = EASY_PLUS_SPEED + 2; // 높아질수록 증가되는 스피드 폭 증가
			level_option[LEVEL] = NORMAL;
			break;
		case 3:
			level_option[STAR_PER] = EASY_STAR_PER - 13;
			level_option[SHIELD_PER] = SHIELD_CREATE_PER;
			level_option[PLUS_SPEED] = EASY_PLUS_SPEED + 4;
			level_option[LEVEL] = HARD;
			break;
		case 4:
			level_option[STAR_PER] = EASY_STAR_PER - 16;
			level_option[SHIELD_PER] = SHIELD_CREATE_PER;
			level_option[PLUS_SPEED] = EASY_PLUS_SPEED + 7;
			level_option[LEVEL] = HELL;
			break;
		case 5:
			Progress = STOP;
			break;
		}
	} while (Progress);
}



void Skill_Effect(int Map[HEIGHT][WIDTH]) // 스킬 발동하면 스킬 효과 좌표 함수
{
	int y = HEIGHT - 2;
	for (int x = 1; x < WIDTH - 1; x++)
	{
		if (Map[y][x] != CHARACTER) // 캐릭터 위치를 제외한 나머지 모든 공간에 스킬 효과 좌표 생성
			Map[y][x] = SKILL_EFFECT;
	}
}

int Skill_Cast(int Map[HEIGHT][WIDTH], int skill_Y, int skill[2], int score[3]) // 스킬 효과 함수
{
	for (int x = 1; x < WIDTH - 1; x++) //WALL범위는 제외하기 위해서
	{
		if (Map[skill_Y][x] == SKILL_EFFECT) // 오브젝트 찾으면
		{
			Map[skill_Y][x] = NULL; // 빈 공간으로 바꾸고
			if (Map[skill_Y - 1][x] == STAR)
				score[PRESENT]++; // 스킬로 없앤 별만큼 스코어 증가
			Map[skill_Y - 1][x] = SKILL_EFFECT;
		}
	}
	skill_Y--; // 한칸 증가된 Y축값을 반환
	if (skill_Y == 0)
	{
		skill[SKILL_ON_OFF] = OFF;
		skill_Y = HEIGHT - 2;
	}
	return skill_Y;
}



void Score_Speed_Increase(int Map[HEIGHT][WIDTH], int level_option[LEVEL_OPTION_INDEX], int speed[2], int skill[2], int score[3], int character[3]) // 점수-스피드 증가 함수
{ // 원래 y = HEIGHT 였음, 원래 y축 인덱스를 마지막 까지 사용해서 마지막 y축에 온 별이 사용할수 있는 인덱스를 넘어가게됨, 사용하는 y축을 하나 줄여서 마지막 y축은 맵에 표시되지 않고 스코어 증가에 사용
	int y = HEIGHT - 1; // 별이 가장 밑으로 떨어지면
	for (int x = 0; x < WIDTH - 1; x++) // x축 범위 탐색해서
	{ // 여기서 Y==19일때 X==1일때 별이 있다고 인식해서 스코어를 증가시켜 버림 -> 전 판에서 내려간 별이 초기화가 안된 것이다 아마?
		if (Map[y][x] == STAR) // 별이 있을시
		{
			score[PRESENT]++; // 있을 때마다 1씩 증가
			Map[y][x] = NULL; // 빈 공간으로 초기화안하면 중복되서 증가하기 때문
			if (character[SHIELD_ON_OFF] == ON && skill[SKILL_ON_OFF] == OFF)
			{
				skill[CHARGE]++;
				if (skill[CHARGE] == SKILL_READY)
					skill[SKILL_ON_OFF] = ON;
			}
		}
	}
	if (score[BEFORE] + UP_SPEED_SCORE - score[EXCEED] <= score[PRESENT])//전 스코어 값에서 스피드가 증가할 스코어값만큼 더해줌, 초과값을 뺴는 것은  만약 증가값을 5로 잡았을 때 초과해버리면 남은 값을 빼줘야 기준에 맞기 때문
	{
		speed[DROP_INDEX] -= level_option[PLUS_SPEED];
		speed[CREATE_INDEX] -= level_option[PLUS_SPEED];
		score[BEFORE] = score[PRESENT];
		score[EXCEED] = score[PRESENT] - (score[PRESENT] / UP_SPEED_SCORE * UP_SPEED_SCORE); // /UP_SPEED_SCORE는 초과한 값   / UP_SPEED_SCORE만 하면 커지는 스코어값에 따라가지 못함기때문에 증가시킬 스코어값만큼 곱해주면 스코어가 커져도 따라감
	}
}



int Move_Check(int Map[HEIGHT][WIDTH], int progress, int x, int y, int direction, int move, int skill[2], int character[3])
{
	if (Map[y][x + direction] == STAR)
	{
		if (character[SHIELD_ON_OFF] == OFF) // 쉴드가 없는 경우
		{
			progress = STOP;
			printf("게임종료\n"); // 게임 종료
			system("pause");
			move = FALSE;
			return move;
		}
		else if (character[SHIELD_ON_OFF] == ON) // 쉴드가 있는 경우
		{
			character[SHIELD_ON_OFF] = OFF; // 쉴드가 없어짐
			skill[SKILL_ON_OFF] = OFF; // 스킬 온 되어있을 때 보호막 사라지면 스킬 오프됨
			// 진짜 모르곘다..위에서 떨어지는 별을 쉴드 ON일때 맞으면 오류뜸 -> DROP함수에서 매개변수에 skill을 잘못 적음
			skill[CHARGE] = 0; // 스킬 차지 없어짐
		}
	}

	else if (Map[y][x + direction] == SHIELD) // 왼쪽으로 이동하려고 할 때 쉴드가 있으면
		character[SHIELD_ON_OFF] = ON; // 쉴드 생성

	else if (Map[y][x + direction] != WALL) // 왼쪽으로 이동하려고 할 때 벽이 없으면
		return move; // 이동

	return move;
}



int Collision(int Map[HEIGHT][WIDTH], int progress, int skill[2], int character[3]) // 충돌 함수
{// 쉴드를 먹고 별을 맞으면 메모리를 읽을 수 없다고 나옴 ->  DROP함수에서 매개변수에 skill을 잘못 적음
	int y = HEIGHT - 2;// 캐릭터는 어차피 젤 밑에 있을 것이기 때문
	int x = character[X]; // 캐릭터와 충동하게 되는 것이므로 캐릭터 좌표만 알면 된다
	int Move = Move_Check(Map, progress, x, y, FALSE, TURE, skill, character);
	{
		if (Move == TURE)
			Map[y][x] = CHARACTER;
		else if (Move == FALSE)
			progress = Move;
	}
	return progress;
}



int Character_Move(int Map[HEIGHT][WIDTH], int Map_change, int progress, int skill[2], int character[3]) // 캐릭터 이동 함수
{
	if (kbhit()) // 키보드가 입력될 시
	{
		int y = HEIGHT - 2; // 캐릭터는 어차피 젤 밑에 있을 것이기 때문
		int x = character[X]; // 캐릭터위치만 알면 되기 때문
		int Direction = 0; // 방향
		char ch = getch(); // 입력된 값을 저장하고
		if (Map[y][x] == CHARACTER) //  캐릭터가 있으면
		{
			Map[y][x] = NULL; // 빈 공간으로 바꿔주고
			switch (ch)
			{
			case 'a':
			case 'A':
				Direction = LEFT; // 왼쪽으로 이동하면
				break;
			case 'd':
			case 'D':
				Direction = RIGHT; // 오른쪽으로 이동하면
				break;
			case SPACE: // 스페이스를 누르면
				if (skill[SKILL_ON_OFF] == ON) // 스킬이 온 되었을 때
				{
					Skill_Effect(Map);
					character[SHIELD_ON_OFF] = OFF; // 오프로 바꾸고
					skill[SKILL_ON_OFF] = CAST; // 스킬이 발동된다.
					skill[CHARGE] = 0; // 게이지는 다시 0으로 초기화
					break;
				}
			}

			if (Map[y][x + Direction] == WALL) //옮긴 좌표에 벽이 있으면 이동안한 거임
				Direction = FALSE;

			int Move = Move_Check(Map, progress, x, y, Direction, TURE, skill, character);// 움직일지 움직이지 않을지
			{
				if (Move == TURE)
					x += Direction; //  x좌표 방향값에 따라 변경
				else if (Move == FALSE) // 이동이 불가능한 상황시
					progress = Move; // 게임종료
			}

			character[X] = x; // 변경된 x좌표를 저장
			Map[y][x] = CHARACTER; // 변경된 좌표에 캐릭터 값 저장		
		}
	}
	return progress;
}



int Drop(int Map[HEIGHT][WIDTH], int progress, int skill[2], int character[3]) // 별-쉴드 떨어지는 함수
{
	for (int y = HEIGHT - 2; y >= 0; y--) //밑에서 부터 확인, 위에서 부터 하면 밑에 별이랑 겹칠 수도 있기 때문
	{
		for (int x = 1; x < WIDTH - 1; x++) //WALL범위는 제외하기 위해서
		{
			if (Map[y][x] == STAR) // 오브젝트 찾으면
			{
				if (Map[y + 1][x] == SKILL_EFFECT)// 생성된 스킬효과가 한칸씩 위로가면서 그 공간은 별-쉴드 사라지게
					// 현재 좌표를 NULL로 바꾸면 두 칸이 한번에 사라짐
					continue;
				Map[y][x] = NULL; // 빈 공간으로 바꾸고
				Map[y + 1][x] = STAR; // 바로 밑의 좌표에 별 생성
			}
			else if (Map[y][x] == SHIELD)
			{
				Map[y][x] = NULL;
				if (Map[y + 1][x] == SKILL_EFFECT)
					continue;
				Map[y + 1][x] = SHIELD;
			}
		}
	}
	if (Map[HEIGHT - 2][character[X]] == STAR || Map[HEIGHT - 2][character[X]] == SHIELD)
		progress = Collision(Map, progress, skill, character); // 캐릭터 - 별 충돌
	return progress;
}



void Create(int Map[HEIGHT][WIDTH], int level_option[LEVEL_OPTION_INDEX]) // 별 - 쉴드 생성 함수
{
	int Star_Drop; // 별이 생성될 확률
	int Shield_Drop;
	for (int x = 1; x < WIDTH - 1; x++) //WALL범위는 제외하기 위해서
	{
		Star_Drop = rand() % level_option[STAR_PER]; // 확률 적으로 별 생성
		Shield_Drop = rand() % level_option[SHIELD_PER]; // 확률 적으로 별 생성
		if (Star_Drop == STAR_DROP)
			Map[0][x] = STAR;
		else if (Shield_Drop == SHIELD_DROP)
			Map[0][x] = SHIELD;
		else
			Map[0][x] = NULL;
	}
}



void Map_Draw(int Map[HEIGHT][WIDTH], int level_option[LEVEL_OPTION_INDEX], char level_name[], int skill[2], int score[3], int character[3]) // 맵 그리기 함수
{
	system("cls");
	printf(" %s\n", level_name);
	for (int y = 0; y < HEIGHT - 1; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == STAR)
				printf("★");

			else if (Map[y][x] == SHIELD)
				printf("□");

			else if (Map[y][x] == CHARACTER) // Map[y][x] ==Map[character[Y]][character[X]] 이게 왜 이상하게 나오는지?? -> 캐릭터는 좌표값만 저장해서 좌표로 이동하는데 맵의 이차원배열에 저장된것이 아니기때문
			{
				if (character[SHIELD_ON_OFF] == OFF)
					printf("■");
				else if (character[SHIELD_ON_OFF] == ON)
					printf("▣");
			}

			else if (Map[y][x] == SKILL_EFFECT)
				printf("▲");

			else if (Map[y][x] == WALL)
				printf("|");

			else if (Map[y][x] == NULL)
				printf("  ");
		}
		printf("\n");
	}
	printf("Score = %d\n", score[PRESENT]);

	if (skill[SKILL_ON_OFF] == OFF)
		printf("Skill_Charge = %d\n", skill[CHARGE]);
	else if (skill[SKILL_ON_OFF] == ON)
		printf("Skill_Ready : Space Bar를 누르세요!\n");
	else if (skill[SKILL_ON_OFF] == CAST)
		printf("Skill_Cast\n");
}



void Game_Start(int Map[HEIGHT][WIDTH], int level_option[LEVEL_OPTION_INDEX]) // 게임 시작 함수
{
	int Drop_Clock = clock(); // 별, 쉴드 떨어지는 시간
	int Create_Clock = clock(); // 별, 쉴드 만들어지는 시간
	int Skill_Clock = clock(); // 별, 쉴드 만들어지는 시간
	int Speed[2] = { DROP_SPEED, CREATE_SPEED }; // 별-쉴드 떨어지는 속도, 별-쉴드 만들어지는 속도
	int Character[3]; // x좌표, 이동전 x좌표(Map_change구분하기 위해 사용), 쉴드 온오프
	int Skill[2] = { 0 }; // 스킬이 준비됐는지아닌지 발동되었는지, 스킬 충천
	int Skill_Y = HEIGHT - 2; // 스킬시작 y축
	int Score[3] = { 0 }; // 현재 스코어, 이전 스코어, 계산할 때 초과된 스코어(스코어에 따라 점수가 증가하기때문에 기준점을 잡기 위해)
	int Map_Change = TURE; // 맵에 변동이 있을 때만 다시 그리기 위해
	int Progress = PROGRESS;

	for (int y = 0; y < HEIGHT; y++) // 마지막 인덱스는 스코어 측정으로 사용할 것이기 때문에 마지막 인덱스는 미사용
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (y == HEIGHT - 2 && x == WIDTH / 2) // 중앙에 캐릭터 생성
			{
				Character[X] = x; // 캐릭터 좌표 찾을 때 사용
				Character[BEFORE_X] = x;
				Character[SHIELD_ON_OFF] = OFF;
				Map[y][x] = CHARACTER;
			}
			else if (y < HEIGHT - 1 && x == 0 || x == WIDTH - 1) // x축 처음과 마지막에 벽 생성
				Map[y][x] = WALL;
			else // 나머지는 빈 공간 // 다시 시작하면 스코어가 증가했던 이유 해결 : 여기서 for문 y축 범위를 스코어 측정까지 늘려서 초기화되지 않은 스코라인 별을 빈공간으로 초기화 시켜준다.
				Map[y][x] = NULL;
		}
	}

	char Level_Name[30]; // 난이도 문자열 출력
	if (level_option[LEVEL] == EASY)
		sprintf(Level_Name, "===== EASY =====");
	else if (level_option[LEVEL] == NORMAL)
		sprintf(Level_Name, "===== NORMAL =====");
	else if (level_option[LEVEL] == HARD)
		sprintf(Level_Name, "===== HARD =====");
	else if (level_option[LEVEL] == HELL)
		sprintf(Level_Name, "===== HELL =====");

	while (Progress)
	{
		if (Map_Change == TURE || Character[X] != Character[BEFORE_X]) // 맵에 변동이 있거나, 캐릭터 좌표가 바뀌었을 경우
		{
			Character[BEFORE_X] = Character[X]; // 이전 캐릭터좌표를 다시 현재 좌표로 변경해줌
			Map_Draw(Map, level_option, Level_Name, Skill, Score, Character); // 맵 그리기
			Map_Change = FALSE;
		}

		if (Skill[SKILL_ON_OFF] == CAST)
		{
			if (clock() - Skill_Clock >= SKILL_SPEED)
			{
				Skill_Y = Skill_Cast(Map, Skill_Y, Skill, Score);
				Skill_Clock = clock();
				Map_Change = TURE;
			}
		}

		if (clock() - Drop_Clock >= Speed[DROP_INDEX])
		{
			Progress = Drop(Map, Progress, Skill, Character);
			Drop_Clock = clock(); // 다시 시간 조정해주기
			if (Progress == STOP)
				return;
			Score_Speed_Increase(Map, level_option, Speed, Skill, Score, Character);
			Map_Change = TURE;
		}

		if (clock() - Create_Clock >= Speed[CREATE_INDEX])
		{
			Create(Map, level_option);
			Create_Clock = clock();
			Map_Change = TURE;
		}

		Progress = Character_Move(Map, Map_Change, Progress, Skill, Character); // 캐릭터 이동
	}
}



void Menu(int Map[HEIGHT][WIDTH]) // 메인 메뉴 함수
{
	int Select;
	int Level_Option[LEVEL_OPTION_INDEX] = { EASY_STAR_PER, SHIELD_CREATE_PER, EASY_PLUS_SPEED, EASY }; // 기본갑 셋팅(이지 모드)
	int Progress = PROGRESS;
	do
	{
		system("cls");
		printf("===== 별똥별 피하기 =====\n");
		printf("	1. 게임 시작\n");
		printf("	2. 난이도 조절\n");
		printf("	3. 종료\n");
		printf("	입력 : ");
		scanf("%d", &Select);

		switch (Select)
		{
		case 1:
			Game_Start(Map, Level_Option);
			break;
		case 2:
			Level_Change(Level_Option);
			break;
		case 3:
			Progress = STOP;
		}
	} while (Progress == PROGRESS);
}



void main()
{
	int Map[HEIGHT][WIDTH];
	srand(time(NULL));
	Menu(Map);
}