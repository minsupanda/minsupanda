#include<iostream>
#include<vector>
#include<Windows.h>
#include<crtdbg.h>
#include"Character.h"
#include"CampFactory.h"
using namespace std;
vector<Character*> vec_pCharacterList;
int Camp_Menu()
{
	system("cls");
	int choice;
	cout << "┌────────────────┐" << endl;
	cout << "│	◎ 진영 목록 ◎		  │" << endl;
	cout << "│	1.얼라이언 진영		  │" << endl;
	cout << "│	2.호드 진영		  │" << endl;
	cout << "│	3.종료			  │" << endl;
	cout << "└────────────────┘" << endl;
	cout << "	선택 : ";
	cin >> choice;
	return choice;
}

void Horde_Menu()
{
	int choice;
	system("cls");
	cout << "┌───────────┐" << endl;
	cout << "│   ● 호드 진영 ●	│" << endl;
	cout << "│	1.오크		│" << endl;
	cout << "│	2.언데드	│" << endl;
	cout << "│	3.타우렌	│" << endl;
	cout << "│	4.트롤		│" << endl;
	cout << "│	5.블러드엘프	│" << endl;
	cout << "│	6.고블린	│" << endl;
	cout << "│	7.판다렌	│" << endl;
	cout << "└───────────┘" << endl;
	cout << "선택 :";
	cin >> choice;
	switch (choice)
	{
	case 1:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("오크"));
		break;
	case 2:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("언데드"));
		break;
	case 3:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("타우렌"));
		break;
	case 4:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("트롤"));
		break;
	case 5:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("블러드엘프"));
		break;
	case 6:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("고블린"));
		break;
	case 7:
		vec_pCharacterList.push_back(HordeCamp::GetInstans()->OrderCharacter("판다렌"));
		break;
	default:
		break;
	}
	system("pause");
}

void Alliance_Menu()
{
	Character* tmp;
	int choice;
	system("cls");
	cout << "┌───────────────┐" << endl;
	cout << "│     ● 얼라이언 진영 ●	│" << endl;
	cout << "│	1.인간			│" << endl;
	cout << "│	2.드워프		│" << endl;
	cout << "│	3.나이트엘프		│" << endl;
	cout << "│	4.노움			│" << endl;
	cout << "│	5.드레나이		│" << endl;
	cout << "│	6.늑대인간		│" << endl;
	cout << "│	7.판다렌		│" << endl;
	cout << "└───────────────┘" << endl;
	cout << "선택 :";
	cin >> choice;
	switch (choice)
	{
	case 1:
		tmp = AllianceCamp::GetInstans()->OrderCharacter("인간");
		if(tmp != NULL)
			vec_pCharacterList.push_back(tmp);
		break;
	case 2:
		vec_pCharacterList.push_back(AllianceCamp::GetInstans()->OrderCharacter("드워프"));
		break;
	case 3:
		vec_pCharacterList.push_back(AllianceCamp::GetInstans()->OrderCharacter("나이트엘프"));
		break;
	case 4:
		vec_pCharacterList.push_back(AllianceCamp::GetInstans()->OrderCharacter("노움"));
		break;
	case 5:
		vec_pCharacterList.push_back(AllianceCamp::GetInstans()->OrderCharacter("드레나이"));
		break;
	case 6:
		vec_pCharacterList.push_back(AllianceCamp::GetInstans()->OrderCharacter("늑대인간"));
		break;
	case 7:
		vec_pCharacterList.push_back(AllianceCamp::GetInstans()->OrderCharacter("판다렌"));
		break;
	default:
		break;
	}
	system("pause");
}


void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 193;
	while (1)
	{
		switch (Camp_Menu())
		{
		case 1:
			Alliance_Menu();
			break;
		case 2:
			Horde_Menu();
			break;
		case 3:
			int i = 1;
			cout << "생성된 캐릭터" << endl;
			for (auto iter = vec_pCharacterList.begin(); iter != vec_pCharacterList.end(); iter++,i++)
			{
				cout << i << "." << (*iter)->GetName() <<"(" << (*iter)->GetCampName() << ")" << endl;
				delete *iter;
			}
			AllianceCamp::GetInstans()->Release();
			HordeCamp::GetInstans()->Release();
			exit(1);
			break;
		}
	}

}