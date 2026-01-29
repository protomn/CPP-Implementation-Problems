/*
Problem Statement
Implement a StringWrapper class that internally holds a std::string and exposes:
    - size()
    - append(const std::string&)
    - compare(const StringWrapper&) const
You may add helper methods if needed.

Constraints:
    - Must not publicly expose std::string.
    - Must store the string internally (composition).
    - Must not use inheritance from std::string.
    - All methods must be exception-safe.
*/

#include <string>
#include <iostream>

class StringWrapper
{
    private:
        std::string data_;

    public:
        // Default Constructor
        StringWrapper() = default;

        // Construct from string literal
        StringWrapper(const char *str) : data_(str) { }

        //Construct from std::string
        StringWrapper(const std::string &str) : data_(str) { }

        // Get size method
        size_t getSize() const
        {
            return data_.size();
        }

        // Append method
        StringWrapper &append(const std::string &str)
        {
            data_.append(str);
            return *this;
        }

        //Compare strings
        int compareString(const StringWrapper &other) const
        {
            return data_.compare(other.data_);
        }

        void print() const
        {
            std::cout << "\"" << data_ << "\"";
        }
};

int main()
{
    StringWrapper s1("Hello");
    StringWrapper s2("Hello");
    StringWrapper s3("World");

    std::cout << "S1 Size: " << s1.getSize() << '\n';

    if (s1.compareString(s2) == 0)
    {
        std::cout << "S1 and S2 are the same!\n";
    }

    if (s1.compareString(s3) != 0)
    {
        std::cout << "S1 and S3 are not the same.\n";
    }

    s1.append(" ").append("World").append("!");

    std::cout << "S1 post append: ";
    s1.print();

    return 0;
}