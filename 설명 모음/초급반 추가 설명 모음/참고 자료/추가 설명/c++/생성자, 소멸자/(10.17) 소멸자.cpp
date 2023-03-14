#include<iostream>
using namespace std;
class Con
{
public:
	Con()
	{
		cout << "생성자 호출" << endl;
	}
	~Con()
	{
		cout << "소멸자 호출" << endl;
	}
};

void main()
{
	Con c;
	c.~Con();
	// 이런식으로 소멸자는 사용자가 호출이 가능하다,
	// 소멸자는 해당 class가 선언되는 지역이 종료될 때 호출되는 특수한 함수로 그냥 지역이 끝나는 시점에 자동으로 호출되는 것이다.
	// 즉, 메모리를 해제하거나 그런 권한이 있는것이 아니므로 -Con 함수는 2번 실행되는 것
	// 정리하면, 생성자는 해당 자신이 속한 class를 변수가 선언할 때 그 시점에 생성되는 것 ( 메모리를 할당하거나 그런 권한이 있는 것이 아님)
	// 소멸자는 자신이 속한 class를 선언한 변수가 속한 지역이 종료될 때 자동으로 호출되는 것
	cout << "Hello" << endl;
}