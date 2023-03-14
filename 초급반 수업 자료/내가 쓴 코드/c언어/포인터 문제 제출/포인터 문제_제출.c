#include<stdio.h>
#define ARR_NUM 8

void ConvertToUppercase(char* string) // �迭�� �����ּҸ� �޾Ұ�, �����͵� �迭ó�� ��� �� �� �����Ƿ� �ٷ� �迭�� ��� ����
{
	//printf("%s", string[0]); ���� �����ϰ� �ּҸ� �Ⱥ��±� ����, �� ���ڰ��� �ְ� �ִ� ��
	for (int i = 0; string[i] != NULL; i++)
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			string[i] -= 32;
	}
}

void BigNumber(int Num1, int Num2, int* BigNum)
{
	if (Num1 < Num2)
		*BigNum = Num2;
	else
		*BigNum = Num1;
}

void Accumulate(int inputnum, int* plusnum)
{
	for (int i = 1; i <= inputnum; i++)
		*plusnum += i;
}

void Sort(int Sort_Num[ARR_NUM])
{
	int Num;
	for (int i = 1; i < ARR_NUM - 1; i++)
	{
		for (int j = i + 1; j < ARR_NUM; j++)
		{
			if (Sort_Num[i] > Sort_Num[j])
			{
				Num = Sort_Num[i];
				Sort_Num[i] = Sort_Num[j];
				Sort_Num[j] = Num;
			}
		}
	}
}

void main()
{
	// 1�� ����
	char string[10];
	printf("1. ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", string);
	printf("�Լ� ȣ�� �� = %s\n", string);
	ConvertToUppercase(string);
	printf("�Լ� ȣ�� �� = %s\n", string);

	// 2�� ����
	int Num1, Num2, BigNum = 0;
	printf("2. �� ������ �Է��Ͻÿ� : ");
	scanf("%d%d", &Num1, &Num2);
	BigNumber(Num1, Num2, &BigNum);
	printf("%d��(��) %d�� ū ���� %d\n", Num1, Num2, BigNum);

	// 3�� ����
	int InputNum;
	int PlusNum = 0;
	printf("3. ������ �Է��Ͻÿ� : ");
	scanf("%d", &InputNum);
	Accumulate(InputNum, &PlusNum);
	printf("1 ~ %d�� ���� : %d\n", InputNum, PlusNum);

	//4�� ����
	int Number[ARR_NUM];
	int* Sort_Num = Number;
	printf("4. �������� ����\n");
	for (int i = 0; i < ARR_NUM; i++)
	{
		printf("[%d]��° ���� �Է� : ", i);
		scanf("%d", &Sort_Num[i]);
	}

	printf("���� �� : ");
	for (int i = 0; i < ARR_NUM; i++)
		printf("%d ", Sort_Num[i]);

	printf("\n");
	Sort(Sort_Num);

	printf("���� �� : ");
	for (int i = 0; i < ARR_NUM; i++)
		printf("%d ", Sort_Num[i]);
}