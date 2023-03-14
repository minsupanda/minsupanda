#include<iostream>
#include<string>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int a, int b) { x = a; y = b; }
	void Print() { cout << "x = " << x << ", y = " << y << "\n"; }
	//bool operator == (Point tmp);
	Point operator + (int date)
	{
		x += date;
		y += date;
		return { x, y };
	}
	friend Point operator + (Point tmp, int date);
};

//bool Point::operator==(Point tmp)
//{
//	if ((this->x == tmp.x) && (this->y == tmp.y))
//		return true;
//	else
//		return false;
//}

Point operator + (Point tmp, int date)
{
	cout << "��ü + ���� " << "\n";
	tmp.x = tmp.x + date;
	tmp.y = tmp.y + date;
	return tmp;
}

void main()
{
	Point ov1(10, 20), ov2(0, 0);
	//if (ov1 == ov2)
	//	cout << "����." << "\n";
	ov2 = ov1 + 10;
	// �̰� ������ �ߴ� ���� : 
	// �翬�� ������ ������ ����� �ϴ� �Լ��� 2���̱� ������ �ߺ����� ����� �ν������� ���� ������ ����� �Ǵ� ���̴�
	// Q : �׷� Point operator + (int date) �긦 private���� ����� �ȵǳ�?
	// A : private�� ����� �ѵ� ������ ȣ���ϴ� ov1�� Point Class�̱� ������ Point operator + (int date) �긦 �ν��ϰ� �ȴ�
	// �׷��Ƿ� �Ȱ��� ������ �ߴ� ��

	// friend�� ���� �ʴ� �ڵ�� ���� �����ϰ� �ذ��� ��
	// ���ʿ� �ִ� �ǿ����ڰ� �Լ��� ȣ���� Class�� ���̱� ������ �Ű������� �����ڸ� ������ ���� �Ǵ� ��
	ov2.Print();
}