/*
Problem Statement
Implement an observer pattern where a Subject holds an integer state, and multiple Observer objects get notified whenever the state changes.

Constraints:
    - Subject must maintain a list of Observer*.
    - Observer must provide an update(int newValue) method.
    - When Subject::setState(int) is called:
        - State is updated
        - All registered observers receive notifications
    - Observers must not own the subject.
    - Demonstrate registering multiple observers and triggering updates.
*/

#include <iostream>
#include <vector>
#include <algorithm>

//The Observer Interface
//Any class that wants to listen to the Subject must implement this
class Observer
{
    public:

        //Pure virtual method
        virtual void update(int newState) = 0;
        virtual ~Observer() = default;
};

//The subject
class Subject
{
    private:

        int state_;
        /*
        The address book of subscribers
        We use raw pointers because the Subject does not own the observers
        */
        std::vector<Observer*> observers;

        //Broadcast method
        void notify()
        {
            for(Observer *obs : observers)
            {
                obs -> update(state_);
            }
        }

    public:

        //Add observer to the list
        void attach(Observer *obs)
        {
            observers.push_back(obs);
        }

        //Remove observer from the list
        void detach(Observer *obs)
        {
            observers.erase(
                std::remove(observers.begin(), observers.end(), obs),
                observers.end()
            );
        }

        //Change and update everyone's state
        void setState(int newState)
        {
            std::cout << "\n[Subject] State changing to: " << newState << '\n';
            state_ = newState;
            notify();
        }
};

//Concrete observer
//Represents a specific listener
class concreteObserver : public Observer
{
    private:

        int id_; // to identify different observers in the output

    public: 

        //Constructor
        concreteObserver(int id) : id_(id) { }

        void update(int newState) override
        {
            std::cout << "  -> Observer " << id_ << " received update: " << newState << '\n';
        }
};

int main()
{
    //Create a Subject
    Subject subject;

    //Create observers (listeners)
    concreteObserver obs1(1);
    concreteObserver obs2(2);
    concreteObserver obs3(3);

    //Subcribe them
    subject.attach(&obs1);
    subject.attach(&obs2);
    subject.attach(&obs3);

    //Trigger an event
    subject.setState(10);

    //Unsubscribe 1 and trigger again.
    subject.detach(&obs2);
    subject.setState(20);

    return 0;
}