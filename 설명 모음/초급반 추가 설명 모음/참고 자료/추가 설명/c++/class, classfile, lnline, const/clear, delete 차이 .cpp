#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
using namespace std;

#define STUDENTMAX 50

void main()
{
	int Select;
	vector<string*> ptrStringList;
	string* studentTmp;
	while (1)
	{
		system("cls");
		cout << "====학생정보관리===(학생수 : " << ptrStringList.size() << "명)" << endl;
		cout << "   1.학생등록" << endl;
		cout << "   2.학생정보 보기" << endl;
		cout << "   3.종료" << endl;
		cout << " 입력 : " << endl;
		cin >> Select;
		switch (Select)
		{
		case 1:
			if (ptrStringList.size() < STUDENTMAX)
			{
				studentTmp = new string;
				cout << ptrStringList.size() + 1 << "번 학생 이름 : ";
				cin >> *studentTmp;
				ptrStringList.push_back(studentTmp);
			}
			break;
		case 2:
			for (int i = 0; i < ptrStringList.size(); i++)
				cout << i + 1 << "번 학생 : " << *ptrStringList[i] << endl;
			system("pause");
			break;
		case 3:
			for (int i = 0; i < ptrStringList.size(); i++)
			{
				cout << *ptrStringList[i] << "학생" << endl;
				delete ptrStringList[i];
				cout << "할당 해제 완료" << endl;
			// 여기서는 new를 사용해 동적할당한 메모리를 해제하는 것
			// 그러면 continer로 만들어진 vector의 공간안에 동적할당이 된 것이기 때문에 vector의 크기는 여전히 줄어들지 않는다
			// 여기서 다시 접근해서 사용하는 것은 오류 : 언제 오류가 터질지 모르기때문에 c언에서도 null을 넣고 오류를 피하고자 하는 것
			}
			ptrStringList.clear();
			//여기서 clear를 해주는 것이 vector에 저장된 메모리들을 날려버리는 것
			//굳이 종료할때 사용할 필요는 없지만 계속 코드가 진행되는 상황이라면
			//해제된 메모리를 가지고 있는 vector에는 접근하면 안되기 때문에 clear를 해주어야 한다

			system("pause");
			return;
		}
	}
}