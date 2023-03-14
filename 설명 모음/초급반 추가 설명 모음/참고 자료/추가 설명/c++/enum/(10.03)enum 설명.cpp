#include <iostream>
using namespace std;

#define WEAPON_SWORD 0
#define WEAPON_WAND 1
#define WEAPON_BOW 2
#define WEAPON_HAMMER 3
#define WEAPON_AXE 4
#define WEAPON_CLAW 5
#define WEAPON_DAGGER 6

enum WEAPON_TYPE
{
	START, // 요소, 항목
	SWORD = 0,
	WAND,
	BOW,
	HAMMER,
	AXE,
	CLAW,
	DAGGER,
	END
};

void PrintWeapon(WEAPON_TYPE weapon)
{
	switch (weapon)
	{
	case SWORD:
		cout << "장검" << endl;
		break;

	case WAND:
		cout << "지팡이" << endl;
		break;
	case BOW:
		cout << "활" << endl;
		break;
	case HAMMER:
		cout << "망치" << endl;
		break;
	case AXE:
		cout << "도끼" << endl;
		break;
	case CLAW:
		cout << "클로" << endl;
		break;
	case DAGGER:
		cout << "단검" << endl;
		break;
	default :
		break;
	}
}

void main()
{
	WEAPON_TYPE WeaponList[WEAPON_TYPE::END];
	
	for (int i = WEAPON_TYPE::START; i != WEAPON_TYPE::END; i++)
		WeaponList[i] = (WEAPON_TYPE)i;

	for (int i = 0; i < WEAPON_TYPE::END; i++)
		PrintWeapon(WeaponList[i]);

	//foreach
	for (WEAPON_TYPE weapon : WeaponList)
		PrintWeapon(weapon);
}