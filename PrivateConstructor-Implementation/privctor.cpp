/*
Problem Statement
Implement a class Logger that has a private constructor, preventing direct instantiation. 
Provide a static factory method create() that returns an instance of the class.

Constraints:
    - Constructor must be private.
    - Static factory must return the object by value.
    - Must demonstrate that Logger x; is illegal.
    - Must show object creation via Logger::create().
    - No dynamic allocation allowed inside the factory (return on stack).
*/

#include <iostream>
#include <string>

class Logger
{
    private:
        std::string tag_;

        //Private Constructor.
        //Only functions belonging to Logger can call.
        Logger(std::string tag) : tag_(tag)
        {
            std::cout << "[Constructor] called with tag: " << tag_ << '\n';
        }

    public:
        
        //Static factory method
        static Logger create(std::string tag)
        {
            if(tag.empty())
            {
                tag = "Default!";
            }

            return Logger(tag); //Returns by value (stack object)
        }

        void log(std::string message)
        {
            std::cout << "[" << tag_ << "] " << message << '\n';
        }
};

int main()
{
    //Instantiation
    Logger myLog = Logger::create("system");
    myLog.log("Booting up.");

    Logger appLog = Logger::create("App");
    appLog.log("Logged in.");

    return 0;
}