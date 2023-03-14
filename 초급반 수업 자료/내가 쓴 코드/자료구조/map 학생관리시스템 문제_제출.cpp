#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<map>

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
void ShowStudent(std::map<int, Student>::iterator iter);
std::map<int, Student>::iterator search(std::map<int, Student>* St, int id);
void print(std::map<int, Student> St);
void modify(std::map<int, Student>* St, int id);
void del(std::map<int, Student>* St, int id);

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

void ShowStudent(std::map<int, Student>::iterator St)
{
	printf("========================\n");
	printf("학생 이름 : %s\n", St->second.name);
	printf("학생 나이 : %d 세\n", St->second.age);
	printf("학생 주소 : %s\n", St->second.add);
	printf("국어 점수 : %d\n", St->second.kor);
	printf("수학 점수 : %d\n", St->second.mat);
	printf("합계 점수 : %d\n", St->second.sum);
	printf("평균 점수 : %.2f\n", St->second.abs);
	printf("등급 : %c\n", St->second.grade);
}

std::map<int, Student>::iterator search(std::map<int, Student>* St, int id)
{
	system("cls");
	std::map<int, Student>::iterator iter = St->find(id);
	if (iter != St->end())
	{
		printf("정보 검색 완료\n");
		ShowStudent(iter);
		return iter;
	}
	else
	{
		printf("찾는학생 없음 \n");
		return St->end();
	}
}

void print(std::map<int, Student> St)
{
	for (std::map<int, Student>::iterator iter = St.begin(); iter != St.end(); iter++)
		printf("%10s%10d%10s\n", iter->second.name, iter->second.age, iter->second.add);
	printf("\n<학생 개개인의 점수는 검색을 이용하세요 !!>\n");
	return;
}

void modify(std::map<int, Student>* St, int id)
{
	int i, ag;
	char na[20], ad[20];
	std::map<int, Student>::iterator iter = search(St, id);
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
				printf("현재 이름 : %s\n", iter->second.name);
				//(*St)[id].name : St는 주소를 가지고 있으므로 포인터로 따라가줘야 함
				//St[id].name : St는 주소를 가지고 있고 []는 id만큼 더해주겠다는 것인데 주소에 id만큼 더하는 것은 말이 안되는 것
				// St[id]->name : 위와 동일
				strcpy(na, iter->second.name);
				printf("수정할 이름 : ");
				scanf("%s", iter->second.name);
				printf("%s -> %s 로 이름 수정 완료\n", na, iter->second.name);
				break;
			case 2:
				printf("현재 나이 : %d\n", iter->second.age);
				ag = iter->second.age;
				printf("수정할 나이 : ");
				scanf("%d", &iter->second.age);
				printf("%d -> %d 로 이름 수정 완료\n", ag, iter->second.age);
				break;
			case 3:
				printf("현재 주소 : %s\n", iter->second.add);
				strcpy(ad, iter->second.add);
				printf("수정할 주소 : ");
				scanf("%s", iter->second.add);
				printf("%s -> %s 로 주소 수정 완료\n", ad, iter->second.add);
				break;
			case 4:
				printf("현재 점수\n");
				printf("국어 : %d\t영어 : %d\t수학 : %d\n", iter->second.kor, iter->second.eng, iter->second.mat);
				printf("수정할 국어 점수 : ");
				scanf("%d", &(iter->second.kor));
				printf("수정할 영어 점수 : ");
				scanf("%d", &iter->second.eng);
				printf("수정할 수학 점수 : ");
				scanf("%d", &iter->second.mat);
				SetGrade(&iter->second);
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

void del(std::map<int, Student>* St, int id)
{
	std::map<int, Student>::iterator iter = St->find(id);
	if (iter != St->end())
		St->erase(iter);
}

void main()
{
	std::map<int, Student> student;
	int i;
	int id;
	int student_ID = 1;
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
			student.insert(std::make_pair(student_ID++, AddStudent()));
			break;
		case 2:
			printf("학번 입력 : ");
			scanf("%d", &id);
			search(&student, id);
			break;
		case 3:
			printf("%10s%10s%10s\n", "학생이름", "학생나이", "학생주소");
			print(student);
			break;
		case 4:
			printf("학번 입력 : ");
			scanf("%d", &id);
			modify(&student, id);
			break;
		case 5:
			printf("학번 입력 : ");
			scanf("%d", &id);
			del(&student, id);
			break;
		case 6:
			student.clear();
			return;
		}
		system("pause");
	}
}