#include<iostream>
#include<string>
using namespace std; // std::을 생략시켜준다.

void main()
{
	string str = "Hello";
	// string : character형 배열을 기반으로 만들어지고, 자료형이 string인 변수는 character형 배열이 만들어지게 된다
	// 이렇게 만들어진 배열에 여러가지로 활용할 수 있는 기능이 내장되어있다? 
	// str이라는 string변수가 만들어지고 이 안에 문자열 배열이 만들어져있는 것
	char* arr = (char*)str.c_str();
	// 얕은복사이므로 주소를 받아야 한다
	// (char*) 형변환 이유 : c_str()이 해당 문자열의 시작주소를 반환하는 함수인데 char형이 아닌 const char*형을 반환하게 된다
	// 그러므로 arr의 자료형인 char*형에 맞춰 형변환해줘야 하거나 애초부터 arr의 자료형의 const char*으로 만들어주어야 한다.
	cout << "str = " << str << endl;
	cout << "arr = " << arr << endl;
	str = "Bye";
	// string에서의 operator= : strcpy의 기능과 동일하다
	// operator= : 대입연산자 (=)에 어떤 기능을 추가시키겠다는 것으로 자신이 추가할 수도 있다.
	// 대입연산자(=)에 기능을 추가시킨 것으로 Bye라는 문자열을 str 문자열에 복사한다는 것이다.
	cout << "str = " << str << endl;
	cout << "arr = " << arr << endl;
	return;
}