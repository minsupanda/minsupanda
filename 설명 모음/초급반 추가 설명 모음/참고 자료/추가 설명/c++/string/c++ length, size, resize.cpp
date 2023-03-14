#include<iostream>
#include<string>
using namespace std; // std::을 생략시켜준다.

void main()
{
	string s1;
	string s2 = "123";
	string s3 = "Hello";
	string s4 = "안녕하세요";
	cout << "s1 = " << s1.length() << endl;
	cout << "s2 = " << s2.length() << endl;
	cout << "s3 = " << s3.length() << endl;
	//length : 문자열의 byte크기 = 배열의 크기
	s4.resize(100);
	//string은 기본적으로 가변배열으로 저장되는 문자열에 따라 알아서 줄어들고 늘어나게됨
	//가변배열은 새로운 배열을 만들어서 늘리거나 줄이므로 애초에 다른 데이터를 침범하지 않게 된다
	//resize를 통해 해당 문자열의 크기를 재조정할 수 있다.
	cout << "s4 = " << s4.length() << endl;
	cout << "s4 = " << s4.size() << endl;
	//size = length은 동일한 기능
	return;
}