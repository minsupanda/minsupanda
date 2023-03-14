#include "AnimationManager.h"
#include"Character.h"


void AnimationManager::Play(std::function<void(Character&, int)> callbackFunc, Character *player)
// �̷������� ó������ Chracter&�� �޾Ƽ� �͹����� ����� ���ѵȴ�
// �Լ������͸� ����ϴ� ������ � ���� ������ ��ɸ� ������ְ� ���������� �Ǹ� �ش� �Լ��� ȣ�����ִ� ��
// ���ϸ��̼� ���忡���� ĳ���͵� ���͵� �����̵� ���� ������ ���ϸ��̼� ������ �Ű������� ���� ����Լ��� ȣ���ϸ� ��
// �׷��� ������ bind�� ����ؼ� �ѹ��� �������� �Լ������ͷ� ����ϸ� ���ϴ�
// �̷��� ���ϸ� �� ������Ʈ���� �����ε��ؼ� �ؾ��ϴ� ���ŷο��� �ִ�
{
	int oldClock = clock();
	cout << "���ϸ��̼� ������..." << endl;
	while (clock() - oldClock < 1000);
	callbackFunc(*player,100);
}
void AnimationManager::Play(std::function<void(Character&)> callbackFunc, Character* player)
{
	int oldClock = clock();
	cout << "���ϸ��̼� ������..." << endl;
	while (clock() - oldClock < 1000);
	callbackFunc(*player);
}