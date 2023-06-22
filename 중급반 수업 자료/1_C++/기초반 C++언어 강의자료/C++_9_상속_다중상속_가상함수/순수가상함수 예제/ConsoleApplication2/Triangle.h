#pragma once
#include"Figure.h"
class Triangle : public Figure
{
public:
	Triangle();
	~Triangle();

	// Figure을(를) 통해 상속됨
	virtual void Draw() override;
	virtual void SetSize() override;
};

