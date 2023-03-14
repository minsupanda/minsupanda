#include<stdio.h>
#include<string.h>
#include<Windows.h>

char* AddBuff(char* Alice_Contents, char* buf);
char* Alice_File_Load();
void Search_Word(char* Alice_Contents);

char* AddBuff(char* Alice_Contents, char* buf)//추가로 불러온 엘리스파일을 저장하는 함수
{
	if (Alice_Contents == NULL) // 해당 변수에 데이터가 없을 때
	{
		Alice_Contents = (char*)malloc(strlen(buf) + 1); // +1은 NULL값까지 포함시켜야 하기 때문이다
		strcpy(Alice_Contents, buf); // fgets한 내용을 복사시킨다
	}
	else
	{
		char* New_Alice_Contents = (char*)malloc(strlen(Alice_Contents) + strlen(buf) + 1); // 추가되는 내용만큼 메모리를 더 받아온다
		//sprintf(New_Alice_Contents, "%s%s", Alice_Contents, buf); // strcpy,strcat과정을 한번에 실행
		strcpy(New_Alice_Contents, Alice_Contents); // 새롭게 만들어진 공간에 기존의 내용을 복사하고
		strcat(New_Alice_Contents, buf); // 그 뒤 이어서 새롭게 받은 내용 저장
		free(Alice_Contents); // 그전의 메모리는 해제시키기
		Alice_Contents = New_Alice_Contents; // 해당 변수를 반환하기 위해
	}
	return Alice_Contents;
}

char* Alice_File_Load() // 앨리스 파일 로드 함수
{
	FILE* Alice_File = fopen("Alice.txt", "r");
	char* Alice_Contents = NULL;
	if (Alice_File == NULL)
		printf("해당 이름의 파일이 없습니다.\n");
	else
	{
		while (!feof(Alice_File))
		{
			char buf[256] = { NULL };
			fgets(buf, sizeof(buf), Alice_File);
			Alice_Contents = AddBuff(Alice_Contents, buf);
		}
	}
	printf("%s", Alice_Contents);
	fclose(Alice_File);
	return Alice_Contents;
}

void Search_Word(char* Alice_Contents)// 문자 검색 함수
{
	char Serch_Word[256];
	int Count = 0;
	printf("Word to search : ");
	scanf("%s", Serch_Word);
	for (int i = 0; Alice_Contents[i] != NULL; i++)
	{
		if (Alice_Contents[i] == Serch_Word[0])
		{
			for (int j = 1; Serch_Word[j] != NULL; j++)
			{
				if (Alice_Contents[i + j] == Serch_Word[j] && Serch_Word[j + 1] == NULL)
					Count++;
				else if (Alice_Contents[i + j] != Serch_Word[j])
					break;
			}
		}
	}
	printf("%d", Count);
}

void main()
{
	char* Alice_Contents = Alice_File_Load();
	Search_Word(Alice_Contents);
	free(Alice_Contents);
}