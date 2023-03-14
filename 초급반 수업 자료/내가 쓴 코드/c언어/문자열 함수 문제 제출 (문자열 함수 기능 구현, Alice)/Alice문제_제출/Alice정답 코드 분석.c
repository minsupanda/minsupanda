#pragma warning(disable:4996) //sdl해제코드(scanf_s 사용 안하려고(옵션에서 sdl 체크 해제한 것과 같음), 파일 입력 받을 때 예를 들어 지정된 배열 크기보다 더 큰 크기를 입력 받으면 메모리가 오버 되는데 그것을 막기 위해서 sdl해제를 옵션에서 해줬던 건데 이거는 그냥 코드로 해제시켜주는 것)
#include<stdio.h>
#include<time.h> //필요없음
#include<string.h>
//KPM 알고리즘을 사용한 것.
int KMPCheck(char buf[], char Check[], int Size)
{
	for (int i = 0; i <= Size / 2; i++)
	{
		if (buf[i] != Check[i] || buf[Size - i] != Check[Size - i])
			//시작문자의 다음문자부터 검색 뒤에서도 가장 뒷문자의 전 문자부터 검색, 이때 앞 뒤로 같이 검색하기 때문에 Size / 2만큼만 반복문을 돌리는 것
			//이때 하나라도 맞지 않으면 바로 0을 반환해서 카운트 올라가지 않음
			return 0;
	}
	return 1;
}

int KMPSearch(char buf[], char Check[], int Size)
{
	int count = 0;
	for (int i = 0; buf[i] != NULL; i++)
	{
		if (Check[0] == buf[i] && Check[Size - 1] == buf[i + Size - 1])
			//찾고자 하는 단어의 길이를 받아  인덱스에 - 1을 하면 마지막 단어가 나오므로
			//첫 글자와 마지막 글자가 동일할 때 if문 실행
			//여기서 중간에 들어간 글자는 달라도 일단 들어감
		{
			if (KMPCheck(&buf[i + 1], &Check[1], Size - 3) == 1)
				//여기서 중간에 들어간 문자 탐색하기 위해 시작문자의 다음문자들을 매개변수로 들고감
				//Size에 -3을 하는 것은 가장 앞문자, 뒷문자, i+1을 했으니 두번째문자부터 시작하기 때문에(안 빼주면 인덱스 범위가 맞지 않음) 들어간 크기만큼 제외한것
			{
				count++;
				i += (Size - 1);
				//탐색이 끝난 다음문자부터 다시 탐색하기 위함
			}
		}
	}
	return count;
}
void main()
{
	char buf[300000] = { 0 };
	FILE* f = fopen("Alice.txt", "r");
	if (f == NULL)
	{
		printf("해당 이름의 파일이 없습니다.\n");
		return;
	}
	else
	{
		fread(buf, sizeof(buf), 1, f);
		fclose(f);
		printf("%s", buf);
		char Check[256];
		printf("Check Word Input : ");
		scanf("%s", Check);
		f = fopen("Alice.txt", "r");
		int count = 0;
		while (!feof(f))
		{
			fgets(buf, sizeof(buf), f);
			count += KMPSearch(buf, Check, strlen(Check));
		}
		printf("KPM Check %s Count : %d\n", Check, count);
	}
}