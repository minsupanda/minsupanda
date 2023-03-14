#include<iostream>
#include<string>
using namespace std;


void main()
{
	cout << 3 + 4 << endl;
	cout << "korea" + 1 << endl;
	cout << "korea" + 2 << endl;
	cout << "korea" + 3 << endl;
	cout << 4 + "korea" << endl;
	// korea는 const char형으로 시작주소를 들고 있게 된다.
	// 그러므로 1을 더하는 것은 k의 시작주소에서 1을 더하게 되므로 orea가 출력되는 것

	//cout << "kor" + "ea" << endl;
	// 즉, 이 코드는 주소에 주소를 더하므로 오류가 나는 것
	
}