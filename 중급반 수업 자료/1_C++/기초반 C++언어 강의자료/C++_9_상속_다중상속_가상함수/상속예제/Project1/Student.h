#pragma once
#include"Person.h"

enum SCORE
{
	KOREAN,
	MATH,
	ENGLISH,
	END
};

class Student : public Person
{
private:
	string m_strSchoolName;
	int m_iGrade;
	int m_iarrScore[SCORE::END];
public:
	Student();
	void PrintStudent();
	~Student();
};

