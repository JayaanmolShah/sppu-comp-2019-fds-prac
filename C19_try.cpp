/*
Department of Computer Engineering has student's club named 
'Pinnacle Club'. Students of second, third and final year of department 
can be granted membership on request. Similarly one may cancel the 
membership of club. First node is reserved for president of club and 
last node is reserved for secretary of club. Write C++ program to 
maintain club members information using singly linked list. Store 
student PRN and Name. Write functions to: 
a) Add and delete the members as well as president or even secretary. 
b) Compute total number of members of club 
c) Display members 
d) Two linked lists exists for two divisions. Concatenate two lists.
*/
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
class list;
class node
{
    int prn;
    string name;
    node* next;
    public:
        node(int pr,string n)
        {
            prn=pr;
            name=n;
            next=NULL;   
        }
        friend class list;
};

class list
{
    node* start;
    int president_prn=0,secretary_prn=0;
    public:
        list()
        {
            start=NULL;
        }
        void create();
        void display();
        void AddAtBegin();
        void AddAtEnd();
        void AddAfter();
        void DeleteFirst();
        void DeleteLast();
        void DeleteByValue();
        void ComputeTotal();
        void concatenate(list &l);
};

void list::create()
{
    int p;
    string n;
    if(start==NULL)
    {
        cout<<"Enter President's Information"<<endl;
        cout<<"Enter PRN: "<<endl;
        cin>>p;
        president_prn=p;
        cout<<"Enter Name: "<<endl;
        cin>>n;
        start=new node(p,n);
        cout<<"Club created"<<endl;
        cout<<"President's Information Inserted."<<endl;
    }
    else
    {
        cout<<"Club has already been created"<<endl;
    }
}

void list::display()
{
    node *temp=start;
    if(start==NULL)
    {
        cout<<"The Club has no members"<<endl;
    }
    else
    {
        if(president_prn!=0)
        {
            cout<<"President: "<<"PRN: "<<temp->prn<<" NAME: "<<temp->name<<endl;
            temp=temp->next;
        }
        
        while(temp!=NULL)
        {
            if(secretary_prn==temp->prn)
            {
                cout<<"Secretary: "<<"PRN: "<<temp->prn<<" NAME: "<<temp->name<<endl;
                return;
            }
            cout<<"PRN: "<<temp->prn<<" NAME: "<<temp->name<<endl;
            temp=temp->next;
        }
    }
}
  
void list::AddAtBegin()
{
    int p;
    string n;
    node* temp;
    if(start==NULL)
    {
        create();
    }
    else
    {
        cout<<"Enter PRN: "<<endl;
        cin>>p;
        president_prn=p;
        cout<<"Enter Name: "<<endl;
        cin>>n;
        temp=new node(p,n);
        temp->next=start;
        start=temp;
        cout<<"President's Information Inserted."<<endl;
    }
}

void list::AddAtEnd()
{
    int p;
    string n;
    node* temp1=start;
    if(start==NULL)
        cout<<"The Club has not been created yet."<<endl;
    else
    {
        cout<<"Enter PRN: "<<endl;
        cin>>p;
        secretary_prn=p;
        cout<<"Enter Name: "<<endl;
        cin>>n;
        while(temp1->next !=NULL)
            temp1=temp1->next;
        node* temp2;
        temp2=new node(p,n);
        temp1->next=temp2;
        cout<<"Secretary's Information Inserted."<<endl;
    }
}

void list:: AddAfter()
{
    int p=-1;
    string n;
    node* temp=start;
    if(start==NULL)
        cout<<"The Club has not been created yet."<<endl;
    else
    {
        cout<<"Enter the PRN number after which you want to enter next information: "<<endl;
        cin>>p;
        if(p==secretary_prn)
        {
            cout<<"You can not insert your information afer secretary' information."<<endl;
            return;
        }
        while(temp->next!=NULL)
        {
            if(temp->prn == p)
            {
                break;
            }
            temp=temp->next;
        }
        if(p== -1)
            {
                cout<<p<<" is not in the list."<<endl;
                return;
            }
        cout<<"Enter PRN: "<<endl;
        cin>>p;
        cout<<"Enter Name: "<<endl;
        cin>>n;
        node* temp2=new node(p,n);
        temp2->next=temp->next;
        temp->next=temp2;
        cout<<"Member's Information Inserted."<<endl;
    }
    
}

