//Include files
#include <iostream>
#include <fstream>
#include "PriorityQueue.cpp"
#include<string>
using namespace std;
//main
int main()
{
    
    //Declare
    ifstream inFile;
    ofstream outFile;
    string inpFleNme;
    string outFleNme;
    inFile.open("inFile.txt");
    outFile.open("outFile.txt");
    string command;
    int priority;
    char item;
    
    //Create
    PriorityQueue<char> priorityQueue(5);
    
    //Read
    inFile >> command; // read commands from a text file
    
    //Loop
    while (command != "Quit")
    {
        try
        {
            //Enqueue
            if (command == "Enqueue")
            {
                //Read item
                inFile >> item;
                
                //Read priority
                inFile>> priority;
                
                //Call Function
                priorityQueue.Enqueue(item,priority);
                
                //Display
                outFile << item<< " is enqueued" << endl;
                
            }
            
            //Dequeue
            else if (command == "Dequeue")
            {
                //Call Function
                item= priorityQueue.Dequeue();
                
                //Display
                outFile<< item << " is dequeued" << endl;
                
            }
            
            //IsEmpty
            else if (command == "IsEmpty")
                
                //Check condition.
                if (priorityQueue.IsEmpty())
                
                    //Print
                    outFile<< "Queue is empty" << endl;
            
                else
                    
                    //Print
                    outFile<< "Queue is not empty" << endl;
            
            //IsFull
                else if (command == "IsFull")
                    
                    //Check condition
                    if (priorityQueue.IsFull())
            
                        //Print
                        outFile<< "Queue is full." << endl;
            
            //print

                    else outFile << "Queue is not full" << endl;
            
            //Check condition
                    else if (command == "MakeEmpty")
                        
                        //Call Function
                        priorityQueue.MakeEmpty();
            
            //Check condition
                    else if(command=="PeekPriority")
                    {
                        //Display
                        outFile<<"Priority of the front item is "<<priorityQueue.PeekPriority()<<endl;
                    }
            
            //Check condition
                    else if(command=="Length")
                    {
                        //Display
                        outFile <<"Number of items in the Queue is: ";
                        outFile<<priorityQueue.Length()<<endl;
                    }
            
            //Check condition
                    else if(command=="Peek")
                    {
                        //Display
                        outFile<<"Front item is "<<priorityQueue.Peek()<<endl;
                    }
            
            //Check condition
                    else if(command=="List")
                    {
                        //Display
                        outFile<<"Queue: ";
                        priorityQueue.PrintQueue(outFile);
                        
                    }
            
        }
        
        //Catch
        
        catch (FullQueue)
        {
            outFile << "FullQueue exception thrown" << endl;
        }
        
        
        
        catch (EmptyQueue)
        {
            outFile << "EmptyQueue exception thrown" << endl;
            
        }
        
        //Read
        
        inFile >> command;
        
    };
    
    //Close
    inFile.close();
    outFile.close();
    
    //Stop
    return 0;
    
}

