/* 
Problem Statement
Implement a class MoveOnly that cannot be copied but can be moved.
Delete the copy constructor and copy assignment operator, and explicitly define the move constructor and move assignment operator.

Constraints:
    - Copy constructor and copy assignment must be explicitly deleted.
    - Move constructor and move assignment must both be implemented and noexcept.
    - Class should store at least one resource (e.g., an int*).
    - Moved-from state must be valid and destructible.
    - Must demonstrate move semantics in main().
*/

#include <iostream>
#include <utility>

class MoveOnly
{
    private:
        int *data_;

    public:

        //Constructor
        explicit MoveOnly(int value) 
        {
            data_ = new int(value);
            std::cout << "[Constructor] Allocated " << value << " at " << data_ << '\n';
        }

        //Destructor
        ~MoveOnly()
        {
            if(data_)
            {
                std::cout << "[Destructor] Freeing memory at " << data_ << '\n';
                delete data_;
            }
            else {
            std::cout << "Nothing to free, empty object.\n";
            }
        }

        //Deleting copy constructor and copy assignment operator
        //This disables copying
        MoveOnly(const MoveOnly &) = delete;
        MoveOnly &operator=(const MoveOnly &) = delete;

        //Enabling moving
        //Move constructor
        MoveOnly(MoveOnly &&other) noexcept : data_(other.data_)
        {
            //Null out the source so it doesn't delete the memory just moved
            other.data_ = nullptr;
            std::cout << "[Move Constructor] Memory moved: " << data_ << '\n';
        }
        
        //Move assignment operator (std::move())
        MoveOnly &operator=(MoveOnly &&other) noexcept
        {
            if (this != &other)
            {
                //Clean current memory
                delete data_;

                //Move memory
                data_ = other.data_;

                //Null the source
                other.data_ = nullptr;

                std::cout << "[Move Assgn Operator] Memory moved: " << data_ << '\n';
            }

            return *this;
        }

        //Helper functions
        void print() const
        {
            if (data_) { std::cout << "Value: " << *data_ << '\n'; }
            else { std::cout << "Value: Empty.\n"; }
        }
};

int main()
{
    //Creating an object
    MoveOnly a(10);
    a.print();

    //Move a to b
    MoveOnly b = std::move(a);
    /*
    std::move() casts a to an r-value reference (MoveOnly &&) trigerring the move constructor
    */

    std::cout << "State of a: "; a.print();
    std::cout << "State of b: "; b.print();

    //Move assignment
    MoveOnly c(20);
    c = std::move(b);
    /*
    What's happening here:
        C initially has its own data (20)
        when c = std::move(b) is executed
        c deletes it's data (20), steals 10 from b, then points b to a nullptr
    */

    std::cout << "State of b: "; b.print();
    std::cout << "State of c: "; c.print();

    return 0;

}