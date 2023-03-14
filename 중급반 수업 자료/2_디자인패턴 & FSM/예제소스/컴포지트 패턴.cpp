#include <iostream>
#include <vector>
#include <algorithm>

// Component
__interface Component
{
	void Operation();
};

// Composite
class GameObject : public Component
{
private:
	std::vector<Component*> components;

public:
	void Operation() override
	{
		for (Component* component : components)
		{
			component->Operation();
		}
	}
	void AddComponent(Component* component) { if(NULL != component) components.push_back(component); }
	void RemoveComponent(Component* component)
	{
		if (NULL == component) return;
		auto iter = std::find(components.begin(), components.end(), component);
		if (components.end() != iter) components.erase(iter);
	}
};

// Leaf
class PlayerInput : public Component
{
public:
	void Operation() override { std::cout << "User Input" << std::endl; }
};
class EnemyInput : public Component
{
public:
	void Operation() override { std::cout << "AI Processing" << std::endl; }
};
class Physics : public Component
{
public:
	void Operation() override { std::cout << "Physics Processing" << std::endl; }
};
class Graphics : public Component
{
public:
	void Operation() override { std::cout << "Graphics Processing" << std::endl; }
};


void main()
{
	PlayerInput playerInput;
	EnemyInput enemyInput;
	Physics physics;
	Graphics graphics;

	std::cout << "=== Set Player Components ===" << std::endl;
	GameObject player;
	player.AddComponent(&playerInput);
	player.AddComponent(&physics);
	player.AddComponent(&graphics);
	player.Operation();

	std::cout << std::endl << "=== Set Enemy Components ===" << std::endl;
	GameObject enemy;
	enemy.AddComponent(&enemyInput);
	enemy.AddComponent(&physics);
	enemy.AddComponent(&graphics);
	enemy.RemoveComponent(&physics);
	enemy.Operation();
}
