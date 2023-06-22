#pragma once
#include <iostream>

// GoF /////////////////////////////////////////

namespace Abstract
{
	class Weapon
	{
	public:
		virtual int Power() abstract;
	};
	class Bow : public Weapon
	{
	public:
		int Power() override
		{
			return 200;
		}
	};
	class Sword : public Weapon
	{
	public:
		int Power() override
		{
			return 50;
		}
	};

	class Armor
	{
	public:
		virtual int Defence() abstract;
	};
	class Leather : public Armor
	{
	public:
		int Defence() override
		{
			return 50;
		}
	};
	class Plate : public Armor
	{
	public:
		int Defence() override
		{
			return 200;
		}
	};

	class EquipmentAbstractFactory
	{
	public:
		virtual Weapon* CreateWeapon() abstract;
		virtual Armor* CreateArmor() abstract;
	};
	// 인터페이스 구현으로 어떤 객체를 만들지 결정.
	class ArcherEquipment : public EquipmentAbstractFactory
	{
	public:
		Weapon* CreateWeapon() override
		{
			return new Bow;
		}
		Armor* CreateArmor() override
		{
			return new Leather;
		}
	};
	class WarriorEquipment : public EquipmentAbstractFactory
	{
	public:
		Weapon* CreateWeapon() override
		{
			return new Sword;
		}
		Armor* CreateArmor() override
		{
			return new Plate;
		}
	};

	class Character
	{
	protected:
		Weapon* m_Weapon;
		Armor* m_Armor;

	public:
		Character(EquipmentAbstractFactory* equipment)
		{
			this->m_Weapon = equipment->CreateWeapon();
			this->m_Armor = equipment->CreateArmor();
		}
		virtual ~Character() { delete this->m_Weapon; delete this->m_Armor; }
		virtual void Attack() abstract;
	};
	class Archer : public Character
	{
	public:
		Archer(EquipmentAbstractFactory* equipment) : Character(equipment) {}
		void Attack() override
		{
			std::cout << "활을 쏘아 공격!! " << m_Weapon->Power() << "의 피해를 입힙니다!" << std::endl;
		}
	};
	class Warrior : public Character
	{
	public:
		Warrior(EquipmentAbstractFactory* equipment) : Character(equipment) {}
		void Attack() override
		{
			std::cout << "검을 휘둘러 공격!! " << m_Weapon->Power() << "의 피해를 입힙니다!" << std::endl;
		}
	};
}

namespace Method
{
	class Character
	{
	public:
		virtual void Attack() abstract;
	};
	class Archer : public Character
	{
	public:
		void Attack() override
		{
			std::cout << "활을 쏜다." << std::endl;
		}
	};
	class Warrior : public Character
	{
	public:
		void Attack() override
		{
			std::cout << "검을 휘두른다." << std::endl;
		}
	};

	class CreateCharacter
	{
	private:
		virtual Character* FactoryMethod() abstract;
	public:		
		Character* Create()
		{
			return FactoryMethod();
		}
	};
	class ArcherCreate : public CreateCharacter
	{
	private:
		Character* FactoryMethod() override // 만들 객체를 자식 클래스 메소드(함수)에서 결정.
		{
			return new Archer;
		}
	};
	class WarriorCreate : public CreateCharacter
	{
	private:
		Character* FactoryMethod() override
		{
			return new Warrior;
		}
	};
}