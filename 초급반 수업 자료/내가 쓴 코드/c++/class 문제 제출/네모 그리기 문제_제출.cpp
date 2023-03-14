#include<iostream>
#include<Windows.h>

using namespace std;

class Figure
{
private:
	int width;
	int length;
public:
	void size();
	void Print();
};

void Figure::size()
{
	cout << "가로 입력 : ";
	cin >> width;
	cout << "세로 입력 : ";
	cin >> length;
}

void Figure::Print()
{
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (y == 0 || y == length - 1)
			{
				if (y == 0)
				{
					if (x == 0)
						cout << "┌";
					else if (x == width - 1)
						cout << "┐";
					else
						cout << "─";
				}
				else if (y == length - 1)
				{
					if (x == 0)
						cout << "└";
					else if (x == width - 1)
						cout << "┘";
					else
						cout << "─";
				}
			}
			else if (x == 0 || x == width - 1)
				cout << "│";
			else
				cout << "  ";
		}
		cout << endl;
	}
	system("pause");
}

void main()
{

	Figure square;
	square.size();
	square.Print();
}