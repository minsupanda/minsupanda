#include<iostream>
using namespace std;

class Bumo
{
public:
	void func()
	{
		cout << "Bumo함수입니다." << endl;
	}
};

class Jasic : public Bumo
{
public:
	void func()
	{
		cout << "Jasic 함수입니다." << endl;
	}
};

void main()
{
	Jasic ob;
	Bumo* mom = &ob;
	mom->func();
	// ob의 주소를 mom에 넣었으므로 메모리 주소를 출력하면 당연히 둘다 ob의 주소가 나온다.
	// ->(에로우 포인터)는 주소를 따라가라이므로 ob의 주소를 따라가게 될텐데 왜 부모class의 함수가 호출되냐?
	// *** 이유 ***
	// 예를들어, 부모class의 메모리 크기를 10byte, 자식class의 메모리 크기를 6byte라고 하자.
	// 이때 자식class에 부모를 상속하면 자식은 16byte 메모리를 사용하게 된다.
	// 이상황에서 upcasting을 한다는게 의아한게 부모는 10byte인데 거기에 자식(16byte)를 넣는다라는 것이다
	// 즉, 자식의 16byte 모두를 저장하는게 아니라는 것이다.
	// 결론은.
	// 생성자는 부모 class가 먼저 호출된다 -> 메모리는 시작주소부터 읽히게 된다.
	// 즉슨, 상속받은 자식 class는 첫 시작 메모리 주소는 부모 class이게 된다.
	// 그러므로 upcasting을 하면 시작주소부터 부모class 메모리 크기만큼만 읽게되고 그 뒤는 안 읽는다.
	// 그렇기 때문에 upcasting을하더라도 당연히 부모 class의 메모리 주소를 읽게되는 것이므로 부모의 함수가 호출되는 것이다
	// *** 가상함수 ***
	// 가상함수는 이러한 경우의 수를 고려해 정말로 부모 함수를 호출하는게 맞냐고 한번더 확인하라는 뜻으로
	// 상속받은 클래스에서 재정의한다는 가능성을 고려해서 정의하는 함수이다.


}
