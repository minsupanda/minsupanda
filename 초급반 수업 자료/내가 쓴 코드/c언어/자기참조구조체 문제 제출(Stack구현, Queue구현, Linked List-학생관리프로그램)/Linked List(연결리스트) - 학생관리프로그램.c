#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define PROGRESS 1
#define SAME 0

typedef struct Student
{
	char Name[10];
	int Age;
	char Address[256];
	int Kor;
	int Eng;
	int Math;
	int Sum;
	float Average;
	char Rating;
	struct Student* Next;
}Student;

void Menu();
void Print(Student* st_List);
Student* Registration(Student* st_List);
void Score(Student* st_List);
Student* Search(Student* st_List);
void List(Student* st_List);
Student* Correction(Student* st_List);
Student* Delete(Student* st_List, Student* Delete_List);
void Exit(Student* st_List);

void Menu()
{
	printf("< < < = = = = 메뉴 = = = = > > >\n\n");
	printf("1. 학생 등록\n");
	printf("2. 학생 검색\n");
	printf("3. 학생 목록\n");
	printf("4. 학생 수정\n");
	printf("5. 학생 삭제\n");
	printf("6. 종료\n");
	printf("선택 : ");
}

void Print(Student* st_List)
{
	printf("< < = = = = information = = = = > >\n");
	printf("학생 이름 : %s\n", st_List->Name);
	printf("학생 나이 : %d 세\n", st_List->Age);
	printf("학생 주소 : %s\n", st_List->Address);
	printf("국어 점수 : %d 점\n", st_List->Kor);
	printf("영어 점수 : %d 점\n", st_List->Eng);
	printf("수학 점수 : %d 점\n", st_List->Math);
	printf("합계 점수 : %d 점\n", st_List->Sum);
	printf("평균 점수 : %.2f 점\n", st_List->Average);
	printf("학생 등급 : %c 등급\n", st_List->Rating);
}

Student* Registration(Student* st_List)
{
	if (st_List == NULL)
	{
		system("cls");
		st_List = (Student*)malloc(sizeof(Student));
		printf("학생 이름 입력 : ");
		scanf("%s", st_List->Name);
		printf("%s 학생 나이 입력 : ", st_List->Name);
		scanf("%d", &st_List->Age);
		printf("%s 학생 주소 입력 : ", st_List->Name);
		scanf("%s", st_List->Address);
		printf("%s 학생 국어 점수 : ", st_List->Name);
		scanf("%d", &st_List->Kor);
		printf("%s 학생 영어 점수 : ", st_List->Name);
		scanf("%d", &st_List->Eng);
		printf("%s 학생 수학 점수 : ", st_List->Name);
		scanf("%d", &st_List->Math);
		Score(st_List);
		st_List->Next = NULL;
		printf("학생 정보 입력 완료\n");
	}
	else
		st_List->Next = Registration(st_List->Next);
	return st_List;
}

void Score(Student* st_List)
{
	st_List->Sum = st_List->Kor + st_List->Eng + st_List->Math;
	st_List->Average = (float)st_List->Sum / 3;
	if (st_List->Average < 70.00)
		st_List->Rating = 'F';
	else if (st_List->Average < 80.00)
		st_List->Rating = 'C';
	else if (st_List->Average < 90.00)
		st_List->Rating = 'B';
	else
		st_List->Rating = 'A';
}

Student* Search(Student* st_List)
{
	system("cls");
	char Serch_Name[10];
	printf("학생 이름 입력 :");
	scanf("%s", Serch_Name);
	for (st_List; st_List != NULL; st_List = st_List->Next)
	{
		if (strcmp(Serch_Name, st_List->Name) == SAME)
		{
			printf("학생 정보 검색 완료\n");
			Print(st_List);
			return st_List;
		}
	}
	printf("해당 학생은 존재하지 않습니다.\n");
	return NULL;
}

void List(Student* st_List)
{
	system("cls");
	if (st_List == NULL)
	{
		printf("저장된 데이터가 없습니다\n");
		return;
	}
	printf("< < = = = = information = = = = > >\n\n");
	printf("\t학생이름\t학생나이\t학생주소\n");
	for (st_List; st_List != NULL; st_List = st_List->Next)
		printf("%16s%16d%16s\n", st_List->Name, st_List->Age, st_List->Address);
	printf("(학생 개개인의 점수는 검색을 이용하세요 !!)\n");
}

