/*
Problem Statement
Implement a class Queue using std::deque<int> internally. Provide:
    - enqueue(int)
    - dequeue()
    - front() const
    - empty() const

Constraints:
    - Must not use std::queue.
    - dequeue() must handle empty queue safely.
    - Must not expose underlying deque.
    - Demonstrate behavior in FIFO order.
*/

#include <exception>
#include <iostream>
#include <deque>
#include <stdexcept>

class Queue
{
    private:
        std::deque<int> elements;

    public:

        //enqueue(int) - add to the back of the line
        void enqueue(int value)
        {
            elements.push_back(value);
            std::cout << "Enqueued: " << value << '\n';
        }

        bool empty() const
        {
            return elements.empty();
        }

        void dequeue()
        {
            if(empty())
            {
                throw std::out_of_range("Queue<>::dequeue(): queue empty.");
            }

            elements.pop_front();
        }

        const int &front() const
        {
            if(empty())
            {
                throw std::out_of_range("Queue<>::front(): queue empty.");
            }

            return elements.front();
        }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    while(!q.empty())
    {
        std::cout << "Front of queue: " << q.front() << '\n';
        q.dequeue();
    }

    try
    {
        q.dequeue();
    }
    catch(const std::exception &e)
    {
        std::cout << "\nError Caught: " << e.what() << '\n';
    }
    
    return 0;
}