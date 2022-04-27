#include "circular-queue.h"
#include <iostream>

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
    items_ = new QueueItem[capacity_];
    head_ = 0;
    tail_ = 0;
    capacity_ = 16;
    size_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
    items_ = new QueueItem[capacity];
    head_ = 0;
    tail_ = 0;
    capacity_ = capacity;
    size_ = 0;
}

CircularQueue::~CircularQueue()
{
    delete items_;
}

bool CircularQueue::empty() const
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

bool CircularQueue::full() const
{
    if(size_ == capacity_)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int CircularQueue::size() const
{
    return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
    if(full())
    {
        return false;
    }
    else
    {
        items_[tail_] = value;

        size_++;

        tail_ = (tail_ + 1) % capacity_;

        return true;
    }
}

CircularQueue::QueueItem CircularQueue::dequeue()
{
    if(empty())
    {
        return EMPTY_QUEUE;
    }
    else
    {
        QueueItem temp = items_[head_];

        size_--;

        head_= (head_ + 1) % capacity_;

        return temp;
    }
}

CircularQueue::QueueItem CircularQueue::peek() const
{
    if(empty())
    {
        return EMPTY_QUEUE;
    }
    else
    {
        return items_[head_];
    }
}

void CircularQueue::print() const
{
    for(int index = 0; index < size_-1; index++)
    {
        std::cout << items_[index] << std::endl;
    }
}