/*
Queues are frequently used in computer programming, and a typical 
example is the creation of a job queue by an operating system. If the 
operating system does not use priorities, then the jobs are processed 
in the order they enter the system. Write C++ program for simulating 
job queue. Write functions to add job and delete job from queue.
*/
#include<iostream>
using namespace std;
#define MAX 5
class Queue
{
    private:
    int data[MAX];
    int front,rear;
    public:
    Queue()
    {
        front=rear=-1;
    }
    bool isempty();
    bool isfull();
    void enqueue(int d);
    void dequeue();
    void display();
};
bool Queue::isempty()
{
    return rear == -1 && front == -1;
}
bool Queue::isfull()
{
    return (rear+1)==MAX;
}
void Queue::enqueue(int d)
{
    if(isfull())
    {
        cout<<"the queue is full. Can not add more jobs."<<endl;
        return ;
    }
    if(isempty())
    {
        front=rear=0;
    }
    else
    {
        rear=rear+1;
    }
    data[rear]=d;
    cout<<d<<" added in the queue successfully"<<endl;
}
void Queue::dequeue()
{
    if(isempty())
    {
        cout<<"The queue is empty, Can not dequeue job."<<endl;
        return;
    }
    if(rear==0 && front==0)
    {
        cout<<data[front]<<" has been dequeued successfully."<<endl;
        front=rear=-1;
    }
    else
    {
        cout<<data[front]<<" has been dequeued successfully."<<endl;
        front=front+1;
    }
}
void Queue::display()
{
    if(isempty())
    {
        cout<<"The queue is empty. "<<endl;
        return;
    }
    cout << "Jobs in the queue: ";
    int i=front;
    while(true)
    {
        cout<<data[i]<<" ";
        if(i== rear)
        {
            break;
        }
        i=i+1;
    }
    cout<<endl;
}
int main()
{
    Queue q;
    int choice,job;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job number to enqueue: ";
                cin >> job;
                q.enqueue(job);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);
    return 0;
}