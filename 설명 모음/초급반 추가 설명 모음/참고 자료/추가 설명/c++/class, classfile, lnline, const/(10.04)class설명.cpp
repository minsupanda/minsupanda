#include<iostream>
#include<string>
using namespace std;

enum GENDER
{
	GENDER_MAN,
	GENDER_WOMAN,
};

class Person
{
private:
	string Name;
	int Age;
	GENDER Gender;

public:
	void SetName(string _Name, int _Age, GENDER _Gender);
	string GetName();
	void ShowPerson(); // 많아지는 class의 코드를 깔끔하게 관리하기 위해 전방선언 하듯 미리 함수의 원형만 선언한다. 
};

// 함수의 사용법은 따로 빼두고 class의 이름을 넣어 전방선언과 구분해준다.
void Person::SetName(string _Name, int _Age, GENDER _Gender)
{
	Name = _Name;
	Age = _Age;
	Gender = _Gender;
}
string Person::GetName()
{
	return Name;
}
void Person::ShowPerson()
{
	cout << "이름 : " << Name << endl;
	cout << "나이 : " << Age << endl;
	cout << "성별 :";
	switch (Gender)
	{
	case GENDER_MAN:
		cout << "남자" << endl;
		break;
	case GENDER_WOMAN:
		cout << "여자" << endl;
		break;
	}
}

void main()
{
	// 변수들은 private 영역(class 내에서만 접근이 가능한 영역)에 함수는 public 영역에 들어가야 한다.(다른 지역에서도 접근이 가능한 영역)
	// 변수들을 private 영역에 두어 정보를 은닉, 은닉한 변수들의 사용법은
	// 기능에 따라 캡슐화한 공간(함수들) 즉, public 공간에 선언한 함수를 통해 해당 변수의 사용 방법을 알려주는 것
	// 이게 왜 객체에 맞는거지? 밖에서 접근해 데이터 바꾸는 거하고 private에 변수를 두어 데이터에 접근해서 사용하는 것하고 왜 후자가 객체에 맞는거지?
	// 객체는 코드 간의 관계를 각각 독립된 객체로 나누어 코드 관리, 보수를 용이하는게 목적
	// -> 변동 가능한 데이터를 private에 넣음으로써 관리가 수월해진다. -> 오류가 나더라도 해당 데이터가 사용된 영역만 확인하면 되기 때문
	// -> Ex. 등록된 사람이 많아져도 이름에서 오류가 나면 SetName에 중단점 걸고 확인하면 된다.  -> 그렇기 때문에 후자가 더 객체에 맞는 것이다.
	Person P1;
	P1.SetName("아이유", 25, GENDER_WOMAN);
	cout << "============" << P1.GetName() << "의 정보" << "==========" << endl;
	P1.ShowPerson();

}