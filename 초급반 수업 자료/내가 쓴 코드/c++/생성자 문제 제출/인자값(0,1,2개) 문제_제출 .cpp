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
			cout << "���� ���� ������ ������ Ů�ϴ�." << endl << "������ �� ���Է�(���� �� : " << m_iStartNum << ") : ";
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
			cout << "���� ���� ������ ������ Ů�ϴ�. (�� �� ��ü)" << endl;
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
	cout << "1�� ���� �հ� : " << Quiz1.GetSum() << endl << endl;


	cout << "�� �Է� : ";
	cin >> _iNum1;
	Setting Quiz2(_iNum1);
	cout << "2�� ���� �հ� : " << Quiz2.GetSum() << endl << endl;;


	cout << "ù��° �� �Է� : ";
	cin >> _iNum1;
	cout << "�ι�° �� �Է� : ";
	cin >> _iNum2;
	Setting Quiz3(_iNum1, _iNum2);
	cout << "3�� ���� �հ� : " << Quiz3.GetSum() << endl;
}