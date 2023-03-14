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
	virtual void Draw() = 0;
	virtual void SetSize() = 0;
	virtual ~Figure();
};

