#include<iostream>
using namespace std;

class A
{
private:
	int m_iprivate;
protected:
	int m_iprotected;
public:
	int m_ipublic;
	void Test()
	{
		m_iprivate = 10;
		m_iprotected = 10;
		m_ipublic = 10;
	}
};

// public A, protected A, private A �� �� �� �ϳ��� ����ص� class A�� ��� �����͸� �������� �ȴ�
// ������
// (�켱 private������ �ִ� �����ʹ� ���� �ƴ� �׻� �θ� class�� �����ؼ� ����ؾ� �Ѵ�
// class B : public A�� public, protected ������ ���ٰ�����
// class B : protected A�� protected ������ ���� ������, public�� protected�� �����ؼ� ��� ���� ��
// �׷��� �θ� class�� public ������ �����ʹ� �ڽ�Ŭ���� ������ ����� ���������� ���ο����� ������� ���ϰ� �ȴ�.
// �ֳ��ϸ� public�� protected�� �ν��߱� ������ protected ������ �ڽŰ� �ڽ� ���������� ��밡���ϱ� �����̴�
// 
// ���� class B : private A�� �ϰ� �ȴٸ� B Ŭ���������� �θ� class�� ��� �������� private�� �����ϰ� �ȴ�.
// �׷��� class C ������ B�� ����ϰ� �Ǵٸ� ��� private�������� ����ϰ� �ȴ�.

class B : public A
{	
	void Test()
	{
		m_iprivate = 10;
		m_iprotected = 10;
		m_ipublic = 10;
	}
};

class C : public B
{
	void Test()
	{
		m_iprivate = 10;
		m_iprotected = 10;
		m_ipublic = 10;
	}
};

void main()
{
	B b;
	b.m_iprivate = 10;
	b.m_iprotected = 10;
	b.m_ipublic = 10;

	C c;
	c.m_iprivate = 10;
	c.m_iprotected = 10;
	c.m_ipublic = 10;
}