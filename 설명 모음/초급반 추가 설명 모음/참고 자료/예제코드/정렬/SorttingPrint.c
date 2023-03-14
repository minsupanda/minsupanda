#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define COLOR_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(COLOR_HANDLE,0x000c)
#define BLUE SetConsoleTextAttribute(COLOR_HANDLE,0x0009)
#define PUPPLE SetConsoleTextAttribute(COLOR_HANDLE,0x0005)
#define WHITE SetConsoleTextAttribute(COLOR_HANDLE,0x0007)

#define ARRAY_MAX 15
#define PRINT_DELAY 50
#define ESC 27

void PrintArray(int Array[ARRAY_MAX], int index1, int index2, int StartTime)
{
	system("cls");
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		if (i == index1)
			RED;
		else if (i == index2)
			BLUE;
		else
			WHITE;
		for (int j = 0; j < Array[i]; j++)
			printf("▩");
		printf("\n");
	}
	if (StartTime != -1)
	{
		WHITE;
		printf("\n걸린 시간 : %.4f초", (clock() - StartTime) / 1000.0f);
	}
	Sleep(PRINT_DELAY);//0.2초
}

void Swap(int* Num1, int* Num2)
{
	int tmp = *Num1;
	*Num1 = *Num2;
	*Num2 = tmp;
}

void Shuffle(int Array[ARRAY_MAX])
{
	for (int i = 0; i < 1000; i++)
	{
		int index1 = rand() % ARRAY_MAX;//0 ~ 9
		int index2 = rand() % ARRAY_MAX;
		Swap(&Array[index1], &Array[index2]);
	}
}

void SelectSort(int Array[ARRAY_MAX], int StartTime)
{
	for (int i = 0; i < ARRAY_MAX - 1; i++)
	{
		for (int j = i + 1; j < ARRAY_MAX; j++)
		{
			PrintArray(Array, i, j, StartTime);
			if (Array[i] > Array[j])
			{
				Swap(&Array[i], &Array[j]);
				PrintArray(Array, i, j, StartTime);
			}
		}
	}
}

void PrintArray_Insert(int Array[ARRAY_MAX], int index, int Temp, int StartTime)
{
	system("cls");
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		if (i == index)
			BLUE;
		else
			WHITE;
		for (int j = 0; j < Array[i]; j++)
			printf("▩");
		printf("\n");
	}
	printf("\n\n");
	RED;
	for (int i = 0; i < Temp; i++)
		printf("▩");
	if (StartTime != -1)
	{
		WHITE;
		printf("\n\n걸린 시간 : %.4f초", (clock() - StartTime) / 1000.0f);
	}
	Sleep(PRINT_DELAY);//0.2초
}

void InsertSort(int Array[ARRAY_MAX], int StartTime)
{
	for (int i = 1; i < ARRAY_MAX; i++)
	{
		int Temp = Array[i], j;
		for (j = i - 1; j >= 0 && Array[j] > Temp; j--)
		{
			PrintArray_Insert(Array, j, Temp, StartTime);
			Array[j + 1] = Array[j];
			PrintArray_Insert(Array, j, Temp, StartTime);
		}
		PrintArray_Insert(Array, j, Temp, StartTime);
		Array[j + 1] = Temp;
		PrintArray_Insert(Array, j, -1, StartTime);
	}
}

void BubbleSort(int Array[ARRAY_MAX], int StartTime)
{
	for (int i = 0; i < ARRAY_MAX - 1; i++)
	{
		for (int j = 0; j < ARRAY_MAX - i - 1; j++)
		{
			PrintArray(Array, j, j + 1, StartTime);
			if (Array[j] > Array[j + 1])
			{
				Swap(&Array[j], &Array[j + 1]);
				PrintArray(Array, j + 1, j, StartTime);
			}
		}
	}
}

void PrintArray_Merge(int Array[ARRAY_MAX], int left, int mid, int right, int StartTime)
{
	system("cls");
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		if (i >= left && i <= mid)
			RED;
		else if (i >= mid + 1 && i <= right)
			BLUE;
		else
			WHITE;
		for (int j = 0; j < Array[i]; j++)
			printf("▩");
		printf("\n");
	}
	if (StartTime != -1)
	{
		WHITE;
		printf("\n걸린 시간 : %.4f초", (clock() - StartTime) / 1000.0f);
	}
	Sleep(PRINT_DELAY);//0.2초
}

