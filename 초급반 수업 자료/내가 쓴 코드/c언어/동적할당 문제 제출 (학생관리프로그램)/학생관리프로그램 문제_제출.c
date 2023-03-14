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
	printf("===== %d�� �л�=====\n", St_Count + 1);
	printf("�̸� �Է� : ");
	scanf("%s", St_List[St_Count].Name);
	printf("���� �Է� : ");
	scanf("%d", &St_List[St_Count].Age);
	printf("���� �Է� : ");
	scanf("%s", St_List[St_Count].Gender);
	printf("�г� �Է� (1~3) : ");
	scanf("%d", &St_List[St_Count].Garade);
	St_List[St_Count].Number = St_Count + 1;
	return St_Count + 1;
}

void Show_Student(P_Information* St_List, int St_Count, int i)
{
	printf("===== %s �л�(%d��) =====\n", St_List[i].Name, St_List[i].Number);
	printf("���� : %d, ���� : %s, �г� : %d\n", St_List[i].Age, St_List[i].Gender, St_List[i].Garade);
	printf("========================\n");
}

void Garde_Sequence(P_Information* St_List, int St_Count, int grade)
{
	printf("------------%d�г�------------\n", grade);
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
		printf("===== �л� ���� ���α׷� ===== (�� �ο� : %d)\n", Student_Count);
		printf("1. �л� ���\n");
		printf("2. �л� ���(��ȣ��)\n");
		printf("3. �л� ���(�г��)\n");
		printf("4. �г� �˻�\n");
		printf("5. �л� �˻�\n");
		printf("6. ������ �л� ����\n");
		printf("7. �л� ��ü ����\n");
		printf("8. ����\n");
		printf("�Է� : ");
		scanf("%d", &Input_Number);
		switch (Input_Number)
		{
		case 1:
			if (Student_Count + 1 >= MAX)
			{
				printf("�л�����(20��)�� ��� á���ϴ�.\n");
				break;
			}
			if (Student_Count == Present_Student)
			{
				if (Student_Count == 0)
					Student_List = (P_Information*)malloc(sizeof(P_Information));
				else
				{
					P_Information* Save_List = Student_List;
					//�� ó�� ���� �� : P_Information *Save_List = Student_List;
					//Save�� �迭�� �ƴѵ� List�� ������ �� ������ �̷������� �����ص� �ǳ�?
					//�����ּҸ� ���� ���� ���̹Ƿ� Save������ ũ��� ������� �ʾƵ� �ȴ�?
					//�ٵ� �ٽ� malloc���� �迭 ����� �����ּ� �޶����� �޶��� �����ּҿ��� �����ؼ� �迭 ũ�⸸ŭ �޸� �Ҵ�
					// �̰� Save�� ����� �� List�����ּҷ� �ٲ������ �����ּҸ� ���� ��� ������ ������ �޸� �ּҸ� ���� ����Ȱ� �ƴѰ�?
					// ���� �� - > �׷��� �̻��� ���ڰ� ��µǴ� �ǰ�??
					Student_List = (P_Information*)malloc(sizeof(P_Information) * (Student_Count + 1));
					//���⼭ �ּҸ� �����ϸ� �ȵ� - > �� �ּҴ� �����Ұ��̱� ����
					//�׷� �ȿ� ���� �����͸� ���;��ϴ� �� ���� �ڵ�� �����ּ��� ������ ������ ������ �� �ڴ� �̻��� ���ڰ� ����� �ȴ�?
					for (int i = 0; i < Student_Count; i++)
						*(Student_List + i) = *(Save_List + i);// �ּҷ� �����ؼ� �ּҿ� ���� �����ָ鼭 ������ �ֱ�
					free(Save_List);
					// case7���� ��ü�� �޸� �ּҸ� ���⼭ �� �ѹ� �����ϱ� ������ �߻��� ����
					// �׷��� ���ǹ� �ɾ ���� ��ü�ϸ� �ٽ� �����Ҵ�
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
				printf("�˻��� �г� �Է�(1~3) : ");
				int Input_Grade;
				scanf("%d", &Input_Grade);
				if (Input_Grade >= 1 && Input_Grade <= 3)
				{
					Garde_Sequence(Student_List, Student_Count, Input_Grade); // �����ؾ���
					system("pause");
					break;
				}
				else
				{
					printf("�г� �߸� �Է� (���� 1~3 �г�)\n");
					system("pause");
				}
			}
			break;

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
					else
						continue;
				}
				system("pause");
				break;
			}

		case 6:
		{
			// free(Student_List + (Student_Count - 1));
			// �迭 ��ü�� �����Ҵ���ױ� ������ Ư�� �л��� ���� ���� ����
			if (Student_Count > 0)
				--Student_Count;
			else
			{
				printf("��ϵ� �л��� �����ϴ�.\n");
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
				printf("��ϵ� �л��� �����ϴ�.\n");
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
