#pragma once
#include "Node.h"

class AVLTree
{
private:
	TreeNode* root;
	int count;

	const int get_height(TreeNode*);
	TreeNode* new_node(int);
	TreeNode* rotate_LL(TreeNode*);
	TreeNode* rotate_RR(TreeNode*);
	TreeNode* rotate_LR(TreeNode*);
	TreeNode* rotate_RL(TreeNode*);
	TreeNode* balance_tree(TreeNode*);
	TreeNode* search_count(TreeNode*, const int&);
	TreeNode* insert(TreeNode*, int);
	TreeNode* min_key_node(TreeNode*);
	TreeNode* remove(TreeNode*, const int&);
	void inoder_print(TreeNode*);
public:
	AVLTree() : count(0) { this->root = NULL; }
	~AVLTree();

	const int get_balance_factor(TreeNode*);
	void search_count(const int&);
	void insert(int);
	void remove(const int&);

	void inoder_print();
};

AVLTree::~AVLTree()
{
	while (NULL != this->root)
	{
		this->root = remove(this->root, this->root->get_key());
	}
}

const int AVLTree::get_height(TreeNode* node)
{
	if (NULL == this->root || NULL == node) return NULL;

	// NULL이 아니라면 루트 1개는 무조건 있다. 높이는 최소 1.
	return 1 + std::max(get_height(node->left), get_height(node->right));
}

TreeNode* AVLTree::new_node(int key)
{
	return new TreeNode(key);
}

// 부모의 왼쪽에 자식이 있고 그 자식의 왼쪽에 자식이 있을 경우.
// 오른쪽으로 회전한다.
TreeNode* AVLTree::rotate_LL(TreeNode* node)
{
	if (NULL == this->root || NULL == node) return NULL;

	TreeNode* child = node->left;	// 왼쪽에 있는 자식을 찾는다.
	node->left = child->right;	// 왼쪽에는 자식의 오른쪽(NULL) 자식을 갖는다.
	child->right = node;			// 부모를 자식의 오른쪽 노드로(부모와 자식이 바뀐다).

	return child;
}

// 부모의 오른쪽에 자식이 있고 그 자식의 오른쪽에 자식이 있을 경우.
// 왼쪽으로 회전한다.
TreeNode* AVLTree::rotate_RR(TreeNode* node)
{
	if (NULL == this->root || NULL == node) return NULL;

	TreeNode* child = node->right;// 오른쪽에 있는 자식을 찾는다.
	node->right = child->left;	// 오른쪽에는 자식의 왼쪽(NULL) 자식을 갖는다.
	child->left = node;			// 부모를 자식의 왼쪽 노드로(부모와 자식이 바뀐다).

	return child;
}

// 부모의 왼쪽에 자식이 있고 그 자식의 오른쪽에 자식이 있을 경우.
// 오른쪽 왼쪽으로 회전한다.
TreeNode* AVLTree::rotate_LR(TreeNode* node)
{
	if (NULL == this->root || NULL == node) return NULL;

	TreeNode* child = node->left;
	node->left = rotate_RR(child);//자식의 오른쪽에 자식이 있기때문에RR회전을 한다.

	return rotate_LL(node);		//현재 자식이 왼쪽에 있으므로 LL회전을 다시해준다.
}

// 부모의 오른쪽에 자식이 있고 그 자식의 왼쪽에 자식이 있을 경우.
// 왼쪽 오른쪽으로 회전한다.
TreeNode* AVLTree::rotate_RL(TreeNode* node)
{
	if (NULL == this->root || NULL == node) return NULL;

	TreeNode* child = node->right;
	node->right = rotate_LL(child);

	return rotate_RR(node);
}

const int AVLTree::get_balance_factor(TreeNode* node)
{
	if (NULL == node) return 0;

	// 균형 인수(balance factor) = 왼쪽 높이 - 오른쪽 높이.
	// 왼쪽으로 기울어져 있으면 양수 오른쪽으로 기울어져 있으면 음수.
	return get_height(node->left) - get_height(node->right);
}

