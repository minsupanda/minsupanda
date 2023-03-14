#include<iostream>
#include<string>
using namespace std;

class test
{
private:
	string m_strname;
public:
	void SetName(string _name)
	{
		m_strname = _name;
	}
	void PrintAddress()
	{
		cout << "PrintAddress()" << endl;
		cout << m_strname << " : " << this << endl;
		// 여기서 호출된 name은 어떤 객체가 호출한 것인지 알 수 없음
		// this는 이 class를 호출한 객체인 나를 의미하는 것
	}
};

void main()
{
	test t1, t2; // 설계도
	t1.SetName("t1"); // 오브젝트
	t2.SetName("t2");
	// 값이 대입된 t1, t2를 인스턴스.
	cout << "main()" << endl;
	cout << "t1 : " << &t1 << endl;
	t1.PrintAddress();

	cout << "main()" << endl;
	cout << "t2 : " << &t2 << endl;
	t2.PrintAddress();
}