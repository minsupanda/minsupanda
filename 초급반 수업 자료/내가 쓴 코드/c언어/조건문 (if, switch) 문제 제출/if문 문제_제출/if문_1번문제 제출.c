#include<stdio.h>

void main()
{
	//1������
	int Num;
	printf("1. ������ �Է��Ͻÿ� : ");
	scanf("%d", &Num);
	if (Num % 3 == 0)
	{
		printf("%d�� 3�� ����Դϴ�.\n", Num);
	}
	if (Num % 3 != 0)
	{
		printf("%d�� 3�� ����� �ƴմϴ�.\n", Num);
	}


	//2������
	int Num1;
	printf("2. ������ �Է��Ͻÿ� : ");
	scanf("%d", &Num1);
	if (Num1 >= 0)
	{
		printf("%d�� ���밪�� %d�Դϴ�.\n", Num1, Num1);
	}
	if (Num1 < 0)
	{
		printf("%d�� ���밪�� %d�Դϴ�.\n", Num1, -Num1);
	}


	//3������
	int Num2;
	printf("3. ������ �Է��Ͻÿ� : ");
	scanf("%d%", &Num2);
	if (Num2 % 2 == 0)
	{
		printf("%d�� ¦�� �Դϴ�.\n", Num2);
	}
	if (Num2 % 2 != 0)
	{
		printf("%d�� Ȧ�� �Դϴ�.\n", Num2);
	}


	//4������
	int Num3;
	int Num4;
	printf("4. ���� �ΰ��� �Է��Ͻÿ� : ");
	scanf("%d%d", &Num3, &Num4);
	if (Num3 > Num4)
	{
		printf("Max = %d\n", Num3);
	}
	if (Num4 >= Num3)
	{
		printf("Max = %d\n", Num4);
	}


	//5������
	int Num5;
	int Num6;
	int Num7;
	printf("5. ���� ������ �Է��Ͻÿ�");
	scanf("%d%d%d", &Num5, &Num6, &Num7);
	if (Num5 > Num6 && Num5 > Num7)
	{
		printf("Max = %d\n", Num5);
	}
	if (Num6 > Num5 && Num6 > Num7)
	{
		printf("Max = %d\n", Num6);
	}
	if (Num7 >= Num6 && Num7 >= Num5)
	{
		printf("Max = %d\n", Num7);
	}


	//6������
	int Num8;
	int Num9;
	printf("6. ���� �ΰ��� �Է��Ͻÿ�");
	scanf("%d%d", &Num8, &Num9);
	if (Num8 > Num9)
	{
		if (Num8 % 2 == 0)
		{
			printf("ū���� %d�̸� ¦���Դϴ�.\n", Num8);
		}
		if (Num8 % 2 != 0)
		{
			printf("ū���� %d�̸� Ȧ���Դϴ�.\n", Num8);
		}
	}
	if (Num9 >= Num8)
	{
		if (Num9 % 2 == 0)
		{
			printf("ū���� %d�̸� ¦���Դϴ�.\n", Num9);
		}
		if (Num9 % 2 != 0)
		{
			printf("ū���� %d�̸� Ȧ���Դϴ�.\n", Num9);
		}
	}


	//7������
	int Num10;
	int Num11;
	int sum;
	printf("7. ���� �ΰ��� �Է��Ͻÿ�");
	scanf("%d%d", &Num10, &Num11);
	sum = Num10 + Num11;
	if (sum % 2 != 0 && sum % 3 == 0)
	{
		printf("%d�� %d�� �� = %d\n", Num10, Num11, sum);
		printf("%d�� Ȧ���̰� 3�� ����Դϴ�\n", sum);
	}
	if (sum % 2 == 0 || sum % 3 != 0)
	{
		printf("�ش������ �����ϴ�.\n");
	}


	return;
}