#pragma once
#include<iostream>
#include<string>
using namespace std;
class Field
{
protected:
	string type;
public:
	virtual void SetField() =0;
	inline string GetType()
	{
		return type;
	}
	Field();
	~Field();
};

class VolcanoField : public Field
{

public:
	void SetField();
	VolcanoField();
	~VolcanoField();
};

class BeachField : public Field
{

public:
	void SetField();
	BeachField();
	~BeachField();
};

