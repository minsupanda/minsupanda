#include<iostream>
#include<Windows.h>
#include"Figure.h"
#include"Triangle.h"
#include"circle.h"
#include"Quadrangle.h"
using namespace std;

Figure* SelectFigure()
{
	system("cls");
	int select;
	Figure* tmp;
	cout << "=== 도형 선택 ===" << endl;
	cout << "  1. 일반 도형" << endl;
	cout << "  2. 삼각형" << endl;
	cout << "  3. 사각형 " << endl;
	cout << "  4. 원형" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		tmp = new Figure;
		break;
	case 2:
		tmp = new Triangle;
		break;
	case 3:
		tmp = new Quadrangle;
		break;
	case 4:
		tmp = new circle;
		break;
	}
	tmp->SetSize();
	return tmp;
}

void Show_Figure(Figure* figure_list[])
{
	int i;
	for (i = 0; figure_list[i] != NULL; i++)
		figure_list[i]->Draw();
	if (i == 0)
		cout << " 등록된 도형이 없습니다."<<endl;
	system("pause");
}

void Exit()
{
	for (int i = 5; i >= 0; i--)
	{
		system("cls");
		cout << "종료 합니다." << endl;
		cout << i << "초전" << endl;
		Sleep(1000);
	}
	exit(1);
}

void main()
{
	Figure* figure_list[50] = { NULL };
	int select;
	while (1)
	{
		system("cls");
		cout << "=== 도형 그리기 ===" << endl;
		cout << "  1. 도형 추가" << endl;
		cout << "  2. 도형 전체 그리기" << endl;
		cout << "  3. 종료 " << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			int i;
			for (i = 0; i < 50; i++)
			{
				if (figure_list[i] == NULL)
					break;
			}
			figure_list[i] = SelectFigure();
			break;
		case 2:
			Show_Figure(figure_list);
			break;
		case 3:
			for(i = 0; i < 50; i++)
			{
				if(figure_list[i] != NULL)
					delete figure_list[i];
			}
			Exit();
			break;
		default:
			break;
		}
	}
}