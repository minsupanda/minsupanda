#include<iostream>
using namespace std;

class A
{
private:
	const int m_iNum1;
	// 현재 하고 싶은 기능이  const int m_iNum1 = Num1을 하고 싶음
	// const 변수는 선언과 동시에 초기화를 해야하므로 오류가 뜨게 된다.
	// ********** 호출되는 순서가 중요함 ****************
	// class를 호출하게 되면 맴버변수가 초기화 되고 생성자가 호출되는 순서이므로 바로 Num1 값을 넣고 싶어도 넣지 못하는 것
	// 이를 해결하기 위한 방법이 콜론 초기화이고 이런 목적으로 대게 사용이 된다.
	int m_iNum2;
public:
	A(int Num1, int Num2) : m_iNum1(Num1)
	{
		m_iNum2 = Num2;
	}
	void print()
	{
		cout << "const int m_iNum1 = " << m_iNum1 << endl;
		cout << "int m_iNum2 = " << m_iNum2 << endl;
	}
};

void main()
{
	A a(10, 20);
	a.print();
}