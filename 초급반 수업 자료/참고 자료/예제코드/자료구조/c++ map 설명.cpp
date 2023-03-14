#include<stdio.h>
#include<map>//Red Black Tree
#include<time.h>
#include<string.h>
#define SIZE 4
//map : key value : 한 쌍으로 묶어서 관리한다.
//쇼핑몰 회원 : 회원번호(id),회원정보(value)
//key : 중복되지 않는 고유 정보를 선정한다.

struct Member
{
	char Name[256];
	int Age;
};

Member CreateMember()
{
	Member member;
	//이름 랜덤생성
	int rnum = rand() % 4 + 1;
	switch (rnum)
	{
	case 1:
		strcpy(member.Name, "아랑");
		break;
	case 2:
		strcpy(member.Name, "민호");
		break;
	case 3:
		strcpy(member.Name, "혜진");
		break;
	case 4:
		strcpy(member.Name, "민우");
		break;
	case 5:
		strcpy(member.Name, "현우");
		break;
	}
	//나이 랜덤생성
	member.Age = rand() % 51 + 16;
	return member;
}

void PrintMap(std::map<int, Member> MemberMap)
{
	for (std::map<int, Member>::iterator iter = MemberMap.begin(); iter != MemberMap.end(); iter++)
	{
		printf("%d %s %d살\n", iter->first, iter->second.Name, iter->second.Age);
	}
	printf("==============================\n");
}

void main()
{
	srand(time(NULL));
	std::map<int, Member> MemberMap;
	//int : key값, Member : value값
	int NumberCount = 1;
	for (int i = 0; i < 5; i++)
		MemberMap[NumberCount++] = CreateMember();
	// 배열처럼 인덱스에 접근해서 데이터 저장
	// key값은 중복되면 안되기 때문에 증가시킴

	MemberMap.insert(std::make_pair(NumberCount++, CreateMember()));
	// 함수방식으로 데이터 저장
	PrintMap(MemberMap);

	MemberMap[1] = CreateMember();
	//key값 1에 데이터는 이미 저장되어 있음 -> 데이터가 덮어씌워짐 즉, 수정
	//다만 insert를 활용한 수정은 불가능, 해당 key값에 데이터가 있을 경우 아예 기능을 실행하지 않는다
	PrintMap(MemberMap);

	MemberMap[1].Age = 70;
	PrintMap(MemberMap);

	std::map<int, Member>::iterator iter = MemberMap.find(12);
	if(iter != MemberMap.end())
	{
		printf("%d %s %d살\n", iter->first, iter->second.Name, iter->second.Age);
	}
	else
	{
		printf("존재하지 않는 회원입니다.\n");
	}

	MemberMap.erase(12);
	PrintMap(MemberMap);

	MemberMap.at(1).Age;
	MemberMap[1].Age;
	//위 2개는 같은 기능이나 수정을 하고 싶을 때는 at은 불가능
	//함수처럼 사용되는 문법이기 때문에 깊은복사가 되서 데이터가 수정되지 않음
}