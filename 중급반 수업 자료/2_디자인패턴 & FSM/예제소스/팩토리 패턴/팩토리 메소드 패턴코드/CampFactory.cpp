#include "CampFactory.h"



CampFactory::CampFactory()
{
	m_pCharaceter = NULL;
}

Character* CampFactory::OrderCharacter(string name)
{
	CreateCharacter(name);
	if(m_pCharaceter != NULL)
	{
		m_pCharaceter->Make_Body();
		m_pCharaceter->Make_Arms();
		m_pCharaceter->Make_Legs();
		m_pCharaceter->Make_Face();
		m_pCharaceter->Make_Trait();
	}
	return m_pCharaceter;
}

CampFactory::~CampFactory()
{
}

HordeCamp* HordeCamp::m_hThis = NULL;
void HordeCamp::CreateCharacter(string name)
{
	if (name == "오크")
		m_pCharaceter = new Orc;
	else if (name == "언데드")
		m_pCharaceter = new Undead;
	else if (name == "타우렌")
		m_pCharaceter = new Tauren;
	else if (name == "트롤")
		m_pCharaceter = new Troll;
	else if (name == "블러드엘프")
		m_pCharaceter = new Blood_Elf;
	else if (name == "고블린")
		m_pCharaceter = new Goblin;
	else if (name == "판다렌")
		m_pCharaceter = new Pandaren;
	else
		cout << "해당 종족이 없습니다.";
	m_pCharaceter->SetName(name,"호드");
}

AllianceCamp* AllianceCamp::m_hThis = NULL;
void AllianceCamp::CreateCharacter(string name)
{
	if (name == "인간")
		m_pCharaceter = new Human;
	else if (name == "드워프")
		m_pCharaceter = new Dwarf;
	else if (name == "나이트엘프")
		m_pCharaceter = new Night_Elf;
	else if (name == "노움")
		m_pCharaceter = new Gnome;
	else if (name == "드레나이")
		m_pCharaceter = new Draenei;
	else if (name == "늑대인간")
		m_pCharaceter = new Worgen;
	else if (name == "판다렌")
		m_pCharaceter = new Pandaren;
	else
	{
		m_pCharaceter = NULL;
		cout << "해당 종족이 없습니다.";
	}
	if(m_pCharaceter != NULL)
		m_pCharaceter->SetName(name, "얼라이언스");
}
