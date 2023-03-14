#include<stdio.h>
#include<stdlib.h>
#include<time.h>//시간 값 사용하는 헤더파일
#define LOTTO_NUM 6
#define TRUE 1
#define FALSE 0
void main()
{
	int Flag;
	int RNum;
	int Lotto[LOTTO_NUM] = { 0 };
	srand(time(NULL));
	while (1)
	{
		system("cls");
		for (int i = 0; i < LOTTO_NUM; i++)
		{
			do
			{
				Flag = TRUE;
				Lotto[i] = (rand() % 6) + 1; // 반복하면서 계속 값이 변함
				for (int j = 0; j < i; j++)
				{
					if (Lotto[i] == Lotto[j]) // 중복되는 값이 있을 시 Flag = FLASE로 바꿔서 j반복문 중단
					{
						Flag = FALSE;
						break;
					}
				}
			} while (Flag == FALSE); // 중복되는 값이 있으면 do while문 계속 반복돌리면서 반복되지 않을 때 까지 돌림
		}
		for (int i = 0; i < LOTTO_NUM; i++)
			printf("%d.%d\n", i + 1, Lotto[i]);
		system("pause");
	}
}
