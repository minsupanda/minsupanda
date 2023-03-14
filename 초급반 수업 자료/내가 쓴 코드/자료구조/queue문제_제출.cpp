#include<stdio.h>
#include<queue>

void main()
{
	std::queue<int>Queue;
	while (1)
	{
		system("cls");
		printf("====Queue System====\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Exit\n");
		printf("====================\n");
		printf("입력 :");
		int Select;
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			int Num;
			scanf("%d", &Num);
			Queue.push(Num);
			printf("Front : %d Rear : %d", Queue.front(), Queue.back());
			break;
		case 2:
			if (Queue.empty())
				break;
			printf("Front : %d Rear : %d", Queue.front(), Queue.back());
			Queue.pop();
			break;
		case 3:
			return;
		}
	}
}