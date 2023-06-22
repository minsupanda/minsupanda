#include "Student.h"

Student::Student()
{
	SetAge(rand() % 4 + 20);
	switch (rand() % 7)
	{
	case 0:
		m_strSchoolName = "경성대학교";
		break;
	case 1:
		m_strSchoolName = "부산대학교";
		break;
	case 2:
		m_strSchoolName = "서울대학교";
		break;
	case 3:
		m_strSchoolName = "부경대학교";
		break;
	case 4:
		m_strSchoolName = "고려대학교";
		break;
	case 5:
		m_strSchoolName = "연세대학교";
		break;
	case 6:
		m_strSchoolName = "세종대학교";
		break;
	}
	m_iGrade = rand() % 4 + 1;
	for (int i = 0; i < SCORE::END; i++)
		m_iarrScore[i] = rand() % 101;
}

void Student::PrintStudent()
{

	cout << "========학생========" << endl;
	PrintInfomation();
	cout << "학교 : " << m_strSchoolName << endl;
	cout << "학년 : " << m_iGrade << endl;
	cout << "점수 : ";
	for (int i = 0; i < SCORE::END; i++)
		cout << m_iarrScore[i] << " ";
	cout << endl;
	cout << "================" << endl;
}

Student::~Student()
{
}
