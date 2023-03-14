#include<iostream>
using namespace std;

class person
{
private:
	int m_iAge;
	string m_strName;
public:
	person(int _age, string tmp)
	{
		m_iAge = _age;
		m_strName = tmp;
	}
	person(const person* tmp)
	// const : 생성된 데이터를 복사할 것인데 데이터가 바꿔지면 안되기 때문에 const를 사용해 이를 방지하는 것 이다.
	// 원래는 &(레퍼런스)로 받아야 하지만 지금은 배우지 않았으므로 const * 를 사용할 것이다.
	// 어쨌거나 p1을 복사하는 거면 p1으로 인자 보내줘서 매개변수를 person tmp로 받으면 되지 않나?
	// -> 복사 생성자 자체를 이미 비쥬얼 스튜디오에서 기능을 제공하기 때문에 형식(* 포인터)을 지켜야한다. 
	{
		m_iAge = tmp->m_iAge;
		m_strName = tmp->m_strName;
	}
	void print()
	{
		cout << "나이 : " << m_iAge << endl;
		cout << "이름 : " << m_strName << endl;
	}

};

void main()
{
	person p1(26, "최정호");
	person p2(&p1);
	p1.print();
	p2.print();

}