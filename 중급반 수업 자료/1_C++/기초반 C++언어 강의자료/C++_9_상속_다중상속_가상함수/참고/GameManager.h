#pragma once
#include"Character.h"
#include"MapDraw.h"
#include"Shop.h"

enum FILESTATE
{
	FILESTATE_SAVE,
	FILESTATE_LOAD
};

class GameManager
{
	Character* m_pPlayer;
	Character* m_pMonster;
	MapDraw m_DrawManager;
	Shop m_Shop;
	string m_strPlayerFileName;
	string m_strMonsterFileName;
	int m_iMonsterCount;
	bool m_bGameExit;	
	void Fight(Character* Player, Character* Monster);
	void Dongeon();
	void Save();
	bool Load(STARTTYPE StartType);
	bool FileList(FILESTATE State);
	void Play();
	bool Init(STARTTYPE StartType);
	void Delete();
	void TitleDraw();
	void RSPDraw(RSP Rsp,int x,int y);
public:
	void GameTitleScene();
	GameManager();
	~GameManager();
};

