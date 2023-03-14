#pragma once
#include"Figure.h"
#include<iomanip>
class circle :public Figure
{
private:
	float pi;
public:
	void Draw();
	void SetSize();
	circle();
	~circle();
};

