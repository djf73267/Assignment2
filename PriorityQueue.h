#include<iostream>
#include<string>

template <class ItemType>
struct QueueNode
{
    ItemType info;
    int priority;
    QueueNode<ItemType>* next;
};

class FullQueue
{};

class EmptyQueue
{};

template <class ItemType>
class PriorityQueue
{
    
public:
    
    PriorityQueue();
    // Class constructor.
    
    PriorityQueue(int max);
    // Parameterized Constructor
    
    ~PriorityQueue();
    // Class Destructor
    void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: queue is empty.

    bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)
    
    bool IsFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)

    void Enqueue(ItemType newItem, int priority = 1);
    // Function: add item to queue
    // Post: newItem added to queue ++length
    
    ItemType Dequeue();
    // Function: removes item from queue
    // Post: item removed from queue --lengrh
    
    int Length();
    // Function: returns number of items in queue
    
    char Peek();
    // Function: returns info of front item
    
    int PeekPriority();
    // Function: returns priority of front item
    
    void PrintQueue(std::ostream &out);
    // Function: prints items in queue
    
private:
    
    QueueNode<ItemType>* front;
    int cap;
    int queueLength;
    
};

