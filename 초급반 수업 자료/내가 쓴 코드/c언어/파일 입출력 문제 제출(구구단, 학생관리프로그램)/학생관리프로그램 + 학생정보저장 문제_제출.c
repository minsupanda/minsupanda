#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define TURE 0
#define FALSE 1
#define UNPLACED 0
#define STOP 0
#define PROGRESS 1
#define LEFT_SEAT 0
#define RITHG_SEAT 1
#define INCOMPLETE 0
#define COMPLETION 1
#define MAX 20


typedef struct  p_information
{
	char Name[256];
	int Age;
	char Gender[10];
	int Garade;
	int Number;
	int seat_Number;
}P_Information;

int Registration(P_Information* St_List, FILE* St_File, int St_Count);
void Name_Overlap(P_Information* St_List, int St_Count);
void Show_Student(P_Information* St_List, int St_Count, int i);
void Garde_Sequence(P_Information* St_List, int St_Count, int grade);
void Student_File_Save(P_Information* St_List, FILE* St_File, int St_Count);
void Seat_Arrangement(P_Information* St_List, FILE* Seat_File, int St_Count);
void Math(P_Information* St_List, FILE* Seat_File, int St_Count);
void Show_Seat(FILE* Seat_File);

int Registration(P_Information* St_List, FILE* St_File, int St_Count) // 학생 등록
{
	system("cls");

	printf("===== %d번 학생=====\n", St_Count + 1);

	Name_Overlap(St_List, St_Count);

	printf("나이 입력 : ");
	scanf("%d", &St_List[St_Count].Age);

	printf("성별 입력 : ");
	scanf("%s", St_List[St_Count].Gender);

	printf("학년 입력 (1~3) : ");
	scanf("%d", &St_List[St_Count].Garade);

	St_List[St_Count].Number = St_Count + 1;

	Student_File_Save(St_List, St_File, St_Count + 1);

	return St_Count + 1;
}

void Name_Overlap(P_Information* St_List, int St_Count)
{
	if (St_Count < 1)
	{
		printf("이름 입력 : ");
		scanf("%s", St_List[St_Count].Name);
	}
	else
	{
		char Input_Name[10];
		while (PROGRESS)
		{
			printf("이름 입력 : ");
			scanf("%s", Input_Name);
			int Over_lap = TURE;
			for (int i = 0; i < St_Count; i++)
			{
				if (strcmp(St_List[i].Name, Input_Name) != TURE)
				{
					strcpy(St_List[St_Count].Name, Input_Name);
					Over_lap = FALSE;
				}
				else
				{
					printf("동명이인이 존재합니다. 다시 입력해주세요.\n");
					Over_lap = TURE;
				}
			}
			if (Over_lap == FALSE)
				break;
		}
	}
}

void Show_Student(P_Information* St_List, int St_Count, int i) // 등록된 학생 출력 함수
{
	printf("===== %s 학생(%d번) =====\n", St_List[i].Name, St_List[i].Number);
	printf("나이 : %d, 성별 : %s, 학년 : %d\n", St_List[i].Age, St_List[i].Gender, St_List[i].Garade);
	printf("========================\n");
}

void Garde_Sequence(P_Information* St_List, int St_Count, int grade) // 학년순으로 출력 함수
{
	printf("------------%d학년------------\n", grade);
	for (int i = 0; i < St_Count; i++)
	{
		if (St_List[i].Garade == grade)
			Show_Student(St_List, St_Count, i);
	}
	printf("------------------------------\n");
}

void Student_File_Save(P_Information* St_List, FILE* St_File, int St_Count) // 학생 파일 저장 함수
{
	fprintf(St_File, "%d\n", St_Count);
	for (int i = 0; i < St_Count; i++)
		fprintf(St_File, "%s %d %s %d %d\n", St_List[i].Name, St_List[i].Age, St_List[i].Gender, St_List[i].Garade, St_List[i].Number);
}

void Seat_Arrangement(P_Information* St_List, FILE* Seat_File, int St_Count) // 자리 배치 함수
{
	int Left_Seat;
	int Right_Seat;
	for (int i = 0; i < St_Count; i++)
		St_List[i].seat_Number = UNPLACED;
	for (int i = 1; i <= St_Count / 2; i++)
	{
		while (PROGRESS) // 자리 중복 방지
		{
			Left_Seat = rand() % St_Count + 1; // 좌석번호를 1번부터 부여하기 위함
			if (St_List[Left_Seat - 1].seat_Number == UNPLACED)
			{
				St_List[Left_Seat - 1].seat_Number = Left_Seat;
				break;
			}
		}
		while (PROGRESS)
		{
			Right_Seat = rand() % St_Count + 1;
			if (St_List[Right_Seat - 1].seat_Number == UNPLACED)
			{
				St_List[Right_Seat - 1].seat_Number = Right_Seat;
				break;
			}
		}
	}
	Math(St_List, Seat_File, St_Count);
}

