#pragma once
#include"Figure.h"
class Triangle : public Figure
{
public:
	Triangle();
	~Triangle();

	// Figure��(��) ���� ��ӵ�
	virtual void Draw() override;
	virtual void SetSize() override;
};

