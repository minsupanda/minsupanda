#pragma once
#include<iostream>
#include<string>
#include"Field.h"
#include "Obstacle.h"
using namespace std;
class Map
{
private:
	string name;
	Field* field;
	Obstacle* Ob;
public:
	void AddField(Field* f);
	void AddObstacle(Obstacle* ob);
	void ShowMap();
	Map(string name);
	~Map();
};

	