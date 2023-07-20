#include<iostream>
#include<Windows.h>
#include<vector>

struct Node
{
	int Date;
	std::vector<Node*> child;
	/*Node* Left;
	Node* Right;*/

	virtual void test()
	{
		std::cout << "node" << std::endl;
	}
};

struct ChildNode : Node
{
	virtual void test()
	{
		std::cout << "ChildNode" << std::endl;
	}
};

Node* Insert(int Num, Node* Parent = NULL)
{
	Node* node = new Node;
	if(Parent != NULL)
		Parent->child.push_back(node);
	return node;
	return Root;
}

void Print(Node* node)
{
	if (node == NULL)
		return;

	std::cout << node->Date << std::endl;

	for (auto node : node->child)
		Print(node);
	/*if (Root == NULL) 
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
	return Root;*/
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
		std::cout << "2.Print" << std::endl;
		/*std::cout << "3.Search" << std::endl;*/
		std::cin >> Select;
		switch (Select)
		{
		case 1:
			std::cout << "Input Data" << std::endl;
			std::cin >> Num;
			if (Root == NULL)
				Root = Insert(Num);
			else Insert(Num, Root);
			break;
		case 2:
			Print(Root);

			break;
		/*case 3:
		{
			std::cout << "Input Date >>" << std::endl;
			std::cin >> Num;
			Node* Search_Node = Search(Root, Num);
			if (Search_Node == NULL)
				std::cout << "%d는 존재하지 않습니다>>" << std::endl;
			break;
		}*/
		default :
			return;
		}
		system("pause");
	}
}