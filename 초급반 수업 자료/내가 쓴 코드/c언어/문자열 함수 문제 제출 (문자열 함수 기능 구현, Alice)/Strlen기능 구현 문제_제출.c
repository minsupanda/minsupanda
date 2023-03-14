#include<stdio.h>
#include<string.h>
#include<Windows.h>


int Str_len(char* str)
{
	int strlen = 0;
	while (*str != NULL)
	{
		strlen++;
		str++;
	}
	return strlen;
}

void main()
{
	char str[10] = "Hello123";
	printf("%s문자열의 길이 : %d\n", str, Str_len(str));
	system("pause");
}