void Merge(int Array[ARRAY_MAX], int left, int mid, int right)
{
	int LeftIndex = left;
	int RightIndex = mid + 1;
	int TempArray[ARRAY_MAX] = { 0 };
	int index = 0;
	while (LeftIndex <= mid && RightIndex <= right)
	{
		if (Array[LeftIndex] <= Array[RightIndex])
			TempArray[index++] = Array[LeftIndex++];
		else
			TempArray[index++] = Array[RightIndex++];
	}
	if (LeftIndex > mid)
	{
		while (RightIndex <= right)
			TempArray[index++] = Array[RightIndex++];
	}
	else
	{
		while (LeftIndex <= mid)
			TempArray[index++] = Array[LeftIndex++];
	}
	int size = right - left + 1;
	for (int i = 0; i < size; i++)
	{
		Array[left + i] = TempArray[i];
	}
}

void MergeSort(int Array[ARRAY_MAX], int left, int right, int StartTime)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(Array, left, mid, StartTime);
	MergeSort(Array, mid + 1, right, StartTime);

	PrintArray_Merge(Array, left, mid, right, StartTime);
	Merge(Array, left, mid, right);
	PrintArray_Merge(Array, left, mid, right, StartTime);
}

void PrintArray_Quick(int Array[ARRAY_MAX], int low, int high, int pivot, int StartTime)
{
	system("cls");
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		if (i == low)
			RED;
		else if (i == high)
			BLUE;
		else if (i == pivot)
			PUPPLE;
		else
			WHITE;
		for (int j = 0; j < Array[i]; j++)
			printf("▩");
		printf("\n");
	}
	if (StartTime != -1)
	{
		WHITE;
		printf("\n걸린 시간 : %.4f초", (clock() - StartTime) / 1000.0f);
	}
	Sleep(PRINT_DELAY);//0.2초
}

int Patition(int Array[ARRAY_MAX], int left, int right, int StartTime)
{
	int low = left;
	int high = right - 1;
	int pivot = right;
	PrintArray_Quick(Array, low, high, pivot, StartTime);
	while (low <= high)
	{
		while (Array[low] <= Array[pivot] && low < right)
			low++;
		while (Array[high] >= Array[pivot] && high >= left)
			high--;
		if (low <= high)
			Swap(&Array[low], &Array[high]);
	}
	Swap(&Array[low], &Array[pivot]);
	PrintArray_Quick(Array, left, right, low, StartTime);
	return low;
}

void QuickSort(int Array[ARRAY_MAX], int left, int right, int StartTime)
{
	if (left >= right)
		return;
	int pivot = Patition(Array, left, right, StartTime);
	QuickSort(Array, left, pivot - 1, StartTime);
	QuickSort(Array, pivot + 1, right, StartTime);

}

void main()
{
	srand(time(NULL));
	//Sleep(3000);//프로그램을 ms 단위로 잠시 멈춰주는 기능(1000 : 1초)

	int Array[ARRAY_MAX];
	for (int i = 0; i < ARRAY_MAX; i++)
		Array[i] = i + 1;
	while (TRUE)
	{
		Shuffle(Array);
		PrintArray(Array, -1, -1, -1);
		printf("\n\n1.SelectSort  2.InsertSort  3.BubbleSort  4.MergeSort  5.QuickSort\n");
		switch (getch())//키보드 입력함수( 키보드 입력할때까지 대기하려는 목적)
		{
		case '1':
			SelectSort(Array, clock());
			break;
		case '2':
			InsertSort(Array, clock());
			break;
		case '3':
			BubbleSort(Array, clock());
			break;
		case '4':
			MergeSort(Array, 0, ARRAY_MAX - 1, clock());
			break;
		case '5':
			QuickSort(Array, 0, ARRAY_MAX - 1, clock());
			break;
		case ESC:
			return;
		}
		getch();
	}
}