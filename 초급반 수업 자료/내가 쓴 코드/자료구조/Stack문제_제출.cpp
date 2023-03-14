#include<stdio.h>
#include<Windows.h>
#include<stack>
#define TURE 1


void main()
{
	std::stack<int> stack;
	while (1)
	{
		system("cls");
		printf("====Stack System====\n");
		printf("1. Push\n");
		printf("2. Pop\n");
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
			stack.push(Num);
			break;
		case 2:
			if (stack.empty() == TURE)
				break;
			stack.pop();
			break;
		case 3:
			while (!stack.empty())
				stack.pop();
			return;
		}
	}
}
