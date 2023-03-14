#include<stdio.h>


void main()
{
	FILE* GoGoDan = fopen("GoGoDan.txt", "w");
	for (int x = 2; x <= 9; x++)
	{
		fprintf(GoGoDan, "===== %d´Ü =====\n", x);
		for (int y = 1; y <= 9; y++)
			fprintf(GoGoDan, "%d x %d = %d\n", x, y, x * y);
		fprintf(GoGoDan, "===============\n\n");
	}
	fclose(GoGoDan);
}