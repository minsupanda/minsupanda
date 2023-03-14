#include "Character.h"



Character::Character(int x, int y)
{
	m_ix = x;
	if(m_ix % 2 == 1)
		m_ix++;
	m_iy = y;
	m_strShape = "¢»";
}


void Character::Move(int x, int y, int Width, int Height)
{
	while(1)
	{
		char ch = getch();
		m_DrawManager.ErasePoint(m_ix, m_iy);
		switch(ch)
		{
			case DIRECTION_LEFT:
				if(m_ix*2 - 1 > x+1)
					m_ix--;
				break;
			case DIRECTION_RIGHT:
				if(m_ix*2 + 1 < x +Width*2 - 3)
				m_ix++;
				break;
			case DIRECTION_UP:
				if(m_iy - 1 > y)
				m_iy--;
				break;
			case DIRECTION_DOWN:
				if(m_iy + 1 < y + Height-1)
				m_iy++;
				break;
		}
		Draw();
	}
}


void Character::Draw()
{
	m_DrawManager.DrawPoint(m_strShape, m_ix, m_iy);
}


Character::~Character()
{
}
