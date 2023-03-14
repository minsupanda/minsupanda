#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//종족 부모 Class
class Character
{
protected:
	string m_szname;
	string m_szCampName;
	vector<string> vec_Trait;
public:
	virtual void Make_Body() = 0;
	virtual void Make_Arms() = 0;
	virtual void Make_Legs() = 0;
	virtual void Make_Face() = 0;
	virtual void Make_Trait() = 0;
	inline void SetName(string name,string name2)
	{
		this->m_szname = name;
		this->m_szCampName = name2;
	}	
	inline string GetName()
	{
		return m_szname;
	}
	inline string GetCampName()
	{
		return m_szCampName;
	}
	Character();
	~Character();
};
//인간종족
class Human : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//드워프 종족
class Dwarf : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//나이트엘프 종족
class Night_Elf : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//노움 종족
class Gnome : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//드레나이 종족
class Draenei : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//늑대인간 종족
class Worgen : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//판다랜 종족
class Pandaren : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//오크 종족
class Orc : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//언데드 종족
class Undead : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//타우렌 종족
class Tauren : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//트롤 종족
class Troll : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//블러드엘프 종족
class Blood_Elf : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
//고블린 종족
class Goblin : public Character
{
public:
	virtual void Make_Body();
	virtual void Make_Arms();
	virtual void Make_Legs();
	virtual void Make_Face();
	virtual void Make_Trait();
};
