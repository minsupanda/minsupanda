#include <iostream>
#include <string>

template <typename val>
void func(val v)
{
	std::cout << "Template Function \t" << v << std::endl;
}

template<> // 탬플릿의 오버로딩 버전
void func<char>(char v)
{
	std::cout << "Speciallzaiton Template Function \t" << v << std::endl;
}

void main()
{
	func(10);
	func(10.1);
	func(0x10);
	func('a');
	func("abcd");
}

template <typename t1, typename t2>
t1 func(t2 num)
{
	std::cout << num << std::endl;
	return num;
}

void main()
{
	double su = 10.2;
	//func(su); // t1의 인수가 부족하기 때문에 오류가 나는 것이다
	std::cout << func<int>(su) << std::endl;
	//<int> : 바로 t1 자리에 형태를 정해주는 것으로 '가독성'이 좋다
	// 그렇기 때문에 (su)이렇게 매개변수로 주는 것보다 <>를 활용해 하는 것을 더 사용하긴 한다.
	// <, , ...>
	// <> : 컨테이너에서 계속 사용했음. 즉, 컨테이너는 템플릿를 활용한 자료구조이다.
	// 후에 직접 템플릿을 활용해 컨테이너를 만드는 것도 도움이 된다.
}


