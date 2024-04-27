#include<iostream>
#include<string>
using namespace std;
#define MAX 100
class Stack
{
    private:
    int top,data[MAX];
    public:
    Stack()
    {
        top= -1;
    }
    bool isempty();
    bool isfull();
    void push(int val);
    int pop();
    int peek();
    
};
bool Stack::isempty()
{
    return top == -1;
}
bool Stack::isfull()
{
    return top== MAX-1;
}
void Stack::push(int val)
{
    if(isfull())
    {
        cout<<"stack full"<<endl;
    }
    else
    {
        data[++top]=val;
    }
}
int Stack::pop()
{
    if(isempty())
    {
        cout<<"stack empty"<<endl;
        return -1;
    }
    else
    {
        return data[top--];
    }
}
int Stack::peek()
{
    if(isempty())
    {
        cout<<"stack empty"<<endl;
        return -1;
    }
    else
    {
        return data[top];
    }
}

bool isoperator(char ch)
{
    return ch=='+' || ch=='-' || ch=='*' || ch=='/';
}

int getpresedence(char ch)
{
    if(ch=='-' || ch=='+')
    {
        return 1;
    }
    else if(ch=='*' || ch=='/')
    {
        return 2;
    }
    return 0;
}
string infixtopostfix(string infix)
{
    string postfix;
    Stack op;
    for(char ch: infix)
    {
        if(isalnum(ch))
        {
            postfix += ch;
        }
        else if(ch== '(')
        {
            op.push(ch);
        }
        else if(ch== ')')
        {
            while(!op.isempty() && op.peek()!= '(')
            {
                postfix += op.pop();
            }
            op.pop();
        }
        else if(isoperator(ch))
        {
            while(!op.isempty() && op.peek() != '(' && getpresedence(op.peek()) >= getpresedence(ch) )
            {
                postfix += op.pop();
            }
            op.push(ch);
        }
    }
    while(!op.isempty())
    {
        postfix += op.pop();
    }
    return postfix;
}
int evaluatepostfix(string postfix)
{
    Stack op;
    for(char ch : postfix)
    {
        if(isalnum(ch))
        {
            op.push(ch -'0');
        }
        else if(isoperator(ch))
        {
            int op2=op.pop();
            int op1=op.pop();
            switch(ch)
            {
                case '+':
                    op.push(op1 + op2);
                    break;
                case '-':
                    op.push(op1 - op2);
                    break;
                case '*':
                    op.push(op1 * op2);
                    break;
                case '/':
                    op.push(op1 / op2);
                    break;
            }
        }
    }
    return op.pop();
}
int main()
{
    string infixex;
    cout << "Enter the infix expression: ";
    getline(cin, infixex);

    // Convert infix to postfix
    string postfixExpression = infixtopostfix(infixex);
    cout << "Postfix expression: " << postfixExpression << endl;

    // Evaluate the postfix expression
    int result = evaluatepostfix(postfixExpression);
    cout << "Result of the expression: " << result << endl;

    return 0;
    // 3+4*2/(1-5)
}