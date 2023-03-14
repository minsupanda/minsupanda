#include<stdio.h>

void main()
{
	//1번문제
	int Num;
	printf("1. 정수를 입력하시오 : ");
	scanf("%d", &Num);
	if (Num % 3 == 0)
	{
		printf("%d는 3의 배수입니다.\n", Num);
	}
	if (Num % 3 != 0)
	{
		printf("%d는 3의 배수가 아닙니다.\n", Num);
	}


	//2번문제
	int Num1;
	printf("2. 정수를 입력하시오 : ");
	scanf("%d", &Num1);
	if (Num1 >= 0)
	{
		printf("%d의 절대값은 %d입니다.\n", Num1, Num1);
	}
	if (Num1 < 0)
	{
		printf("%d의 절대값은 %d입니다.\n", Num1, -Num1);
	}


	//3번문제
	int Num2;
	printf("3. 정수를 입력하시오 : ");
	scanf("%d%", &Num2);
	if (Num2 % 2 == 0)
	{
		printf("%d는 짝수 입니다.\n", Num2);
	}
	if (Num2 % 2 != 0)
	{
		printf("%d는 홀수 입니다.\n", Num2);
	}


	//4번문제
	int Num3;
	int Num4;
	printf("4. 정수 두개를 입력하시오 : ");
	scanf("%d%d", &Num3, &Num4);
	if (Num3 > Num4)
	{
		printf("Max = %d\n", Num3);
	}
	if (Num4 >= Num3)
	{
		printf("Max = %d\n", Num4);
	}


	//5번문제
	int Num5;
	int Num6;
	int Num7;
	printf("5. 정수 세개를 입력하시오");
	scanf("%d%d%d", &Num5, &Num6, &Num7);
	if (Num5 > Num6 && Num5 > Num7)
	{
		printf("Max = %d\n", Num5);
	}
	if (Num6 > Num5 && Num6 > Num7)
	{
		printf("Max = %d\n", Num6);
	}
	if (Num7 >= Num6 && Num7 >= Num5)
	{
		printf("Max = %d\n", Num7);
	}


	//6번문제
	int Num8;
	int Num9;
	printf("6. 정수 두개를 입력하시오");
	scanf("%d%d", &Num8, &Num9);
	if (Num8 > Num9)
	{
		if (Num8 % 2 == 0)
		{
			printf("큰수는 %d이며 짝수입니다.\n", Num8);
		}
		if (Num8 % 2 != 0)
		{
			printf("큰수는 %d이며 홀수입니다.\n", Num8);
		}
	}
	if (Num9 >= Num8)
	{
		if (Num9 % 2 == 0)
		{
			printf("큰수는 %d이며 짝수입니다.\n", Num9);
		}
		if (Num9 % 2 != 0)
		{
			printf("큰수는 %d이며 홀수입니다.\n", Num9);
		}
	}


	//7번문제
	int Num10;
	int Num11;
	int sum;
	printf("7. 정수 두개를 입력하시오");
	scanf("%d%d", &Num10, &Num11);
	sum = Num10 + Num11;
	if (sum % 2 != 0 && sum % 3 == 0)
	{
		printf("%d와 %d의 합 = %d\n", Num10, Num11, sum);
		printf("%d는 홀수이고 3의 배수입니다\n", sum);
	}
	if (sum % 2 == 0 || sum % 3 != 0)
	{
		printf("해당사항이 없습니다.\n");
	}


	return;
}