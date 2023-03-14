#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

#define ASC 1



void Absorption(int* NumArr, int left, int right, int mid, int Type)
{
	int* TmpArr = new int[right - left + 1];
	// right - left 일떄 뜨는 오류
	// 메모리 해제 시 오류가 뜸
	// heap corruption detected : after Normal block at 메모리 주소
	// 1. 해당 메모리 주소를 해제 시킨적이 없냐 -> 이미 해제시킨 메모리 주소를 또해제하려 할때
	// 2. 인덱스를 사용할 때 허용된 인덱스를 초과한 범위 0보다 작거나 설정한 인덱스 초과할 때 메모리 오류가 뜨는 것
	// 2번의 사항에 해당하는 것 : 동적할당으로 메모리 할당 시 인덱스 범위가 하나 적었기 떄문

	int leftindex = left;
	int rightindex = mid + 1;
	int i = 0;

	while (leftindex <= mid && rightindex <= right)
	{
		if (NumArr[leftindex] <= NumArr[rightindex] && Type == ASC)
			TmpArr[i++] = NumArr[leftindex++];
		else
			TmpArr[i++] = NumArr[rightindex++];
	}

	if (leftindex > mid)
	{
		while (rightindex <= right)
			TmpArr[i++] = NumArr[rightindex++];
	}

	else
	{
		while (leftindex <= mid)
			TmpArr[i++] = NumArr[leftindex++];
	}

	for (int i = 0; i <= right - left; i++)
		NumArr[left + i] = TmpArr[i];

	delete[]TmpArr;
}

void Sort(int* NumArr, int left, int right, int Type)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	Sort(NumArr, left, mid, Type);
	Sort(NumArr, mid + 1, right, Type);
	Absorption(NumArr, left, right, mid, Type);
}

void Print(int* NumArr, int size)
{
	cout << "==================" << endl;
	for (int i = 0; i < size; i++)
		cout << i + 1 << "번째 정수 : " << NumArr[i] << endl;
	cout << "==================" << endl << endl;
}

void main()
{
	srand(time(NULL));

	int size;
	int* NumArr;
	cout << "배열의 크기 설정 : ";
	cin >> size;
	NumArr = new int[size];

	for (int i = 0; i < size; i++)
		NumArr[i] = rand() % 100 + 1;

	cout << "오름차순 정렬 전" << endl;
	Print(NumArr, size);

	Sort(NumArr, 0, size - 1, ASC);

	cout << "오름차순 정렬 후" << endl;
	Print(NumArr, size);

	delete[]NumArr;
	system("pause");
}