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
	{ // ���⿡ �θ� �����ڸ� ȣ���ϴ� ������ �ִ°� => ��, ���� ȣ��Ǵ� ���� �ڽ� Class�� �´� ���̴�
		m_iChildDate = 1;
	}
	Child(int _iDate) : Parent(_iDate) // �ݷ��ʱ�ȭ�� �ϸ鼭 �θ��� � �����ڸ� ȣ���� ������ �����ϴ� ��
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