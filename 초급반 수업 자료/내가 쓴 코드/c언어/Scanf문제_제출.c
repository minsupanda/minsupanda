#pragma warning(disable:4996)
#include<stdio.h>

void main()
{
	char ch;
	int num;
	printf("���� ���ڸ� �Է��Ͻÿ� : ");
	scanf("%c", &ch);
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &num);
	printf("%c + %d = %c\n\n", ch, (char)num, ch + (char)num);

	float Fnum;
	printf("�Ҽ������� �Է��Ͻÿ� : ");
	scanf("%f,", &Fnum);
	printf("�Ҽ����� : %.2f\n\n", Fnum);

	int koreascore, mathscore, englishscore, sum;
	printf("���������� �Է��Ͻÿ� : ");
	scanf("%d", &koreascore);
	printf("���������� �Է��Ͻÿ� : ");
	scanf("%d", &mathscore);
	printf("���������� �Է��Ͻÿ� : ");
	scanf("%d", &englishscore);
	printf("�������� : %d\n", koreascore);
	printf("�������� : %d\n", mathscore);
	printf("�������� : %d\n", englishscore);
	sum = koreascore + mathscore + englishscore;
	printf("�հ����� : %d ", sum);
	printf("������� : %d \n\n", sum / 3);


	char name[10];
	int age;
	printf("�̸��� �Է��Ͻÿ� : ");
	scanf("%s", name);
	printf("%s���� ���̸� �Է��Ͻÿ� : ", name);
	scanf("%d", &age);
	printf("%s���� ���̴� %d�Դϴ�.", name, age);

	return;
}