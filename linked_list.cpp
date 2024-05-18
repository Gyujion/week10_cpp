#include "linked_list.h"
#include <iostream>

// 링크드리스트 생성자
LinkedList::LinkedList() : head_(nullptr), size_(0){};
// 링크드리스트 소멸자
LinkedList::~LinkedList()
{
    Node *current = head_;
    while (current != nullptr)
    {
        Node *next = current->next_;
        delete current;
        current = next;
    }
}
void LinkedList::print()
{
    Node *current = head_;
    while (current != nullptr)
    {
        std::cout << current->value_ << " ";
        current = current->next_;
    }
}
void LinkedList::insert(int index, int value)
{
    if (index < 0 || index > size_)
        return;

    Node *newNode = new Node(value);

    if (index == 0)
    {
        newNode->next_ = head_;
        head_ = newNode;
    }
    else
    {
        Node *pre = head_;
        for (int i = 0; i < index - 1; i++)
        {
            pre = pre->next_;
        }
        newNode->next_ = pre->next_;
        pre->next_ = newNode;
    }
    size_++;
}
int LinkedList::get(int index)
{
    if (index < 0 || index > size_)
        return -1;

    Node *current = head_;
    for (int i = 0; i < index; i++)
    {
        current = current->next_;
    }
    return current->value_;
}
void LinkedList::remove(int index)
{
    if (index < 0 || index > size_)
        return;

    Node *removeNode = nullptr;
    if (index == 0)
    {
        removeNode = head_;
        head_ = head_->next_;
    }
    else
    {
        Node *pre = head_;
        for (int i = 0; i < index - 1; i++)
        {
            pre = pre->next_;
        }
        removeNode = pre->next_;
        pre->next_ = removeNode->next_;
    }
    delete removeNode;
    size_--;
}