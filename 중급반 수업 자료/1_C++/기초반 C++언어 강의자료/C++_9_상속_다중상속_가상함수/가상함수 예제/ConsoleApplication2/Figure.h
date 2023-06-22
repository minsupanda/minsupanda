#pragma once
#include<iostream>
using namespace std;
class Figure
{
protected:
	int x;
	int y;
public:
	Figure();
	virtual void Draw();
	virtual void SetSize();
	virtual ~Figure();
};

