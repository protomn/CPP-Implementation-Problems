/*
Problem Statement
Implement a templated class FixedStack<T, N> that stores up to N elements without dynamic allocation.

Constraints:
    - Use a std::array<T, N> or a raw array.
    - Provide:
        - push(const T&)
        - pop()
        - top() const
        - empty() const
        - full() const
    - Must handle overflow and underflow gracefully (throw or guard).
    - Must work for any type T.
*/

#include <exception>
#include <iostream>
#include <array>
#include <stdexcept>
#include <string>

/*
Template with 2 parameters
    1. The type of data
    2. The size being stored (maximum capacity) - must be known at compile time
*/

template <typename T, size_t N>
class FixedStack
{
    private:

        std::array<T, N> data_; //the storage, allocated on the stack
        size_t currSize{0};

    public:

        void push(const T &value)
        {
            if(full())
            {
                throw std::overflow_error("Stack Overflow: Cannot push, stack is full.");
            }
            data_[currSize] = value;
            currSize++;
        }

        void pop()
        {
            if(empty())
            {
                throw std::underflow_error("Stack Underflow: Cannot pop, stack is empty.");
            }
            currSize--;
        }

        const T& top() const
        {
            if(empty())
            {
                throw std::underflow_error("Stack Underflow: stack is empty, no top.");
            }

            return data_[currSize - 1];
        }

        //UTILS
        bool empty() const
        {
            return currSize == 0;
        }

        bool full() const
        {
            return currSize == N;
        }

        size_t size() const
        {
            return currSize;
        }
};

int main()
{
    try
    {
        FixedStack<int, 3> fs;
        
        fs.push(10);
        fs.push(20);
        fs.push(30);

        std::cout << "Top is: " << fs.top() << '\n';

        fs.pop();
        std::cout << "Popped one. New top is: " << fs.top() << '\n';

        FixedStack<std::string, 2> ss;
        ss.push("Hello");
        ss.push("World!");

        while(!ss.empty())
        {
            std::cout << "Top is: " << ss.top() << '\n';
            ss.pop();
        }

        ss.pop(); //throws exception
    }
    catch(const std::exception &e)
    {
        std::cerr << "EXCEPTION: " << e.what() << '\n';
    }

    return 0;
}