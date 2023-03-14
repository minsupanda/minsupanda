#include<iostream>

void main()
{
	int su1 = 10;
	float su2 = 10.5;
	char arr[10] = "Hello";
	// c언에 비해 간략하게 사용할 수 있다
	// 그러면 소수점 2,3번째 자리 까지 표현만 하는건 불가능?
	// 가능하다 -> 포메팅이라는 헤더파일 추가해서 하면 사용가능
	std::cout << "su1 = " << su1 << std::endl;
	std::cout << "su1 = " << su2 << std::endl;
	std::cout << "su1  + su2 = " << su1 + su2 << std::endl;
	std::cout << arr << std::endl;

	return;
}