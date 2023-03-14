#include<stdio.h>
#define SIZE 10
#define EVEN 0
#define ODD 1

void PrintArr(int Arr[]) //배열 출력 함수
{
	for (int i = 0; i < SIZE; i++)
		printf("%d,", Arr[i]);
	printf("\b \n");
}


int EvenOdd(int Arr[], int EvenOddType) // 홀짝 함수
{
	int Sum = 0;
	if (EvenOddType == ODD)
		printf("홀수 번째 원소 : ");
	else
		printf("짝수 번째 원소 : ");
	for (int i = EvenOddType; i < SIZE; i += 2)
	{
		printf("%d,", Arr[i]);
		Sum += Arr[i];
	}
	printf("\b \n");
	return Sum;
}

void main()
{
	int Arr[SIZE] = { 10,17,3,9,37,10,8,9,13,21 };
	printf("1번 문제\n");
	PrintArr(Arr);
	printf("\n");


	int j = 0, Invert_Arr[SIZE]; // 역순 배열 변수
	printf("2번 문제\n");
	printf("Invert_Arr : ");
	for (int i = SIZE - 1; i >= 0; i--)
	{
		Invert_Arr[j] = Arr[i];
		j++;
	}
	PrintArr(Invert_Arr);
	printf("Arr : ");
	PrintArr(Arr);
	printf("\n");


	printf("3번 문제\n");
	printf("홀수 번째 총합 : %d\n", EvenOdd(Arr, ODD));
	printf("짝수 번째 총합 : %d\n", EvenOdd(Arr, EVEN));
	printf("\n");


	int Sort_Arr[SIZE]; // 내림차순 정렬 변수
	printf("4번 문제\n");
	printf("Arr : ");
	PrintArr(Arr);
	printf("\n");
	printf("Sort_Arr : ");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (Arr[i] <= Arr[j] && j >= i)
			{
				Sort_Arr[i] = Arr[j];
				Arr[j] = Arr[i];
				Arr[i] = Sort_Arr[i];
			}
		}
	}
	PrintArr(Sort_Arr);
	printf("\n");
}