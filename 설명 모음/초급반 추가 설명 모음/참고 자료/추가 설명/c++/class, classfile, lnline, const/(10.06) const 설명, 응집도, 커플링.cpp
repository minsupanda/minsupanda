#include<iostream>
using namespace std;

class Point
{
private:
	// 해당 지역 즉, class 범위 밖에서 값이 수정되는 것은 결모 이루어 져서는 안된다.
	
	// 객체성 유지
	// 응집도 : 높아야 좋음 : 객체가 스스로 활동할 수 있느 정도
	// 커플링 : 낮아야 좋음 : 객체간의 의존도

	// const : 변경이 불가능한 상수로 바꾸는 것, const 뒤에 붙은 것이 뭐인지 보면 된다.
	// 값이 변경되면 안되는 코드에 const를 붙혀 여기서는 값 변경이 이루어지면 안되는 부분이라는 것으로 알리는 용도로 사용하게 됨.
	// 코드가 수정되면 안 된다는 뜻이 아님.

	int m_ix; // const int m_ix : m_ix에 대입연산자를 사용한 모든 코드에 오류가 발생
	int m_iy;

public:
	Point(){} // 지금 신경 쓰지 않아도 된다.
	void SetNum(int x, int y)
	{
		m_ix = x;
		m_iy = y;
	}
	void ShowNum() // void ShowNum() const : const뒤는 {}스코프가 있으므로 이 범위에서 발생한 값 변경은 오류가 뜨게 된다.
	{
		cout << "x = " << m_ix << endl;
		cout << "y = " << m_iy << endl;
		m_ix = 30;
		m_iy = 40;
		cout << "x = " << m_ix << endl;
	}
	int* GetNum() // const int* GetNum() : const뒤에 int*가 있으므로 int형 포인터를 반환하게됨 -> 주소를 출력, 따라가는 것은 가능하나 값을 바꿀 수 는 없다 (오류 발생) 
	{
		return &m_ix;
	}
};

void main()
{
	Point p;
	p.SetNum(10, 20);
	p.ShowNum();
	*(p.GetNum()) = 100; // GetNum함수에서 주소를 리턴받고 따라가라는 뜻. 거기에 수정을 하는 것
	p.ShowNum();
}