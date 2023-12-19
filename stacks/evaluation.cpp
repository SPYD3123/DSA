#include <iostream>
#include <sstream>
#include <typeinfo>
#include <math.h>

using namespace std;

template <class U, int size>
class CustomStack
{
private:
public:
    int elements[size] = {0};
    int top = -1;
    int *nums = elements;

    CustomStack();
    void push(U el);
    U pop();
    void clear();
    void display();
    ~CustomStack();
};

template <class U, int size>
CustomStack<U, size>::CustomStack() {}

template <class U, int size>
CustomStack<U, size>::~CustomStack() 
{
    delete[] nums;
}

template <class U, int size>
void CustomStack<U, size>::clear() 
{
    while (top > -1)
    {
        top--;
    }
}

template <class U, int size>
void CustomStack<U, size>::push(U el) 
{
    if (top + 1 < sizeof(elements) / sizeof(int))
    {
        elements[++top] = el;
    }
}

template <class U, int size>
void CustomStack<U, size>::display() 
{
    int index = 0;
    while (index <= top)
    {
        cout << elements[index++] << " ";
    }
    cout << endl;
}

template <class U, int size>
U CustomStack<U, size>::pop() 
{
    return elements[top--];
}

int main(int argc, char const *argv[]) 
{
    CustomStack<int, 50> s;
    string expression;
    getline(cin, expression);

    for (int i = 0; i < expression.size(); i++) 
    {
        if (isdigit(expression.at(i)))
        {
            int num = 0;
            while (isdigit(expression.at(i))) 
            {
                num = num * 10 + (int)(expression.at(i) - '0');
                i++;
            }
            s.push(num);
        }
        else if (expression.at(i) == '+') 
        {
            int op1 = s.pop();
            int op2 = s.pop();
            s.push(op1 + op2);
        }
        else if (expression.at(i) == '-') 
        {
            int op1 = s.pop();
            int op2 = s.pop();
            s.push(op2 - op1);
        }
        else if (expression.at(i) == '*') 
        {
            int op1 = s.pop();
            int op2 = s.pop();
            s.push(op1 * op2);
        }
        else if (expression.at(i) == '/') 
        {
            int op1 = s.pop();
            int op2 = s.pop();
            s.push(op2 / op1);
        }
        else if (expression.at(i) == '^') 
        {
            int op1 = s.pop();
            int op2 = s.pop();
            s.push(pow(op2, op1));
        }
        else if (expression.at(i) == ' ') 
        {
            continue;
        }
    }
    s.display();
    return 0;
}
