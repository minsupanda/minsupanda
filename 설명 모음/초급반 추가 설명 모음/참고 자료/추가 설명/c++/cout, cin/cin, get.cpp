#include<iostream>

void main()
{
	char name[20];
	std::cout << "이름을 입력하세요!";
	//std::cin >> name;
	std::cin.get(name, 20);
	//c언어에서 scanf는 데이터를 가져올 때 띄어쓰기, 엔터값을 만나면 거기까지만 데이터를 가져옴
	// 파일입출력 시 사용했던 fscanf와 동일하게 메모장에서 띄어쓰기, 엔터 기준을 데이터를 가져왔었음
	//이를 위해 띄어쓰기를 포함해 데이터를 입력하기 위한 것이 gets, fgets
	// c++에서는 get을 사용한다
	std::cout << "나의 이름은" << name << "입니다." << std::endl;
	return;
}