#include<stdio.h>
#define EVEN 1
#define ODD 2
//1�� ����
int BigNum(int x, int y)
{
	int Answer;
	if (x > y)
		Answer = x;
	else
		Answer = y;
	return Answer;
}


//2�� ����
int evenoddNum(int x)
{
	int Answer;
	if (x % 2 == 0)
		Answer = EVEN;
	else
		Answer = ODD;
	return Answer;
}


//3�� ����
int ABS(int x)
{
	int Answer;
	if (x >= 0)
		Answer = x;
	else
		Answer = -x;
	return Answer;
}


//4�� ����
int Reverse(int x)
{
	int Answer = 0;
	while (x != 0)
	{
		Answer *= 10;
		Answer += x % 10;
		x /= 10;
	}
	return Answer;
}

void main()
{
	//1�� ����
	int Num1, Num2;
	printf("1.�� ���� �Է� �Ͻÿ� : ");
	scanf("%d%d", &Num1, &Num2);
	int Answer = BigNum(Num1, Num2);
	printf("%d �� %d �� ū ���� %d �Դϴ�.\n", Num1, Num2, Answer);

	//2�� ����
	int Num3;
	printf("2. ���� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &Num3);
	Answer = evenoddNum(Num3);
	if (Answer == EVEN)
		printf("%d�� ¦�� �Դϴ�.\n", Num3);
	else
		printf("%d�� Ȧ�� �Դϴ�.\n", Num3);


	//3�� ����
	int Num4;
	printf("3. ���� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &Num4);
	Answer = ABS(Num4);
	if (Num4 >= 0)
		printf("%d�� ���밪 : %d\n", Num4, Answer);
	else
		printf("%d�� ���밪 : %d\n", Num4, Answer);



	//4�� ����
	int Num5;
	printf("4. ������ �Է��ϼ��� : ");
	scanf("%d", &Num5);
	Answer = Reverse(Num5);
	printf("%d�� �Ųٷ� �� : %d", Num5, Answer);
		printf("4.���� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &Num1);
	printf("%d�� �Ųٷ� �� : %d", Num1, Reverse(Num1));
}