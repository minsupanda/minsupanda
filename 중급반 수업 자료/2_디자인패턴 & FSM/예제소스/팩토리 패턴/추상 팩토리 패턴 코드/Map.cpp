#include "Map.h"



Map::Map(string name)
{
	this->name = name;
}
void Map::AddField(Field* f)
{
	this->field = f;
}
void Map::AddObstacle(Obstacle* ob)
{
	this->Ob = ob;
}

void Map::ShowMap()
{
	cout << "=======" << name << "======" << endl;
	cout << "1." << field->GetType() << endl;
	cout << "2." << Ob->GetType() << endl;
	cout << "=================" << endl<<endl;
}

Map::~Map()
{
	delete field;
	delete Ob;
}
