#include "Person.h"

Person::Person()
{
	SetAge(rand() % 51 + 10);
	m_fHeight = (float)(rand() % 3000 + 15000) / 100.0f;
	switch (rand() % 7)
	{
	case 0:
		m_strName = "ȫ�浿";
		m_eGender = GENDER::MAN;
		break;
	case 1:
		m_strName = "��ξ�";
		m_eGender = GENDER::WOMAN;
		break;
	case 2:
		m_strName = "����ȯ";
		m_eGender = GENDER::MAN;
		break;
	case 3:
		m_strName = "�ſ���";
		m_eGender = GENDER::WOMAN;
		break;
	case 4:
		m_strName = "������";
		m_eGender = GENDER::MAN;
		break;
	case 5:
		m_strName = "�ּ���";
		m_eGender = GENDER::WOMAN;
		break;
	case 6:
		m_strName = "������";
		break;
	}
}

void Person::PrintPerson()
{
	cout << "========���========" << endl;
	PrintInfomation();
	cout << "================" << endl;
}

void Person::SetAge(int _iAge)
{
	m_iAge = _iAge;
}

void Person::PrintInfomation()
{
	cout << "�̸� : " << m_strName << endl;
	cout << "���� : " << m_iAge << "��" << endl;
	cout << "Ű : " << m_fHeight << "cm" << endl;
	if (m_eGender == GENDER::MAN)
		cout << "���� : ���� " << endl;
	else
		cout << "���� : ���� " << endl;
}

Person::~Person()
{
}
