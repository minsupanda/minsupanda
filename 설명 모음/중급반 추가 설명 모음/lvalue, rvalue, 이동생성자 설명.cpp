#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <vector>

class Type
{
private:
	int* data;
public:
	Type() : data(new int(1)) { std::cout << data << "�⺻ ������ ȣ��" << std::endl; }

	Type(const Type& t) : data(new int(2))
	{
		if (nullptr != t.data) 
			*data = *t.data;
		std::cout << data << "���� ������ ȣ��" << std::endl;
	}
	 
	Type(Type&& t) noexcept/* ���ܰ� �߻����� �ʴ´ٰ� �˷��ִ� �� (vector�� ����� �� �ʿ���, �̵� ������ ���� �� ������ ��)*/ : data(t.data)
	{
		t.data = nullptr;
		// t.data = nullptr; �갡 �ּ��̸� �����Ҵ� ���� �� �ָ� �� �����ؼ� ������ �����
		// �̵� �����ڸ� ���� ������ �����Ͱ� �̵��� �Ǳ� ������ ���� ���� �ʿ䰡 ����.
		// �׷��� ������ null �ٲ��ְ� delete�� ���� �ʵ��� ���ִ� ��
		if (nullptr == data)
			data = new int(0);
		std::cout << data << "�̵� ������ ȣ��" << std::endl;
	}

	~Type() { if (data) { std::cout << "�Ҹ��� ȣ��" << std::endl; delete data; data = nullptr; } }
	// 
};
\
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	int a(0);
	// std::move() ��ü�� �̵��� �� ������ �˷��ش�
	// -> �̵� �����ڰ� ������ ȣ��, ������ ����Ʈ�� ���� ������ ȣ��
	Type t = std::move(Type());
	// <���� ������, �̵� ������ �� �� �ּ��� ��>
	// Type()�� �����ڰ� ȣ�� �ȴ� -> data�� �� ��
	// ������ ���� ������ ������ �ʾұ⿡ t�� ���� ���� ���� -> ���� ���� ���� ������ ���� �Ҹ��ڰ� ȣ���� �Ǹ鼭 �����Ͱ� ���󰡰� �ȴ�
	// �� ���ư� �����͸� t�� �ֱ� ������ �ν��Ͻ��� ����� �������� �����Ⱚ�� ���ְ� �ȴ�(1�� ���� ���� ����)
	// <�̵� �����ڸ� �ּ� �� ��>
	// Type t = std::move(Type()) == Type t(std::move(Type())) �� �� ���� ���̴� -> �׷��Ƿ� ���� �����ڰ� ȣ���� �Ǵ� ���̴�  
	// <�ּ��� ���� ��>
	// std::move()�� ��� �̵� �����ڰ� �ֱ� ������ �̵� �����ڰ� ȣ���� �Ǵ� ��
	// �׷� type() �� �Ҹ��� ȣ���� �ȵǴ� ������ ��� �����Ͱ� t�� �̵��� �Ǿ��� ������ type() �긦 ������ �ʿ䰡 ���� null�� �־��־��� �����̴�?

	std::cout << "----------------------------------" << std::endl;
	std::vector<Type> v;
	v.push_back(t); // ���� vector�� t�� �����Ͱ� ���� ������ ���� �����ڰ� ȣ���� �ȴ�
	// ���ķδ� t�� �����Ͱ� �ֱ� ������ �̵������ڰ� ȣ���� �ȴ�
	v.push_back(t); // noexcept ������ �̵� �����ڰ� ȣ���� ���� ����
	// �ٵ� ���⼭ ������ ��������ڷ� ���� ���� �̵��������� �Ű������� �ͼ� ���� -> �׷� nullptr�� �ְ� ������ �ʱ�ȭ �Ǵ��� �� �ٽ� vector���� ����� �� ���� �� ����?
	v.push_back(t);
	std::cout << "------------------------------------" << std::endl;

	return 0;
}