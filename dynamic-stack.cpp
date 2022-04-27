#include "dynamic-stack.h"
#include <iostream>

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    items_ = new StackItem[capacity_];
    capacity_ = 16;
    size_ = 0;
    init_capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int capacity)
{
    items_ = new StackItem[capacity];
    capacity_ = capacity;
    size_ = 0;
    init_capacity_ = capacity;
}

DynamicStack::~DynamicStack()
{
    delete items_;
}

bool DynamicStack::empty() const
{
    if(size_ == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
    if(size_ < capacity_)
    {
        items_[size_] = value;
    }
    else
    {
        capacity_ = capacity_*2;
        StackItem* newStack = new StackItem[capacity_];

        for(int index = 0; index < size_-1; index++)
        {
            newStack[index] = items_[index];
        }

        delete items_;
        items_ = newStack;
    }

    size_++;
}

DynamicStack::StackItem DynamicStack::pop()
{
    if(empty())
    {
        return EMPTY_STACK;
    }
    else
    {
        StackItem top = items_[size_-1];

        size_--;

        if(size_ <= capacity_/4)
        {
            if(capacity_/2 >= init_capacity_)
            {
                capacity_ = capacity_/2;

                StackItem* newStack = new StackItem[capacity_];

                for(int index = 0; index < size_; index++)
                {
                    newStack[index] = items_[index];
                }

                delete items_;
                items_ = newStack;
            }
        }

        return top;
    }
}

DynamicStack::StackItem DynamicStack::peek() const
{
    if(empty())
    {
        return EMPTY_STACK;
    }
    else
    {
        return items_[size_-1];
    }
}

void DynamicStack::print() const
{
    for(int index = 0; index < size_-1; index++)
    {
        std::cout << items_[index] << std::endl;
    }
}