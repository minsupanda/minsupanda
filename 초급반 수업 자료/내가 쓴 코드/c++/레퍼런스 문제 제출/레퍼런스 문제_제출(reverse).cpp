#include<iostream>
#include <algorithm>
#include <string>
// reverse �Լ��� string �ȿ��� ������ ���� ����� �� algorithm�� include�ؼ� ����Ѵ�
// ����Ʈ �Ű������� ���۷����� ������� ���Ѵ�.  => ������ó�� �ּҸ� ����ϴ� ���̱� ����
// �������ó�� ������ ������ �� ������ ����� ���� �ִ�.

void BigNum(int _iNum1, int _iNum2, int& _iAnswer)
{
	if (_iNum1 >= _iNum2)
		_iAnswer = _iNum1;
	else
		_iAnswer = _iNum2;
}

void Sum(int _iNum1, int& _iAnswer)
{
	int iDefaultNum = _iNum1;
	while (_iNum1 <= 100)
	{
		_iAnswer += _iNum1;
		_iNum1 += iDefaultNum;
	}
}

void Reverse(int _iNum1, int& _iAnswer)
{
	std::string strReverseNum = std::to_string(_iNum1);
	std::reverse(strReverseNum.begin(), strReverseNum.end());
	_iAnswer = std::stoi(strReverseNum);
}


void main()
{
	int iNum1;
	int iNum2;
	int iAnswer = 0;

	std::cout << "1������ ���� 2���� �Է� : ";
	std::cin >> iNum1 >> iNum2;
	BigNum(iNum1, iNum2, iAnswer);
	std::cout << iNum1 << "��" << iNum2 << "�� ū ���� : " << iAnswer << std::endl << std::endl;

	iAnswer = 0;

	std::cout << "2������ ���� �ϳ� �Է� : ";
	std::cin >> iNum1;
	Sum(iNum1, iAnswer);
	std::cout << "1 ~ 100 ���� " << iNum1 << "����� ���� : " << iAnswer << std::endl << std::endl;

	iAnswer = 0;

	std::cout << "3������ ���� �ϳ� �Է� : ";
	std::cin >> iNum1;
	Reverse(iNum1, iAnswer);
	std::cout << iNum1 << "�� �Ųٷ� �� : " << iAnswer;
}