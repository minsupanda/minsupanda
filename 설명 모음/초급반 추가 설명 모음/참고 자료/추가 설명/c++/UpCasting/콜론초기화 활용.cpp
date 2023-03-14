#include<iostream>
#include<vector>
using namespace std;

#define MAMMAL_COUNT 30

class Parent
{
private:
	int m_iParentDate;
public:
	Parent()
	{
		m_iParentDate = 1;
	}
	Parent(int _iDate)
	{
		m_iParentDate = _iDate;
	}
	void PrintDate()
	{
		cout << "ParentaDate : " << m_iParentDate << endl;
	}
};

class Child : public Parent
{
private:
	int m_iChildDate;
public:
	Child()
	{ // 여기에 부모 생성자를 호출하는 과정이 있는것 => 즉, 먼저 호출되는 것은 자식 Class가 맞는 것이다
		m_iChildDate = 1;
	}
	Child(int _iDate) : Parent(_iDate) // 콜론초기화를 하면서 부모의 어떤 생성자를 호출할 것인지 결정하는 것
	{
		m_iChildDate = _iDate;
	}
	Child(int _iParentDate, int _iChildDate) : Parent(_iParentDate)
	{
		m_iChildDate = _iChildDate;
	}
	void PrintDate()
	{
		Parent::PrintDate();
		cout << "ChildDate : " << m_iChildDate << endl;
	}
};

void main()
{
	Child child1;
	cout << "child1" << endl;
	child1.PrintDate();
	cout << "========================" << endl;

	Child child2(2);
	cout << "child2" << endl;
	child2.PrintDate();
	cout << "========================" << endl;

	Child child3(3,4);
	cout << "child3" << endl;
	child3.PrintDate();
	cout << "========================" << endl;
}