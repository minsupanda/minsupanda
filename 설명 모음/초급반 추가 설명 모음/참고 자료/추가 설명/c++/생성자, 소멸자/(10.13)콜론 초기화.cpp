#include<iostream>
using namespace std;

class A
{
private:
	const int m_iNum1;
	// ���� �ϰ� ���� �����  const int m_iNum1 = Num1�� �ϰ� ����
	// const ������ ����� ���ÿ� �ʱ�ȭ�� �ؾ��ϹǷ� ������ �߰� �ȴ�.
	// ********** ȣ��Ǵ� ������ �߿��� ****************
	// class�� ȣ���ϰ� �Ǹ� �ɹ������� �ʱ�ȭ �ǰ� �����ڰ� ȣ��Ǵ� �����̹Ƿ� �ٷ� Num1 ���� �ְ� �; ���� ���ϴ� ��
	// �̸� �ذ��ϱ� ���� ����� �ݷ� �ʱ�ȭ�̰� �̷� �������� ��� ����� �ȴ�.
	int m_iNum2;
public:
	A(int Num1, int Num2) : m_iNum1(Num1)
	{
		m_iNum2 = Num2;
	}
	void print()
	{
		cout << "const int m_iNum1 = " << m_iNum1 << endl;
		cout << "int m_iNum2 = " << m_iNum2 << endl;
	}
};

void main()
{
	A a(10, 20);
	a.print();
}