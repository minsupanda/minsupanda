#include<stdio.h>

void main()
{

	int Num = 10;
	int* pNum = &Num;
	// int *pNum = pNum�� int���� �ּҸ� ������ �� �ִ� ������!
	int** ppNum = &pNum; // pNum ���� �ּҸ� ������ ��
	//int* *ppNum = ppNum�� int*���� �ּҸ� ������ �� �ִ� ������!
	//������ �� �ϳ�¥�� int���� ���� �����ϴ�
	int*** pppNum = &ppNum;
	// ���� ������ �߿��ϴ�
	printf("Num = %d\t&Num = %p\n", Num, &Num);
	printf("*pNum = %d\tpNum = %p \t&pNum = %p\n", *pNum, pNum, &pNum); //Num��, pNum�� ����� Num�� �ּ�, pNum ������ �ּ�
	printf("**ppNum = %d\t*ppNum = %p\tppNum = %p\t&ppNum = %p\n", **ppNum, *ppNum, ppNum, &ppNum);
	printf("***pppNum = %d\t**pppNum = %p\t*pppNum = %p\tpppNum = %p\t&pppNum = %p\n", ***pppNum, **pppNum, *pppNum, pppNum, &pppNum);
}