TreeNode* AVLTree::balance_tree(TreeNode* node)
{
	const int& bf = get_balance_factor(node);
	if (1 < bf)			// balance factor가 1보다 크면 왼쪽으로 치우쳐 있다.
	{
		if (0 < get_balance_factor(node->left))
		{
			return rotate_LL(node);
		}
		else
		{
			return rotate_LR(node);
		}
	}
	else if(-1 > bf)	// balance factor가 -1보다 작으면 오른쪽으로 치우쳐 있다.
	{
		if (0 > get_balance_factor(node->right))
		{
			return rotate_RR(node);
		}
		else
		{
			return rotate_RL(node);
		}
	}

	return node;
}

TreeNode* AVLTree::search_count(TreeNode* node, const int& key)
{
	if (NULL == node) return NULL;

	this->count++;

	if (key == node->get_key()) return node;
	else if (key > node->get_key()) return search_count(node->right, key);	// 키 값이 나의 키 값보다 크면 오른쪽,
	else return search_count(node->left, key);								// 작으면 왼쪽을 찾는다.
}

void AVLTree::search_count(const int& key)
{
	search_count(this->root, key);

	std::cout << this->count << "번 검색" << std::endl;
	this->count = 0;
}

TreeNode* AVLTree::insert(TreeNode* node, int key)
{
	try
	{
		if (NULL == node) return new_node(key);

		if (node->get_key() > key)		// 키 값이 현재 노드의 키 값보다 작으면 왼쪽에 생성.
		{
			node->left = insert(node->left, key);
		}
		else if (node->get_key() < key)	// 키 값이 현재 노드의 키 값보다 크면 오른쪽에 생성.
		{
			node->right = insert(node->right, key);
		}
		else
		{
			std::cerr << "중복 데이터 삽입!!" << std::endl;
			return node;
		}

		return balance_tree(node);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	return node;
}

void AVLTree::insert(int key)
{
	this->root = insert(this->root, key);
}

TreeNode* AVLTree::min_key_node(TreeNode* node)
{
	if (NULL == node) return NULL;
	if (NULL == node->left) return node;
	return min_key_node(node->left);
}

TreeNode* AVLTree::remove(TreeNode* node, const int& key)
{
	if (NULL == node) return NULL;

	if (node->get_key() > key) node->left = remove(node->left, key);		// 키 값이 작으면 왼쪽 자식에서 찾아 삭제.
	else if (node->get_key() < key) node->right = remove(node->right, key);	// 키 값이 크면 오른쪽 자식에서 찾아 삭제.
	else
	{
		TreeNode* child = NULL;
		// 삭제할 데이터를 찾았고,
		if (NULL == node->left || NULL == node->right)
		{
			// 한 쪽에 자식이 있거나 양 쪽다 없을 경우.
			// 외쪽 오른쪽을 확인하여 자식 노드를 기억해 둔다.
			if (NULL == node->left) child = node->right;
			else child = node->left;

			// 자신은 삭제.
			delete node;

			node = child;
		}
		else
		{
			// 양 쪽에 자식이 있을 경우.
			child = min_key_node(node->right);					// 오른쪽 자식 중에서 가장 작은 키 값을 가진 자식을 찾아온다.
			node->set_key(child->get_key());					// 데이터를 복사. 여기서는 키 값만을 복사한다.
			node->right = remove(node->right, child->get_key());// 같은 키 값을 가지는 데이터를 지닐 수 없기 때문에 해당 값을 가진 자식을 삭제한다.
		}
	}

	if (NULL == node) return NULL;

	return balance_tree(node);
}

void AVLTree::remove(const int& key)
{
	this->root = remove(this->root, key);
}

void AVLTree::inoder_print(TreeNode* node)	// 키 값의 오름 차순으로 데이터 정보를 출력한다.
{
	if (NULL != node)
	{
		inoder_print(node->left);

		std::cout << "key:" << node->get_key() << std::endl;

		inoder_print(node->right);
	}
}

void AVLTree::inoder_print()
{
	inoder_print(this->root);
}