/*
Problem Statement
Implement a class FileHandle that wraps a FILE* and:
    - Opens a file in the constructor
    - Closes it in the destructor
    - Provides a bool isOpen() const
    - Disallow copying, allow moving

Constraints:
    - Must implement the Rule of 5:
        - Destructor
        - Copy Constructor (delete)
        - Move Constructor
        - Copy Assignement Operator (delete)
        - Move Assignment Operator

    - fopen and fclose must be handled carefully
    - Must be exception-safe (constructor must check for null).
    - No raw FILE* leaks allowed.
*/

#include <cstdio>
#include <stdexcept>

class FileHandler
{
    private:

        FILE *file_;

    public:

        //Constructor (Acquisition)
        FileHandler(const char *filename, const char *mode)
        {
            file_ = std::fopen(filename, mode);
            
            if (!file_)
            {
                throw std::runtime_error("Failed to open file!");
            }
        }

        //Destructor (Release)
        ~FileHandler()
        {
            close();
        }

        //Disable copying
        //This prevents 2 objects from closing the same file.
        FileHandler(const FileHandler &) = delete;
        FileHandler &operator=(const FileHandler&) = delete;

        //Enable Moving

        //Move Constructor
        FileHandler(FileHandler &&other) noexcept : file_(other.file_)
        {
            other.file_ = nullptr; //Null the source so it doesn't close it
        }

        //Move Assignment Operator
        FileHandler &operator=(FileHandler &&other) noexcept
        {
            if (this != &other) //Check for self-aliasing
            {
                close(); //Close the current file
                file_ = other.file_;
                other.file_ = nullptr;
            }

            return *this;
        }

        //Helper function to check state
        bool isOpen() const
        {
            return file_ != nullptr;
        }

        //Helper function to cleanly close file.
        void close()
        {
            if (file_)
            {
                std::fclose(file_);
                file_ = nullptr;
            }
        }

        //Expose the raw pointer
        FILE *get() const { return file_; }
};  
