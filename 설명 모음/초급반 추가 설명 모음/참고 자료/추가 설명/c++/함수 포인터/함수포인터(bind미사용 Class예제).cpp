#include "AnimationManager.h"
#include"Character.h"


void AnimationManager::Play(std::function<void(Character&, int)> callbackFunc, Character *player)
// 이런식으로 처음부터 Chracter&를 받아서 와버리면 사용이 제한된다
// 함수포인터를 사용하는 목적은 어떤 값이 들어오든 기능만 대신해주고 일정시점이 되면 해당 함수를 호출해주는 것
// 에니메이션 입장에서는 캐릭터든 몬스터든 무엇이든 값만 들어오면 에니메이션 돌리고 매개변수로 받은 멤버함수만 호출하면 됨
// 그렇기 때문에 bind를 사용해서 한번에 묶은다음 함수포인터로 사용하면 편리하다
// 이렇게 안하면 각 오브젝트마다 오버로딩해서 해야하는 번거로움이 있다
{
	int oldClock = clock();
	cout << "에니메이션 실행중..." << endl;
	while (clock() - oldClock < 1000);
	callbackFunc(*player,100);
}
void AnimationManager::Play(std::function<void(Character&)> callbackFunc, Character* player)
{
	int oldClock = clock();
	cout << "에니메이션 실행중..." << endl;
	while (clock() - oldClock < 1000);
	callbackFunc(*player);
}