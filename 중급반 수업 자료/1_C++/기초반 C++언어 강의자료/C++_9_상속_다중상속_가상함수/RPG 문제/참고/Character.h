#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"Weapon.h"

#define UPATTACKSTAT 4
#define UPHEALTHSTAT 10
enum RSP
{
	RSP_START,
	RSP_SCISSOR= 0,
	RSP_ROCK,
	RSP_PAPER,
	RSP_END
};

enum CHARACTER
{
	CHARACTER_PLAYER,
	CHARACTER_MONSTER
};


class Character
{
private:
	MapDraw		m_DrawManager;
	string		m_strName;
	Weapon		*m_pWeapon;
	int			m_iDamage;
	int			m_iCurHealth;
	int			m_iMaxHealth;
	int			m_iExp;
	int			m_iMaxExp;
	int			m_iGetExp;
	int			m_iLv;
	int			m_iGold;
	CHARACTER	m_eType;
public:
	void ShowInfo(int x,int y);
	void Hit(int Damage);
	void Attack(Character* Enemy);
	void LvUp();
	bool ExpUp(Character& Enemy);
	void SetInfo(ifstream& Load, CHARACTER Type,STARTTYPE StartType);
	void ResetExp();
	void ResetHealth();
	void Save(ofstream& Save);
	void DeleteWeapon();
	RSP GetRSP();
	void Buy(Weapon* weapon);
	inline int GetExp()
	{
		return m_iGetExp;
	}
	inline int GetDamage()
	{
		return m_iDamage;
	}
	inline CHARACTER GetType()
	{
		return m_eType;
	}
	inline string GetName()
	{
		return m_strName;
	}
	inline int GetGold()
	{
		return m_iGold;
	}
	inline int GetHealth()
	{
		return m_iCurHealth;
	}
	Character();
	~Character();
};

