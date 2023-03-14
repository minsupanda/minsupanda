#include<iostream>
#include <algorithm>
#include <string>
// reverse 함수는 string 안에도 있지만 보통 사용할 때 algorithm을 include해서 사용한다
// 디폴트 매개변수는 레퍼런스에 사용하지 못한다.  => 포인터처럼 주소를 사용하는 것이기 때문
// 멤버변수처럼 뭔가를 참조할 수 있으면 사용할 수도 있다.

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

	std::cout << "1번문제 정수 2개를 입력 : ";
	std::cin >> iNum1 >> iNum2;
	BigNum(iNum1, iNum2, iAnswer);
	std::cout << iNum1 << "과" << iNum2 << "중 큰 수는 : " << iAnswer << std::endl << std::endl;

	iAnswer = 0;

	std::cout << "2번문제 정수 하나 입력 : ";
	std::cin >> iNum1;
	Sum(iNum1, iAnswer);
	std::cout << "1 ~ 100 사이 " << iNum1 << "배수의 합은 : " << iAnswer << std::endl << std::endl;

	iAnswer = 0;

	std::cout << "3번문제 정수 하나 입력 : ";
	std::cin >> iNum1;
	Reverse(iNum1, iAnswer);
	std::cout << iNum1 << "의 거꾸로 수 : " << iAnswer;
}