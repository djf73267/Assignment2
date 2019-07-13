#include <iostream>
#include <string>
#include "PriorityQueue.h"
using std::exception;
using namespace std;
template <class ItemType>

PriorityQueue<ItemType>::PriorityQueue()
// default argument constructor
// Post: Cap and length initialized front pointer set to null
{
    cap = 100;
    queueLength = 0;
    front = NULL;
}

template <class ItemType>

PriorityQueue<ItemType>::PriorityQueue(int max)
// parameterized argument constructor
// Post: Cap set to paramter and length initialized front pointer set to null
{
    cap = max;
    queueLength = 0;
    front = NULL;
}

template <class ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
// destructor
// Post: calls MakeEmptyFunction

{
    MakeEmpty();
}

template <class ItemType>

void PriorityQueue<ItemType>::MakeEmpty()
// Post: Length has been reset to the empty state.
// Iterative loop that copies front node to temp and delete
// Sets length to 0 and front to null
{
    QueueNode<ItemType> * temp = front;
    
    while(temp != NULL) //loop
    {
        QueueNode<ItemType> * deleteNode = temp->next;
        delete temp;
        temp = deleteNode;
    }
    
    front = NULL;
    queueLength = 0;
    
}

template <class ItemType>

bool PriorityQueue<ItemType>::IsEmpty() const
// Post: Returns true if front is null; false otherwise.
{
    return (front == NULL);
}

template <class ItemType>

bool PriorityQueue<ItemType>::IsFull() const
// Post: Returns true if the Length is equal to cap; false otherwise.
{
  
    return (queueLength == cap);
}

template <class ItemType>

void PriorityQueue<ItemType>::Enqueue(ItemType newItem, int priority)
// Post: If queue is not full newItem is checked whether the priority is higher than previous node then added
//       increment length ++
//       otherwise a FullList exception is thrown.
{
  
    if (IsFull()) //conditional throw statement
    {
        throw FullQueue();
    }
    else
    {
       
        QueueNode<ItemType> *temp;
        QueueNode<ItemType> *queNode;
        temp = new QueueNode<ItemType>;
        temp->info = newItem;
        temp->priority = priority;

        if (front == NULL || priority < front->priority)
        {
            temp->next = front;
            front = temp;
            
        }

        else
        {
            queNode = front;
        
            while (queNode->next != NULL && queNode->next->priority <= priority)
            {
                queNode = queNode->next;
            }

            temp->next = queNode->next;
            queNode->next = temp;
        }
        
        queueLength++;
        cout<<newItem<<" enqueued"<<endl;
        
    }
    
}

template <class ItemType>

ItemType PriorityQueue<ItemType>::Dequeue()
// Post: If List is empty EmptyList exception is thrown
//       else remove item from list and decrement length
{
    if (IsEmpty())
    {
        throw EmptyQueue();
    }
    else
    {
        QueueNode<ItemType> *temp = front;
        ItemType retVal = temp->info;
        front = front->next;
        free(temp);
        queueLength--;
       
        return retVal;
    }
    
}

template <class ItemType>

int PriorityQueue<ItemType>::Length()
// Post: return length
{
    return queueLength;
}

template <class ItemType>

char PriorityQueue<ItemType>::Peek()
// Post: if empty throw exception
//       return info of front node
{
   
    if (IsEmpty())
    {
        throw EmptyQueue();
    }
    
    return front->info;
    
}

template <class ItemType>

int PriorityQueue<ItemType>::PeekPriority()
// Post: if empty throw exception
//       else return priority of the front node
{

    if (IsEmpty())
    {
        throw EmptyQueue();
    }
  
    return front->priority;
}

template <class ItemType>

void PriorityQueue<ItemType>::PrintQueue(std::ostream &out)
// Post: if empty throw exception
//       else temp nide will iterate and print info till null
{
  
    QueueNode<ItemType> *temp=front;
    
    if (IsEmpty())
    {
        throw EmptyQueue();
    }
    
    else
    {
        while(temp!= NULL)
        {
            out<<temp->info<<" ";
            temp = temp->next;
        }
        
        out<<endl;
        
    }
    
}

