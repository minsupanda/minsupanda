#pragma once
#include "BaseGameEntity.h"
#include "Locations.h"

#define COMFORT_LEVEL		5	// 안락함을 느끼는 금덩이의 양.
#define MAX_NUGGETS			3	// 최대 소지금.
#define THIRST_LEVEL		5	// 갈증 한계.
#define TIREDNESS_THRESHOLD	5	// 피로 한계.

class Miner;
class State
{
public:
	virtual ~State() {}

	virtual void Enter(Miner*) abstract;
	virtual void Excute(Miner*) abstract;
	virtual void Exit(Miner*) abstract;
};

class Miner : public BaseGameEntity
{
private:
	State*			m_pCurrState;
	Location_Type	m_Location;
	int				m_nGoldCarried;	// 광부가 광산에서 캔 금덩이의 양.
	int				m_nMoneyInBank;	// 저축 금액.
	int				m_nThirst;		// 갈증도.
	int				m_nFatigue;		// 피로도.

public:
	Miner(const int& id);
	virtual ~Miner() {}

	void Update() override;
	void ChangeState(State*);

	Location_Type Location() const { return m_Location; }
	void ChangeLocation(const Location_Type& loc_type) { m_Location = loc_type; }

	int GoldCarried() const { return m_nGoldCarried; }
	void SetGoldCarried(const int& value) { m_nGoldCarried = value; }
	void AddToGoldCarried(const int&);
	bool PocketsFull() const { return (MAX_NUGGETS <= m_nGoldCarried); }

	bool Fatigued() const;
	void DecreaseFatigue() { m_nFatigue--; }
	void IncreaseFatigue() { m_nFatigue++; }

	int Wealth() const { return m_nMoneyInBank; }
	void SetWealth(const int& value) { m_nMoneyInBank = value; }
	void AddToWealth(const int&);

	bool Thirsty() const;
	void BuyAndDrinkAWhiskey() { m_nThirst = 0; m_nMoneyInBank -= 2; }
};