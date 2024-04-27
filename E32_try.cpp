/*
Pizza parlor accepting maximum M orders. Orders are served in first 
come first served basis. Order once placed cannot be cancelled. Write 
C++ program to simulate the system using circular queue using array.
*/
#include<iostream>
using namespace std;
#define MAX 5
class Circular_queue
{
    private:
    int data[MAX],front,rear;
    public:
    Circular_queue()
    {
        front = -1;
        rear = -1;
    }
    bool isempty();
    bool isfull();
    void place_order(int ord);
    void serve();
    void display();
};
bool Circular_queue:: isempty()
{
    return rear== -1 && front== -1;
}
bool Circular_queue::isfull()
{
    return (rear+1)%MAX==front;
}
void Circular_queue::place_order(int ord)
{
    if(isfull())
    {
        cout<<"Sorry the pizza palor orders are full. Can not accept."<<endl;
        return;
    }
    if(isempty())
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=(rear+1)%MAX;
    }
    data[rear]=ord;
    cout<<"Order "<<ord<<" has been placed successfully."<<endl;
}
void Circular_queue ::serve()
{
    if(isempty())
    {
        cout<<"No orders to serve. Pizza parlor is empty"<<endl;
        return;
    }
    cout<<"Order "<<data[front]<<" served. Enjoy!!!"<<endl;
    if(front==0 && rear==0)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%MAX;
    }
}
void Circular_queue:: display()
{
    int i=front;
    if (isempty()) 
    {
        cout << "No orders in the queue."<< endl;
        return;
    }
    cout<<"The orders are: ";
    while(true)
    {
        cout<<data[i]<<" ";
        if(i==rear)
        {
            break;
        }
        i=(i+1)%MAX;
    }
    cout<<endl;
}
int main()
{
    Circular_queue pizzaParlor;
    int choice, order;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                cout << "Enter order number to place: ";
                cin >> order;
                pizzaParlor.place_order(order);
                break;
            case 2:
                pizzaParlor.serve();
                break;
            case 3:
                pizzaParlor.display();
                break;
            case 4:
                cout << "Exiting the pizza parlor simulation.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }while(choice!=4);
    return 0;
}