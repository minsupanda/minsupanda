#include<stdio.h>
#include<string.h>

void plus_str(char* str, char* Plus_Str)
{
	int i;
	int j;
	for (i = 0; str[i] != NULL; i++);
	for (j = 0; Plus_Str[j] != NULL; j++)
		str[i + j] = Plus_Str[j];
	str[i + j] = NULL;
}

void main()
{
	char str[10] = "Hello";
	char Plus_Str[10] = "123";
	printf("%s\n", str);
	plus_str(str, Plus_Str);
	printf("%s\n", str);
}