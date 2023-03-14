#include<stdio.h>

typedef struct people
{
	char Name[10];
	int Age;
	char PhonNumber[20];
}People;

void main()
{
	People P1 = { "A",20,"010-1234-5678" };
	FILE* f = fopen("People.txt", "w");
	char buf[256] = { 0 };
	fprintf(f, "이름 : %s나이 : %d\n", P1.Name, P1.Age);
	fprintf(f, "휴대폰 번호 : %s", P1.PhonNumber);
	fclose(f);
	f = fopen("People.txt", "r");
	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	else
	{
		fread(buf, sizeof(buf), 1, f); // fread는 모든 정보를 들고오는 것이고, 1은 한번만 들고 오겠다라는 뜻
		printf("%s\n", buf);
		//char buf[256];
		//뒤에 쓰레기값이 나오게 됨
		//필요한 정보를 다 들고 오고도 NULL값을 만나지 못하게 되어 나머지 빈 공간을 채우기 위해 쓰레기값으로 채우게 된것
		// 즉, buf에 필요한 정보를 저장하고 나머지 공간을 메모장에 저장되어있는 쓰레기값으로 채워진것
		//그러면 buf에 처음부터 NULL값을 저장해두면 된다.
	}
	fclose(f);
}
