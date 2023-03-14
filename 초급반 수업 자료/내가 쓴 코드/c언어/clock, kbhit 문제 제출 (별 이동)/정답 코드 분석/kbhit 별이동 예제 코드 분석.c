#include<stdio.h>
#include<Windows.h>
#include<time.h>
#define WIDTH 10
#define HEIGHT 10
#define MOVE_STAR 1
#define STOP_STAR 2
#define NULL 0
#define SPEED 100

void Draw(int Map[HEIGHT][WIDTH]) // �� �׸��� ��
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
}

void Update(int Map[HEIGHT][WIDTH], int Stop_y) // �� ��ǥ �̵� �Լ�
{
	for (int x = 0; x < WIDTH; x++)
	{
		if (Map[0][x] == MOVE_STAR) 
		// x���� ���� Ž���ϴ� ������ y�� ���� Ž���ϰ� �Ǹ� n�� ������ŭ Ž���ϹǷ� ó���� ���� ��������
		// ���� ���� |�ڷ� ����ϹǷ� ���� ó�� y��ǥ�� ���� ��ġ�� Ȯ���ϸ� �Ǳ� �����̿� �� x��ǥ�� ã�� y�� �ݺ��� ������ �ȴ�.
			// �׷� �ƹ��� ���� ������ n * 2 ��ŭ �ݺ��� ������ �ǹǷ�  ó�� Ƚ���� �پ��
		{
			for (int y = 0; y <= Stop_y; y++)
			{
				Map[y][x] = NULL; 
				// ���� ���� ��ġ�� ��ǥ�� NULL������ �ٲ���
				if (x == 0) 
					// ���� ���� �������� ���� �ٽ� ó�� ��ġ�� �����ִ� ��
					Map[y][WIDTH - 1] = MOVE_STAR; 
				else
					// ���� �������� �� ĭ �̵� ������ ��
					Map[y][x - 1] = MOVE_STAR; 
			}
			break;
		}
	}
}

int Stop(int Map[HEIGHT][WIDTH], int y) // ���� ũ��� Stop_Y���� ������
// Stop_Y���� �������� ���� �� ����� y��ǥ�� �ִ� ���� STOP_STAR�� �ٲ� ���� ���߰��ϰ� ���� ���� ����ϱ� ����
{
	if (kbhit())
	// kbhit�� �Է¹��ۿ� ���� ����ִ� �� ���� �� Ȯ���ϴ� ��
	// ������ �ٷ� getch�� ������ �Ǵµ� getch�� �Է¹��ۿ� �ִ� ���� �������� ������ ���� ���� �� ���� ��ٸ��� �ȴ�
	// �׷��Ƿ� Ű���带 �Է��� ������ ���α׷��� ���߰� �Ǹ� �ݺ����� �۵����ϰ� ��
	// �׷��� kbhit�� �ʿ��� ��
	// �׷� �ƿ� Stop�Լ� ȣ���� ���� ������ ������ �ȵǳ�?
	// �̰� ��ǻ�� ��翡 ���� �޶����� (������ main�Լ����� ����) 
	{
		char ch = getch();
		if (ch == 'd' || ch == 'D')
		{
			// �Է¹��ۿ� D,d���� ������ for ����
			for (int x = 0; x < WIDTH; x++)
				// y�� ��ǥ�� �������Ƿ� y���� ��ã�Ƶ� ������ x��ǥ�� �ϳ� �� �����鼭 STAR�� ã�ƾ���
			{
				if (Map[y][x] == MOVE_STAR)
					// STAR�� �ִ� x��ǥ�� ã����
				{
					Map[y][x] = STOP_STAR; // �Լ� ȣ�� �� ���� y��ǥ�� �ִ� ���� STOP_STAR�� �ٲ���
					break; // ������ x���� ���� �ʿ� �����Ƿ� break������ Ż��
				}
			}
			y--; 
			// y���� ���ҽ��� STOP_STAR���� �ű⼭ ���߰� ���̻� Update �Լ� �ݺ����� �������� �ʵ��� �����ϴ� ��
			// ���⼭ ���߱⸸ �ҰŸ� ���� if���� �ʿ����. if���� �� ������ �ٸ� ������ ����ϱ� ����
		}
	}
	return y; //���ҵ� y���� ��ȯ�ؼ� Update�Լ��� for�� Ž�� ������ ���̴� ��
}


void main()
{
	int OldClock = clock();
	int Stop_Y = HEIGHT - 1; 
	// �ؿ��� ���� ���� �ö�� ���̱� ������ Y�� ������ �ε����� �����ϰ�
	// ���� �� ���� 1�� ���ҽ��� ������Ʈ �Լ����� Ž�������� ���̸鼭 ���� ���߰� �Ϸ��� ���� ����
	int Map[HEIGHT][WIDTH] = { NULL };
	for (int y = 0; y < HEIGHT; y++)
	{
		Map[y][WIDTH - 1] = MOVE_STAR; 
		// ��� y�࿡�� ������ x��ǥ���� MOVE_STAR����
		// MOVE_STAR���� ����Ǹ� Update�Լ����� 1�� ���ҵǸ鼭 ���� �������� �̵��ϰ� �ȴ�.
	}
	while (1)
	{
		Stop_Y = Stop(Map, Stop_Y); 
		if (clock() - OldClock >= SPEED)
		{
			Update(Map, Stop_Y);
			Draw(Map);
			OldClock = clock();
		}
		// (������ main�Լ����� ����) Stop_Y = Stop(Map, Stop_Y) kbhit�� ���� ��;  �̰Ÿ� ����� �����ٴ� ���ε�
		// �̰� �����Ӱ� ����� �ƶ�
		// if���� ���� ������ �ɸ� Ŭ���� SPEED ���� ũ�ų� ������ if���� ������ ����� �ǰ����� ������ ���� ������ Stop�Լ��� ������ �Ǽ� ����
		// �ٸ� ��ǻ�� ó�� �ӵ��� SPEED ������ �ٷ� ���� �ٷ� ���߰� �� �� 
	}
}
