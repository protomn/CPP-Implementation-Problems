/*
Problem Statement
Implement a Strategy pattern where a Context class uses a pluggable strategy object to perform an operation. 
Provide two concrete strategies:
    - AddStrategy: adds two numbers
    - MultiplyStrategy: multiplies two numbers

Constraints:
    - Define a base Strategy interface with a virtual method execute(int,int).
    - Context must accept a strategy via constructor or setter.
    - Must allow switching strategies at runtime.
    - Must demonstrate calling both strategies through the same Context object.
*/

#include <iostream>

//The strategy interface
//Determines the shape of the tool we can plug in

class Strategy
{
    public:

        virtual int execute(int a, int b) const = 0;
        virtual ~Strategy() = default;
};

//Strategy A: Add
class AddStrategy : public Strategy
{
    public:
        
        int execute(int a, int b) const override
        {
            return a + b;
        }
};

class MultiplyStrategy : public Strategy
{
    public:

        int execute(int a, int b) const override
        {
            return a * b;
        }
};

//The context - doesn't know how to do the math - delegates that work to Strategy
class Context
{
    private:

        // I've used a raw pointer here because Context does not own the strategy, it just references it
        Strategy *strat;

    public:

        //Constructor (initialStrat)
        Context(Strategy *initialStrat) : strat(initialStrat) { }

        //Setter - allows swapping at runtime
        void setStrategy(Strategy *newStrat)
        {
            strat = newStrat;
        }

        int executeStrat(int a, int b) const
        {
            if(!strat) { return 0; }
            return strat -> execute(a, b);
        }
};

int main()
{
    AddStrategy adder;
    MultiplyStrategy multiplier;

    //Initialize context with addition
    Context ctx(&adder);
    std::cout << "10 + 5 = " << ctx.executeStrat(10, 5) << '\n';

    //Hot-swap to multiplication using the same object
    ctx.setStrategy(&multiplier);
    std::cout << "10 x 5 = " << ctx.executeStrat(10, 5) << '\n';

    return 0;
}