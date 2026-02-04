/*
Problem Statement
Create a class Buffer that manages a dynamically allocated array of integers. 
Demonstrate:
    - What happens with a default shallow copy (copying the pointer only).
    - How to implement a correct deep copy (duplicate underlying memory).

Constraints:
    - Must store an int* buffer and a size.
    - Show shallow-copy behavior explicitly (double delete or shared mutation).
    - Then fix using a proper copy constructor + copy assignment operator.
    - Must follow the Rule of 3.
    - Demonstrate in main() that modifying one buffer does not affect the other.
*/

#include <iostream>
#include <algorithm>
#include <string>

class Buffer
{
    private:

        int *data_;
        size_t size_;

    public:

        //Constructor
        Buffer(size_t size) : size_(size)
        {
            data_ = new int[size_];
            std::cout << "[Constructor] Allocated buffer of size: " << size_ << '\n';
            for(size_t i{0}; i < size_; ++i) { data_[i] = i * 10; }
        }

        //Destructor
        ~Buffer()
        {
            std::cout << "[Destructor] Releasing memory at: " << data_ << '\n';
            delete[] data_;
        }
        
        //Copy Constructor (Deep copy)
        Buffer(const Buffer &other) : size_(other.size_)
        {
            data_ = new int[size_]; //Allocate new memory

            //Copy the values, not the pointer
            std::copy(other.data_, other.data_ + size_, data_);

            std::cout << "[Copy Constructor] Deep copy created at: " << data_ << " from " << other.data_ << '\n';
        }

        //Copy Assignment Operator
        Buffer &operator=(const Buffer &other)
        {
            //Check for self assignment
            if(&other == this)
            {
                return *this;
            }

            //Cleanup existing old memory
            delete[] data_;

            //Allocate new memory and copy
            size_ = other.size_;
            data_ = new int[size_];
            std::copy(other.data_, other.data_ + size_, data_);

            std::cout << "[Copy Assignment Op] Deep Copy assigned at: " << data_ << " from " << other.data_ << '\n';

            return *this;
        }

        //Helper function to modify data
        void set(int index, int value)
        {
            if (index < 0 || static_cast<size_t>(index) >= size_)
            {
                return;
            }

            data_[index] = value;
        }

        void print(const std::string &name) const
        {
            std::cout << name << " [" << data_ << "]: ";
            for (size_t i{0}; i < size_; ++i)
            {
                std::cout << data_[i] << " ";
            }
            std::cout << '\n';
        }
};

int main()
{
    //Create original
    Buffer b1(3);
    b1.print("b1");

    //Deep copy
    Buffer b2 = b1;
    b2.print("b2");

    //Modify b1
    b1.set(0, 999);

    b1.print("b1");
    b2.print("b2");

    Buffer b3(2);
    b3 = b1;
    b3.print("b3");

    //End of main
    return 0;
}