void Re_Seat_Arrangement(P_Information* St_List, FILE* Seat_File, int Dissatisfaction_St, int St_Count) // 자리 재배치 함수
{
	Seat_File = fopen("자리 배치.txt", "w");
	for (int i = 0; i < St_Count; i++)
	{
		if (i != Dissatisfaction_St) // 불만을 가진 학생만 두고 나머지만 자리 교체
		{
			while (PROGRESS)
			{
				int Change_Student = rand() % St_Count;
				if (Change_Student != Dissatisfaction_St)
					// 학생들에게 부여된 좌석번호를 변경
				{
					int tmp_Seat = St_List[i].seat_Number;
					St_List[i].seat_Number = St_List[Change_Student].seat_Number;
					St_List[Change_Student].seat_Number = tmp_Seat;
					break;
				}
			}
		}
	}
	Math(St_List, Seat_File, St_Count);
	fclose(Seat_File);
	printf("\n자리 재배치 완료!\n");
}

void Math(P_Information* St_List, FILE* Seat_File, int St_Count)
{
	int Seat_Number = 1; // 좌석번호는 1부터 부여했기 때문
	while (Seat_Number <= St_Count)
	{
		// 변경된 좌석번호를 가지고 1번 자리부터 다시 좌석 배치
		// 불만을 가진 학생은 변경되지 않았으므로 기존의 번호를 그대로 가지고 있을 것
		for (int i = 0; i < St_Count; i++)
		{
			if (St_List[i].seat_Number == Seat_Number)
			{
				fprintf(Seat_File, "%s", St_List[i].Name);
				if (Seat_Number % 2 == 0) // 2명씩 짝찌어서 줄을 바꿔주기 위함
					fprintf(Seat_File, "\n");
				Seat_Number++;
				break;
			}
		}
	}
}

void Show_Seat(FILE* Seat_File) // 배치된 자리 출력 함수
{
	Seat_File = fopen("자리 배치.txt", "r");
	while (!feof(Seat_File))
	{
		char show_seat[20] = { 0 }; // 초기화 안하면 남은 공간에 임의로 값이 들어가서 출력됨
		fgets(show_seat, sizeof(show_seat), Seat_File);
		printf("%s\n", show_seat);
	}
	fclose(Seat_File);
}

