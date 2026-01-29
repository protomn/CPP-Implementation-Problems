/*
Problem Statement
Implement a class IntArray that manages a dynamic array of integers. It must include:
    - Constructor(size): Allocates memory.
    - Destructor: Frees memory.
    - Copy Constructor: Performs a Deep Copy.
    - setValue / getValue: To modify and read data.

Constraints:
    - Must manage int* manually.
    - The default (compiler-generated) copy constructor is forbidden (it performs a shallow copy).
    - Demonstrate in main that modifying a copy does not change the original.
*/

#include <iostream>

class IntArray
{
    private:
        int size_;
        int *data_;

    public:

        //Constructor (Allocation)
        IntArray(int size) : size_(size) 
        {
            data_ = new int[size];

            for(int i{0}; i < size; ++i)
            {
                data_[i] = 0;
            }

            std::cout << "[Allocated] " << data_ << '\n';
        }

        //Destructor
        ~IntArray()
        {
            delete[] data_;
            std::cout << "[Freed] " << data_  << '\n';
        }

        //Copy constructor (Deep copy)
        IntArray(const IntArray &other) : size_(other.size_)
        {
            data_ = new int[size_];

            for (int i{0}; i < size_; i++)
            {
                data_[i] = other.data_[i];
            }

            std::cout << "[Deep Copy] created " << data_ << " from " << other.data_ << '\n';
        }

        //Helper functions
        void setValue(int index, int val)
        {
            if (index >= 0 && index < size_)
            {
                data_[index] = val;
            }
        }

        int getValues(int index) const
        {
            if (index >= 0 && index < size_)
            {
                return data_[index];
            }
            return -1;
        }
};

int main()
{
    //Create an original array
    IntArray original(5);
    original.setValue(0, 100);

    //Create a deep copy
    {
        IntArray copy = original;   

        //Modify the copy
        copy.setValue(0, 999);

        std::cout << "Original[0]: " << original.getValues(0) << '\n';
        std::cout << "Copy[0]: " << copy.getValues(0) << '\n';

    } //copy goes out of scope and is automatically destroyed.

    return 0;
}