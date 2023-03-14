#include<stdio.h>
#include<stdlib.h>
#include<time.h> // 시간 값을 사용하능 헤더파일
#define DEFAULT_LEAST_RANGE 1
#define DEFAULT_MAXIMUM_RANGE 100
#define DEFAULT_TURN 10
#define LEAST_RANGE 0
#define MAXIMUM_RANGE 1
#define TURN 2
#define DATE 3
#define UP 1
#define DOWN 0
#define CONTINUE 1
#define STOP 0
#define CORRECT 20
#define PAUSE system("pause")
#define CLS system("cls")

//알트 드래그
//알트 방향키
// 쉬프트 탭

int Up_Down_Check(int answer, int input_answer, int game_date[DATE]);
void Game_Start(int game_date[DATE]);
int Range_Option(int game_date[DATE]);
int Turn_Option(int game_date[DATE]);
int Option(int game_date[DATE]);


int Up_Down_Check(int answer, int input_answer, int game_date[DATE], int turn) // 업 다운 확인 함수
{
	scanf("%d", &input_answer);
	if (input_answer != answer)
	{
		if (input_answer < answer && input_answer >= game_date[LEAST_RANGE]) // 여기서 디버깅이 예외처리가 안됐다고 뜬다 = > 호출함수의 매개변수와 갯수가 달라 오류가 뜬 것
			printf("Up\n");

		if (input_answer > answer && input_answer <= game_date[MAXIMUM_RANGE])
			printf("Down\n");

		if (input_answer < game_date[LEAST_RANGE] || input_answer >  game_date[MAXIMUM_RANGE])
		{
			printf("범위를 벗어났습니다.\n");
			turn--;
		}
		if (turn == game_date[TURN])
		{
			PAUSE;
			CLS;
			printf("Game Over : Turn수 초과\n"); // 턴수내에 끝내지 못했을 경우
		}
	}

	if (input_answer == answer)
	{
		CLS;
		printf("정답!!\n턴수 : %d\n", turn);
		turn = CORRECT;
		PAUSE;
			return turn;
	}
	PAUSE;
	CLS;
	return turn;
}


void Game_Start(int game_date[DATE]) // 게임 진행 함수, 디버깅하면 game_date값이 주소값~{1} 이렇게 뜨는데 이건 주소값은 시작주소값이고 1은 뭐지? 주소값이 가지고 있는 값인가? = >맞음
{
	CLS;
	int Answer = (rand() % (game_date[MAXIMUM_RANGE] - (game_date[LEAST_RANGE] - 1)) + game_date[LEAST_RANGE]; // 무작위 수 지정
	int Input_Answer = 0; // 내가 넣을 답
	for (int i = 1; i <= game_date[TURN]; i++)
	{
		printf("범위 : %d ~ %d\n", game_date[LEAST_RANGE], game_date[MAXIMUM_RANGE]);
		printf("제한 Turn : %d\n", game_date[TURN]);
		printf("========= %d턴 =========\n", i);
		printf("입력 : ");

		i = Up_Down_Check(Answer, Input_Answer, game_date, i); // 내가 입력한 답 확인

		if (i == CORRECT)
			return;
	}
}


int Range_Option(int game_date[DATE]) // 범위 변경 함수
{
	int Progress = CONTINUE;
	int Least = game_date[LEAST_RANGE]; // 오류 발생시 그 전 값으로 덮어주기 위해
	int Maximum = game_date[MAXIMUM_RANGE]; // 오류 발생시 그 전 값으로 덮어주기 위해
	CLS;
		while (Progress)
		{
			CLS;
			printf("(현재 : %d) 최소 값 변경 : ", game_date[LEAST_RANGE]);
			scanf("%d", &game_date[LEAST_RANGE]);
			printf("(현재 : %d) 최소 값 변경 : ", game_date[MAXIMUM_RANGE]);
			scanf("%d", &game_date[MAXIMUM_RANGE]);

			if (game_date[MAXIMUM_RANGE] > game_date[LEAST_RANGE])
				Progress = STOP;
			else if (game_date[MAXIMUM_RANGE] <= game_date[LEAST_RANGE])
			{
				printf("오류 : 최소값이 최대값보다 큽니다. 다시 입력하세요.\n");
				game_date[LEAST_RANGE] = Least;
				game_date[MAXIMUM_RANGE] = Maximum;
				PAUSE;
				CLS;
			}
		}
}


int Turn_Option(int game_date[DATE]) // 턴수 변경 함수
{
	int Progress = CONTINUE;
	int turn = game_date[TURN]; // 오류 발생시 그 전 값으로 덮어주기 위해
	while (Progress)
	{
		CLS;
		printf("(현재 : %d) 최대 Turn 값 변경 : ", game_date[TURN]);
		scanf("%d", &game_date[TURN]);

		if (game_date[TURN] > 0)
			Progress = STOP;
		else if (game_date[TURN] <= 0)
		{
			printf("오류 : Turn수가 0 보다 작거나 같습니다. 다시 입력하세요.\n");
			game_date[TURN] = turn;
			PAUSE;
			CLS;
		}
	}
}


int Option(int game_date[DATE]) // 게임설정 변경 함수
{
	int Option_Progress = CONTINUE;
	while (Option_Progress)
	{
		CLS;
		int Input_Num;
		printf("========= 게임 설정 =========\n");
		printf("1. 최대, 최소범위 설정\n");
		printf("2. 최대 Turn수 설정\n");
		printf("3. 돌아가기\n");
		printf("입력 : ");
		scanf("%d", &Input_Num);
		switch (Input_Num)
		{
		case 1:
			Range_Option(game_date);
			//함수에서 reutnr했으면 이게 따로 저장안하면 그냥 값이 날라가는게 아니였나?
			//근데 따로 저장안했는데도 이함수내에서는 저장됨 => 왜냐하면 배열은 주소를 사용하는 것이기 때문에 바로 해당 메모리주소로 접근하기 때문에 값을 반환하지 않아도 바뀌는 것
			//모든case에서 반환할때 이상한 값들이 나옴..? 1229978808? = > 위와 같은 맥락으로 해당 값은 주소값이다
			break;
		case 2:
			Turn_Option(game_date);
			break;
		case 3:
			Option_Progress = STOP;
			break;
		}
	}
}



void main()
{
	int InputNum; // 입력번호
	int Game_Progress = CONTINUE; // 게임을 계속 진행할지, 끝낼지
	int Game_Date[DATE] = { DEFAULT_LEAST_RANGE, DEFAULT_MAXIMUM_RANGE, DEFAULT_TURN }; // 변화시킬값들
	srand(time(NULL)); // 시드값 변경
	while (Game_Progress)
	{
		CLS;
		printf("========= UpDown GAME =========\n");
		printf("	  1. 게임 시작\n");
		printf("	  2. 범위 설정\n");
		printf("	  3. 종	    료\n");
		printf("입력 : ");
		scanf("%d", &InputNum);

		switch (InputNum)
		{
		case 1:
			Game_Start(Game_Date);
			break;
		case 2:
			Option(Game_Date);
			break;
		case 3:
			Game_Progress = STOP;
			break;
		}
	}
}
