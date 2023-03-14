#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRUE 1
#define FALSE 0
#define MAX 10

typedef struct Quiz
{
	char quiz[256];
	char answer;
	int result;
}Quiz;

void PlayQuiz(Quiz quiz_list[MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		printf("%s", quiz_list[i].quiz);
		printf("(O or X) : ");
		char select;
		scanf("%c", &select);
		scanf("%*c");
		if (select == quiz_list[i].answer)
		{
			quiz_list[i].result = TRUE;
			printf("정답!!\n");
		}
		else
		{
			quiz_list[i].result = FALSE;
			printf("오답..\n");
		}
	}
}

int ScoreSet(Quiz quiz_list[MAX])
{
	int point = 0;
	int Score = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (quiz_list[i].result == TRUE)
		{
			point++;
			Score += point;
		}
		else
			point = 0;
	}
	return Score;
}

void Swap(Quiz* q1, Quiz* q2) // 문제 순서 바꿔주는 함수
{
	//만들어진 문제들을 rand에서 뽑힌 문제들끼리 순서 바꿔주는 것
	Quiz tmp = *q1;
	*q1 = *q2;
	*q2 = tmp;
}

void Shuffle(Quiz quiz_list[MAX]) // 문제 섞는 함수
{
	for (int i = 0; i < 100; i++)
	{
		// 왜 99까지 돌리는지?
		//그냥 많이 섞는 것이다
		int index1 = rand() % MAX;
		int index2 = rand() % MAX;
		Swap(&quiz_list[index1], &quiz_list[index2]);
	}
}

void main()
{
	srand(time(NULL));
	Quiz quiz_list[MAX] = {
		{"달팽이도 이빨이 있다.", 'O',-1},
		{"게의 다리는 모두 10개이다.", 'O',-1},
		{"고대 원시인들의 가장 큰 적은 공룡이었다.", 'X',-1},
		{"남자와 여자의 목소리 중 멀리 들리는 것은 여자 목소리다.", 'O',-1},
		{"고래는 쉼 5M 이하의 물 속에서 잠을 잔다.", 'X',-1},
		{"육상 선수가 한쪽 발에만 운동화를 신고 경기할 수 없다.", 'X',-1},
		{"닭도 왼발잡이 , 오른발잡이가 있다.", 'O',-1},
		{"새는 뒤로도 날 수 있다.", 'O',-1},
		{"위가 없어도 사람은 살 수 있다.", 'O',-1},
		{"사람의 세포는 개미의 세포보다 크다.", 'X',-1},
		//-1은 그냥 잘 쓰지 않는 값을 넣어둔 것
		//나중에 스코어 증가할 떄 TURE, FALSE로 바꿔 점수확인할 것이다
	};
	Shuffle(quiz_list);
	PlayQuiz(quiz_list);
	printf("총 획득 점수 : %d점", ScoreSet(quiz_list));
}