/* 
Problem Statement
Implement a class SimpleHashSet from scratch. 

Constraints:
    - Use a fixed number of buckets (e.g., 10) for simplicity.
    - Use Separate Chaining (Linked Lists) to handle collisions.
    - Implement insert(int) and contains(int).
    - Do not use std::unordered_set or std::list. (Use a Node struct).
*/

/*
The concept: Hash Tables
    unordered_set is essentially an array of buckets.
        - Hash Function: Turns value (key) into an index [Index = Key % BucketCount]
        - Collision: If 10%5 and 55%5 are both equal to 0, then they try to go into the same bucket
        - Chaining: We make each bucket a Linked List. If two keys collide, we chain them together in that list.
*/

#include <iostream>
#include <vector>

// The Linked List Node
struct Node
{
    int data_;
    Node *next;

    Node(int val) : data_(val), next(nullptr) { }
};

class SimpleHastSet
{
    private:

        //Buckets is a vector of pointer, where each pointer is the head of a node.
        std::vector<Node*> buckets;
        int bucketCount;    

        // The hash function
        //It maps a large integer to a valid index [0, ..., bucketCount - 1]
        int hash(int key) const
        {
            //To handle negative numbers we use std::abs()
            return std::abs(key) % bucketCount;
        }

    public:
        
        //Constructor, intialize buckets to nullptrs
        SimpleHastSet(int size = 10) : bucketCount(size)
        {
            buckets.resize(size, nullptr);
        }

        //Destructor
        ~SimpleHastSet()
        {
            for (int i{0}; i < bucketCount; ++i)
            {
                Node *current = buckets[i];
                while(current != nullptr)
                {
                    Node *toDelete = current;
                    current = current -> next;
                    delete toDelete;
                }
            }
        }

        //Insert function
        void insert(int key)
        {
            int index = hash(key);

            if(contains(key))
            {
                return;
            }

            //Insert at the head of the list
            Node *newNode = new Node(key);
            newNode -> next = buckets[index]; // point the new node to the old head
            buckets[index] = newNode; // update bucket to point to the new node

            std::cout << "Inserted " << key << " at bucket " << index << '\n';
        }

        //Contains function (search)
        bool contains(int key) const
        {
            int index = hash(key);
            Node *current = buckets[index];

            // Walking the linked list in this bucket
            while(current != nullptr)
            {
                if(current -> data_ == key)
                {
                    return true;
                }

                current = current -> next;
            }

            return false; //Reached the end of the list without finding the key
        }

        void printStruct()
        {
            for (int i{0}; i< bucketCount; ++i)
            {
                std::cout << "Bucket " << i << ": ";
                Node *current = buckets[i];
                while(current)
                {
                    std::cout << "[" << current -> data_ << "] -> ";
                    current = current -> next;
                }
                
                std::cout << "nullptr\n";
            }
        }
};

int main()
{
    SimpleHastSet s(5);

    // Insert values
    s.insert(10);
    s.insert(15);
    s.insert(20);
    s.insert(7);
    s.insert(10);

    s.printStruct();

    //Search
    std::cout << "Contains 15? " << (s.contains(15) ? "Yes" : "No") << '\n';

    return 0;
}