/*A palindrome is a string of character thats the same forward and
backward. Typically, punctuation, capitalization, and spaces are
ignored. For example, “Poor Dan is in a droop” is a palindrome, as
can be seen by examining the characters “poor danisina droop” and
observing that they are the same forward and backward. One way to
check for a palindrome is to reverse the characters in the string and
then compare with them the original-in a palindrome, the sequence
will be identical. Write C++ program with functionsa) To print
original string followed by reversed string using stack b) To check
whether given string is palindrome or not*/
#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;

#define MAX 100
class Stack
{
private:
    int top;
    char str[MAX];
    char rev[MAX];

public:
    Stack()
    {
        top = -1;
    }
    void push(char ch);
    char pop();
    bool isempty();
    bool isfull();
    string reverse();
    bool ispalindrome();
    string original();
};

void Stack::push(char ch)
{
    if (!isfull())
    {
        if(isalnum(ch))
        {
            str[++top] = ch; 
        }
    }
    else
    {
        cout << "Stack Overflow";
    }
}
char Stack::pop()
{
    char ch;
    if (!isempty())
    {
        ch = str[top--];
        cout<<ch<<"pushed"<<endl;
        return ch;
    }
    else
    {
        cout << "Stack Underflow";
        return '\0';
    }
}
bool Stack::isempty()
{
    return top == -1;
}
bool Stack::isfull()
{
    return top == (MAX - 1);
}
string Stack::reverse()
{
    int i = 0;
    while (!isempty())
    {
        rev[i] = pop();
        i++;
        rev[i]='\0';
    }
    
    return rev;
}
string Stack::original()
{
    return str;
}
bool Stack::ispalindrome()
{
    
    return strcmp(str, rev) == 0;
}

int main()
{
    Stack S;
    char str[MAX];
    cout << "Enter the string: ";
    cin.getline(str, MAX);
    for (int i=0;i < strlen(str); i++)
    {
        if (str[i] == '\0')
            break;
        S.push(str[i]);
    }

    cout << "The Original string is: " << S.original()<< endl;
    cout << "The Reversed string is: " << S.reverse() << endl;
    
    if (S.ispalindrome())
        cout << "The String is Palindrome." << endl;
    else
        cout << "The String is not Palindrome." << endl;
}
