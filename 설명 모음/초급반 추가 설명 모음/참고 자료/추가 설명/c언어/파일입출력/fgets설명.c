#include<stdio.h>


typedef struct people
{
	char Name[10];
	int Age;
	char PhonNumber[20];
}People;

void main()
{
	People P1 = { "A", 20, "010-1234-5678" };
	FILE* f = fopen("People.txt", "w");
	char buf[256];
	//������⸦ �����Ҽ� �ִ� �ڷ����� char�� ���δ�
	fprintf(f, "%s %d", P1.Name, P1.Age);
	fprintf(f, "�޴��� ��ȣ : %s", P1.PhonNumber);
	fclose(f);
	f = fopen("People.txt", "r");
	if (f == NULL)
		printf("�ش� �̸��� ������ �����ϴ�");
	else
	{
		while (!feof(f))
		{
			//������⸦ ������ �����͸� �������� ���� �� ��������� ���� ������ fgets�� char���θ� ����� �����ϴ�
			fgets(buf, sizeof(buf), f);
			//�����͸� �����ų ����, �����ų ������ ũ��(NULL�ٱ����� �Ѿ�� �ʱ� ����), �����͸� ������ ����
			printf("%s\n", buf);
		}
		fclose(f);
	}
}
