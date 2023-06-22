#pragma once
#include<iostream>
#include<string>
#include<time.h>

using namespace std;

enum class GENDER
{
	WOMAN,
	MAN,
};

class Person
{
private:
	int m_iAge;
	float m_fHeight;
	string m_strName;
	GENDER m_eGender;
protected:
	void SetAge(int _iAge);
	void PrintInfomation();
public:
	Person();
	void PrintPerson();
	~Person();
};

