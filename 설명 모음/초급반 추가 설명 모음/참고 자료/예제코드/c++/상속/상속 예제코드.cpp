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

// public A, protected A, private A 이 중 뭐 하나든 상속해도 class A의 모든 데이터를 가져오게 된다
// 하지만
// (우선 private영역에 있는 데이터는 뭐가 됐던 항상 부모 class를 경유해서 사용해야 한다
// class B : public A는 public, protected 영역에 접근가능함
// class B : protected A는 protected 영역에 접근 가능함, public은 protected로 인지해서 들고 오게 됨
// 그래서 부모 class의 public 영역의 데이터는 자식클래스 내에서 사용은 가능하지만 메인에서는 사용하지 못하게 된다.
// 왜냐하면 public을 protected로 인식했기 때문에 protected 영역은 자신과 자식 영역에서만 사용가능하기 때문이다
// 
// 만약 class B : private A를 하게 된다면 B 클래스에서는 부모 class의 모든 영역들을 private로 인지하게 된다.
// 그래서 class C 에서는 B를 상속하게 되다면 모두 private영역으로 상속하게 된다.

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