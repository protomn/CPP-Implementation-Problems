/*
Problem Statement
Define a Node struct that contains:
    - An int value
    - A pointer to another Node (e.g., a “next” pointer)

Use it to build a small linked structure manually (e.g., 3 nodes linked together).

Constraints:
    - Must manually allocate nodes with new.
    - Must correctly set pointer links.
    - Must print values by walking through the structure.
    - Must delete all nodes to avoid memory leaks.
*/

/*
The idea employed here is that of Self-Referential Structs
What this means is that a struct can hold a pointer to itself (not a full instance of itself).
This is the foundational idea behind a Linked List.
*/

#include <iostream>

struct Node
{
    int value;
    Node *next; // Link to the next Node.
};

int main()
{
    //Create nodes on the Heap (allocation)
    //Get 3 distinct addresses in memory
    Node *head = new Node;
    Node *middle = new Node;
    Node *tail = new Node;

    head -> value = 10;
    head -> next = middle;

    middle -> value = 20;
    middle -> next = tail;

    tail -> value = 30;
    tail -> next = nullptr; //Tail points to nothing (end of list)

    //Walking the list
    Node *current = head; //Start at the beggining

    while(current != nullptr)
    {
        std::cout << "Node at " << current << " contains: " << current->value << ".\n";
        current = current -> next;
    }

    //Cleanup
    delete head;
    delete middle;
    delete tail;

    head = nullptr;
    middle = nullptr;
    tail = nullptr;

    return 0;
}