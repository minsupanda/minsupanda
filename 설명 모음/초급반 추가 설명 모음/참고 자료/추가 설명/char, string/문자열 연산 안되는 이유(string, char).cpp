#include <iostream>
#include <string>
using namespace std;

template <typename Type>
void Sum(Type su1, Type su2)
{
	Type sum;
	sum = su1 + su2;
	cout << sum << endl;
}
void main()
{
	int a = 1, b = 2;
	Sum(a, b);
	Sum("Ace", "ace");
	// ������ �ߴ� ���� : const char ���·� �ö󰡸鼭 �ּҿ� ���� ���ϴ� ���� �Ǳ� �����̴�
	std::string str = "asd", str2 = "vec";
	str + str2; // string�� ������ �����ε��� �Ǿ��ֱ� ������ ������ ���̴�.
	//c���� strcat�� ���ڿ� ������ ã�Ƽ� �ϳ��� �ִ� ����� ��������� ���ִ� ���̱� ������ ������ ��
}
