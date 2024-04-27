/*
A double-ended queue (deque) is a linear list in which additions
and deletions may be made at either end. Obtain a data
representation mapping a deque into a onedimensional array.
Write C++ program to simulate deque with functions to add and
delete elements from either end of the deque.
*/
#include <iostream>
using namespace std;
#define MAX 5
class Dequeue
{
private:
    int data[MAX], front, rear;

public:
    Dequeue()
    {
        front = -1;
        rear = -1;
    }
    bool isempty();
    bool isfull();
    void enqueue_f(int d);
    void enqueue_r(int d);
    void dequeue_f();
    void dequeue_r();
    void display();
};
bool Dequeue::isempty()
{
    return front == -1;
}
bool Dequeue::isfull()
{
    return (front == 0 && rear == (MAX - 1)) || (front == (rear + 1));
}
void Dequeue::enqueue_f(int d)
{
    if (isfull())
    {
        cout << "The queue is full. cant enqueue at front" << endl;
    }
    else
    {
        if (isempty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = MAX - 1;
        }
        else
        {
            front--;
        }
        data[front] = d;
        cout << "Data " << d << " has been enqueued at front successfully." << endl;
    }
}
void Dequeue::enqueue_r(int d)
{
    if (isfull())
    {
        cout << "The queue is full. cant enqueue at rear" << endl;
    }
    else
    {
        if (isempty())
        {
            front = rear = 0;
        }
        else if (rear == (MAX - 1))
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        data[rear] = d;
        cout << "Data " << d << " has been enqueued at rear successfully." << endl;
    }
}
void Dequeue::dequeue_f()
{
    if (isempty())
    {
        cout << "The queue is empty. cant dequeue at front" << endl;
    }
    else
    {
        cout<<data[front]<<" was dequeued from front."<<endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == (MAX - 1))
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}
void Dequeue::dequeue_r()
{
    if (isempty())
    {
        cout << "The queue is empty. cant dequeue at rear" << endl;
    }
    else
    {
        cout<<data[rear]<<" was dequeued from rear."<<endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = MAX - 1;
        }
        else
        {
            rear--;
        }
    }
}
void Dequeue::display()
{
    if (isempty())
    {
        cout << "The queue is empty. cant display," << endl;
    }
    else
    {
        int i = front;
        cout<<"Dequeue Elements: ";
        do
        {
            cout << data[i] << " ";
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        cout<<endl;
    }
}
int main()
{
    Dequeue d;
    int choice, value;
    do
    {
        cout << "\n1. Insert at Front";
        cout << "\n2. Insert at Rear";
        cout << "\n3. Delete from Front";
        cout << "\n4. Delete from Rear";
        cout << "\n5. Display Deque";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert at front: ";
            cin >> value;
            d.enqueue_f(value);
            break;

        case 2:
            cout << "Enter the value to insert at rear: ";
            cin >> value;
            d.enqueue_r(value);
            break;

        case 3:
            d.dequeue_f();
            break;

        case 4:
            d.dequeue_r();
            break;

        case 5:
            d.display();
            break;

        case 6:
            cout << "Exiting the program.";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.";
        }
    } while (choice != 6);

    return 0;
}