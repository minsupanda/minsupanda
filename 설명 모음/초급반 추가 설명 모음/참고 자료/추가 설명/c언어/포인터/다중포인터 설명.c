#include<stdio.h>

void main()
{

	int Num = 10;
	int* pNum = &Num;
	// int *pNum = pNum은 int형의 주소를 저장할 수 있는 변수야!
	int** ppNum = &pNum; // pNum 얘의 주소를 저장한 것
	//int* *ppNum = ppNum은 int*형의 주소를 저장할 수 있는 변수야!
	//무조건 별 하나짜리 int형만 저장 가능하다
	int*** pppNum = &ppNum;
	// 별의 갯수가 중요하다
	printf("Num = %d\t&Num = %p\n", Num, &Num);
	printf("*pNum = %d\tpNum = %p \t&pNum = %p\n", *pNum, pNum, &pNum); //Num값, pNum에 저장된 Num의 주소, pNum 본인의 주소
	printf("**ppNum = %d\t*ppNum = %p\tppNum = %p\t&ppNum = %p\n", **ppNum, *ppNum, ppNum, &ppNum);
	printf("***pppNum = %d\t**pppNum = %p\t*pppNum = %p\tpppNum = %p\t&pppNum = %p\n", ***pppNum, **pppNum, *pppNum, pppNum, &pppNum);
}
