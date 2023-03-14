#include<iostream>
using namespace std;

class Add
{
public:
	void AddNum1(int Num = 10);
	void AddNum2(int Num1 = 10, int Num2 = 5);
	// 여기서 = 5가 빠진다면 오류가 뜨게 된다.
	// 매개변수는 항상 왼쪽부터 시작하게 되며 인자로 전달되지 않아 컴파일러에서 오류를 띄우는 것
	//-> 컴파일 과정에서 걸러지므로 여기서 오류가 뜨는 것이 아니면 최소한 인자의 갯수에는 문제가 있다는 것이 아니다.
};

void Add::AddNum1(int Num)
{
	cout << Num << "+" << "1 = " << Num + 1 << endl;
}

void Add::AddNum2(int Num1, int Num2)
{
	cout << Num1 << "+" << Num2 << " = " << Num1 + Num2 << endl;
}

void main()
{
	Add add;
	add.AddNum1();
	add.AddNum1(20);
	add.AddNum2(); // 아예 말도 안되는 것
	add.AddNum2(20); // 인자가 부족하게 됨 -> 위가 아니라 여기서 오류가 뜨면 이 부분에서 잘못된 것
	add.AddNum2(10, 20);
}

﻿