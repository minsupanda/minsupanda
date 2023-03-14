#pragma once

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;
    Node* tail;
    int size;

    Node* get(const int&);
public:
    LinkedList();
    ~LinkedList();

    const int get_size()const { return size; }
    bool add(int);
    bool insert(int, const int&);
    bool remove(const int&);
    int get_data(const int&);
};

LinkedList::LinkedList() : size(0)
{
    try
    {
        this->head = new Node;
        this->tail = new Node;

        this->head->next = this->tail;
        this->tail->next = this->tail;
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

LinkedList::~LinkedList()
{
    Node* node = this->head;
    while (node != this->tail)
    {
        Node* delNode = node;
        node = delNode->next;

        delete delNode;
    }
    delete this->tail;
}

Node* LinkedList::get(const int& id)
{
    if ((NULL == this->head) || (NULL == this->tail)) return NULL;

    if (0 <= id)
    {
        Node* dest = this->head->next;
        for (int i = 0; this->get_size() > i; i++)
        {
            if (id == i)
            {
                return dest;
            }
            dest = dest->next;
        }
    }
    return NULL;
}

bool LinkedList::add(int data)
{
    return this->insert(data, this->get_size());
}

bool LinkedList::insert(int data, const int& id)
{
    if ((NULL == this->head) || (NULL == this->tail)) return false;

    try
    {
        if (0 == id)
        {
            Node* new_node = new Node;

            new_node->data = data;
            new_node->next = this->head->next;
            this->head->next = new_node;

            size++;

            return true;
        }

        Node* pre_dest = this->get(id - 1);
        if (NULL == pre_dest) return false;

        Node* new_node = new Node;

        new_node->data = data;
        new_node->next = pre_dest->next;
        pre_dest->next = new_node;

        size++;
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return false;
    }

    return true;
}

bool LinkedList::remove(const int& id)
{
    if (this->get_size() == 0) return false;
    
    Node* pre_dest = this->get(id - 1);
    if (0 == id) pre_dest = this->head;

    if (NULL == pre_dest) return false;

    Node* delNode = pre_dest->next;
    pre_dest->next = delNode->next;

    delete delNode;

    this->size--;

    return true;
}

int LinkedList::get_data(const int& id)
{
    Node* dest = this->get(id);
    if (NULL == dest) return NULL;

    return dest->data;
}