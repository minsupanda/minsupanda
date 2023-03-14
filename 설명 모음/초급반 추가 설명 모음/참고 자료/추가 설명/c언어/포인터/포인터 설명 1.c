#include<stdio.h>

void main()
{
	int Num;
	int* pNum = &Num;
	// 포인터 변수 선언시 * 의 의미 : 주소를 저장할 수 있는 변수로 만들어졌다라는 뜻
	*pNum = 10;
	// 변수 선언 후 *의 의미 : 해당 포인터 변수에 저장된 주소를 따라가라는 뜻
	printf("Num의 주소 = %p\n", &Num);
	printf("pNum이 가지고 있는 값 = %p\n", pNum);
	// 주소값이라는 정수와, 문자열을 저장했으므로 p말고도 출력할 수 있지 않나? -> 10,16진수로 출력해보기
	printf("pNum이 가지고 있는 값 = %x\n", pNum); // 16진수로 출력 -> 16진수이므로 0이 앞자리에 있으면 생략되고 출력
	printf("pNum이 가지고 있는 값 = %d\n", pNum); // 10진수로 출력 -> 10진수는 10진수로 바꿔서 출력
	printf("Num = %d\n", Num);
	printf("*pNum = %d\n", *pNum);
	printf("*pNum의 주소 = %p\n", &pNum); // 포인터 변수도 변수이니 자신의 주소값이 따로 있다.
}