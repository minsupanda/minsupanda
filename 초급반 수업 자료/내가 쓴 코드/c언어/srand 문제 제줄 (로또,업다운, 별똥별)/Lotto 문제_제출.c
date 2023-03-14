#include<stdio.h>
#include<stdlib.h>
#include<time.h> // 시간 값을 사용하능 헤더파일
#define LOTTO_NUM 6
#define FALSE 0
#define TURE 1

void main()
{
	int Lotto_Num[LOTTO_NUM] = { 0 };
	srand(time(NULL));
	while (1)
	{
		for (int i = 0; i < LOTTO_NUM; i++)
		{
			int Overlap = FALSE;
			Lotto_Num[i] = (rand() % 45) + 1;
			for (int j = 0; j <= i - 1; j++)
			{
				if (Lotto_Num[j] == Lotto_Num[i])
				{
					i--;
					Overlap = TURE;
				}
			}
			if (Overlap == FALSE)
				printf("%d. %d\n", i + 1, Lotto_Num[i]);
		}
		system("pause");
	}
}



