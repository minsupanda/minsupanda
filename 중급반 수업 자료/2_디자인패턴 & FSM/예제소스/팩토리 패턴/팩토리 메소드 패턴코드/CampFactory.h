#pragma once
#include"Character.h"

class CampFactory
{
private:
	virtual void CreateCharacter(string name) = 0;
protected:
	Character* m_pCharaceter;
public:
	Character* OrderCharacter(string name);
	CampFactory();
	~CampFactory();
};

class HordeCamp :public CampFactory
{
private:
	virtual void CreateCharacter(string name);
	static HordeCamp* m_hThis;
public:
	static HordeCamp* GetInstans()
	{
		if (m_hThis == NULL)
			m_hThis = new HordeCamp;
		return m_hThis;
	}
	static inline void Release()
	{
		delete m_hThis;
	}
};

class AllianceCamp :public CampFactory
{
private:
	virtual void CreateCharacter(string name);
	static AllianceCamp* m_hThis;
public:
	static AllianceCamp* GetInstans()
	{
		if (m_hThis == NULL)
			m_hThis = new AllianceCamp;
		return m_hThis;
	}
	static inline void Release()
	{
		delete m_hThis;
	}
};

