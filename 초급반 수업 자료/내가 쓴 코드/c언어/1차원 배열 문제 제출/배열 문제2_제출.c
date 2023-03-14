#include<stdio.h>
#define SIZE 10
#define EVEN 0
#define ODD 1

void PrintArr(int Arr[]) //�迭 ��� �Լ�
{
	for (int i = 0; i < SIZE; i++)
		printf("%d,", Arr[i]);
	printf("\b \n");
}


int EvenOdd(int Arr[], int EvenOddType) // Ȧ¦ �Լ�
{
	int Sum = 0;
	if (EvenOddType == ODD)
		printf("Ȧ�� ��° ���� : ");
	else
		printf("¦�� ��° ���� : ");
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
	printf("1�� ����\n");
	PrintArr(Arr);
	printf("\n");


	int j = 0, Invert_Arr[SIZE]; // ���� �迭 ����
	printf("2�� ����\n");
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


	printf("3�� ����\n");
	printf("Ȧ�� ��° ���� : %d\n", EvenOdd(Arr, ODD));
	printf("¦�� ��° ���� : %d\n", EvenOdd(Arr, EVEN));
	printf("\n");


	int Sort_Arr[SIZE]; // �������� ���� ����
	printf("4�� ����\n");
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