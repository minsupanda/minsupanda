#include "Obstacle.h"



Obstacle::Obstacle()
{
}
Obstacle::~Obstacle()
{
}



void BeachObstacle::SetObstacle()
{
	type = "해변지대 장애물";
}
BeachObstacle::BeachObstacle()
{
	SetObstacle();
	cout << "해변지대 장애물 생성 완료" << endl;
}
BeachObstacle::~BeachObstacle()
{
}



void VolcanoObstacle::SetObstacle()
{
	type = "화산지대 장애물";
}
VolcanoObstacle::VolcanoObstacle()
{
	SetObstacle();
	cout << "화산장애물 생성 완료" << endl;
}
VolcanoObstacle::~VolcanoObstacle()
{
}