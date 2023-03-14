#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

typedef struct Point
{
	int number; // 추가되는 메모리 구분?
	int x, y; // X,Y좌표
	struct Point* Next; // 다음 추가될 X,Y좌표
}Point;

void Menu(int icount)
{
	printf("좌표 갯수 = %d\n", icount);
	printf("1. 좌표 추가\n");
	printf("2. 좌표 보기\n");
	printf("3. 종료\n");
	printf("입력 = ");
}

void Release(Point* Node)
{
	if (Node == NULL)
		return;
	//동적할당으로 메모리를 받은 메모리만 까지만 접근하기 위해
	Release(Node->Next);

	printf("%d번째 좌표 메모리 해제\n", Node->number);
	free(Node);
	//재귀함수가 돌아가는 지점에 메모리 해제
}

Point* Insert(Point* pt, int count)
{
	if (pt == NULL)
	{
		pt = (Point*)malloc(sizeof(Point));
		//구조체의 크기만큼 메모리 동적할당 (Next 구조체에만 메모리를 할당하면 되기 때문에 구조체의 크기만큼만 메모리를 할당하면 된다.)
		printf("x = ");
		scanf("%d", &pt->x);
		printf("y = ");
		scanf("%d", &pt->y);
		pt->number = count;
		//추가되는 메모리 구분?
		pt->Next = NULL;
		//다음 좌표를 쓸지 안쓸지는 아직 모르지만 NULL값으로 초기화 해둠( 초기화 하지 않으면 쓰레기값 들어가있고 NULL값을 기준으로 메모리를 해제할 것이기 때문)
	}
	else
		pt->Next = Insert(pt->Next, count);
	 // NULL값이 들어간 구조체에 마지막 Next구조체에 연결하면서 메모리 할당
	return pt;

}

void Print(Point* pt)
{
	if (pt == NULL)
		return;
	printf("%d번째 좌표\nx = %d\ny = %d\n", pt->number, pt->x, pt->y);
	printf("==============================\n\n");
	Print(pt->Next);
}

void main()
{
	int icount = 0;
	int num;
	Point* pt = NULL;
	while (1)
	{
		system("cls");
		Menu(icount);
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			icount++;
			pt = Insert(pt, icount);
			break;
		case 2:
			Print(pt);
			system("pause");
			break;
		case 3:
			Release(pt);
			return;
		}
	}
}