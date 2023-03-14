#include "MapManager.h"


MapManager* MapManager::m_hThis = NULL;

MapManager::MapManager()
{
}

void MapManager::CreateMap(Factory& fac)
{
	vecMap.push_back(fac.MakeMap());
}

void MapManager::ShowMapList()
{
	for (auto iter = vecMap.begin(); iter != vecMap.end(); iter++)
	{
		(*iter)->ShowMap();
	}
}

MapManager::~MapManager()
{
	for (auto iter = vecMap.begin(); iter != vecMap.end(); iter++)
	{
		delete *iter;
	}
	vecMap.clear();
}
