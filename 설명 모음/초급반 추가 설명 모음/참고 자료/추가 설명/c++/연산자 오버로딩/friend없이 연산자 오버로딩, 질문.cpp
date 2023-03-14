#include<iostream>
#include<string>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int a, int b) { x = a; y = b; }
	void Print() { cout << "x = " << x << ", y = " << y << "\n"; }
	//bool operator == (Point tmp);
	Point operator + (int date)
	{
		x += date;
		y += date;
		return { x, y };
	}
	friend Point operator + (Point tmp, int date);
};

//bool Point::operator==(Point tmp)
//{
//	if ((this->x == tmp.x) && (this->y == tmp.y))
//		return true;
//	else
//		return false;
//}

Point operator + (Point tmp, int date)
{
	cout << "객체 + 정수 " << "\n";
	tmp.x = tmp.x + date;
	tmp.y = tmp.y + date;
	return tmp;
}

void main()
{
	Point ov1(10, 20), ov2(0, 0);
	//if (ov1 == ov2)
	//	cout << "같다." << "\n";
	ov2 = ov1 + 10;
	// 이게 오류가 뜨는 이유 : 
	// 당연히 완전히 동일한 기능을 하는 함수가 2개이기 때문에 중복으로 제대로 인식을하지 못해 오류가 생기게 되는 것이다
	// Q : 그럼 Point operator + (int date) 얘를 private으로 숨기면 안되냐?
	// A : private로 숨긴다 한들 어차피 호출하는 ov1도 Point Class이기 때문에 Point operator + (int date) 얘를 인식하게 된다
	// 그러므로 똑같이 오류가 뜨는 것

	// friend를 쓰지 않는 코드는 위와 동일하게 해결한 것
	// 왼쪽에 있는 피연산자가 함수를 호출한 Class의 것이기 때문에 매개변수는 연산자만 데리고 오면 되는 것
	ov2.Print();
}