#include "Student.h"

Student::Student()
{
	SetAge(rand() % 4 + 20);
	switch (rand() % 7)
	{
	case 0:
		m_strSchoolName = "�漺���б�";
		break;
	case 1:
		m_strSchoolName = "�λ���б�";
		break;
	case 2:
		m_strSchoolName = "������б�";
		break;
	case 3:
		m_strSchoolName = "�ΰ���б�";
		break;
	case 4:
		m_strSchoolName = "������б�";
		break;
	case 5:
		m_strSchoolName = "�������б�";
		break;
	case 6:
		m_strSchoolName = "�������б�";
		break;
	}
	m_iGrade = rand() % 4 + 1;
	for (int i = 0; i < SCORE::END; i++)
		m_iarrScore[i] = rand() % 101;
}

void Student::PrintStudent()
{

	cout << "========�л�========" << endl;
	PrintInfomation();
	cout << "�б� : " << m_strSchoolName << endl;
	cout << "�г� : " << m_iGrade << endl;
	cout << "���� : ";
	for (int i = 0; i < SCORE::END; i++)
		cout << m_iarrScore[i] << " ";
	cout << endl;
	cout << "================" << endl;
}

Student::~Student()
{
}
