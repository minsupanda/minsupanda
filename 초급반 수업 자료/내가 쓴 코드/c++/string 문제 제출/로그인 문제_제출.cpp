#include <iostream>
#include <map>
#include <string>
#include <Windows.h>
#define MAX_MEMBER 10
#define MIN_ID_LENGTH 3
#define MIN_PW_LENGTH 8
#define KOREAN 2
#define JOIN_MILEAGE 1000
#define CONDITION 3
using namespace std;

struct profile
{
	string PW;
	string name;
	int age;
	int phone_number;
	int mileage;
};

bool Eng_Check(string Check);
bool Num_Check(string Check);
string ID_Create(map<string, profile> Member);
profile SignUp(map<string, profile> Member);
map<string, profile>::iterator LogIn(map<string, profile>* Member);
void Menu(map<string, profile>::iterator Member);
void Information(map<string, profile>::iterator Member);
void Modify(map<string, profile>::iterator Member);
void main();

bool Eng_Check(string Check)
{
	for (int i = 0; i < Check.size(); i++)
	{
		if (!('0' <= Check[i] && Check[i] <= '9') && !('A' <= Check[i] && Check[i] <= 'Z') && !('a' <= Check[i] && Check[i] <= 'z'))
			return false;
	}
	return true;
}

bool Num_Check(string Check)
{
	for (int i = 0; i < Check.size(); i++)
	{
		if (('0' <= Check[i] && Check[i] <= '9'))
			return true;
	}
	return false;
}

string ID_Create(map<string, profile> Member)
{
	string ID;
	int Condition = 0;
	while (Condition < CONDITION)
	{
		system("cls");
		bool ID_Check = true;
		Condition = 0;
		cout << "아이디 입력([3글자이상] AND [한글X]) : ";
		cin >> ID;

		map<string, profile>::iterator iter = Member.find(ID);
		if (iter == Member.end())
			Condition++;
		else
		{
			cout << "동일한 아이디가 존재합니다" << endl;
			continue;
		}

		ID_Check = Eng_Check(ID);
		if (ID_Check != true)
			cout << "ID가 영문이 아닙니다." << endl;
		else
			Condition++;


		if (ID.length() >= MIN_ID_LENGTH)
			Condition++;
		else
			cout << "ID가 세글자 이하 입니다." << endl;

		system("pause");
		// map<string, profile>::iterator iter = Member.find(i);
		// Member[i] 왜 안되지? -> i key값의 value에 접근하겠다는 뜻이 되므로 오류가 뜨는 것이다
		// 그러면 벨류값인 profile형태로 iter 받아야 가능하다
		// 하지만 이렇게 되면 무조건 key값이 있다는 가정하에 진행하는 것이므로 해당 key값이 없으면 오류가 뜨게 된다
	}
	return ID;
}

profile SignUp(map<string, profile> Member)
{
	profile Create_Member;
	int Condition = 0;
	while (Condition < CONDITION)
	{
		system("cls");
		bool eng_check = true;
		bool num_check = true;
		Condition = 0;
		string PW_Confirm;
		cout << "비밀번호 입력([8글자이상] AND [영문] AND [숫자 포함]) : ";
		cin >> Create_Member.PW;
		cout << "비밀번호 확인 : ";
		cin >> PW_Confirm;

		if (Create_Member.PW.length() >= MIN_PW_LENGTH)
			Condition++;
		else
			cout << "PW가 여덟글자 이하 입니다." << endl;

		if (Create_Member.PW == PW_Confirm)
			Condition++;
		else
		{
			cout << "비밀번호가 일치하지 않습니다." << endl;
			system("pause");
			continue;
		}

		eng_check = Eng_Check(PW_Confirm);
		if (eng_check == false)
			cout << "PW가 영문이 아닙니다." << endl;

		num_check = Num_Check(PW_Confirm);
		if (num_check == false)
			cout << "PW에 숫자가 포함되어 있지 않습니다" << endl;

		if (num_check == true && eng_check == true)
			Condition++;

		system("pause");
	}

	system("cls");
	cout << "닉네임 입력 : ";
	cin >> Create_Member.name;
	cout << "나이 입력 : ";
	cin >> Create_Member.age;
	cout << "휴대폰 번호 입력 : ";
	cin >> Create_Member.phone_number;
	Create_Member.mileage = JOIN_MILEAGE;
	cout << "회원가입 성공 !! 마일지지 1000원 등록" << endl;
	return Create_Member;
}

