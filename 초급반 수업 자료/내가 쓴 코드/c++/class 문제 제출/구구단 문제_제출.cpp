#include<iostream>
#include<Windows.h>

using namespace std;

class Times_Table
{
private:
	int Start;
	int End;
public:
	void Multiply();
	void Print();
};

void Times_Table::Multiply()
{
	cout << "시작 단 입력 : ";
	cin >> Start;
	cout << "끝 단 입력 : ";
	cin >> End;
}

void Times_Table::Print()
{
	for (int i = Start; i <= End; i++)
	{
		cout << "====== " << i << "단======\t";
	}

	cout << endl;

	for (int i = 1; i <= 9; i++)
	{
		for (int j = Start; j <= End; j++)
		{
			cout << "   " << j << " x " << i << " = " << j * i << "\t\t";
		}
		cout << endl;
	}
}

void main()
{
	Times_Table GuGuDan;
	GuGuDan.Multiply();
	GuGuDan.Print();
	system("pause");
}