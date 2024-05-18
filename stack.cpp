#include "stack.h"
#include <iostream>

void Stack::push(int data)
{
    insert(0, data);
}
int Stack::pop()
{
    if (size_ == 0)
        return -1;
    int returnVal = get(0);
    remove(0);

    return returnVal;
}
int Stack::peek()
{
    if (size_ == 0)
        return -1;

    return get(0);
}
Stack &Stack::operator+=(int value)
{
    push(value);
    return *this;
}