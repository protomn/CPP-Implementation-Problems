/*
Problem Statement
Implement a Proxy pattern where:
    - a class RealService exposes a method perform().
    - a class LoggingProxy wraps a RealService and logs every call to perform() before delegating to the real object.

Constraints:
    - Proxy must hold a pointer/reference to RealService.
    - Proxy must log timing or text before forwarding the call.
    - Must not modify the underlying real object.
    - Must demonstrate that calling proxy.perform() outputs logs + performs actual work.
*/

#include <iostream>
#include <memory>

/*
The Interface
implemented by both, the RealService and Proxy
*/
class IService
{
    public:

        virtual void perform() const = 0;
        virtual ~IService() = default;
};

//RealService
class RealService : public IService
{
    public:

        void perform() const override
        {
            std::cout << "[RealService] Executing the core logic...\n";
        }
};

/*
The proxy
Wrap RealService and adds logging
*/

class Proxy : public IService
{   
    private:

        //Owns/references the RealService
        std::unique_ptr<RealService> realService_;

    public:

        //Constructor
        Proxy() : realService_(std::make_unique<RealService>()) { }

        //Deleting copy constructor and copy assignment operator
        Proxy(const Proxy &) = delete;
        Proxy &operator=(const Proxy &) = delete;

        void perform() const override
        {
            std::cout << "[Proxy] LOG: Request received. Forwarding to RealService.\n";
            realService_ -> perform();
            std::cout << "[Proxy] LOG: Request completed successfully.\n";
        }
};

void clientCode(const IService &service)
{
    service.perform();
}

int main()
{
    //A. Direct Access
    RealService real;
    real.perform();

    //Access via proxy
    Proxy proxy;
    clientCode(proxy);

    return 0;
}