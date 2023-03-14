#pragma once
#include"Figure.h"
#include<iomanip>
class circle :public Figure
{
private:
	float pi;
public:
	virtual void Draw() override;
	virtual void SetSize();
	circle();
	~circle();
};

