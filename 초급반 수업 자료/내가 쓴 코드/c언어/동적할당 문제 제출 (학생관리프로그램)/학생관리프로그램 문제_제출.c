#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#include<stdlib.h>
#define STOP 0
#define TURE 0
#define PROGRESS 1
#define MAX 20


typedef struct  p_information
{
	char Name[256];
	int Age;
	char Gender[10];
	int Garade;
	int Number;
}P_Information;


int Registration(P_Information* St_List, int St_Count);
void Show_Student(P_Information* St_List, int St_Count, int i);
void Garde_Sequence(P_Information* St_List, int St_Count, int grade);


int Registration(P_Information* St_List, int St_Count)
{
	system("cls");
	printf("===== %d번 학생=====\n", St_Count + 1);
	printf("이름 입력 : ");
	scanf("%s", St_List[St_Count].Name);
	printf("나이 입력 : ");
	scanf("%d", &St_List[St_Count].Age);
	printf("성별 입력 : ");
	scanf("%s", St_List[St_Count].Gender);
	printf("학년 입력 (1~3) : ");
	scanf("%d", &St_List[St_Count].Garade);
	St_List[St_Count].Number = St_Count + 1;
	return St_Count + 1;
}

void Show_Student(P_Information* St_List, int St_Count, int i)
{
	printf("===== %s 학생(%d번) =====\n", St_List[i].Name, St_List[i].Number);
	printf("나이 : %d, 성별 : %s, 학년 : %d\n", St_List[i].Age, St_List[i].Gender, St_List[i].Garade);
	printf("========================\n");
}

void Garde_Sequence(P_Information* St_List, int St_Count, int grade)
{
	printf("------------%d학년------------\n", grade);
	for (int i = 0; i < St_Count; i++)
	{
		if (St_List[i].Garade == grade)
			Show_Student(St_List, St_Count, i);
	}
	printf("------------------------------\n");
}
void main()
{
	int Progress = PROGRESS;
	int Input_Number;
	int Student_Count = 0;
	int Present_Student = 0;
	P_Information* Student_List;
	while (Progress)
	{

		system("cls");
		printf("===== 학생 관리 프로그램 ===== (총 인원 : %d)\n", Student_Count);
		printf("1. 학생 등록\n");
		printf("2. 학생 목록(번호순)\n");
		printf("3. 학생 목록(학년순)\n");
		printf("4. 학년 검색\n");
		printf("5. 학생 검색\n");
		printf("6. 마지막 학생 삭제\n");
		printf("7. 학생 전체 삭제\n");
		printf("8. 종료\n");
		printf("입력 : ");
		scanf("%d", &Input_Number);
		switch (Input_Number)
		{
		case 1:
			if (Student_Count + 1 >= MAX)
			{
				printf("학생정원(20명)이 모두 찼습니다.\n");
				break;
			}
			if (Student_Count == Present_Student)
			{
				if (Student_Count == 0)
					Student_List = (P_Information*)malloc(sizeof(P_Information));
				else
				{
					P_Information* Save_List = Student_List;
					//젤 처음 했을 때 : P_Information *Save_List = Student_List;
					//Save는 배열이 아닌데 List의 정보가 더 많은데 이런식으로 저장해도 되나?
					//시작주소만 따로 빼는 것이므로 Save변수의 크기는 상관하지 않아도 된다?
					//근데 다시 malloc으로 배열 만들면 시작주소 달라지고 달라진 시작주소에서 시작해서 배열 크기만큼 메모리 할당
					// 이걸 Save에 저장된 전 List시작주소로 바꿔버리면 시작주소만 따로 놀고 나머지 공간의 메모리 주소만 따로 연결된게 아닌가?
					// 따로 놈 - > 그래서 이상한 문자가 출력되는 건가??
					Student_List = (P_Information*)malloc(sizeof(P_Information) * (Student_Count + 1));
					//여기서 주소를 저장하면 안됨 - > 전 주소는 해제할것이기 때문
					//그럼 안에 들은 데이터만 빼와야하는 데 지금 코드는 시작주소의 정보만 빼오기 때문에 그 뒤는 이상한 문자가 출력이 된다?
					for (int i = 0; i < Student_Count; i++)
						*(Student_List + i) = *(Save_List + i);// 주소로 접근해서 주소에 값을 더해주면서 데이터 넣기
					free(Save_List);
					// case7에서 해체한 메모리 주소를 여기서 또 한번 해제하기 때문에 발생한 문제
					// 그래서 조건문 걸어서 전부 해체하면 다시 동적할당
				}
				Student_Count = Registration(Student_List, Student_Count);
				Present_Student = Student_Count;
				break;
			}
			else
			{
				Student_Count = Registration(Student_List, Student_Count);
				break;
			}

		case 2:
			system("cls");
			for (int i = 0; i < Student_Count; i++)
				Show_Student(Student_List, Student_Count, i);
			system("pause");
			break;

		case 3:
			system("cls");
			{
				int grade = 1;
				while (grade <= 3)
				{
					Garde_Sequence(Student_List, Student_Count, grade);
					grade++;
				}
				system("pause");
				break;
			}

		case 4:
			system("cls");
			while (Progress)
			{
				printf("검색할 학년 입력(1~3) : ");
				int Input_Grade;
				scanf("%d", &Input_Grade);
				if (Input_Grade >= 1 && Input_Grade <= 3)
				{
					Garde_Sequence(Student_List, Student_Count, Input_Grade); // 수정해야함
					system("pause");
					break;
				}
				else
				{
					printf("학년 잘못 입력 (범위 1~3 학년)\n");
					system("pause");
				}
			}
			break;

		case 5:
			system("cls");
			{
				char Input_Name[256];
				printf("검색할 이름 입력 : ");
				scanf("%s", Input_Name);
				for (int i = 0; i < Student_Count; i++)
				{
					if (strcmp(Student_List[i].Name, Input_Name) == TURE)
						Show_Student(Student_List, Student_Count, i);
					else
						continue;
				}
				system("pause");
				break;
			}

		case 6:
		{
			// free(Student_List + (Student_Count - 1));
			// 배열 자체를 동적할당시켰기 때문에 특정 학생만 따로 빼지 못함
			if (Student_Count > 0)
				--Student_Count;
			else
			{
				printf("등록된 학생이 없습니다.\n");
				system("pause");
			}
			break;
		}

		case 7:
			if (Student_Count > 0)
			{
				free(Student_List);
				Student_Count = 0;
				Present_Student = 0;
			}
			else
			{
				printf("등록된 학생이 없습니다.\n");
				system("pause");
			}
			break;
		case 8:
			if (Student_Count > 0)
			{
				free(Student_List);
				Progress = STOP;
			}
			else
				Progress = STOP;
		}
	}
}
