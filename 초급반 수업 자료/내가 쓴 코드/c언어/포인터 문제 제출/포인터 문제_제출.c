#include<stdio.h>
#define ARR_NUM 8

void ConvertToUppercase(char* string) // 배열의 시작주소를 받았고, 포인터도 배열처럼 사용 할 수 있으므로 바로 배열로 사용 가능
{
	//printf("%s", string[0]); 슈벌 간단하게 주소를 안보냈기 때문, 난 문자값을 주고 있는 것
	for (int i = 0; string[i] != NULL; i++)
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			string[i] -= 32;
	}
}

void BigNumber(int Num1, int Num2, int* BigNum)
{
	if (Num1 < Num2)
		*BigNum = Num2;
	else
		*BigNum = Num1;
}

void Accumulate(int inputnum, int* plusnum)
{
	for (int i = 1; i <= inputnum; i++)
		*plusnum += i;
}

void Sort(int Sort_Num[ARR_NUM])
{
	int Num;
	for (int i = 1; i < ARR_NUM - 1; i++)
	{
		for (int j = i + 1; j < ARR_NUM; j++)
		{
			if (Sort_Num[i] > Sort_Num[j])
			{
				Num = Sort_Num[i];
				Sort_Num[i] = Sort_Num[j];
				Sort_Num[j] = Num;
			}
		}
	}
}

void main()
{
	// 1번 문제
	char string[10];
	printf("1. 문자열을 입력하시오 : ");
	scanf("%s", string);
	printf("함수 호출 후 = %s\n", string);
	ConvertToUppercase(string);
	printf("함수 호출 후 = %s\n", string);

	// 2번 문제
	int Num1, Num2, BigNum = 0;
	printf("2. 두 정수를 입력하시오 : ");
	scanf("%d%d", &Num1, &Num2);
	BigNumber(Num1, Num2, &BigNum);
	printf("%d와(과) %d중 큰 수는 %d\n", Num1, Num2, BigNum);

	// 3번 문제
	int InputNum;
	int PlusNum = 0;
	printf("3. 정수를 입력하시오 : ");
	scanf("%d", &InputNum);
	Accumulate(InputNum, &PlusNum);
	printf("1 ~ %d의 총합 : %d\n", InputNum, PlusNum);

	//4번 문제
	int Number[ARR_NUM];
	int* Sort_Num = Number;
	printf("4. 오름차순 정렬\n");
	for (int i = 0; i < ARR_NUM; i++)
	{
		printf("[%d]번째 정수 입력 : ", i);
		scanf("%d", &Sort_Num[i]);
	}

	printf("정렬 전 : ");
	for (int i = 0; i < ARR_NUM; i++)
		printf("%d ", Sort_Num[i]);

	printf("\n");
	Sort(Sort_Num);

	printf("정렬 후 : ");
	for (int i = 0; i < ARR_NUM; i++)
		printf("%d ", Sort_Num[i]);
}