#include<stdio.h>
#include<conio.h>
#define TRUE 1
#define ESC 0

void main()
{
	//1������
	int Num = 1, sum = 0, InputNum;
	while (TRUE)
	{
		printf("1. 10 ~ 20���� ���� �Է� : ");
		scanf("%d", &InputNum);
		if (InputNum >= 10 && InputNum <= 20)
		break;
		printf("�߸� �Է�\n");
	}
	while (Num <= InputNum)
	{
		sum += Num;
		Num++;
	}
	printf("1 ~ %d ���� ���� �հ� : %d\n",InputNum, sum);


	//2�� ����
	int Num2 = 1;
	printf("2. Hello ���\n");
	while (Num2 <= 5)
	{
		printf("Hello\n");
		Num2++;
	}

	//3�� ����
	int Num3, sum3 = 0;
	printf("3. ���� �ݺ� �Է� (0�Է½� ����)\n");
	do
	{
		printf("���� �Է� : ");
		scanf("%d", &Num3);
		sum3 += Num3;
	} while (Num3 != ESC)
	printf("���� �հ� : %d\n", sum3);

	//4�� ����
	int Num4, i=1, count=0;
	printf("4. �Ҽ� �Ǻ�\n");
	printf("���� �Է� : ");
	scanf("%d", &Num4);
	while (i <= Num4)
	{
		if (Num4 % i == 0)
		{
			count++;
		}
		i++;
	}
	if (count >= 3)
	{
		printf("%d�� �Ҽ��� �ƴմϴ�.\n", Num4);
	}
	else
	{
		printf("%d�� �Ҽ� �Դϴ�.\n", Num4);
	}

	//5�� ����
	int Num5, Reverse;
	printf("5. �Էµ� ���� �Ųٷ� ���\n");
	printf("���� �Է� : ");
	scanf("%d", &Num5);
	while (TRUE)
	{
		if (Num5 != 0)
		{
			Reverse = Num5 % 10;
			Num5 /= 10;
			printf("%d", Reverse);
		}
		else
			break;
	}
	printf("\n");

	//6�� ����
	int Num6, Num7, sum6 = 0;
	printf("6. �Էµ� ������ ���ڸ� �� �հ�\n");
	printf("���� �Է� : ");
	scanf("%d", &Num6);
	while (TRUE)
	{
		if (Num6 != 0)
		{
			Num7 = Num6 % 10;
			sum6 += Num7;
			Num6 /= 10; 
		}
		else
			break;
	}
	printf("���� �հ� : %d\n", sum6);
	
	return;
}