Student* Correction(Student* st_List)
{
	Student* Correction_List = Search(st_List);
	system("cls");
	if (Correction_List == NULL)
	{
		printf("찾는 학생이 없습니다.\n");
		return st_List;
	}
	while (PROGRESS)
	{
		system("cls");
		int select;
		Print(Correction_List);
		printf("\n수정할 항목을 선택하시오\n");
		printf("1.이름  2.나이  3.주소  4.점수  5.수정종료\n");
		printf("선택 :");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
		{
			char Pre_Name[10];
			strcpy(Pre_Name, Correction_List->Name);
			printf("현재 이름 : %s\n", Pre_Name);
			printf("수정할 이름 :");
			scanf("%s", Correction_List->Name);
			printf("%s -> %s 로 이름 수정 완료\n", Pre_Name, Correction_List->Name);
			break;
		}
		case 2:
		{
			int Pre_Age;
			Pre_Age = Correction_List->Age;
			printf("현재 나이 : %d\n", Pre_Age);
			printf("수정할 나이 :  세\b\b");
			scanf("%d", &Correction_List->Age);
			printf("%d세 -> %d세 로 이름 수정 완료\n", Pre_Age, Correction_List->Age);
			break;
		}
		case 3:
		{
			char Pre_Aderess[256];
			strcpy(Pre_Aderess, Correction_List->Address);
			printf("현재 주소 : %s\n", Pre_Aderess);
			printf("수정할 주소 :");
			scanf("%s", Correction_List->Address);
			printf("%s -> %s 로 주소 수정 완료\n", Pre_Aderess, Correction_List->Address);
			break;
		}
		case 4:
		{
			printf("현재 점수\n");
			printf("국어 : %d 영어 : %d 수학 : %d\n", Correction_List->Kor, Correction_List->Eng, Correction_List->Math);
			printf("수정할 국어 점수 :");
			scanf("%d", &Correction_List->Kor);
			printf("수정할 영어 점수 :");
			scanf("%d", &Correction_List->Eng);
			printf("수정할 수학 점수 :");
			scanf("%d", &Correction_List->Math);
			Score(Correction_List);
			printf("점수 수정 완료\n");
			break;
		}
		case 5:
			printf("수정을 종료합니다.\n");
			return st_List;
		}
		system("pause");
	}
}

Student* Delete(Student* st_List, char Delete_Name[10])
{
	if (st_List == NULL)
	{
		printf("해당 학생은 존재하지 않습니다.\n");
		return st_List;
	}
	else if (strcmp(st_List->Name, Delete_Name) == SAME)
	{
		Student* Temp = st_List;
		st_List = st_List->Next;
		free(Temp);
		printf("삭제 완료\n");
		return st_List;
	}
	st_List->Next = Delete(st_List->Next, Delete_Name);
	return st_List;
}

void Exit(Student* st_List)
{
	if (st_List == NULL)
		return st_List;
	Exit(st_List->Next);
	free(st_List);
}

void main()
{
	Student* student_List = NULL;
	while (PROGRESS)
	{
		system("cls");
		Menu();
		int selcet;
		scanf("%d", &selcet);
		switch (selcet)
		{
		case 1:
			student_List = Registration(student_List);
			break;
		case 2:
		{
			Search(student_List);
			break;
		}
		case 3:
			List(student_List);
			break;
		case 4:
			student_List = Correction(student_List);
			break;
		case 5:
		{
			system("cls");
			if (student_List == NULL) // 저장된 학생이 없거나, 검색한 학생이 없을 때
				printf("삭제할 학생이 없습니다.\n");
			else
			{
				char Delete_Name[10];
				printf("삭제할 학생 이름 : ");
				scanf("%s", Delete_Name);
				student_List = Delete(student_List, Delete_Name);
			}
			break;
		}
		case 6:
			Exit(student_List);
			return;
		}
		system("pause");
	}
}