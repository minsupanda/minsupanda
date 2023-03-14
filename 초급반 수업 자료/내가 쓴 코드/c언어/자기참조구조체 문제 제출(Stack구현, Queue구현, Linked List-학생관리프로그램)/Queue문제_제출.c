#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#define PROGRESS 1

typedef struct Queue
{
	int Data;
	struct Queue* Link;
}Queue;

Queue* Enqueue(Queue* node);
Queue* Dequeue(Queue* Front, Queue* Rear);

void Menu()
{
	printf("===Stack System===\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Exit\n");
	printf("==================\n");
	printf("입력 : ");
}

Queue* Enqueue(Queue* node)
{
	Queue* NewNode = (Queue*)malloc(sizeof(Queue));
	printf("데이터 입력 : ");
	scanf("%d", &NewNode->Data);
	NewNode->Link = NULL;
	if (node != NULL)
		node->Link = NewNode;
	return NewNode;
}

Queue* Dequeue(Queue* Front, Queue* Rear)
{
	if (Front == NULL)
	{
		printf("삭제할 데이터가 없습니다.\n");
		return Front;
	}
	printf("Front : %d\tRear : %d\n", Front->Data, Rear->Data);
	Queue* DeleteNode = Front;
	Front = Front->Link;
	free(DeleteNode);
	return Front;
}

void main()
{
	Queue* Front = NULL;
	Queue* Rear = NULL;
	while (PROGRESS)
	{
		int Select;
		system("cls");
		Menu();
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			if (Front == NULL)
			{
				Front = Enqueue(Front);
				Rear = Front;
			}
			else
				Rear = Enqueue(Rear);
			printf("Front : %d\tRear : %d\n", Front->Data, Rear->Data);
			system("pause");
			break;
		case 2:
			Front = Dequeue(Front, Rear);
			if (Front == NULL)
				Rear = NULL;
			system("pause");
			break;
		case 3:
			while (Front != NULL)
				Front = Dequeue(Front, Rear);
			return;
		}
	}
}