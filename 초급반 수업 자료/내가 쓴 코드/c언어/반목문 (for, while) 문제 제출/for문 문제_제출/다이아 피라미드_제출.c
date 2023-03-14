#include<stdio.h>

void main()
{
	int Num;
	printf("세로 입력 : ");
	scanf("%d", &Num);;

	for (int y = 0; y <= Num * 2 + 2; y++)
	{
		for (int x = 0; x <= Num * 2; x++)
		{
			if (y == 0 || y == Num * 2 + 2)
				printf("★");
			else if (x == 0)
				printf("★");
			if (y > 0 && y <= Num)
			{
				if (x + (y+1) <= Num || x >= Num + (y+1))
					printf("  ");
				if (x + y == Num + 1 || x - y == Num - 1)
					printf("★");
				if (y > 1 && 2 <= x && x <= Num * 2 - 2)
				{
					if (x + y > Num + 1 && x - y < Num - 1)
						printf("  ");
				}
				if (x == Num * 2)
					printf("★");
			}
			if (y == Num + 1 && x > 0 && x <= Num * 2)
			{
				if (x == Num * 2)
					printf("★");
				else
					printf("  ");
			}
			if (y >= Num + 2 && y < Num * 2 + 2)
			{
				if ((y-1) - x >= Num + 2 || x+(y-1) >= Num * 3 + 2)
					printf("  ");
				if (x + y == Num * 3 + 1 || y - x == Num + 1)
					printf("★");
				if (y < Num * 2 + 1 && 2 <= x && x <= Num * 2 - 2)
				{
					if (x + y <= Num * 3 && y - x <= Num )
						printf("  ");
				}
				if (x == Num * 2)
					printf("★");
			}
		}
		printf("\n");
	}
	return;
}