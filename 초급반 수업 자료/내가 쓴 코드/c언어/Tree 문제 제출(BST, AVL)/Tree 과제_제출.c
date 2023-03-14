#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
//2진탐색트리, B-Tree, AVL Tree, 레드 블랙 Tree
#define WIDTH_VALUE 15
#define HEIGHT_VALUE 4

typedef struct Node
{
	int Date;
	struct Node* Left;
	struct Node* Right;
}Node;

Node* Insert(Node* Root, int Num);
void gotoxy(int x, int y);
void RightPrint(Node* node, int x, int y, int i);
void LeftPrint(Node* node, int x, int y, int i);
void Print_Tree(Node* node);
void PreOrder(Node* Root);
void InOrder(Node* Root);
void PostOrder(Node* Root);
Node* Search(Node* Root, int Num);
Node* Delete(Node* Root, int Num);
Node* LastNode(Node* Root);
Node* Connect(Node* Root, Node* MinNode);
void Exit(Node* Root);

Node* Insert(Node* Root, int Num)
{
	if (Root != NULL)
	{
		if (Root->Date == Num)
			printf("중복된 숫자가 이미 존재합니다.\n");
		else if (Root->Date < Num)
			Root->Right = Insert(Root->Right, Num);
		else if (Root->Date > Num)
			Root->Left = Insert(Root->Left, Num);
		return Root;
	}
	Root = (Node*)malloc(sizeof(Node));
	Root->Left = NULL;
	Root->Right = NULL;
	Root->Date = Num;
	return Root;
}

//WinAIP : 마이크로스프트사에서 제공하는 윈도우즈 컨트롤 함수 모음
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void RightPrint(Node* node, int x, int y, int i)
{
	if (node == NULL)
		return;
	x += WIDTH_VALUE - i;
	y += HEIGHT_VALUE;
	gotoxy(x, y);
	printf("%d", node->Date);
	RightPrint(node->Right, x, y, i + 6);
	LeftPrint(node->Left, x, y, i + 6);
}

void LeftPrint(Node* node, int x, int y, int i)
{
	if (node == NULL)
		return;
	x -= WIDTH_VALUE - i;
	y += HEIGHT_VALUE;
	gotoxy(x, y);
	printf("%d", node->Date);
	RightPrint(node->Right, x, y, i + 6);
	LeftPrint(node->Left, x, y, i + 6);
}

void Print_Tree(Node* node)
{
	system("cls");
	int x = 70, y = 2;
	if (node == NULL)
		return;
	gotoxy(x, y);
	printf("%d", node->Date);
	RightPrint(node->Right, x, y, 1);
	LeftPrint(node->Left, x, y, 1);
	gotoxy(0, 0);
}

void PreOrder(Node* Root)
{
	if (Root == NULL)
		return;
	printf("%d ", Root->Date);
	PreOrder(Root->Left);
	PreOrder(Root->Right);
}

void InOrder(Node* Root)
{
	if (Root == NULL)
		return;
	InOrder(Root->Left);
	printf("%d ", Root->Date);
	InOrder(Root->Right);
}

void PostOrder(Node* Root)
{
	if (Root == NULL)
		return;
	PostOrder(Root->Left);
	PostOrder(Root->Right);
	printf("%d ", Root->Date);
}

Node* Search(Node* Root, int Num)
{
	if (Root == NULL)
		return NULL;
	else if (Root->Date > Num)
	{
		if (Root->Left == NULL)
			return NULL;
		Root = Search(Root->Left, Num);
	}
	else if (Root->Date < Num)
	{
		if (Root->Right == NULL)
			return NULL;
		Root = Search(Root->Right, Num);
	}
	else if (Root->Date == Num)
	{
		printf("%d는 존재합니다.\n", Num);
		return Root;
	}
	return Root;
}

Node* Delete(Node* Root, int Num)
{
	if (Root->Date == Num)
	{
		Node* DeleteNode = Root;
		if (Root->Right != NULL && Root->Left == NULL)
		{
			Root = Root->Right;
			free(DeleteNode);
		}
		else if (Root->Right == NULL && Root->Left != NULL)
		{
			Root = Root->Left;
			free(DeleteNode);
		}
		else if (Root->Right != NULL && Root->Left != NULL)
		{
			Node* MinNode = LastNode(Root->Right);
			MinNode->Right = Connect(Root->Right, MinNode);
			Root = MinNode;
			Root->Left = DeleteNode->Left;
			free(DeleteNode);
		}
		else if (Root->Right == NULL && Root->Left == NULL)
		{
			free(DeleteNode);
			Root = NULL;
		}
		return Root;
	}
	else
	{
		if (Root->Left == NULL && Root->Right == NULL)
		{
			printf("삭제할 숫자가 없습니다.\n");
			return Root;
		}
		else if (Root->Date > Num)
			Root->Left = Delete(Root->Left, Num);
		else if (Root->Date < Num)
			Root->Right = Delete(Root->Right, Num);
	}
	return Root;
}

Node* LastNode(Node* Root)
{
	if (Root->Left == NULL)
		return Root;
	Root = LastNode(Root->Left);
	return Root;
}

Node* Connect(Node* Root, Node* MinNode)
{
	if (Root == NULL)
		return Root;
	Root->Left = Connect(Root->Left, MinNode);
	if (Root == MinNode)
		Root = Root->Right;
	return Root;
}

void Exit(Node* Root)
{
	if (Root == NULL)
		return;
	Exit(Root->Left);
	Exit(Root->Right);
	free(Root);
}

void  main()
{
	Node* Root = NULL;
	int Date;
	while (1)
	{
		printf("=======Tree=======\n");
		printf("1.Insert\n");
		printf("2.Print\n");
		printf("3.PreOrder\n");
		printf("4.InOrder\n");
		printf("5.PostOrder\n");
		printf("6.Delete\n");
		printf("7.Search\n");
		printf("8.Exit\n");
		int Select;
		int Num;
		printf("Input >> ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			printf("Input Date >> ");
			scanf("%d", &Num);
			Root = Insert(Root, Num);
			Print_Tree(Root);
			break;
		case 2:
			Print_Tree(Root);
			break;
		case 3:
			Print_Tree(Root);
			printf("PreOrder : ");
			PreOrder(Root);
			break;
		case 4:
			Print_Tree(Root);
			printf("InOrder : ");
			InOrder(Root);
			break;
		case 5:
			Print_Tree(Root);
			printf("PostOrder : ");
			PostOrder(Root);
			break;
		case 6:
			if (Root == NULL)
			{
				printf("삭제할 숫자가 없습니다.\n");
				break;
			}
			printf("Input Date >> ");
			scanf("%d", &Num);
			Root = Delete(Root, Num);
			Print_Tree(Root);
			break;
		case 7:
			Print_Tree(Root);
			printf("Input Date >> ");
			scanf("%d", &Num);
			Node* Search_Node = Search(Root, Num);
			if (Search_Node == NULL)
				printf("%d는 존재하지 않습니다.\n", Num);
			break;
		case 8:
			if (Root != NULL)
				Exit(Root);
			return;
		}
		system("pause");
	}
}