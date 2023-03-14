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

int Registration(P_Information* St_List, FILE* St_File, int St_Count) // �л� ���
{
	system("cls");

	printf("===== %d�� �л�=====\n", St_Count + 1);

	Name_Overlap(St_List, St_Count);

	printf("���� �Է� : ");
	scanf("%d", &St_List[St_Count].Age);

	printf("���� �Է� : ");
	scanf("%s", St_List[St_Count].Gender);

	printf("�г� �Է� (1~3) : ");
	scanf("%d", &St_List[St_Count].Garade);

	St_List[St_Count].Number = St_Count + 1;

	Student_File_Save(St_List, St_File, St_Count + 1);

	return St_Count + 1;
}

void Name_Overlap(P_Information* St_List, int St_Count)
{
	if (St_Count < 1)
	{
		printf("�̸� �Է� : ");
		scanf("%s", St_List[St_Count].Name);
	}
	else
	{
		char Input_Name[10];
		while (PROGRESS)
		{
			printf("�̸� �Է� : ");
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
					printf("���������� �����մϴ�. �ٽ� �Է����ּ���.\n");
					Over_lap = TURE;
				}
			}
			if (Over_lap == FALSE)
				break;
		}
	}
}

void Show_Student(P_Information* St_List, int St_Count, int i) // ��ϵ� �л� ��� �Լ�
{
	printf("===== %s �л�(%d��) =====\n", St_List[i].Name, St_List[i].Number);
	printf("���� : %d, ���� : %s, �г� : %d\n", St_List[i].Age, St_List[i].Gender, St_List[i].Garade);
	printf("========================\n");
}

void Garde_Sequence(P_Information* St_List, int St_Count, int grade) // �г������ ��� �Լ�
{
	printf("------------%d�г�------------\n", grade);
	for (int i = 0; i < St_Count; i++)
	{
		if (St_List[i].Garade == grade)
			Show_Student(St_List, St_Count, i);
	}
	printf("------------------------------\n");
}

void Student_File_Save(P_Information* St_List, FILE* St_File, int St_Count) // �л� ���� ���� �Լ�
{
	fprintf(St_File, "%d\n", St_Count);
	for (int i = 0; i < St_Count; i++)
		fprintf(St_File, "%s %d %s %d %d\n", St_List[i].Name, St_List[i].Age, St_List[i].Gender, St_List[i].Garade, St_List[i].Number);
}

