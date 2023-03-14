#include "Factory.h"



Factory::Factory()
{
}
Factory::~Factory()
{
}


Map* BeachFactory::MakeMap()
{
	Map* m = new Map("해변");
	cout << "해변 맵 생성 완료" << endl;
	m->AddField(MakeField());
	m->AddObstacle(MakeObstacle());
	return m;
}
Field* BeachFactory::MakeField()
{
	return new BeachField;
}
Obstacle* BeachFactory::MakeObstacle()
{
	return new BeachObstacle;
}
BeachFactory::BeachFactory()
{
	cout << "해변맵 공장 생성 완료" << endl;
}
BeachFactory::~BeachFactory()
{

}


Map* VolcanoFactory::MakeMap()
{
	Map* m = new Map("화산");
	cout << "화산 맵 생성 완료" << endl;
	m->AddField(MakeField());
	m->AddObstacle(MakeObstacle());
	return m;
}
Field* VolcanoFactory::MakeField()
{
	return new VolcanoField;
}
Obstacle* VolcanoFactory::MakeObstacle()
{
	return new VolcanoObstacle;
}
VolcanoFactory::VolcanoFactory()
{
	cout << "화산맵 공장 생성 완료" << endl;
}
VolcanoFactory::~VolcanoFactory()
{

}


