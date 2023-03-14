#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<Windows.h>
#include<list>

typedef struct student
{
	char name[20];
	char add[20];
	int sum, kor, eng, mat, age;
	float abs;
	char grade;
}Student;

Student AddStudent();
void SetGrade(Student* St);
void ShowStudent(std::list<Student>::iterator St);
std::list<Student>::iterator search(std::list<Student>* St, char* name);
void print(std::list<Student> St);
void del(std::list<Student>* St, char* name);

Student AddStudent()
{
	Student St_inforamation;
	printf("학생 이름 입력 : ");
	scanf("%s", St_inforamation.name);
	printf("%s 학생 나이 입력 : ", St_inforamation.name);
	scanf("%d", &St_inforamation.age);
	printf("%s 학생 주소 입력 : ", St_inforamation.name);
	scanf("%s", St_inforamation.add);
	printf("%s 학생 국어 입력 : ", St_inforamation.name);
	scanf("%d", &St_inforamation.kor);
	printf("%s 학생  영어 입력 : ", St_inforamation.name);
	scanf("%d", &St_inforamation.eng);
	printf("%s 학생 수학 입력 : ", St_inforamation.name);
	scanf("%d", &St_inforamation.mat);
	SetGrade(&St_inforamation);
	return St_inforamation;
}

void SetGrade(Student* St)
{
	St->sum = (St->eng) + (St->kor) + (St->mat);
	St->abs = St->sum / 3;
	if (St->abs > 90)
		St->grade = 'A';
	else if (St->abs > 80)
		St->grade = 'B';
	else if (St->abs > 70)
		St->grade = 'C';
	else if (St->abs > 60)
		St->grade = 'D';
	else
		St->grade = 'F';
}

void ShowStudent(std::list<Student>::iterator St)
{
	printf("========================\n");
	printf("학생 이름 : %s\n", St->name);
	printf("학생 나이 : %d 세\n", St->age);
	printf("학생 주소 : %s\n", St->add);
	printf("국어 점수 : %d\n", St->kor);
	printf("영어 점수 : %d\n", St->eng);
	printf("수학 점수 : %d\n", St->mat);
	printf("합계 점수 : %d\n", St->sum);
	printf("평균 점수 : %.2f\n", St->abs);
	printf("등급 : %c\n", St->grade);
}

std::list<Student>::iterator search(std::list<Student>* St, char* name)
{
	system("cls");
	for (std::list<Student>::iterator iter = St->begin(); iter != St->end(); iter++)
	{
		if (strcmp(iter->name, name) == 0)
		{
			printf("정보 검색 완료\n");
			ShowStudent(iter);
			return iter;
		}
	}
	return St->end();
}

void print(std::list<Student> St)
{
	for (std::list<Student>::iterator iter = St.begin(); iter != St.end(); iter++)
		printf("%10s%10d%10s\n", iter->name, iter->age, iter->add);
	printf("\n<학생 개개인의 점수는 검색을 이용하세요 !!>\n");
	return;
}

void modify(std::list<Student>* St, char* name)
{
	int i, ag;
	char na[20], ad[20];
	std::list<Student>::iterator iter = search(St, name);
	if (iter != St->end())
	{
		while (1)
		{
			system("cls");
			printf("수정할 항목을 선택 하시오 \n");
			printf("1.이름\t2.나이\t3.주소\t4.점수\t5.수정종료\n선택 : ");
			scanf("%d", &i);
			switch (i)
			{
			case 1:
				printf("현재 이름 : %s\n", iter->name);
				strcpy(na, iter->name);
				printf("수정할 이름 : ");
				scanf("%s", iter->name);
				printf("%s -> %s 로 이름 수정 완료\n", na, iter->name);
				break;
			case 2:
				printf("현재 나이 : %d\n", iter->age);
				ag = iter->age;
				printf("수정할 나이 : ");
				scanf("%d", &iter->age);
				printf("%d -> %d 로 이름 수정 완료\n", ag, iter->age);
				break;
			case 3:
				printf("현재 주소 : %s\n", iter->add);
				strcpy(ad, iter->add);
				printf("수정할 주소 : ");
				scanf("%s", iter->add);
				printf("%s -> %s 로 주소 수정 완료\n", ad, iter->add);
				break;
			case 4:
				printf("현재 점수\n");
				printf("국어 : %d\t영어 : %d\t수학 : %d\n", iter->kor, iter->eng, iter->mat);
				printf("수정할 국어 점수 : ");
				scanf("%d", &(iter->kor));
				printf("수정할 영어 점수 : ");
				scanf("%d", &iter->eng);
				printf("수정할 수학 점수 : ");
				scanf("%d", &iter->mat);
				Student modify_student = *iter;
				SetGrade(&modify_student);
				*iter = modify_student;
				printf("점수 수정 완료\n");
				break;
			case 5:
				printf("수정을 종료합니다\n");
				return;
			}
			system("pause");
		}
	}
}

void del(std::list<Student>* St, char* name)
{
	std::list<Student>::iterator iter = search(St, name);
	if (iter != St->end())
		St->erase(iter);
}

void main()
{
	std::list<Student> student;
	int i;
	char name[20];
	while (1)
	{
		system("cls");
		printf("< < < = = = = 메뉴 = = = = > > >\n\n");
		printf("1.학생 등록\n");
		printf("2.학생 검색\n");
		printf("3.학생 목록\n");
		printf("4.학생 수정\n");
		printf("5.학생 삭제\n");
		printf("6.종     료\n");
		printf("선  택 : ");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			student.push_back(AddStudent());
			break;
		case 2:
		{
			printf("학생 이름 입력 : ");
			scanf("%s", name);
			std::list<Student>::iterator search_result = search(&student, name);
			if (search_result == student.end())
				printf("찾는 학생 없음\n");
			break;
		}
		case 3:
			printf("%10s%10s%10s\n", "학생이름", "학생나이", "학생주소");
			print(student);
			break;
		case 4:
			printf("수정할 학생 이름 : ");
			scanf("%s", name);
			modify(&student, name);
			break;
		case 5:
			printf("학생 이름 입력 : ");
			scanf("%s", name);
			del(&student, name);
			break;
		case 6:
			student.clear();
			return;
		}
		system("pause");
	}
}