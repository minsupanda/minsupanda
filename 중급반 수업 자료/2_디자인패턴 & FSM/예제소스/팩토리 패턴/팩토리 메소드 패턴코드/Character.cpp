#include "Character.h"

Character::Character(){}
Character::~Character(){}
//인간종족
void Human::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Human::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Human::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Human::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Human::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("인간의 재생력");
	vec_Trait.push_back("외교");
	vec_Trait.push_back("인간의 정신력");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++,i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}

//드워프종족
void Dwarf::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Dwarf::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Dwarf::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Dwarf::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Dwarf::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("탐험가");
	vec_Trait.push_back("냉기 마법 저항");
	vec_Trait.push_back("신의 강대함");
	vec_Trait.push_back("석화");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}

//나이트엘프 종족
void Night_Elf::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Night_Elf::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Night_Elf::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Night_Elf::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Night_Elf::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("그림자 숨기");
	vec_Trait.push_back("위습의 영혼");
	vec_Trait.push_back("자연 저항력");
	vec_Trait.push_back("민첩");
	vec_Trait.push_back("엘룬의 손길");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}



//노움종족
void Gnome::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Gnome::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Gnome::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Gnome::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Gnome::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("탈출의 명수");
	vec_Trait.push_back("비전 저항력");
	vec_Trait.push_back("영리함");
	vec_Trait.push_back("기계공학 전문화");
	vec_Trait.push_back("날렵한 손가락");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}

//드레나이종족
void Draenei::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Draenei::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Draenei::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Draenei::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Draenei::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("나루의 선물");
	vec_Trait.push_back("용맹의 기운");
	vec_Trait.push_back("암흑 저항력");
	vec_Trait.push_back("보석 연마술");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}

//늑대인간종족
void Worgen::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Worgen::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Worgen::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Worgen::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Worgen::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("야생 질주");
	vec_Trait.push_back("돌연변이");
	vec_Trait.push_back("암흑군단");
	vec_Trait.push_back("갈퀴손");
	vec_Trait.push_back("포악함");
	vec_Trait.push_back("두 가지 모습");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}

//판다랜종족
void Pandaren::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Pandaren::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Pandaren::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Pandaren::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Pandaren::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("진영: 중립");
	vec_Trait.push_back("식도락");
	vec_Trait.push_back("대식가");
	vec_Trait.push_back("평상심");
	vec_Trait.push_back("오동통");
	vec_Trait.push_back("전율의 장풍");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}

//오크종족
void Orc::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Orc::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Orc::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Orc::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Orc::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("피의 격노");
	vec_Trait.push_back("강인함");
	vec_Trait.push_back("지배");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}

//언데드종족
void Undead::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Undead::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Undead::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Undead::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Undead::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("포세이큰의 의지");
	vec_Trait.push_back("암흑 저항력");
	vec_Trait.push_back("시체먹기");
	vec_Trait.push_back("저승의 손길");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}

//타우렌종족
void Tauren::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Tauren::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Tauren::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Tauren::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Tauren::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("우직함");
	vec_Trait.push_back("재배");
	vec_Trait.push_back("인내력");
	vec_Trait.push_back("자연 저항력");
	vec_Trait.push_back("전투 발구르기");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}

//트롤종족
void Troll::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Troll::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Troll::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Troll::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Troll::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("광폭화");
	vec_Trait.push_back("부두 춤");
	vec_Trait.push_back("재생력");
	vec_Trait.push_back("야수 사냥 전문화");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}

//블러드엘프종족
void Blood_Elf::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Blood_Elf::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Blood_Elf::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Blood_Elf::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Blood_Elf::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("비전 지각");
	vec_Trait.push_back("비전 격류");
	vec_Trait.push_back("비전 친화");
	vec_Trait.push_back("마법 저항력");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}

//고블린종족
void Goblin::Make_Body()
{
	cout << m_szname << "의 몸생성!!" << endl;
}
void Goblin::Make_Arms()
{
	cout << m_szname << "의 팔생성!!" << endl;
}
void Goblin::Make_Legs()
{
	cout << m_szname << "의 다리생성!!" << endl;
}
void Goblin::Make_Face()
{
	cout << m_szname << "의 얼굴생성!!" << endl;
}
void Goblin::Make_Trait()
{
	cout << endl << m_szname << "의 특성생성!!" << endl;
	vec_Trait.push_back("로켓 도약");
	vec_Trait.push_back("로켓 연발탄");
	vec_Trait.push_back("짐꾼 밥통고블린");
	vec_Trait.push_back("거래의 달인");
	vec_Trait.push_back("시간은 돈");
	vec_Trait.push_back("연금술로 나아지는 삶");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "특성" << i << " : " << *iter << " 생성!!" << endl;
}

