#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#define MAX 6
#define DESC 1
#define ASC 2

void Print(int Arr[MAX]);
void SetArray(int Arr[MAX]);
void Sort(int Arr[MAX], int Type, int left, int right);
void merge(int Arr[MAX], int Type, int left, int right, int mid);
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
		Arr[i] = rand() % 100 + 1;
}

void Sort(int Arr[MAX], int Type, int left, int right)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;
	// 배열을 반으로 쪼개는 작업
	Sort(Arr, Type, left, mid);
	// 왼쪽배열을 먼저 하나의 인덱스만 남을 때 까지 쪼갬
	Sort(Arr, Type, mid + 1, right);  // 2개씩 끊어야하기 때문에 mid(정렬중인 배열의 중앙 + 1 )을 해서 절반으로 인덱스를 나눔
	// 왼쪽배열이 정렬이 끝나고 재귀가 풀리면서 Sort함수에 가장 처음 계산된 mid값을 가지고 재귀함수 시작
	merge(Arr, Type, left, right, mid);
}

void merge(int Arr[MAX], int Type, int left, int right, int mid)
{
	int tmp_arr[MAX] = { 0 };
	int k = 0; // 임시 배열 엔덱스로 사용
	int i = left;
	int j = mid + 1; // mid가 왼쪽배열의 마지막으로 가리키므로 +1을 하면 오른쪽 배열의 시작을 가리키게 된다
	for (i, j; i <= mid && j <= right; k++)
		// 왼쪽배열의 마지막은 mid값이기 때문
		// 마지막 인덱스를 가리키는 right를 넘어가는 것을 방지하기 위함
	{
		if ((Arr[i] <= Arr[j] && Type == ASC) || (Arr[i] >= Arr[j] && Type == DESC))
		{
			tmp_arr[k] = Arr[i];
			i++;
		}
		else
		{
			tmp_arr[k] = Arr[j];
			j++;
		}
		//swap이 아니기 때문에 조건을 각각 걸어서 직접 대입해줘야 한다.
	}

	for (i; i <= mid; i++, k++)
		tmp_arr[k] = Arr[i];
	for (j; j <= right; j++, k++)
		tmp_arr[k] = Arr[j];
	// 위에서 서로 비교하지 않은 인덱스를 대입 -> 즉, 정렬이 필요없는 부분들을 그대로 대입
	// 어차피 정리될고 되고 비교는 가장 작은수 부터 앞에서 시작하므로
	// 마저 이어서 반복문 돌리면 비교되지 않은 인덱스만 남기 때문
	// k도 증가해야 배열에 올바르게 값이 들어가기 때문
	k--;
	//마지막 반복문에서 right값을 넘어서면서 증가되기 때문에 감소히켜줘야함
	for (k; k >= 0; k--)
		Arr[left + k] = tmp_arr[k];
	// 각 값들을 비교해서 바뀐값들을 대입해주고 나머지 값들은 그대로 대입
	// k는 왼쪽, 오른쪽 배열 상관없이 무조건 첫 인덱스부터 저장
	// k는 저장하는 만큼 증가하고 해당 k값만큼 인덱스에 값이 저장된것
	// left를 사용하면 왼쪽배열은 왼쪽배열의 시작을 가리키게되므로
	// left에 k를 더하면 시작부터 인덱스부터 정리가 된 k인덱스까지 접근할 수 있게됨
	// 결과적으로 tmp_arr의 0 ~ k 인덱스에 정리된 값을 Arr의 left ~ k 인덱스에 저장할 수 있게 되는 것
}

void main()
{
	int Number;
	int Arr[MAX] = { 0 };
	int left = 0;
	int right = MAX - 1;

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
			Sort(Arr, ASC, left, right);
			break;
		case 3:
			Sort(Arr, DESC, left, right);
			break;
		case 4:
			return;
		}
	}
}