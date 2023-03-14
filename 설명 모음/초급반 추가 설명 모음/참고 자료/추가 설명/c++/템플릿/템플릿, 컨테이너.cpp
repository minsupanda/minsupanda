#include <iostream>
#include <string>

template <typename val>
void func(val v)
{
	std::cout << "Template Function \t" << v << std::endl;
}

template<> // ���ø��� �����ε� ����
void func<char>(char v)
{
	std::cout << "Speciallzaiton Template Function \t" << v << std::endl;
}

void main()
{
	func(10);
	func(10.1);
	func(0x10);
	func('a');
	func("abcd");
}

template <typename t1, typename t2>
t1 func(t2 num)
{
	std::cout << num << std::endl;
	return num;
}

void main()
{
	double su = 10.2;
	//func(su); // t1�� �μ��� �����ϱ� ������ ������ ���� ���̴�
	std::cout << func<int>(su) << std::endl;
	//<int> : �ٷ� t1 �ڸ��� ���¸� �����ִ� ������ '������'�� ����
	// �׷��� ������ (su)�̷��� �Ű������� �ִ� �ͺ��� <>�� Ȱ���� �ϴ� ���� �� ����ϱ� �Ѵ�.
	// <, , ...>
	// <> : �����̳ʿ��� ��� �������. ��, �����̳ʴ� ���ø��� Ȱ���� �ڷᱸ���̴�.
	// �Ŀ� ���� ���ø��� Ȱ���� �����̳ʸ� ����� �͵� ������ �ȴ�.
}


