#include<stdio.h>
#include<list>
#include<vector>

void Print(std::list<int> iList) // 똑같이 매개변수 가져오고
{
	// iterator : 포인터는 아니지만 포인터와 역할은 비슷, 컨테이너에 저장되어있는 원소들을 참조할 때 사용하는 것
	// 포인터가 주소를 참조해서 데이터에 접근하는 방식
	// iterator(반복자)는 list에 저장된 각각의 데이터 위치를 가리키는 것
	// begin : list의 가장 첫번째 위치를 반환해주는 문법
	// end : NULL과 비슷하게 가장 마지막에 저장된 데이터 다음에 있는 것
	// iter++는 iter에 저장된 값을 더해주는 것이 아닌 list에 저장된 다음 데이터를 가리키는 것
	for (std::list<int>::iterator iter = iList.begin(); iter != iList.end(); iter++)
	{
		printf("%d ", *iter);
		//iterator는 포인터처럼 list에 저장된 위치를 참조하는 것이기 때문에 문법상으로 *가 들어가는 것
	}
	printf("\n");
}

std::list <int>::iterator Search(std::list<int>* iList, int Data)
{
	//begin부터 시작해, end까지 반복문
	for (std::list<int>::iterator iter = iList->begin(); iter != iList->end(); iter++)
	{
		if (*iter == Data)
			return iter;
		// 찾는 데이터 있으면 해당 데이터 반환
	}
	return iList->end();
	// 없으면 end반환
}

void SearchData(std::list<int> iList, int Data)
{
	std::list<int>::iterator iter = std::find(iList.begin(), iList.end(), Data);
	// find : 라이브러리에서 제공되는 검색 함수
	// being부터 end까지 중에서 Data를 찾는 것
	// 시작과 끝은 iterator를 활용해서 커스텀 가능 (이 기능은 오버??뭐시기 : 나중에 c++배울 때 학습)
	// 하지만 이러한 방법은 == 연산자가 사용가능한 데이터만 찾을 수 있다
	// int, double, float, char 이런 애들은 찾을 수 있지만 str, 구조체는 변수의 이름이 시작주소를 가지고 있으므로 데이터를 비교할 수 없기 떄문이다.
	// 그러므로 위와 같은 경우는 따로 함수를 만들어서 찾아야 한다.
	if (iter == iList.end())
		// 마지막 데이터 다음에 end가 있고 찾지 못했을 경우 end를 반환하기 때문이다
		printf("%d 데이터를 찾지 못했습니다.\n", Data);
	else
		printf("%d 데이터를 찾았습니다.\n", Data);
}

void AddData(std::list<int>* iList, int Data, int Add) // 내가 원하는 위치에 데이터 추가
{
	std::list<int>::iterator iter = Search(iList, Data);
	// 내가 원하는 위치 찾고
	if (iter != iList->end()) // 찾았을 경우
		iList->insert(iter, Add); // insert : 라이브러에서 제공하는 함수로 해당 위치 앞에 추가
}

void ModifyData(std::list<int>* iList, int Data, int ModifyData) // 데이터 수정
{
	// 추가와 거의 비슷
	std::list<int>::iterator iter = Search(iList, Data);
	if (iter != iList->end())
		*iter = ModifyData;
}

void DeleteData(std::list<int>* iList, int Data)
{
	std::list<int>::iterator iter = Search(iList, Data);
	if (iter != iList->end())
		iList->erase(iter); // erase : 라이브러리에서 제공하는 함수로 해당 위치의 데이터 삭제
}


void main()
{
	// 저장, 출력, 검색, 추가, 수정, 삭제
	std::list<int>iList;

	for (int i = 1; i <= 10; i++)
	{
		iList.push_back(i); // back은 가장 뒤에 데이터 저장
	}
	iList.push_front(200); // front는 가장 앞에 데이터 저장
	Print(iList); // 저장한 데이터 출력
	SearchData(iList, 5); // 데이터 검색
	SearchData(iList, 15);

	AddData(&iList, 5, 15); // 데이터 추가
	Print(iList);
	ModifyData(&iList, 15, 30); // 데이터 수정
	Print(iList);
	ModifyData(&iList, 200, 0);
	Print(iList);

	iList.pop_front(); // 가장 앞의 데이터 삭제
	Print(iList);

	iList.pop_back(); // 가장 뒤의 데이터 삭제
	Print(iList);

	DeleteData(&iList, 30); // 원하는 위치 데이터 삭제
	Print(iList);

	iList.sort(); // 오름차순
	iList.reverse(); // 역순 (내림차순은 오름차순 정렬후 reverse하면 된다)
	Print(iList);

	iList.sort();
	Print(iList); // 오름차순

	iList.clear(); // 전체삭제
}