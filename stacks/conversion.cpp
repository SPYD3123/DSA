#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class Stack
{
private:
    int t;
    int cap;
    char *s;
public:
    Stack(int capp=100);
    bool empty() const{
        return t<0;
    }
    const char & top() const{
        return s[t];
    }
    int size() const{
        return t+1;
    }
    void push(char el){
        s[++t]=el;
    }
    void pop(){
        --t;
    }
    void display(){
        for (int i = 0; i < size(); i++)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
        
    }
};

Stack::Stack(int capp)
{
    cap=capp;
    t=-1;
    s=new char[cap];
}


int prec(char x){
    if (x=='^')
    {
        return 3;
    }
    else if (x=='*'|| x=='/')
    {
        return 2;
    }
    else if (x=='+'||x=='-')
    {
        return 1;
    }
    else{
        return -1;
    }
    
    
    
}
int main(int argc, char const *argv[])
{
    Stack a;
    char *m=new char[100];
    cout<<"Enter the delimeter expression";
    cin>> m;
    for (int i = 0;m[i]!='\0'; i++)
    {
     if (m[i]=='(')
     {
        a.push(m[i]);
     }
     else if (m[i]=='+'||m[i]=='-' || m[i]=='*'||m[i]=='/'||m[i]=='^')
     {
        while (!a.empty() && prec(a.top())>=prec(m[i]))
        {
            cout<<a.top();
            a.pop();
        }
        a.push(m[i]);
        
     }
     else if (m[i]==')')
     {
        while (!a.empty() && a.top()!='(')
        {
            cout<<a.top();
            a.pop();
        }
        if (!a.empty())
        {
            a.pop();
        }
     }
     else if ((m[i]>='a' && m[i]<='z' )|| (m[i]>='A' && m[i]<='Z'))
     {
        cout<<m[i];
     }
        
    }
    while (!a.empty()) 
    {
        cout<<a.top();
        a.pop();
    }
    
    
    
    return 0;
}

