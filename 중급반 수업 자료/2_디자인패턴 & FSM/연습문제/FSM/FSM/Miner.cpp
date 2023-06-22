#include "Miner.h"
#include "MinerOwnedStates.h"
#include <cassert>

Miner::Miner(const int& id) :
	BaseGameEntity(id),
	m_Location(Location_Type::shack),
	m_nGoldCarried(0),
	m_nMoneyInBank(0),
	m_nThirst(0),
	m_nFatigue(0),
	m_pCurrState(GoHomeAndSleepTilRested::Instance()) { }

void Miner::Update()
{
	m_nThirst += 1;

	if (m_pCurrState)
	{
		m_pCurrState->Excute(this);
	}
}

void Miner::ChangeState(State* pState)
{
	assert(m_pCurrState && pState);

	m_pCurrState->Exit(this);
	m_pCurrState = pState;
	m_pCurrState->Enter(this);
}

void Miner::AddToGoldCarried(const int& value)
{
	m_nGoldCarried += value;
	if (m_nGoldCarried < 0)
	{
		m_nGoldCarried = 0;
	}
}

void Miner::AddToWealth(const int& value)
{
	m_nMoneyInBank += value;
	if (m_nMoneyInBank < 0)
	{
		m_nMoneyInBank = 0;
	}
}

bool Miner::Thirsty() const
{
	if (THIRST_LEVEL <= m_nThirst)
	{
		return true;
	}

	return false;
}

bool Miner::Fatigued() const
{
	if (TIREDNESS_THRESHOLD < m_nFatigue)
	{
		return true;
	}

	return false;
}