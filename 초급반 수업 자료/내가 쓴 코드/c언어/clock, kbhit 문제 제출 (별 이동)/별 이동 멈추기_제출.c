#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#define WIDTH 10
#define HEIGHT 10
#define NULL 0
#define MOVE_STAR 1// �����̴� ��
#define STOP_STAR 2// ���� ��
#define RIGHT_DIRECTION 1 // �Ϸķ� �� ���� �������� �̵��ϵ��� �ϱ� ����
#define LEFT_DIRECTION -1 // �Ϸķ� �� ���� �������� �̵��ϵ��� �ϱ� ����
#define TURN_LEFT WIDTH  //���� ������ ������ ������ �������� �̵��ϵ���
#define TURN_RIGHT -1 //���� ������ ������ ������ �������� �̵��ϵ���
#define SPEED 200 // ���� ������ �ӵ�
#define STOP_KEY 32 //���� ���߰� �� Ű


void Draw(int Map[WIDTH][HEIGHT])//�� �׸��� �Լ�
{
	system("cls");
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == MOVE_STAR)
				printf("��");
			else if (Map[y][x] == STOP_STAR)
				printf("��");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("�� ���߱� = SP");
}



int Update(int Map[HEIGHT][WIDTH], int direction, int Stop_y)//���� ��ǥ�� ������ �Լ�
{
	for (int x = 0; x < WIDTH; x++)
	{
		if (Map[0][x] == MOVE_STAR)// for�� �ݺ��� ����ȭ�ϱ� ���� x��ǥ�� ���� ���� ã���ְ� y�ݺ��� ������
		{
			if (x + RIGHT_DIRECTION == TURN_LEFT)
				direction = LEFT_DIRECTION;
			// ���� x�� ��, ���� �ִ� ��ǥ���� ���������� �ѹ� �� �̵��ҽ� ������ �����̸� ������ �ٲ��ش�

			else if (x + LEFT_DIRECTION == TURN_RIGHT)
				direction = RIGHT_DIRECTION;
			// ���� x�� ��, ���� �ִ� ��ǥ���� �������� �ѹ� �� �̵��ҽ� ������ �����̸� ������ �ٲ��ش�

			for (int y = 0; y <= Stop_y; y++)// y�� Stop_y���� ������ ���� ���� �������� ����
			{
				Map[y][x] = NULL; //���� �׷����ִ� ���� �ʱ�ȭ
				Map[y][x + direction] = MOVE_STAR;//������ ����� �������� ���� �̵��Ѵ�
			}
			break;
		}
	}
	return direction;//������ ����� ���� ���� ��ȯ�Ѵ�.
}


int Stop(int Map[HEIGHT][WIDTH], int Stop_y)// ���� ���߰� �� �Լ�
{
	if (kbhit())  // �Է¹��ۿ� ���� ������
	{
		char ch = getch();
		if (ch == STOP_KEY)// define�ص� Ű�� �Է��� ��
		{
			for (int x = 0; x < WIDTH; x++)
			{
				if (Map[Stop_y][x] == MOVE_STAR)// ���� y��ǥ�� ���� ã��
					Map[Stop_y][x] = STOP_STAR; // ����  y��ǥ�� �ִ� ���� ���� ���� ����
			}
			Stop_y--; // ������ ���� �������� �ʵ��� �ϱ� ����
		}
	}
	return Stop_y; // Update�Լ����� ���� ���� for�� �������� ���� ����
}

void main()
{
	int Direction = LEFT_DIRECTION;// ���� ó�� ������ ����
	int Stop_Y = HEIGHT - 1;  // Ű�� �Է��� �� ���� ���� ������ ���߰� �� ���̰� ���ʴ�� �ö���� �� ��
	int OldClock = clock(); // ���� �ڵ������� ������ �ӵ��� �����̰� �ϱ� ����
	int Map[HEIGHT][WIDTH] = { NULL };
	printf("���� ���ðڽ��ϱ�?\n");
	system("pause");

	for (int y = 0; y < HEIGHT; y++)
		Map[y][WIDTH - 1] = MOVE_STAR;// ���� �������� ������ ���� ��ǥ�� ����

	while (1)
	{
		Stop_Y = Stop(Map, Stop_Y);
		if (clock() - OldClock >= SPEED)
			//���� �ڵ带 ����������� �ð����� ���� ó�� ȣ���� clock�Լ������� �ð��� �� ����  define�� ���� ũ�ų� ���� �� ����
			//clock�Լ� ���ۺ��� �� �ڵ带 ����������� Ŭ�������� ���� clock�Լ��� ���� Ŭ������ ���� ��
			// ���� while���� ���� �� SPEED���� ������ �׳� while�� ���� ������ SPEED���� �������� �� ������ �ǰ�, �ؿ��� �ٽ� clock�����ϴ� ������ �׷��߸� ������ �ӵ��� while���� �ݺ��� �� �ֱ� �����̴�
		{
			Direction = Update(Map, Direction, Stop_Y);
			Draw(Map);
			OldClock = clock();
			// ó���� �ڵ带 �� ������ �ٽ� ���� clock���� ����
			// �׷��� ������ �ӵ��� �ݺ����� ������ �ֱ� ����
			// ���� ��ǻ���� ���ɿ� ���� �ƹ��� ���� SPEED���� ���� �������� Ŭ���������� �ɸ�����, ó���ӵ��� ������ �׺��� �ʾ������� �ִ�. But �� ��ǻ���� ó���ӵ�(�ݺϸ��� ������ �ӵ�)�� �����ϴ�
		}
	}
}