#include<stdio.h>
#define EVEN 1
#define ODD 2
//1번 문제
int BigNum(int x, int y)
{
	int Answer;
	if (x > y)
		Answer = x;
	else
		Answer = y;
	return Answer;
}


//2번 문제
int evenoddNum(int x)
{
	int Answer;
	if (x % 2 == 0)
		Answer = EVEN;
	else
		Answer = ODD;
	return Answer;
}


//3번 문제
int ABS(int x)
{
	int Answer;
	if (x >= 0)
		Answer = x;
	else
		Answer = -x;
	return Answer;
}


//4번 문제
int Reverse(int x)
{
	int Answer = 0;
	while (x != 0)
	{
		Answer *= 10;
		Answer += x % 10;
		x /= 10;
	}
	return Answer;
}

void main()
{
	//1번 문제
	int Num1, Num2;
	printf("1.두 수를 입력 하시오 : ");
	scanf("%d%d", &Num1, &Num2);
	int Answer = BigNum(Num1, Num2);
	printf("%d 와 %d 중 큰 수는 %d 입니다.\n", Num1, Num2, Answer);

	//2번 문제
	int Num3;
	printf("2. 정수 하나를 입력하시오 : ");
	scanf("%d", &Num3);
	Answer = evenoddNum(Num3);
	if (Answer == EVEN)
		printf("%d는 짝수 입니다.\n", Num3);
	else
		printf("%d는 홀수 입니다.\n", Num3);


	//3번 문제
	int Num4;
	printf("3. 정수 하나를 입력하시오 : ");
	scanf("%d", &Num4);
	Answer = ABS(Num4);
	if (Num4 >= 0)
		printf("%d의 절대값 : %d\n", Num4, Answer);
	else
		printf("%d의 절대값 : %d\n", Num4, Answer);



	//4번 문제
	int Num5;
	printf("4. 정수를 입력하세요 : ");
	scanf("%d", &Num5);
	Answer = Reverse(Num5);
	printf("%d의 거꾸로 값 : %d", Num5, Answer);
		printf("4.정수 하나를 입력하시오 : ");
	scanf("%d", &Num1);
	printf("%d의 거꾸로 수 : %d", Num1, Reverse(Num1));
}