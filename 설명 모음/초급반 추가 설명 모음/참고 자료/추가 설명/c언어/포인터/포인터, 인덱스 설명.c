#include<stdio.h>

void main()
{
	int Num;
	int Num2 = 10;
	int NumArray[3] = { 1,2,3 };

	printf("Num2 = %d\n", Num2);
	NumArray[3] = 20;
	//�̷������� �迭 ����� �ּҰ� ��Ģ������ ��������� ������ ������ �ε����� ������ ����� �ǵ����� ���� ���� ���� �Ǳ� �����̴�.
	printf("Num2 = %d\n", Num2);
	printf("Num = %p\n", &Num);
	printf("Num2 = %p\n", &Num2);
	for (int i = 0; i <= 3; i++)
	{
		printf("NumArray[%d] = %p", i, &NumArray[i]);
		printf("%d\n", NumArray[i]);
	}
}