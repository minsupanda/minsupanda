#include<stdio.h>
#include<Windows.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}Node;

void gotoxy(int x, int y);
void Left_Print(Node* node, int x, int y, int addx);
void Right_Print(Node* node, int x, int y, int addx);
void print_data(Node* node);
int Height(Node* node);
int DepthCheck(Node* node);
Node* LL(Node* node);
Node* RR(Node* node);
Node* LR(Node* node);
Node* RL(Node* node);
Node* AVLSet(Node* node);
Node* insert(Node* node, int data);
void PreOrder(Node* node);
void InOrder(Node* node);
void PostOrder(Node* node);
void All_Delete(Node* node);
Node* Delete(Node* node, int data);


void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Left_Print(Node* node, int x, int y, int addx)
{
	if (node == NULL)	return;
	gotoxy(x -= addx, y += 2);
	printf("%d", node->data);
	if (node->left)
		Left_Print(node->left, x, y, addx - 4);
	if (node->right)
		Right_Print(node->right, x, y, addx - 4);
}
void Right_Print(Node* node, int x, int y, int addx)
{
	if (node == NULL)	return;
	gotoxy(x += addx, y += 2);
	printf("%d", node->data);
	if (node->left)
		Left_Print(node->left, x, y, addx - 4);
	if (node->right)
		Right_Print(node->right, x, y, addx - 4);
}
void print_data(Node* node)
{
	int x = 70, y = 2;
	if (node == NULL)
		return;

	gotoxy(x, y);
	printf("%d", node->data);
	if (node->right) {
		Right_Print(node->right, x, y, 32);
	}
	if (node->left) {
		Left_Print(node->left, x, y, 32);
	}
	gotoxy(0, 10);
}
int Height(Node* node)
{
	int HCount = 0;
	if(node != NULL)
	{
		int LeftCount = Height(node->left);
		int RightCount = Height(node->right);
		if (LeftCount > RightCount)
			HCount = LeftCount + 1;
		else
			HCount = RightCount + 1;
		//마지막노드까지 탐색해서 재귀함수 돈만큼 깊이 +1해서 반환
	}
	return HCount;
}

int DepthCheck(Node* node)
{
	int LeftCount = Height(node->left);
	int RightCount = Height(node->right);
	printf("Data(%d) LeftDepth(%d) RightDepth(%d)", node->data, LeftCount, RightCount);
	system("pause");
	return LeftCount - RightCount;
}

Node* AVLSet(Node* node)
{
	int Depth = DepthCheck(node);//추가한 노드의 부모노드부터 루트노드까지 깊이 측정하면서 깊이 차이가 1을초과하면 정리
	if (Depth > 1) // 왼쪽노드의 깊이가 오른쪽노드의 깊이보다 2이상 깊을 때
	{
		if (DepthCheck(node->left) > 0)
		{
			
		}
		else
		{
			
		}
	}
	else if (Depth < -1) // 오른쪽노드의 깊이가 왼쪽노드의 깊이보다 2이상 깊을 때
	{
		if (DepthCheck(node->right) > 0)
		{

		}
		else
		{

		}
	}
	return node;
}

Node* insert(Node* node, int data)
{
	if (node == NULL)
	{
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	else if (node->data < data)
	{
		node->right = insert(node->right, data);
		node = AVLSet(node);
	}
	else if (node->data > data)
	{
		node->left = insert(node->left, data);
		node = AVLSet(node);
	}
	else
	{
		printf("Data already exists\n");
	}
	return node;
}

void PreOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	PreOrder(node->left);
	PreOrder(node->right);
}

void InOrder(Node* node)
{
	if (node == NULL)
		return;
	InOrder(node->left);
	printf("%d ", node->data);
	InOrder(node->right);
}

void PostOrder(Node* node)
{
	if (node == NULL)
		return;
	PostOrder(node->left);
	PostOrder(node->right);
	printf("%d ", node->data);
}

void All_Delete(Node* node)
{
	if (node == NULL)
		return;
	All_Delete(node->left);
	All_Delete(node->right);
	printf("%d Deallocation Success \n", node->data);
	free(node);
}

Node* FindMinNode(Node* node, Node** MinNode)
{
	if (node->left == NULL)
	{
		*MinNode = node;
		node = node->right;
		return node;
	}
	else
	{
		node->left = FindMinNode(node->left, MinNode);
		return node;
	}
}

Node* Delete(Node* node, int data)
{
	if (node == NULL)
	{
		printf("Not find data\n");
	}
	else if (node->data > data)
	{
		node->left = Delete(node->left, data);
		node = AVLSet(node);
	}
	else if (node->data < data)
	{
		node->right = Delete(node->right, data);
		node = AVLSet(node);
	}
	else
	{
		Node* deletetemp = node;
		if (node->left != NULL && node->right != NULL)
		{
			Node* MinNode = NULL;
			node->right = FindMinNode(node->right, &MinNode);
			MinNode->left = deletetemp->left;
			MinNode->right = deletetemp->right;

			node = MinNode;
		}
		else if (node->left != NULL)
			node = node->left;
		else
			node = node->right;
		free(deletetemp);
	}
	return node;
}

void Search(Node* node, int Data)
{
	if (node == NULL)
	{
		printf("Not Find Data..\n");
		return;
	}
	else if (node->data == Data)
	{
		printf("Find Success Data!!\n");
		return;
	}
	else if (node->data > Data)
		Search(node->left, Data);
	else if (node->data < Data)
		Search(node->right, Data);
}

void main()
{
	Node* Root = NULL;
	int Select;
	while (1)
	{
		system("cls");
		printf("======AVLTree======\n");
		printf("1.Insert\n");
		printf("2.Search\n");
		printf("3.PrintTree\n");
		printf("4.PreOrder\n");
		printf("5.InOrder\n");
		printf("6.PostOrder\n");
		printf("7.Delete\n");
		printf("8.Exit\n");
		printf("Input >> ");
		scanf("%d", &Select);
		system("cls");
		switch (Select)
		{
		case 1:
			printf("Add Data >> ");
			scanf("%d", &Select);
			Root = insert(Root, Select);
			print_data(Root);
			break;
		case 2:
			printf("Select Data >> ");
			scanf("%d", &Select);
			Search(Root, Select);
			break;
		case 3:
			print_data(Root);
			break;
		case 4:
			PreOrder(Root);
			break;
		case 5:
			InOrder(Root);
			break;
		case 6:
			PostOrder(Root);
			break;
		case 7:
			printf("Delete Data >> ");
			scanf("%d", &Select);
			Root = Delete(Root, Select);
			break;
		case 8:
			All_Delete(Root);
			return;
		default:
			printf("Please enter again!\n");
			break;
		}
		system("pause");
	}
}