void Seat_Arrangement(P_Information* St_List, FILE* Seat_File, int St_Count) // �ڸ� ��ġ �Լ�
{
	int Left_Seat;
	int Right_Seat;
	for (int i = 0; i < St_Count; i++)
		St_List[i].seat_Number = UNPLACED;
	for (int i = 1; i <= St_Count / 2; i++)
	{
		while (PROGRESS) // �ڸ� �ߺ� ����
		{
			Left_Seat = rand() % St_Count + 1; // �¼���ȣ�� 1������ �ο��ϱ� ����
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

void Re_Seat_Arrangement(P_Information* St_List, FILE* Seat_File, int Dissatisfaction_St, int St_Count) // �ڸ� ���ġ �Լ�
{
	Seat_File = fopen("�ڸ� ��ġ.txt", "w");
	for (int i = 0; i < St_Count; i++)
	{
		if (i != Dissatisfaction_St) // �Ҹ��� ���� �л��� �ΰ� �������� �ڸ� ��ü
		{
			while (PROGRESS)
			{
				int Change_Student = rand() % St_Count;
				if (Change_Student != Dissatisfaction_St)
					// �л��鿡�� �ο��� �¼���ȣ�� ����
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
	printf("\n�ڸ� ���ġ �Ϸ�!\n");
}

void Math(P_Information* St_List, FILE* Seat_File, int St_Count)
{
	int Seat_Number = 1; // �¼���ȣ�� 1���� �ο��߱� ����
	while (Seat_Number <= St_Count)
	{
		// ����� �¼���ȣ�� ������ 1�� �ڸ����� �ٽ� �¼� ��ġ
		// �Ҹ��� ���� �л��� ������� �ʾ����Ƿ� ������ ��ȣ�� �״�� ������ ���� ��
		for (int i = 0; i < St_Count; i++)
		{
			if (St_List[i].seat_Number == Seat_Number)
			{
				fprintf(Seat_File, "%s", St_List[i].Name);
				if (Seat_Number % 2 == 0) // 2�� ¦�� ���� �ٲ��ֱ� ����
					fprintf(Seat_File, "\n");
				Seat_Number++;
				break;
			}
		}
	}
}

void Show_Seat(FILE* Seat_File) // ��ġ�� �ڸ� ��� �Լ�
{
	Seat_File = fopen("�ڸ� ��ġ.txt", "r");
	while (!feof(Seat_File))
	{
		char show_seat[20] = { 0 }; // �ʱ�ȭ ���ϸ� ���� ������ ���Ƿ� ���� ���� ��µ�
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
	FILE* Student_File = fopen("�л� ���.txt", "r");
	FILE* Seat_File;

	if (Student_File != NULL) // �ش� ������ ������ ���ӹ� ����
	{
		printf("��ϵ� �л��� �ҷ��ɴϴ�.\n");
		fscanf(Student_File, "%d", &Present_Student);
		printf(" ���� �л� �� : %d\n", Present_Student);
		Student_List = (P_Information*)malloc(sizeof(P_Information) * Present_Student);
		for (int i = 0; i < Present_Student; i++)
		{
			fscanf(Student_File, "%s", Student_List[i].Name);
			fscanf(Student_File, "%d", &Student_List[i].Age);
			fscanf(Student_File, "%s", Student_List[i].Gender);
			fscanf(Student_File, "%d", &Student_List[i].Garade);
			fscanf(Student_File, "%d", &Student_List[i].Number);
			printf("�̸� : %s, ���� : %d, ���� : %s, �� : %d\n", Student_List[i].Name, Student_List[i].Age, Student_List[i].Gender, Student_List[i].Garade, Student_List[i].Number);
		}
		Student_Count = Present_Student;
		Transfer_Student = Present_Student;
		fclose(Student_File);
		//���л� ����� ����
	}
	else
		printf("���� ��ϵ� �л��� �����ϴ�.\n");
	system("pause");
	while (Progress)
	{

		system("cls");
		printf("===== �л� ���� ���α׷� ===== (�� �ο� : %d)\n", Student_Count);
		printf("1. �л� ���\n");
		printf("2. �л� ���(��ȣ��)\n");
		printf("3. �л� ���(�г��)\n");
		printf("4. �г� �˻�\n");
		printf("5. �л� �˻�\n");
		printf("6. ���л� ���\n");
		printf("7. �ڸ� ��ġ\n");
		printf("8. �ڸ� Ȯ��\n");
		printf("9. ������ �л� ����\n");
		printf("10. �л� ��ü ����\n");
		printf("11. ����\n");
		printf("�Է� : ");
		scanf("%d", &Input_Number);
		switch (Input_Number)
		{
		case 1:
			if (Student_Count + 1 >= MAX)
			{
				printf("�л�����(%d��)�� ��� á���ϴ�.\n", MAX);
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
				Student_File = fopen("�л� ���.txt", "w");
				Student_Count = Registration(Student_List, Student_File, Student_Count);
				Present_Student = Student_Count;
			}
			else
			{
				Student_File = fopen("�л� ���.txt", "a");
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
				printf("�˻��� �г� �Է�(1~3) : ");
				int Input_Grade;
				scanf("%d", &Input_Grade);
				if (Input_Grade >= 1 && Input_Grade <= 3)
				{
					Garde_Sequence(Student_List, Student_Count, Input_Grade);
					system("pause");
					break;
				}
				printf("�г� �߸� �Է� (���� 1~3�г�)\n");
			}

		case 5:
			system("cls");
			{
				char Input_Name[256];
				printf("�˻��� �̸� �Է� : ");
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
					printf("���л��� �����ϴ�.\n");
				else
				{
					for (int i = Transfer_Student; i < Student_Count; i++)
						Show_Student(Student_List, Student_Count, i);
				}
				system("pause");
				break;
			}

		case 7: // �ڸ� ���� ��ġ
			system("cls");
			{
				if (Student_Count % 2 == 0 && Student_Count > 0)
				{
					Seat_File = fopen("�ڸ� ��ġ.txt", "w");
					Seat_Arrangement(Student_List, Seat_File, Student_Count);
					fclose(Seat_File);
					printf("�ڸ� ��ġ �Ϸ�!\n\n");
					Seat_Completion = COMPLETION;
				}
				else
					printf("�л� ���� �����մϴ�.\n""ȥ�� �ɴ� �л��� �ܷο���\n""");
				system("pause");
				break;
			}

		case 8: // ��ġ�� �ڸ� Ȯ��
			system("cls");
			{
				if (Seat_Completion == COMPLETION) // �ڸ� ��ġ�� �Ϸ�Ǿ�����
				{
					Show_Seat(Student_List, Seat_File);
					int Dissatisfactioin = rand() % 3; // ����Ȯ���� �Ҹ��л� ����
					if (Dissatisfactioin == TURE)
					{
						int Dissatisfaction_Student = rand() % Student_Count;
						printf("%s�л� : �� ¦���� ������ �ȵ���....\n", Student_List[Dissatisfaction_Student].Name);
						system("pause");
						Re_Seat_Arrangement(Student_List, Seat_File, Dissatisfaction_Student, Student_Count);
						Show_Seat(Student_List, Seat_File);
						printf("%s�л� : ���� ������ ����!\n", Student_List[Dissatisfaction_Student].Name);
					}
				}
				else
					printf("�ڸ� ��ġ�� �����ʾҽ��ϴ�.\n");
				system("pause");
				break;
			}

		case 9:
		{
			if (Student_Count > 0)
			{
				Student_File = fopen("�л� ���.txt", "w");
				--Student_Count;
				Student_File_Save(Student_List, Student_File, Student_Count);
				fclose(Student_File);
			}
			else
			{
				printf("��ϵ� �л��� �����ϴ�.\n");
				system("pause");
			}
			break;
		}

		case 10:
			if (Student_Count > 0)
			{
				Student_File = fopen("�л� ���.txt", "w");
				free(Student_List);
				Student_Count = 0;
				Present_Student = 0;
				Student_List = NULL;
				Student_File_Save(Student_List, Student_File, Student_Count);
				fclose(Student_File);
			}
			else
			{
				printf("��ϵ� �л��� �����ϴ�.\n");
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
