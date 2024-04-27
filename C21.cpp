// c21 , linked list .
#include <iostream>
using namespace std;

int size;
struct node
{
    float start;
    float end;
    float max;
    float min;
    float flag;
    struct node *next;
}*head;

class appschedule
{
public:
    void createshed();
    void displayshed();
    void bookapp();
    void cancelapp();
    void sortapp();
};

int main()
{
    int ch;
    char ans;
    appschedule A1;

    do
    {
        cout << "\n\n**menu**";
        cout << "\n 1. create appointment schedule ";
        cout << "\n 2. display free slots ";
        cout << "\n 3. book an appointment";
        cout << "\n 4. cancel an appointment ";
        cout << "\n 5. sort slotes based on time ";
        cout << "\n 6.exit ";
        cout << "\nenter your choice";
        cin >> ch;
        switch (ch)
        {
        case 1:
            A1.createshed();
            break;
        case 2:
            A1.displayshed();
            break;
        case 3:
            A1.bookapp();
            break;
        case 4:
            A1.cancelapp();
            break;
        case 5:
            A1.sortapp();
            break;
        case 6:
            exit(0);
            break;
        }
    } while (ch != 6);
}

void appschedule ::createshed()
{
    int i ;
    struct node *temp, *last;
    head =NULL;
    cout<<"\nHow many appointment slots:=";
    cin>>size;
    for(i=0;i<size;i++) 
    {
        temp = new(struct node);
        cout<<"\n enter start time :";
        cin>>temp->start;
        cout<<"\n enter end duration :";
        cin>>temp->end;
        cout<<"\n enter minimum duration :";
        cin>>temp->min;
        cout<<"\n enter maximum duration :";
        cin>>temp->max;
        
        temp->flag=0;
        temp->next=NULL;
        if(head==NULL)
        {
            head = temp;
            last = head;

        }
        else{

            last->next = temp;
            last = last->next;

        }

    }
}

void appschedule ::displayshed()
{
    int cnt=1;
    struct node *temp ;
    cout<<"\n**appointment schedule**";
    cout<<"\n srno.\tstart\tend\tmindur\tmax\tstatus";
    temp=head;
    while(temp !=NULL ){
        cout<<"\n"<<cnt;
        cout<<"\t"<<temp->start;
        cout<<"\t"<<temp->end;
        cout<<"\t"<<temp->min;
        cout<<"\t"<<temp->max;

        if(temp->flag)
            cout<<"\t-booked-";
        else
            cout<<"\t--free--";

        temp= temp->next;
        cnt++;


    }
}
void appschedule::bookapp()
{
    int start;
    struct node *temp;

    cout<<"\n please enter appointment time";
    cin>>start;
    temp=head;
    while(temp != NULL)
    {
        if(start==temp->start)
        {
            if(temp->flag==0)
            {
                cout<<"\n Appointment slot is booked !!!";
                temp->flag=1;

            }
            else 
                cout<<"\n appointment slot is not available!!!";

        }
        temp=temp->next;
    }
}
void appschedule::cancelapp()
{
    int start;
    struct node *temp;
    cout<<"\n pleaseenter appointment time to cancel :";
    cin>>start;
    temp=head;

    while(temp !=NULL)
    {
        if(start ==temp->start)
        {
            if(temp->flag==1)
            {
                cout<<" your appointment is cancelled";
                temp->flag=0;
            }
            else
                cout<<"\n your appointment was not booked !!! ";
        }
        temp=temp->next;
    }

}

void appschedule::sortapp(){
    int i,j,val;
    struct node *temp;
    for(i=0;i<size-1;i++){
        temp=head;
        while(temp->next !=NULL)
        {
            if(temp->start>temp->next->start){
                val=temp->start;
            temp->start=temp->start;
            temp->next->start=val;

                 val=temp->end;
            temp->end=temp->next->end;
            temp->next->end=val;

                val=temp->min;
            temp->min=temp->next->min;
            temp->next->min=val;

                val=temp->max;
            temp->max = temp->next->max;
            temp->next->max=val;

            }
            temp=temp->next;
        }
    }
    cout<<"\n The appointments got sorted !!! ";
}