void list::DeleteFirst()
{
    node* temp;
    if(start==NULL)
    {
        cout<<"Club has not been created yet."<<endl;
        return;
    }
    else
    {
        if(president_prn==0)
        {
            cout<<"There is no President's Information."<<endl;
            return;
        }
        temp=start;
        start=start->next;
        delete temp;
        president_prn=0;
        cout<<"President's Information Deleted"<<endl;
    }
}

void list::DeleteLast()
{
    node* temp=start;
    node* prev;
    if(start==NULL)
    {
        cout<<"Club has not been created yet."<<endl;
    }
    else
    {
        if(secretary_prn==0)
        {
            cout<<"There is no Secretary's Information."<<endl;
            return;
        }
        while(temp->next !=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        delete temp;
        secretary_prn=0;
        cout<<"Secretary's Information Deleted"<<endl;
    }
}

void list:: DeleteByValue()
{
    int p;
    int flag=0;
    node *prev=NULL;
    node* temp=start;
    if(start==NULL)
        cout<<"Club has not been created yet."<<endl;
    else
    {
        cout<<"Enter the PRN number of the member you want to delete: "<<endl;
        cin>>p;
        if(p==president_prn || p==secretary_prn)
        {
            cout<<"To delete president/secretray information choose 6/7"<<endl;
            return;
        }
        if(temp->prn==p)
        {
            start=temp->next;
            delete temp;
            cout<<"Member's information deleted"<<endl;
            return;
        }
        while(temp!=NULL)
        {
            if(temp->prn == p)
            {
                flag=1;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        if(flag==1)
        {
            prev->next=temp->next;
            delete temp;
            cout<<"Member's information deleted"<<endl;
        }
        else
        {
            cout<<p<<" is not a member of the club."<<endl;
        }
        
    }
    
}

void list::ComputeTotal()
{
    int count=0;
    node* temp=start;
    if(start==NULL)
    {
        cout<<"Club has not been created yet."<<endl;
        return;
    }
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    cout<<"There are "<<count<<" members in the club"<<endl;
}

void list::concatenate(list &l)
{
    if(l.start==NULL)
    {
        cout<<"The Second Club has not been created yet."<<endl;
        return;
    }
    node* temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=l.start;
    l.start=NULL;
    cout<<"After Concatenation: "<<endl;
    display();
}

int main()
{
    list *l;
    list l1,l2;
    char ch='y';
    int choice;
X:
    cout<<"1) Pinnacle Club 1"<<endl;
    cout<<"2) Pinnacle Club 2"<<endl;
    cout<<"Enter your chocie: "<<endl;
    cin>>choice;
    if(choice==1)
        l=&l1;
    else if(choice==2)
        l=&l2;
    else
    {
        cout<<"Wrong Choice"<<endl;
        goto X;
    }  
    while(ch=='y' || ch=='Y')
    {
        cout<<"1) Create Club"<<endl;
        cout<<"2) Display Members of the Club"<<endl;
        cout<<"3) Insert President's Information"<<endl;
        cout<<"4) Insert Secretary's Information"<<endl;
        cout<<"5) Insert Member's Information"<<endl;
        cout<<"6) Delete President's Information"<<endl;
        cout<<"7) Delete Secretary's Information"<<endl;
        cout<<"8) Delete Member's Information"<<endl;
        cout<<"9) Total Members of Club"<<endl;
        cout<<"10) Combine Clubs of Two Division"<<endl;
        cout<<"11) Reselect List"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        if(choice==1)
            l->create();
        if(choice==2)
            l->display();
        if(choice==3)
            l->AddAtBegin();
        if(choice==4)
            l->AddAtEnd();
        if(choice==5)
            l->AddAfter();
        if(choice==6)
            l->DeleteFirst();
        if(choice==7)
            l->DeleteLast();
        if(choice==8)
            l->DeleteByValue();
        if(choice==9)
            l->ComputeTotal();
        if(choice==10)
            l->concatenate(l2);
        if(choice==11)
            goto X;
        cout<<"enter y if you wish to continue: "<<endl;
        cin>>ch;
    }
}