#include<stdio.h>
#include<conio.h>
#define TRUE 1
#define ESC 0

void main()
{
	//1번문제
	int Num = 1, sum = 0, InputNum;
	while (TRUE)
	{
		printf("1. 10 ~ 20사이 정수 입력 : ");
		scanf("%d", &InputNum);
		if (InputNum >= 10 && InputNum <= 20)
		break;
		printf("잘못 입력\n");
	}
	while (Num <= InputNum)
	{
		sum += Num;
		Num++;
	}
	printf("1 ~ %d 사이 누적 합계 : %d\n",InputNum, sum);


	//2번 문제
	int Num2 = 1;
	printf("2. Hello 출력\n");
	while (Num2 <= 5)
	{
		printf("Hello\n");
		Num2++;
	}

	//3번 문제
	int Num3, sum3 = 0;
	printf("3. 정수 반복 입력 (0입력시 종료)\n");
	do
	{
		printf("정수 입력 : ");
		scanf("%d", &Num3);
		sum3 += Num3;
	} while (Num3 != ESC)
	printf("최종 합계 : %d\n", sum3);

	//4번 문제
	int Num4, i=1, count=0;
	printf("4. 소수 판별\n");
	printf("정수 입력 : ");
	scanf("%d", &Num4);
	while (i <= Num4)
	{
		if (Num4 % i == 0)
		{
			count++;
		}
		i++;
	}
	if (count >= 3)
	{
		printf("%d는 소수가 아닙니다.\n", Num4);
	}
	else
	{
		printf("%d는 소수 입니다.\n", Num4);
	}

	//5번 문제
	int Num5, Reverse;
	printf("5. 입력된 정수 거꾸로 출력\n");
	printf("정수 입력 : ");
	scanf("%d", &Num5);
	while (TRUE)
	{
		if (Num5 != 0)
		{
			Reverse = Num5 % 10;
			Num5 /= 10;
			printf("%d", Reverse);
		}
		else
			break;
	}
	printf("\n");

	//6번 문제
	int Num6, Num7, sum6 = 0;
	printf("6. 입력된 정수의 각자리 수 합계\n");
	printf("정수 입력 : ");
	scanf("%d", &Num6);
	while (TRUE)
	{
		if (Num6 != 0)
		{
			Num7 = Num6 % 10;
			sum6 += Num7;
			Num6 /= 10; 
		}
		else
			break;
	}
	printf("최종 합계 : %d\n", sum6);
	
	return;
}