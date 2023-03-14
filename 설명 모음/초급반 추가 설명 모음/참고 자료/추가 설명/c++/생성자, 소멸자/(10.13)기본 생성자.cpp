#include<iostream>
using namespace std;

class Point
{
private:
	int m_ipx, m_ipy;
public:
	Point() // 기본 생성자 (default distruct)
	{
		m_ipx = 5;
		m_ipy = 5;
	}
	Point(int x, int y) // 생성자
	{
		m_ipx = x;
		m_ipy = y;
	}
	int getPx() { return m_ipx; };
	int getPy() { return m_ipy; };
};

void main()
{
	Point pt1, pt2(10, 20);
	// 기본 생성자를 만들지 않으면 pt1이 오류가 뜬다. : '기본 생성자가 없습니다.'
	// 오버로딩해서 가능하게 만들어 준다.
	// 이런 경우는 매개변수가 있든 없든 사용하고 싶을 경우
	// 반대로 매개변수가 있을 때만 만들고 싶게 강제하고 싶으면 기본 생성자를 만들지 않으면 된다.
	// ********************많이 사용하는 기법이므로 잘 알고 있을 것 ****************************************
	cout << "pt -> x : " << pt1.getPx() << ", y : " << pt1.getPy() << endl;
	cout << "pt -> x : " << pt2.getPx() << ", y : " << pt2.getPy() << endl;
}