#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <vector>

class Type
{
private:
	int* data;
public:
	Type() : data(new int(1)) { std::cout << data << "기본 생성자 호출" << std::endl; }

	Type(const Type& t) : data(new int(2))
	{
		if (nullptr != t.data) 
			*data = *t.data;
		std::cout << data << "복사 생성자 호출" << std::endl;
	}
	 
	Type(Type&& t) noexcept/* 예외가 발생하지 않는다고 알려주는 것 (vector를 사용할 때 필요함, 이동 생성자 만들 때 붙히면 됨)*/ : data(t.data)
	{
		t.data = nullptr;
		// t.data = nullptr; 얘가 주석이면 동적할당 해제 한 애를 또 해제해서 문제가 생긴다
		// 이동 생성자를 쓰면 완전히 데이터가 이동이 되기 떄문에 굳이 해줄 필요가 없다.
		// 그렇기 때문에 null 바꿔주고 delete를 하지 않도록 해주는 것
		if (nullptr == data)
			data = new int(0);
		std::cout << data << "이동 생성자 호출" << std::endl;
	}

	~Type() { if (data) { std::cout << "소멸자 호출" << std::endl; delete data; data = nullptr; } }
	// 
};
\
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	int a(0);
	// std::move() 객체가 이동할 수 있음을 알려준다
	// -> 이동 생성자가 있으면 호출, 없으면 디폴트나 복사 생성자 호출
	Type t = std::move(Type());
	// <복사 생성자, 이동 생성자 둘 다 주석일 때>
	// Type()의 생성자가 호출 된다 -> data에 값 들어감
	// 하지만 아직 라인이 끝나지 않았기에 t에 값이 들어가진 않음 -> 들어가기 전에 먼저 지역이 끝나 소멸자가 호출이 되면서 데이터가 날라가게 된다
	// 이 날아간 데이터를 t에 넣기 때문에 인스턴스는 만들어 져있지만 쓰레기값이 들어가있게 된다(1이 들어가지 않은 이유)
	// <이동 생성자만 주석 일 때>
	// Type t = std::move(Type()) == Type t(std::move(Type())) 두 개 같은 뜻이다 -> 그러므로 복사 생성자가 호출이 되는 것이다  
	// <주석이 없을 때>
	// std::move()를 썼고 이동 생성자가 있기 때문에 이동 생성자가 호출이 되는 것
	// 그럼 type() 얘 소멸자 호출이 안되는 이유가 모든 데이터가 t로 이동이 되었기 때문에 type() 얘를 해제할 필요가 없어 null을 넣어주었기 때문이다?

	std::cout << "----------------------------------" << std::endl;
	std::vector<Type> v;
	v.push_back(t); // 아직 vector에 t의 데이터가 없기 때문에 복사 생성자가 호출이 된다
	// 이후로는 t의 데이터가 있기 때문에 이동생성자가 호출이 된다
	v.push_back(t); // noexcept 없으면 이동 생성자가 호출이 되지 않음
	// 근데 여기서 위에서 복사생성자로 만든 놈이 이동생성자의 매개변수로 와서 사용됨 -> 그럼 nullptr로 넣고 데이터 초기화 되던데 왜 다시 vector에는 제대로 된 값이 들어가 있음?
	v.push_back(t);
	std::cout << "------------------------------------" << std::endl;

	return 0;
}