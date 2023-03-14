#include <stdio.h>

void main()
{
	int Num1;
	printf("1.정수를 입력하시오 : ");
	scanf("%d", &Num1);
	(Num1 % 5 == 0) ? printf("%d는(은) 5의 배수입니다.\n", Num1) : printf("%d는(은) 5의 배수가 아닙니다.\n", Num1);

	
	int koreanscore;
	int mathscore;
	int englishscore;
	float sum;
	printf("2.세 과목의 점수를 입력하시오\n");
	printf("국어 점수 : ");
	scanf("%d", &koreanscore);
	printf("수학 점수 : ");
	scanf("%d", &mathscore);
	printf("영어 점수 : ");
	scanf("%d", &englishscore);
	sum = (koreanscore + mathscore + englishscore)/3;
	(sum >= 60.00) ? printf("평균 %.2f합격\n", sum) : printf("평균 %.2f불합격\n", sum);
	
	int Num2;
	int Num3;
	printf("3. 두정수를 입력하시오 : \n");
	scanf("%d%d", &Num2, &Num3);
	(Num2 > Num3) ? printf("큰 수 : %d\n", Num2) : printf("큰 수 : %d\n", Num3);


	int Num4;
	printf("4. 정수를 입력하시오 : ");
	scanf("%d", &Num4);
	(Num4 % 3 == 0 && Num4 % 2 == 0) ? printf("%d는 짝수이며 3의 배수입니다\n.", Num4) : printf("조건실패\n");
	

	int Num5;
	printf("5. 정수를 입력하시오 : ");
	scanf("%d", &Num5);
	(Num5 % 5 == 0 || Num5 % 7 == 0) ? printf("%d는 5의 배수이거나 7의 배수입니다.", Num5) : printf("조건실패");


	return;
}