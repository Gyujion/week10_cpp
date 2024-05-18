#include "queue.h"
#include <iostream>

void Queue::push(int data)
{
    insert(size_, data);
}
int Queue::pop()
{
    if (size_ == 0)
        return -1;
    int returnVal = get(0);
    remove(0);

    return returnVal;
}
int Queue::peek()
{
    if (size_ == 0)
        return -1;
    return get(0);
}
Queue &Queue::operator+=(int value)
{
    push(value);
    return *this;
}