#include<iostream>
#include<string> // c언어의 string.h와 다른것
using namespace std; // std::을 생략시켜준다.

void main()
{
	char name[20] = "Hello";
	printf("%s", name);
	scanf("%s", name);
	printf("%s", name);

	string str = "Hello";
	cout << "str = " << str << endl << endl;
	cout << "새로운 문자열 입력 : ";
	cin >> str;
	cout << "새로운 str = " << str << endl;
	return;
}