void main()
{
	srand(time(NULL));
	int Progress = PROGRESS;
	int Input_Number;
	int Student_Count = 0;
	int Present_Student = 0;
	int Transfer_Student = 0;
	int Seat_Completion = INCOMPLETE;
	P_Information* Student_List;
	FILE* Student_File = fopen("학생 명부.txt", "r");
	FILE* Seat_File;

	if (Student_File != NULL) // 해당 파일이 있으면 종속문 실행
	{
		printf("등록된 학생을 불러옵니다.\n");
		fscanf(Student_File, "%d", &Present_Student);
		printf(" 현재 학생 수 : %d\n", Present_Student);
		Student_List = (P_Information*)malloc(sizeof(P_Information) * Present_Student);
		for (int i = 0; i < Present_Student; i++)
		{
			fscanf(Student_File, "%s", Student_List[i].Name);
			fscanf(Student_File, "%d", &Student_List[i].Age);
			fscanf(Student_File, "%s", Student_List[i].Gender);
			fscanf(Student_File, "%d", &Student_List[i].Garade);
			fscanf(Student_File, "%d", &Student_List[i].Number);
			printf("이름 : %s, 나이 : %d, 성별 : %s, 반 : %d\n", Student_List[i].Name, Student_List[i].Age, Student_List[i].Gender, Student_List[i].Garade, Student_List[i].Number);
		}
		Student_Count = Present_Student;
		Transfer_Student = Present_Student;
		fclose(Student_File);
		//전학생 출력을 위함
	}
	else
		printf("현재 등록된 학생이 없습니다.\n");
	system("pause");
	while (Progress)
	{

		system("cls");
		printf("===== 학생 관리 프로그램 ===== (총 인원 : %d)\n", Student_Count);
		printf("1. 학생 등록\n");
		printf("2. 학생 목록(번호순)\n");
		printf("3. 학생 목록(학년순)\n");
		printf("4. 학년 검색\n");
		printf("5. 학생 검색\n");
		printf("6. 전학생 목록\n");
		printf("7. 자리 배치\n");
		printf("8. 자리 확인\n");
		printf("9. 마지막 학생 삭제\n");
		printf("10. 학생 전체 삭제\n");
		printf("11. 종료\n");
		printf("입력 : ");
		scanf("%d", &Input_Number);
		switch (Input_Number)
		{
		case 1:
			if (Student_Count + 1 >= MAX)
			{
				printf("학생정원(%d명)이 모두 찼습니다.\n", MAX);
				break;
			}

			if (Student_Count == Present_Student)
			{
				if (Student_Count == 0)
					Student_List = (P_Information*)malloc(sizeof(P_Information));
				else
				{
					P_Information* Save_List = Student_List;
					Student_List = (P_Information*)malloc(sizeof(P_Information) * (Student_Count + 1));
					for (int i = 0; i < Student_Count; i++)
						*(Student_List + i) = *(Save_List + i);
					free(Save_List);
				}
				Student_File = fopen("학생 명부.txt", "w");
				Student_Count = Registration(Student_List, Student_File, Student_Count);
				Present_Student = Student_Count;
			}
			else
			{
				Student_File = fopen("학생 명부.txt", "a");
				Student_Count = Registration(Student_List, Student_File, Student_Count);
			}
			fclose(Student_File);
			break;

		case 2:
			system("cls");
			for (int i = 0; i < Student_Count; i++)
				Show_Student(Student_List, Student_Count, i);
			system("pause");
			break;

		case 3:
			system("cls");
			{
				for (int i = 0; i <= 3; i++)
					Garde_Sequence(Student_List, Student_Count, i + 1);
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
					Garde_Sequence(Student_List, Student_Count, Input_Grade);
					system("pause");
					break;
				}
				printf("학년 잘못 입력 (범위 1~3학년)\n");
			}

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
				}
				system("pause");
				break;
			}

		case 6:
			system("cls");
			{
				if (Transfer_Student == Student_Count || Student_Count == 0)
					printf("전학생이 없습니다.\n");
				else
				{
					for (int i = Transfer_Student; i < Student_Count; i++)
						Show_Student(Student_List, Student_Count, i);
				}
				system("pause");
				break;
			}

		case 7: // 자리 랜덤 배치
			system("cls");
			{
				if (Student_Count % 2 == 0 && Student_Count > 0)
				{
					Seat_File = fopen("자리 배치.txt", "w");
					Seat_Arrangement(Student_List, Seat_File, Student_Count);
					fclose(Seat_File);
					printf("자리 배치 완료!\n\n");
					Seat_Completion = COMPLETION;
				}
				else
					printf("학생 수가 부족합니다.\n""혼자 앉는 학생은 외로워요\n""");
				system("pause");
				break;
			}

		case 8: // 배치된 자리 확인
			system("cls");
			{
				if (Seat_Completion == COMPLETION) // 자리 배치가 완료되었을때
				{
					Show_Seat(Student_List, Seat_File);
					int Dissatisfactioin = rand() % 3; // 일정확률로 불만학생 생김
					if (Dissatisfactioin == TURE)
					{
						int Dissatisfaction_Student = rand() % Student_Count;
						printf("%s학생 : 저 짝꿍이 마음에 안들어요....\n", Student_List[Dissatisfaction_Student].Name);
						system("pause");
						Re_Seat_Arrangement(Student_List, Seat_File, Dissatisfaction_Student, Student_Count);
						Show_Seat(Student_List, Seat_File);
						printf("%s학생 : 이제 마음에 들어요!\n", Student_List[Dissatisfaction_Student].Name);
					}
				}
				else
					printf("자리 배치가 되지않았습니다.\n");
				system("pause");
				break;
			}

		case 9:
		{
			if (Student_Count > 0)
			{
				Student_File = fopen("학생 명부.txt", "w");
				--Student_Count;
				Student_File_Save(Student_List, Student_File, Student_Count);
				fclose(Student_File);
			}
			else
			{
				printf("등록된 학생이 없습니다.\n");
				system("pause");
			}
			break;
		}

		case 10:
			if (Student_Count > 0)
			{
				Student_File = fopen("학생 명부.txt", "w");
				free(Student_List);
				Student_Count = 0;
				Present_Student = 0;
				Student_List = NULL;
				Student_File_Save(Student_List, Student_File, Student_Count);
				fclose(Student_File);
			}
			else
			{
				printf("등록된 학생이 없습니다.\n");
				system("pause");
			}
			break;

		case 11:
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
