#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>

#define START_MEMORY 10

typedef struct DynamicArray
{
	int* pArray; // 배열포인터
	int MaxCount; // 최대메모리 크기
	int Count; // 현재 데이터 갯수
}DynamicArray;

void lnitMemory(DynamicArray* dynamicArray)
{
	dynamicArray->pArray = (int*)malloc(sizeof(int) * START_MEMORY);
	//시작메모리만큼 메모리 동적할당
	dynamicArray->MaxCount = START_MEMORY;
	dynamicArray->Count = 0;
}

void CreateMemory(DynamicArray* dynamicArray)
{
	//가변배열 : 기존의 1.2배 ~ 1.5배 증설
	dynamicArray->MaxCount *= 1.5;
	//가변배열의 공간복잡도는 n + 1이다. 하지만 현재 코드는 1.2~1.5배로 하는데 이유는
	// 조금이라도 반복문이 도는 것을 최소화하기 위함이다
	// 가변배열을 만드는 것은 아예 새롭게 배열을 만들고 기존의 배열에 있는 것을 옮기는 것이데 이 과정에서 코드비용소모가 가장 심한것이다
	// 그렇기 때문에 약간 넉넉하게 증설을 하는 것이지만, 이렇게 하면 안쓰는 메모리가 생기고 놀수 있으므로 마냥 장점만은 아니다
	// 그렇다면 1.2~1.5배가 넘어가도록 증설되것 같은 경우에 가변배열이 아닌 다른 자료구조를 쓰는 것인가?
	// 아님, 시간복잡도와 공간복잡도를 고려해서 배열에 자주 접근할 것 같은 경우에는 시간복잡도가 좋은것을, 증설혹은 해제를 자주 할 것 같은 경우는 공간복잡도가 좋은것을
	// 가변배열은 시간복잡도가 가장 좋은 자료구조이기 때문에 배열에 자주 접근할 것 같은 경우에 활용
	// Ex. 맵에서 몬스터가 잡히고 새롭게 만들어지고 이런경우는 공간복잡도가 좋은경우, 맵에 들어가면 100마리의 몬스터가 생기고 껏다 다시들어올때 다시 100마리 생기는 것은 시간 복잡도가 좋은 것을 활용
	int* NewArray = (int*)malloc(sizeof(int) * dynamicArray->MaxCount);
	//새로운 배열을 아예 새로 만들어서 증설된 크기만큼 새로 메모리 공간 할당

	for (int i = 0; i < dynamicArray->Count; i++) // 지금까지 저장된 값만 옮기는 것
		NewArray[i] = dynamicArray->pArray[i];

	free(dynamicArray->pArray); // 기존의 메모리 해제
	dynamicArray->pArray = NewArray; // 새로 증설된 배열을 다시 넣어줌
}

void AddDate(DynamicArray* dynamicArray)
{
	if (dynamicArray->Count >= dynamicArray->MaxCount) // 모든 데이터가 다 옮겨졌을 때
	{
		CreateMemory(dynamicArray);
		printf("\n이사완료\n");
	}
	dynamicArray->pArray[dynamicArray->Count++] = rand() % 100 + 1;
	//포인터를 배열처럼 활용해서 해당인덱스로 접근해 임의의 숫자를 넣어주는 것
	//CreateMemory함수로 만들어진 공간에도 숫자 넣어줌
}

void PrintDate(DynamicArray dynamicArray)
{
	for (int i = 0; i < dynamicArray.Count; i++)
		printf("%4d", dynamicArray.pArray[i]);
	printf("\n");
}

void LeftMoveDate(DynamicArray* dynamicArray, int i)
{
	int max = dynamicArray->Count - 1; // 마지막 인덱스까지 반복문돌리기 위함
	//마지막 인덱스에서 삭제시킬 데이터와 같게 나오면 다음 인덱스는 쓰레기값이 있으니 그냥 출력만 안되는 것
	for (; i < max; i++) // 삭제시킬 데이터값이 있는 인덱스부터 시작
	{
		dynamicArray->pArray[i] = dynamicArray->pArray[i + 1]; // 삭제시킬 데이터값이 있는 인덱스부터 오른쪽에 있는 값을 덮어씌움
	}
}

void DeleteDate(DynamicArray* dynamicArray, int Date)
{
	for (int i = 0; i < dynamicArray->Count; i++)
	{
		if (dynamicArray->pArray[i] == Date) // 삭제시킬 데이터값과 같으면
		{
			LeftMoveDate(dynamicArray, i);
			--dynamicArray->Count; // 현재 데이터 갯수 한개 감소
			break;
		}
	}
}
void main()
{
	srand(time(NULL));
	DynamicArray dynamicArray;
	lnitMemory(&dynamicArray);

	for (int i = 0; i < 20; i++) // 20은 최대로 만들 메모리 갯수
		AddDate(&dynamicArray);
	//Max는 22, count는 20이면 할당받은 메모리에 아직 빈공간이 있는건가? 구조체의 크키 * 2만큼의 메모리 공간이?
	PrintDate(dynamicArray);
	DeleteDate(&dynamicArray, 30);// 30은 그냥 삭제시키고 싶은 숫자
	PrintDate(dynamicArray);

	free(dynamicArray.pArray);
}