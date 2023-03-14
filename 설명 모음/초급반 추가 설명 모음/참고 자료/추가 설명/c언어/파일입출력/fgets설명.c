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
	//띄워쓰기를 저장할수 있는 자료형은 char형 뿐인다
	fprintf(f, "%s %d", P1.Name, P1.Age);
	fprintf(f, "휴대폰 번호 : %s", P1.PhonNumber);
	fclose(f);
	f = fopen("People.txt", "r");
	if (f == NULL)
		printf("해당 이름의 파일이 없습니다");
	else
	{
		while (!feof(f))
		{
			//띄워쓰기를 포함한 데이터를 가져오고 싶을 때 사용하지만 위의 이유로 fgets는 char으로만 사용이 가능하다
			fgets(buf, sizeof(buf), f);
			//데이터를 저장시킬 공간, 저장시킬 공간의 크기(NULL바깥으로 넘어가지 않기 위함), 데이터를 가져올 파일
			printf("%s\n", buf);
		}
		fclose(f);
	}
}
