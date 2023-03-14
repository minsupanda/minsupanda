#include<iostream>
using namespace std;

class A
{
private:
	int Num;
public:
	static int count;
	A()
	{
		Num = 10;
		cout << ++count << endl;
	}
	void Num()
	{

	}
	static void Print()
	{
		cout << "count : " << count << endl;
		//cout << "Num : " << Num << endl;
		// this 포인터도 없다.
		// this; 하면 오류난다.
		// Static 함수안에서는 Static 변수만 사용이 가능하다.
	}
};

int A::count = 0;

void main()
{
	A a1;
	// A::Print() 는 호출이 가능하지만
	// A::Num()은 호출이 불가능하다 -> 여기서 호출하면 누가 어떤 오브젝트가 호출했는지 모르기때문
	A a2;
	A::count = 10;
	A a3;
	A a4;
	A a5;
	a5.Print();
}