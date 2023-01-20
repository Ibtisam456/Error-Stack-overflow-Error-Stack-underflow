#include <iostream>
#include <stack>
#include <string>

using namespace std;


class Stack
{
private:
    
    int *arr;

    int size;

    int top;

public:
    
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (top == size - 1)
        {
            cout << "Error: Stack overflow" << endl;
            return;
        }

        arr[++top] = element;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Error: Stack underflow" << endl;
            return;
        }

        top--;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Error: Stack is empty" << endl;
            return INT_MIN;
        }

        return arr[top];
    }

    bool is_empty()
    {
        return top == -1;
    }
};

string infixToPostfix(string infix)
{
    
    Stack s(infix.length());

    string postfix = "";

    for (char ch : infix)
    {

        if (isdigit(ch))
            postfix += ch;

        else if (ch == '(')
            s.push(ch);

        else if (ch == ')')
        {
            while (s.peek() != '(')
            {
                postfix += s.peek();
                s.pop();
            }

            s.pop();
        }

        else
        {
            while (!s.is_empty() && (s.peek() == '*' || s.peek() == '/' || s.peek() == '+' || s.peek() == '-') && (s.peek() == '*' || s.))
                        {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main()
{
  
    cout << infixToPostfix("2 + 3 * 4") << endl; 
    cout << infixToPostfix("(2 + 3) * 4") << endl; 
    cout << infixToPostfix("2 * 3 + 4") << endl; 
    cout << infixToPostfix("2 / (3 - 4)") << endl; 

    return 0;
}