map<string, profile>::iterator LogIn(map<string, profile>* Member)
{
	string ID;
	string PW;

	cout << "아이디 입력 : ";
	cin >> ID;
	map<string, profile>::iterator iter = Member->find(ID);
	if (iter != Member->end())
	{
		cout << "비밀번호 입력 : ";
		cin >> PW;
		if (PW != iter->second.PW)
			cout << "비밀번호가 일치하지 않습니다." << endl;
		else
			return iter;
		// 여기서 return iter 하고 main에서 iter로 받고 iter!=end(); 조건 걸어서 메뉴로 갔는데 왜 무조건 end반환되고 오류터지는거지?
		// 매개변수로 받으면 그 변수는 깊은 복사가 되는 것
		// return하고 끝내면 member는 login 함수의 지역변수이기 때문에 메모리 날라가게 되므로 당연히 iter값도 날라가게 되는 것
		// 그래서 주소를 가져가야 한다
	}
	else
		cout << "존재하는 아이디가 없습니다." << endl;
	return Member->end();
}

void Menu(map<string, profile>::iterator Member)
{
	int select;
	while (1)
	{
		system("cls");
		cout << "==== Menu ====" << endl;
		cout << "1. 회원 정보" << endl;
		cout << "2. 회원 정보 변경" << endl;
		cout << "3. 로그 아웃" << endl;
		cout << "입력 : ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			Information(Member);
			break;
		}
		case 2:
		{
			Modify(Member);
			break;
		}

		case 3:
			return;
		}
		system("pause");
	}
}

void Information(map<string, profile>::iterator Member)
{
	system("cls");
	cout << "===== 회원 정보 =====" << endl;
	cout << "ID : " << Member->first;
	cout << "\t닉네임 : " << Member->second.name << endl;
	cout << "나이 : " << Member->second.age;
	cout << "\t휴대폰 번호 : " << Member->second.phone_number << endl;
	cout << "마일리지 : " << Member->second.mileage << "원" << endl;
}

void Modify(map<string, profile>::iterator Member)
{
	int select;
	while (1)
	{
		system("cls");
		Information(Member);
		cout << "1. 닉네임 변경" << endl;
		cout << "2. 나이 변경" << endl;
		cout << "3. 휴대폰 번호 변경" << endl;
		cout << "4. 돌아가기 " << endl;
		cout << "입력 : ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			string ModifyName;
			cout << "현재 닉네임 : " << Member->second.name << endl;
			cout << "변경할 닉네임 입력: ";
			cin >> ModifyName;
			cout << Member->second.name << "->" << ModifyName << endl;
			Member->second.name = ModifyName;
			break;
		}

		case 2:
		{
			int ModifyAge;
			cout << "현재 나이 : " << Member->second.age << endl;
			cout << "변경할 나이 입력: ";
			cin >> ModifyAge;
			cout << Member->second.age << "->" << ModifyAge << endl;
			Member->second.age = ModifyAge;
			break;
		}

		case 3:
		{
			int ModifyPhone;
			cout << "현재 휴대폰 번호: " << Member->second.phone_number << endl;
			cout << "변경할 휴대폰 번호 입력: ";
			cin >> ModifyPhone;
			cout << Member->second.age << "->" << ModifyPhone << endl;
			Member->second.phone_number = ModifyPhone;
			break;
		}

		case 4:
			return;
		}
		system("pause");
	}
}

void main()
{
	map<string, profile> Member;
	string ID;
	int select;
	while (1)
	{
		system("cls");
		cout << "==== Login ====" << endl;
		cout << "1. 회원 가입" << endl;
		cout << "2. 로그인" << endl;
		cout << "3. 종료" << endl;
		cout << "입력 : ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			system("cls");
			ID = ID_Create(Member);
			if (Member.size() <= MAX_MEMBER)
			{
				Member.insert(make_pair(ID, SignUp(Member)));
			}
			else
				cout << "가입 인원을 초과하였습니다." << endl;
			break;
		}

		case 2:
		{
			system("cls");
			map<string, profile>::iterator iter = LogIn(&Member);
			if (iter != Member.end())
				Menu(iter);
			break;
		}

		case 3:
			return;
		}
		system("pause");
	}
}