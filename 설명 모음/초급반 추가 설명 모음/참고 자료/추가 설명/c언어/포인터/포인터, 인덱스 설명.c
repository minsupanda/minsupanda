#include<stdio.h>

void main()
{
	int Num;
	int Num2 = 10;
	int NumArray[3] = { 1,2,3 };

	printf("Num2 = %d\n", Num2);
	NumArray[3] = 20;
	//이런식으로 배열 선언시 주소가 규칙적으로 만들어지기 때문에 선언한 인덱스의 범위를 벗어나면 의도하지 않은 값이 들어가게 되기 때문이다.
	printf("Num2 = %d\n", Num2);
	printf("Num = %p\n", &Num);
	printf("Num2 = %p\n", &Num2);
	for (int i = 0; i <= 3; i++)
	{
		printf("NumArray[%d] = %p", i, &NumArray[i]);
		printf("%d\n", NumArray[i]);
	}
}