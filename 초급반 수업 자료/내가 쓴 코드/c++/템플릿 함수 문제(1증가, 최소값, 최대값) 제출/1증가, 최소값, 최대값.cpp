#include<iostream>
#include<string>

template<typename value>
value Increase(value v)
{
	return  v + 1;	
}

template <>
char Increase<char>(char v)
{
	if (v == 'z')
		return 'a';
	else return v + 1;
}

template<typename value>
value Minimum(value v1 ,value v2)
{
	if (v1 >= v2)
		return v2;
	else
		return v1;
}

template<typename value>
value Maximum(value v1, value v2, value v3)
{
	// �ȿ��� �ڷ����� �ٸ��� ���� �� �ֳ�?
	if (v1 >= v2 && v1 >= v3)
			return v1;
	else if (v2 >= v1 && v2 >= v3)
			return v2;
	else return v3;
}

void main()
{
	int iParameter1, iParameter2, iParameter3;
	char chParameter1, chParameter2, chParamter3;
	std::string strParameter1, strParameter2, strParameter3;

	std::cout << "1�� ����" << std::endl;
	std::cin >> iParameter1;
	std::cout << "int ��� : " << Increase(iParameter1) << std::endl;
	std::cin >> chParameter1;
	std::cout << "ch ��� : " << Increase(chParameter1) << std::endl;

	std::cout << "2�� ����" << std::endl;
	std::cin >> iParameter1 >> iParameter2;
	std::cout << "int �ּҰ� : " << Minimum(iParameter1, iParameter2) << std::endl;
	std::cin >> chParameter1 >> chParameter2;
	std::cout << "char �ּҰ� : " << Minimum<char>(chParameter1, chParameter2) << std::endl;
	std::cin >> strParameter1 >> strParameter2;
	std::cout << "string �ּҰ� : " << Minimum<std::string>(strParameter1, strParameter2) << std::endl;

	std::cout << "3�� ����" << std::endl;
	std::cin >> iParameter1 >> iParameter2 >> iParameter3;
	std::cout << "int �ִ밪 : " << Maximum<int>(iParameter1, iParameter2, iParameter3) << std::endl;
	std::cin >> chParameter1 >> chParameter2 >> chParamter3;
	std::cout << "char �ִ밪 : " << Maximum<char>(chParameter1, chParameter2, chParamter3) << std::endl;
	std::cin >> strParameter1 >> strParameter2 >> strParameter3;
	std::cout << "string �ִ밪 : " << Maximum<std::string>(strParameter1, strParameter2, strParameter3) << std::endl;
}
