#include <iostream>
#include <functional>
using namespace std;

void Add(int a, int b, int c)
{
	cout << a << " + ";
	cout << b << " - ";
	cout << c << " = ";
	cout << a + b + c << endl;
}

void FuncTest1(function<void()> _Func)
{
	_Func();
}

void FuncTest2(function<void(int)> _Func)
{
	_Func(15);
}

void FuncTest3(function<void(int, int)> _Func)
{
	_Func(15, 20);
}

void main()
{
	FuncTest1(bind(Add, 1, 2, 3));
	FuncTest2(bind(Add, 1, 2, placeholders::_1));
	// �÷��̽�Ȧ�� ���� ���ڴ� �ش� �Լ������ͷ� ȣ���ϴ� �Լ��� ������ ���� -> ������ ������ ����
	FuncTest3(bind(Add, 1, placeholders::_2, placeholders::_1));
}
