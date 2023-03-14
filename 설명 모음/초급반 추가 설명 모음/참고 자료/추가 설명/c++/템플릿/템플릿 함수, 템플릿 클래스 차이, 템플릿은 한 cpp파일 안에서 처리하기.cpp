#include<iostream>

template <typename Type>
class Point
{
private:
	Type x, y;
public:
	Point(Type a, Type b) { x = a; y = b; }
	void Display()
	{
		std::cout << "x = " << x << "\n";
		std::cout << "y = " << y << "\n";
	}
};

void main()
{
	Point<int> PInt(10, 20);
	Point<double> PDouble(10.4, 20.6);
	PInt.Display();
	PDouble.Display();
}
// 템플릿 함수와 템플릿 클랫스의 차이점
// 템플릿 함수 : 인자값을 보내면서 자료형을 정해줘도 되지만 가독성을 고려해 함수 호출부 부분에 <>를 활용해 바로 자료형을 정해주는 것이 좋았음
// 즉, 선택사항(이긴 하지만 <>활용하는게 좋다)
// 템플릿 클래스 : 무조건 자료형을 정해줘놓고 시작해야한다
// 콜론초기화도 생성자가 만들어지면서 되기 때문에 불가능하다. 즉 무조건 <>를 활용해야 한다

// 템플릿은 무조건 한 파일안에서 처리되어야 한다!!!!!!!!!!!!!!!!!1