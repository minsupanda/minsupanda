#include<stdio.h>
#include<Windows.h> //system("cls"),ststem("pause") �� ����ϱ� ���� ����ϴ� �������

void main()
{
	int Select, Kor, Math, Eng, Sum, inputname = 0, inputscore = 0;
	float Avg;
	char name[10];
	while (1)
	{
		system("cls");
		printf("====================\n");
		printf("   �л���������\n");
		printf("====================\n");
		printf("   1. �л� �̸����\n");
		printf("   2. 3���� �������\n");
		printf("   3. ����Ȯ��\n");
		printf("   4. ����\n");
		printf("====================\n");
		printf("�Է� : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			system("cls");
			printf("�̸� �Է� : ");
			scanf("%s", name);
			inputname = 1;
			break;

		case 2:
			system("cls");
			printf("�������� ������ �Է��Ͻÿ�\n");
			printf("���� : ");
			scanf("%d", &Kor);
			printf("���� : ");
			scanf("%d", &Math);
			printf("���� : ");
			scanf("%d", &Eng);
			Sum = Kor + Math + Eng;
			Avg = (float)Sum / 3.0f;
			inputscore = 1;
			break;

		case 3:
			system("cls");
			if (inputname == 0 || inputscore == 0)
			{
				if (inputname == 0 )
					printf("�̸��� �Է��ϼ���\n");
				if (inputscore == 0)
					printf("������ �Է��ϼ���\n");
				system("pause");
			}
			else
			{
				printf("===============\n");
				printf("%s���� ����\n", name);
				printf("���� ���� : %d\n", Kor);
				printf("���� ���� : %d\n", Math);
				printf("���� ���� : %d\n", Eng);
				printf("�հ� ���� : %d\n", Sum);
				printf("��� ���� : %.2f\n", Avg);
				printf("===============\n");
				system("pause");
			}
			break;

		case 4:
			return;
		}
	}
}