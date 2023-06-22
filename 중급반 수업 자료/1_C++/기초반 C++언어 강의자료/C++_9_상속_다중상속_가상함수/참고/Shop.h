#pragma once
#include"Weapon.h"
#include"MapDraw.h"
#include"Mecro.h"
#include"Character.h"
class Shop
{
private:
	MapDraw m_DrawManager;
	Weapon** m_pWeaponList;
	int m_iWeaponCount;
public:
	int GetWeaponCount();
	void ShopMenu(Character* Player);
	void WeaponMenu(Character* Player,WEAPON Type);
	string GetTypeString(WEAPON Type);
	Shop();
	~Shop();
};

