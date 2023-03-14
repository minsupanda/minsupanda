#include<stdio.h>

void main()
{
	int Num;
	printf("세로 입력 : ");
	scanf("%d", &Num);
	for (int y = 0; y <= Num + 1; y++)
	{
		for (int x = 0; x <= Num * 2; x++)
		{
			if (y == 0 || y == Num + 1)
				printf("★");
			else if (x == 0)
				printf("★");
		}
		if(0 < y && y <= Num)
		{
			for (int a = 1; (y+1) + a < Num + 2; a++)
			{
				printf("  ");
			}
			for (int b = 1; b <= Num * 2 + 1; b++)
			{
				if (b <= y + (y-1))
					printf("★");
				if (b > Num+1 + y)
					printf("  ");
				if (b == Num * 2 + 1)
					printf("★");
			}
		}
		printf("\n");
	}
	return;
}
