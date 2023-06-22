#include<iostream>
#include<Windows.h>
#include<list>
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
	cout << "=== ���� ���� ===" << endl;
	cout << "  1. �ﰢ��" << endl;
	cout << "  2. �簢�� " << endl;
	cout << "  3. ����" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		tmp = new Triangle;
		break;
	case 2:
		tmp = new Quadrangle;
		break;
	case 3:
		tmp = new circle;
		break;
	}
	tmp->SetSize();
	return tmp;

}
void Show_Figure(list<Figure*> figure_list)
{
	if (figure_list.empty())
		cout << " ��ϵ� ������ �����ϴ�." << endl;
	else
	{
		for (Figure* figure : figure_list)
			figure->Draw();
	}
	system("pause");
}

void main()
{
	list<Figure*> figure_list;
	int select;
	while (1)
	{
		system("cls");
		cout << "=== ���� �׸��� ===" << endl;
		cout << "  1. ���� �߰�" << endl;
		cout << "  2. ���� ��ü �׸���" << endl;
		cout << "  3. ���� " << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			figure_list.push_back(SelectFigure());
			break;
		case 2:
			Show_Figure(figure_list);
			break;
		case 3:
			for (Figure* figure : figure_list)
					delete figure;
			return;
		default:
			break;
		}
	}
}