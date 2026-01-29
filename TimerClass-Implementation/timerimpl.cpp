/*
Problem Statement
Implement a Timer class that measures elapsed time between start() and stop(). Should support:
    - start() — record starting time
    - stop() — record ending time
    - elapsedMilliseconds() const
    - elapsedSeconds() const

Constraints:
    - Use std::chrono::steady_clock (not system_clock).
    - Timer must be reusable (start/stop multiple times).
    - No global/static variables.
    - Everything must be exception safe.
*/

#include <chrono>
#include <cmath>
#include <iostream>

class Timer
{
    private: 

        //Type aliasing
        using Clock = std::chrono::steady_clock;
        using TimeStamp = std::chrono::time_point<Clock>;

        TimeStamp startTime_;
        TimeStamp stopTime_;
        
        /*
        In order for the clock to be reusable, we need to know what state the timer is in.
        If a user calls elapsedSeconds(), while the timer is running, we should calculate
        the time from now vs start instead of using stopTime_
        */
        bool isRunning_;

        // Helper function to centralize duration logic.
        std::chrono::duration<double> getDuration() const
        {
            TimeStamp end = isRunning_ ? Clock::now() : stopTime_;
            return end - startTime_;
        }

    public:

        Timer() : isRunning_(false) { };

        void start() 
        {
            startTime_ = Clock::now();
            isRunning_ = true;
        }

        void stop()
        {
            stopTime_ = Clock::now();
            isRunning_ = false;
        }

        double elapsedMilliseconds() const
        {
            std::chrono::duration<double, std::milli> ms = getDuration();
            return ms.count();
        }

        double elapsedSeconds() const
        {
            return getDuration().count();
        }

};

//Helper work function

void doWork()
{
    volatile double result {0.0};
    
    for(int i{0}; i < 1000000; ++i)
    {
        result += std::sin(i) * std::cos(i);
    }
}

int main()
{
    Timer t;

    t.start();

    doWork(); //Block CPU for actual work

    t.stop();

    std::cout << "Time elapsed: " << t.elapsedMilliseconds() << " ms." << '\n';

    return 0;
}