#pragma once
#include<Windows.h>


class BitMap
{
private:
	HDC MemDC;
	HBITMAP m_BitMap;
	SIZE m_Size;
public:
	void Init(HDC hdc,char* FileName);
	void Draw(HDC hdc, int x, int y);
	inline SIZE GetSize()
	{
		return m_Size;
	}
	BitMap();
	~BitMap();
};

