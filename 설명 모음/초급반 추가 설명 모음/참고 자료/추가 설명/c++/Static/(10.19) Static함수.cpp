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
		// this �����͵� ����.
		// this; �ϸ� ��������.
		// Static �Լ��ȿ����� Static ������ ����� �����ϴ�.
	}
};

int A::count = 0;

void main()
{
	A a1;
	// A::Print() �� ȣ���� ����������
	// A::Num()�� ȣ���� �Ұ����ϴ� -> ���⼭ ȣ���ϸ� ���� � ������Ʈ�� ȣ���ߴ��� �𸣱⶧��
	A a2;
	A::count = 10;
	A a3;
	A a4;
	A a5;
	a5.Print();
}