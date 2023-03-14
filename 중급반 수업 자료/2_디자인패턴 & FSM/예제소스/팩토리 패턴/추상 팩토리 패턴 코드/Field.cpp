#include "Field.h"



Field::Field()
{
}
Field::~Field()
{
}



void BeachField::SetField() 
{
	type = "해변지대 필드";
}
BeachField::BeachField()
{
	SetField();
	cout << "해변지대 필드 생성 완료" << endl;
}
BeachField::~BeachField()
{
}



void VolcanoField::SetField()
{
	type = "화산지대 필드";
}
VolcanoField::VolcanoField()
{
	SetField();
	cout << "화산지대 필드 생성 완료" << endl;
}
VolcanoField::~VolcanoField()
{
}