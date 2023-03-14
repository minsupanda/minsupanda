#include<iosteram>
#include<stack>

template <typename type>
class Stack
{
	struct node
	{
		type value;
		node* next;
	}
private:
	node* m_pTop;
	int m_iSize;
public:
	Stack();
	~Stack();
	void Push(type value);
	void Pop();
	void Top();
	bool Empty();
	int Size();
};

void main()
{
	Stack<int> MyStack;
}