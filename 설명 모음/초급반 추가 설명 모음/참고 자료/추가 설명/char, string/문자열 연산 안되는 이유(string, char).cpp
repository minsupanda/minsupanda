#include <iostream>
#include <string>
using namespace std;

template <typename Type>
void Sum(Type su1, Type su2)
{
	Type sum;
	sum = su1 + su2;
	cout << sum << endl;
}
void main()
{
	int a = 1, b = 2;
	Sum(a, b);
	Sum("Ace", "ace");
	// 오류가 뜨는 이유 : const char 형태로 올라가면서 주소에 값을 더하는 것이 되기 때문이다
	std::string str = "asd", str2 = "vec";
	str + str2; // string은 연산자 오버로딩이 되어있기 때문에 가능한 것이다.
	//c언어에서 strcat도 문자열 마지막 찾아서 하나씩 넣는 기능을 언어측에서 해주는 것이기 떄문에 가능한 것
}
