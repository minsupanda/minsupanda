#include<iostream>
#include<Windows.h>

typedef struct Node
{
	int Date;
	struct Node* Left;
	struct Node* Right;
}Node;

Node* Insert(Node* Root, int Num);
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
			std::cout << "중복된 숫자가 이미 존재합니다." << std::endl;
		else if (Root->Date < Num)
			Root->Right = Insert(Root->Right, Num);
		else if (Root->Date > Num)
			Root->Left = Insert(Root->Left, Num);
		return Root;
	}
	Root = new Node;
	Root->Left = NULL;
	Root->Right = NULL;
	Root->Date = Num;
	return Root;
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
		std::cout << "%d는 존재합니다." << std::endl;
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
			std::cout << "삭제할 숫자가 없습니다" << std::endl;
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
	while (1)
	{
		int Select;
		int Num;
		std::cout << "=======Tree=======" << std::endl;
		std::cout << "1.Insert" << std::endl;
		std::cout << "2.Delete" << std::endl;
		std::cout << "3.Search" << std::endl;
		std::cout << "4.Exit" << std::endl;
		std::cout << "Input" << std::endl;
		std::cin >> Select;
		switch (Select)
		{
		case 1:
			std::cout << "Input Data" << std::endl;
			std::cin >> Num;
			Root = Insert(Root, Num);
			break;
		case 2:
			if (Root == NULL)
				std::cout << "삭제할 숫자가 없습니다" << std::endl;
			else
			{
				std::cout << "Input Date >>" << std::endl;
				std::cin >> Num;
				Root = Delete(Root, Num);
			}
			break;
		case 3:
		{
			std::cout << "Input Date >>" << std::endl;
			std::cin >> Num;
			Node* Search_Node = Search(Root, Num);
			if (Search_Node == NULL)
				std::cout << "%d는 존재하지 않습니다>>" << std::endl;
			break;
		}
		case 4:
			if (Root != NULL)
				Exit(Root);
			return;
		}
		system("pause");
	}
}