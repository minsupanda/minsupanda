#include <stdio.h>

void main()
{
	int Num1;
	printf("1.������ �Է��Ͻÿ� : ");
	scanf("%d", &Num1);
	(Num1 % 5 == 0) ? printf("%d��(��) 5�� ����Դϴ�.\n", Num1) : printf("%d��(��) 5�� ����� �ƴմϴ�.\n", Num1);

	
	int koreanscore;
	int mathscore;
	int englishscore;
	float sum;
	printf("2.�� ������ ������ �Է��Ͻÿ�\n");
	printf("���� ���� : ");
	scanf("%d", &koreanscore);
	printf("���� ���� : ");
	scanf("%d", &mathscore);
	printf("���� ���� : ");
	scanf("%d", &englishscore);
	sum = (koreanscore + mathscore + englishscore)/3;
	(sum >= 60.00) ? printf("��� %.2f�հ�\n", sum) : printf("��� %.2f���հ�\n", sum);
	
	int Num2;
	int Num3;
	printf("3. �������� �Է��Ͻÿ� : \n");
	scanf("%d%d", &Num2, &Num3);
	(Num2 > Num3) ? printf("ū �� : %d\n", Num2) : printf("ū �� : %d\n", Num3);


	int Num4;
	printf("4. ������ �Է��Ͻÿ� : ");
	scanf("%d", &Num4);
	(Num4 % 3 == 0 && Num4 % 2 == 0) ? printf("%d�� ¦���̸� 3�� ����Դϴ�\n.", Num4) : printf("���ǽ���\n");
	

	int Num5;
	printf("5. ������ �Է��Ͻÿ� : ");
	scanf("%d", &Num5);
	(Num5 % 5 == 0 || Num5 % 7 == 0) ? printf("%d�� 5�� ����̰ų� 7�� ����Դϴ�.", Num5) : printf("���ǽ���");


	return;
}