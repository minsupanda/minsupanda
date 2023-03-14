#include "BitMapManager.h"

BitMapManager* BitMapManager::m_hThis = NULL;

BitMapManager::BitMapManager()
{
	m_parrBitMap = new BitMap[IMAGE_END];
}


void BitMapManager::Init(HWND hWnd)
{
	char buf[256];
	HDC hdc = GetDC(hWnd);
	for (int i = IMAGE_START; i < IMAGE_END; i++)
	{
		sprintf_s(buf, "RES//0%d.bmp", i);
		m_parrBitMap[i].Init(hdc,buf);
	}
	ReleaseDC(hWnd, hdc);
}

BitMapManager::~BitMapManager()
{
	delete[] m_parrBitMap;
}
