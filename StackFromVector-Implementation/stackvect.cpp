/*
Problem Statement
Implement a class Stack using std::vector<int> internally. Provide:
    - push(int)
    - pop()
    - top() const
    - empty() const

Constraints:
    - Must not use std::stack.
    - pop() must handle empty-stack safely (throw or guard).
    - Must not expose underlying vector.
    - Must demonstrate stack operations in main().
*/

#include <iostream>
#include <vector>
#include <stdexcept>

class Stack
{
    private:
        std::vector<int> elements;

    public:

        //Push - add element to the top
        void push(int elem)
        {
            return elements.push_back(elem);
        }

        // empty() const - check if stack is empty
        bool empty() const
        {
            return elements.empty();
        }

        // pop() - remove element from the top
        void pop()
        {
            if(empty())
            {
                throw std::out_of_range("Stack<>::pop(): empty stack.");
            }

            elements.pop_back();
        }

        // top() - gives view of the top element
        const int &top() const
        {
            if(empty())
            {
                throw std::out_of_range("Stack<>::top(): empty stack.");
            }

            return elements.back();
        }
};

int main()
{
    Stack s; //instantiate

    s.push(10);
    s.push(50);
    s.push(33);

    std::cout << "The top is: " << s.top() << '\n';

    s.pop();

    std::cout << "Popped. New top is: " << s.top() << '\n';

    s.pop();
    s.pop(); //Stack now empty

    std::cout << "Stack empty? " << (s.empty() ? "Yes." : "No.") << '\n';

    return 0;
}