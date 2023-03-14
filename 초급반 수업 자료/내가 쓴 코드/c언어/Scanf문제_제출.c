#pragma warning(disable:4996)
#include<stdio.h>

void main()
{
	char ch;
	int num;
	printf("단일 문자를 입력하시오 : ");
	scanf("%c", &ch);
	printf("정수를 입력하시오 : ");
	scanf("%d", &num);
	printf("%c + %d = %c\n\n", ch, (char)num, ch + (char)num);

	float Fnum;
	printf("소수점수를 입력하시오 : ");
	scanf("%f,", &Fnum);
	printf("소숫점수 : %.2f\n\n", Fnum);

	int koreascore, mathscore, englishscore, sum;
	printf("국어점수를 입력하시오 : ");
	scanf("%d", &koreascore);
	printf("수학점수를 입력하시오 : ");
	scanf("%d", &mathscore);
	printf("영어점수를 입력하시오 : ");
	scanf("%d", &englishscore);
	printf("국어점수 : %d\n", koreascore);
	printf("수학점수 : %d\n", mathscore);
	printf("영어점수 : %d\n", englishscore);
	sum = koreascore + mathscore + englishscore;
	printf("합계점수 : %d ", sum);
	printf("평균점수 : %d \n\n", sum / 3);


	char name[10];
	int age;
	printf("이름을 입력하시오 : ");
	scanf("%s", name);
	printf("%s님의 나이를 입력하시오 : ", name);
	scanf("%d", &age);
	printf("%s님의 나이는 %d입니다.", name, age);

	return;
}