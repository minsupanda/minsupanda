#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#define MAX 10
#define DESC 1
#define ASC 2


void Print(int Arr[MAX]);
void SetArray(int Arr[MAX]);
void swap(int* num1, int* num2);
void partition(int Arr[MAX], int low, int high, int Type);
void main();

void Print(int Arr[MAX])
{
	for (int i = 0; i < MAX; i++)
		printf("%d ", Arr[i]);
	printf("\n");
}

void SetArray(int Arr[MAX])
{
	for (int i = 0; i < MAX; i++)
		Arr[i] = rand() % 15 + 1;
}

void swap(int* num1, int* num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void partition(int Arr[MAX], int left, int right, int Type)
{// 1 2 4 6 5 3
	if (left >= right)
		return;
	int pivot = right;
	int low = left;
	int high = right - 1;
	while (low < high)
	{
		while (((Arr[low] <= Arr[pivot] && Type == ASC) || (Arr[low] >= Arr[pivot] && Type == DESC)) && low < pivot)
			low++;
		while (((Arr[high] >= Arr[pivot] && Type == ASC) || (Arr[high] <= Arr[pivot] && Type == DESC)) && high > left)
			high--;
		if (low < high)
			// high가 더 크다는 것은 아직 pivot보다 작은 값이 있다는 뜻
			// 위에서 증감을 하다 low가 high보다 커지게 되면 서로 관계가 뒤짚혔으므로 스왑하면 안되기 때문
			// 이때는 while문을 탈출하게 되는 것
			swap(&Arr[low], &Arr[high]);
	}
	if ((Arr[low] > Arr[pivot] && Type == ASC) || (Arr[low] < Arr[pivot] && Type == DESC))
		swap(&Arr[low], &Arr[pivot]);

	pivot = low;

	partition(Arr, left, pivot - 1, Type);
	partition(Arr, pivot + 1, right, Type);
}

void main()
{
	int Arr[MAX] = { 0 };
	srand(time(NULL));

	int Select;
	while (1)
	{
		system("cls");
		Print(Arr);
		printf("1. 번호 생성\n");
		printf("2. 오름차순 정렬\n");
		printf("3. 내림차순 정렬\n");
		printf("4. 종료\n");
		printf("선택 : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			SetArray(Arr);
			break;
		case 2:
			partition(Arr, 0, MAX - 1, ASC);
			break;
		case 3:
			partition(Arr, 0, MAX - 1, DESC);
			break;
		case 4:
			return;
		}
	}
}