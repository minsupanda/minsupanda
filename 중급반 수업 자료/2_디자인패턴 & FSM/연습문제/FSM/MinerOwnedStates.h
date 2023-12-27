#pragma once
#include "Miner.h"


class EnterMineAndDigForNugget : public State
{
private:
	EnterMineAndDigForNugget() {}
	EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);
	EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);

public:
	static EnterMineAndDigForNugget* Instance();

	virtual void Enter(Miner*);
	virtual void Excute(Miner*);
	virtual void Exit(Miner*);
};

class VisitBankAndDepositGold : public State
{
private:
	VisitBankAndDepositGold() {}
	VisitBankAndDepositGold(const VisitBankAndDepositGold&);
	VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);

public:
	static VisitBankAndDepositGold* Instance();

	virtual void Enter(Miner*);
	virtual void Excute(Miner*);
	virtual void Exit(Miner*);
};

class GoHomeAndSleepTilRested : public State
{
private:
	GoHomeAndSleepTilRested() {}
	GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
	GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested&);

public:
	static GoHomeAndSleepTilRested* Instance();

	virtual void Enter(Miner*);
	virtual void Excute(Miner*);
	virtual void Exit(Miner*);
};

class QuenchThirst : public State
{
private:
	QuenchThirst() {}
	QuenchThirst(const QuenchThirst&);
	QuenchThirst& operator=(const QuenchThirst&);

public:
	static QuenchThirst* Instance();

	virtual void Enter(Miner*);
	virtual void Excute(Miner*);
	virtual void Exit(Miner*);
};