#include <iostream>
#include "Miner.h"
#include "ConsoleUtils.h"
#include "EntityNames.h"


int main()
{
	Miner miner(ent_Miner_Bob);

	for (int i = 0; 20 > i; i++)
	{
		miner.Update();

		Sleep(1000);
	}

	PressAnyKeyToContinue();
}