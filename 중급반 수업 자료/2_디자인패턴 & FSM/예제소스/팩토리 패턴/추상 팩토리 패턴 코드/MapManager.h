#pragma once
#include<vector>
#include"Map.h"
#include"Obstacle.h"
#include"Field.h"
#include"Factory.h"
using namespace std;

class MapManager
{
private:
	static MapManager* m_hThis;
	vector<Map*> vecMap;
public:
	static MapManager* GetInstans()
	{
		if (m_hThis == NULL)
		{
			m_hThis = new MapManager;
		}
		return m_hThis;
	}
	static inline void Release()
	{
		delete m_hThis;
	}
	void CreateMap(Factory& fac);
	void ShowMapList();
	MapManager();
	~MapManager();
};

