#pragma once
#include"Figure.h"
#include<iomanip>
class circle :public Figure
{
private:
	float pi;
public:
	virtual void Draw();
	virtual void SetSize();
	circle();
	~circle();
};

