#include<iostream>
using namespace std;

class A
{
public:
	static int count;
	// 여기는 저 전역변수가 A꺼야라고 한번더 알려주는 것
	A()
	{
		cout << ++count << endl;
	}
};

int A::count = 0;
// 여기서 진짜 전역변수 처럼 cpp파일에 선언해줘야한다.
// 없으면 오류남
// 

void main()
{
	// 여기서 private에 변수가 있으면 오브젝트장 존재하지만 static은 하나만 존재한다.
	// 그러힉 때문에 오브젝트가 늘면서 전역변수가 늘어난다는 것은 말도 안되므로 밖에서 선언하는 것
	// 전역변수는 동일한 것이 여러개 존재할 수 없기 때문
	A a1;
	A a2;
	A a3;
	A::count = 10;
	A a4;
	A a5;
}