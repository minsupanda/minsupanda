#pragma once

class BaseGameEntity
{
private:
	int m_nID;

	static int m_nNextVaildID;

	void SetID(const int&);

public:
	BaseGameEntity(const int& id) { SetID(id); }
	virtual ~BaseGameEntity() {}

	virtual void Update() abstract;
	int ID() const { return m_nID; }
};