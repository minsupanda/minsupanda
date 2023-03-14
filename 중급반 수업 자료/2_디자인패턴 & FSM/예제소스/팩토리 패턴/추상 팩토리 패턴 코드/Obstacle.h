#pragma once
#include<iostream>
#include<string>
using namespace std;
class Obstacle
{
protected:
	string type;
public:
	virtual void SetObstacle() = 0;
	inline string GetType()
	{
		return type;
	}
	Obstacle();
	~Obstacle();
};

class VolcanoObstacle : public Obstacle
{

public:
	void SetObstacle();
	VolcanoObstacle();
	~VolcanoObstacle();
};

class BeachObstacle : public Obstacle
{

public:
	void SetObstacle();
	BeachObstacle();
	~BeachObstacle();
};


