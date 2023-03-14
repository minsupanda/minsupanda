#include<stdio.h>
#define SIZE 10
void main()
{
	int Num[SIZE], Big = 0, Sum = 0, count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		printf("[%d]번째 정수 입력 : ", i + 1);
		scanf("%d", &Num[i]);
		if (i == 0 || Big <= Num[i])
			Big = Num[i];
		Sum += Num[i];
	}
	printf("최대값 = %d  총합 = %d  평균 = %.3f", Big, Sum, (float)Sum / SIZE);
}