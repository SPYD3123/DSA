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

int main(int argc, char const *argv[])
{
    Stack a;
    char *m=new char[100];
    cout<<"Enter the delimeter expression";
    cin>> m;
    for (int i = 0;m[i]!='\0'; i++)
    {
        if (m[i]=='{'||m[i]=='[' || m[i]=='(' || m[i]=='<')
        {
            a.push(m[i]);
        }
        else if ((a.top()=='{'&& m[i]=='}')||(a.top()=='('&& m[i]==')')||(a.top()=='['&& m[i]==']')||(a.top()=='<'&& m[i]=='>'))
        {
            a.pop();
        }
        
        
    }
    if (a.empty())
    {
        cout<<"Correct";
    }
    else{
        cout<<"Incorrect";
    }
    
    
    return 0;
}

