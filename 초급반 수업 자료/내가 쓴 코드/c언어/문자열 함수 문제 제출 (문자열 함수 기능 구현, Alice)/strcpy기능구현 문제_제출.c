#include<stdio.h>
#include<string.h>

void Name_Copy(char* Name, char* My_Name)
{
	int i;
	for (i = 0; My_Name[i] != NULL; i++)
		Name[i] = My_Name[i];
	Name[i] = NULL;
}

void main()
{
	char Name[10];
	char My_Name[10];
	printf("�̸� �Է�(�ִ� 9��) : ");
	scanf("%s", My_Name);
	Name_Copy(Name, My_Name);
	printf("Name : %s\n", My_Name);
	printf("Name : %s\n", Name);
}