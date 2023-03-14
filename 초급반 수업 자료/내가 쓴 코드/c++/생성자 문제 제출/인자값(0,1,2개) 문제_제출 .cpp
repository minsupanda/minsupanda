#include<iostream>
using namespace std;

class Setting
{
private:
	int m_iStartNum;
	int m_iEndtNum;
	int m_iSum;
public:
	Setting()
	{
		m_iSum = 0;
		m_iStartNum = 1;
		m_iEndtNum = 10;
	}
	Setting(int _iNum1)
	{
		m_iSum = 0;
		m_iStartNum = 1;
		m_iEndtNum = _iNum1;
		while (1)
		{
			if (m_iEndtNum > 0)
				break;
			cout << "시작 값이 마지막 값보다 큽니다." << endl << "마지막 값 재입력(시작 값 : " << m_iStartNum << ") : ";
			cin >> m_iEndtNum;
		}
	}
	Setting(int _iNum1, int _iNum2)
	{
		m_iSum = 0;
		m_iStartNum = _iNum1;
		m_iEndtNum = _iNum2;
		if (m_iStartNum > m_iEndtNum)
		{
			cout << "시작 값이 마지막 값보다 큽니다. (두 수 교체)" << endl;
			m_iStartNum = _iNum2;
			m_iEndtNum = _iNum1;
		}
	}
	inline int GetSum()
	{
		for (int i = m_iStartNum; i <= m_iEndtNum; i++)
			m_iSum += i;
		return m_iSum;
	}
};


void main()
{
	int _iNum1, _iNum2;

	Setting Quiz1;
	cout << "1번 문제 합계 : " << Quiz1.GetSum() << endl << endl;


	cout << "수 입력 : ";
	cin >> _iNum1;
	Setting Quiz2(_iNum1);
	cout << "2번 문제 합계 : " << Quiz2.GetSum() << endl << endl;;


	cout << "첫번째 수 입력 : ";
	cin >> _iNum1;
	cout << "두번째 수 입력 : ";
	cin >> _iNum2;
	Setting Quiz3(_iNum1, _iNum2);
	cout << "3번 문제 합계 : " << Quiz3.GetSum() << endl;
}