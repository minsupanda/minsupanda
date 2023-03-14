#pragma once
#include"Mecro.h"
#include"MapDraw.h"


enum DIRECTION
{
	DIRECTION_LEFT = 'a',
	DIRECTION_RIGHT = 'd',
	DIRECTION_UP = 'w',
	DIRECTION_DOWN = 's'
};

class Character
{
private:
	MapDraw m_DrawManager;
	string m_strShape;
	int m_ix;
	int m_iy;
public:
	void Draw();
	void Move(int x,int y,int Width,int Height);
	Character(int x,int y);
	~Character();
};

