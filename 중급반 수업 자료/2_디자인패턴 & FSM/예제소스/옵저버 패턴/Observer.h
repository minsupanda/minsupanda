#pragma once
#include <vector>
#include <algorithm>
#include<iostream>
#include<string>
class Observer
{
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void update() abstract;
};

class Subject
{
private:
	std::vector<Observer*> m_Observer;

public:
	Subject() {}
	virtual ~Subject() { }

	void add(Observer*);
	void remove(Observer*);
	void notify();
};

void Subject::add(Observer* observer)
{
	m_Observer.push_back(observer);

	std::sort(m_Observer.begin(), m_Observer.end());
	m_Observer.erase(std::unique(m_Observer.begin(), m_Observer.end()), m_Observer.end());
}
void Subject::remove(Observer* observer)
{
	auto iter = find(m_Observer.begin(), m_Observer.end(), observer);
	if (m_Observer.end() != iter)
	{
		m_Observer.erase(iter);
	}
}
void Subject::notify()
{
	for (const auto& elem : m_Observer)
	{
		if(NULL != elem) elem->update();
	}
}