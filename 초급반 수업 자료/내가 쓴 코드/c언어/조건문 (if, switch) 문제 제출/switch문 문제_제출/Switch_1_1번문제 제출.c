#include<stdio.h>
#include<Windows.h> //system("cls"),ststem("pause") 를 사용하기 위해 사용하는 헤더파일

void main()
{
	int Select, Kor, Math, Eng, Sum, inputname = 0, inputscore = 0;
	float Avg;
	char name[10];
	while (1)
	{
		system("cls");
		printf("====================\n");
		printf("   학생성적관리\n");
		printf("====================\n");
		printf("   1. 학생 이름등록\n");
		printf("   2. 3과목 점수등록\n");
		printf("   3. 점수확인\n");
		printf("   4. 종료\n");
		printf("====================\n");
		printf("입력 : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			system("cls");
			printf("이름 입력 : ");
			scanf("%s", name);
			inputname = 1;
			break;

		case 2:
			system("cls");
			printf("세과목의 성적을 입력하시오\n");
			printf("국어 : ");
			scanf("%d", &Kor);
			printf("수학 : ");
			scanf("%d", &Math);
			printf("영어 : ");
			scanf("%d", &Eng);
			Sum = Kor + Math + Eng;
			Avg = (float)Sum / 3.0f;
			inputscore = 1;
			break;

		case 3:
			system("cls");
			if (inputname == 0 || inputscore == 0)
			{
				if (inputname == 0 )
					printf("이름을 입력하세요\n");
				if (inputscore == 0)
					printf("점수를 입력하세요\n");
				system("pause");
			}
			else
			{
				printf("===============\n");
				printf("%s님의 점수\n", name);
				printf("국어 점수 : %d\n", Kor);
				printf("수학 점수 : %d\n", Math);
				printf("영어 점수 : %d\n", Eng);
				printf("합계 점수 : %d\n", Sum);
				printf("평균 점수 : %.2f\n", Avg);
				printf("===============\n");
				system("pause");
			}
			break;

		case 4:
			return;
		}
	}
}