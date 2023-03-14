#include "Quadrangle.h"



Quadrangle::Quadrangle()
{
}



void Quadrangle::Draw()
{
	cout << "가로 : " << x << " 세로 : " << y << " 인 사각형을 그렸습니다." << endl;
}

void Quadrangle::SetSize()
{
	cout << "가로 : ";
	cin >> x;
	cout << "세로 : ";
	cin >> y;
}


Quadrangle::~Quadrangle()
{
}
