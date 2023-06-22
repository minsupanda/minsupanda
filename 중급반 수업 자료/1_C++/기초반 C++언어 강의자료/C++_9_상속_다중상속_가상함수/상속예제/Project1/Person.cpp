#include "Person.h"

Person::Person()
{
	SetAge(rand() % 51 + 10);
	m_fHeight = (float)(rand() % 3000 + 15000) / 100.0f;
	switch (rand() % 7)
	{
	case 0:
		m_strName = "홍길동";
		m_eGender = GENDER::MAN;
		break;
	case 1:
		m_strName = "김민아";
		m_eGender = GENDER::WOMAN;
		break;
	case 2:
		m_strName = "박정환";
		m_eGender = GENDER::MAN;
		break;
	case 3:
		m_strName = "신연주";
		m_eGender = GENDER::WOMAN;
		break;
	case 4:
		m_strName = "민정우";
		m_eGender = GENDER::MAN;
		break;
	case 5:
		m_strName = "최수현";
		m_eGender = GENDER::WOMAN;
		break;
	case 6:
		m_strName = "정일현";
		break;
	}
}

void Person::PrintPerson()
{
	cout << "========사람========" << endl;
	PrintInfomation();
	cout << "================" << endl;
}

void Person::SetAge(int _iAge)
{
	m_iAge = _iAge;
}

void Person::PrintInfomation()
{
	cout << "이름 : " << m_strName << endl;
	cout << "나이 : " << m_iAge << "살" << endl;
	cout << "키 : " << m_fHeight << "cm" << endl;
	if (m_eGender == GENDER::MAN)
		cout << "성별 : 남자 " << endl;
	else
		cout << "성별 : 여자 " << endl;
}

Person::~Person()
{
}
