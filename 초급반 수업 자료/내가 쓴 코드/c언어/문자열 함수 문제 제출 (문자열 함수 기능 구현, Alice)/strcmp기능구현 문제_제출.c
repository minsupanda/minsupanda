#include<stdio.h>
#include<string.h>

int Str_Compare(char* str1, char* str2)
{
	int i;
	for (i = 0; str1[i] != NULL; i++)
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] > str2[i])
				return 1;
			else
				return -1;
		}
	}
	if (str2[i] != NULL)
		return -1;
	else
		return 0;
}

void main()
{
	char str1[20] = "string!!!";
	char str2[20] = "string!!";
	printf("%s == %s : %d\n", str1, str2, Str_Compare(str1, str2));
	printf("%s == %s : %d\n", str1, str2, Str_Compare("abc", "def"));
	printf("%s == %s : %d\n", str1, str2, Str_Compare("abc", "abc"));
}