#pragma once
#include"Map.h"
#include"Obstacle.h"
#include"Field.h"
#include<iostream>
using namespace std;
class Factory
{
public:
	virtual Map* MakeMap() = 0;
	virtual Field* MakeField() = 0;
	virtual Obstacle* MakeObstacle() = 0;
	Factory();
	~Factory();
};

class VolcanoFactory : public Factory
{
public:
	virtual Map* MakeMap();
	virtual Field* MakeField();
	virtual Obstacle* MakeObstacle();
	VolcanoFactory();
	~VolcanoFactory();
};

class BeachFactory : public Factory
{
public:
	virtual Map* MakeMap();
	virtual Field* MakeField();
	virtual Obstacle* MakeObstacle();
	BeachFactory();
	~BeachFactory();
};


