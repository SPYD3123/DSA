#include <iostream>
#include <stdexcept>
using namespace std;


class StackEmpty : public runtime_error {
    public:
    StackEmpty(const string &err): runtime_error(err){}
};

class StackFull : public runtime_error {
    public:
    StackFull(const string &err): runtime_error(err){}
};

template <typename T>
class Arrstack
{
    enum{DEF_CAPACITY=100};
public:
    Arrstack(int cap=DEF_CAPACITY);
    int size() const;
    bool empty() const;
    const T &top() const throw(StackEmpty);
    void push(const T& e ) throw(StackFull);
    void pop() throw(StackEmpty);
    void display();
    void clear();
    void copy(const Arrstack &x);
    void operator=(const Arrstack &x);

    T *s;
    int capacity;
    int t;
};

template <typename T>
Arrstack<T> :: Arrstack(int cap): s(new T[cap]), capacity(cap),t(-1){};

template <typename T>
int Arrstack<T> :: size() const{
    return t+1;
}

template <typename T>
bool Arrstack<T> :: empty() const{
    return (t<0);
}

template <typename T>
const T & Arrstack<T>:: top() const throw(StackEmpty){
    if (empty())
    {
        throw StackEmpty("TOP OF THE EMTPY STACK");
    }
    else{
        return s[t];
    }
    
}
template <typename T>
void Arrstack<T>::push(const T& e ) throw(StackFull){
    if (size()==capacity)
    {
        throw StackFull("push to full stack");
    }
    else{
        s[++t]=e;
    }
    
}
template <typename T>
void Arrstack<T>::pop() throw(StackEmpty){
    if (empty())
    {
        throw StackEmpty("pop from empty stack");
    }
    else{
        --t;
    }
    
}

template <typename T>
void Arrstack<T>::display(){
    int a=0;
    while (a<=t)
    {
        cout<<s[a++]<<" ";
    }
    
}

template <typename T>
void Arrstack<T>::clear(){
    while (t>-1)
    {
        pop();
    }
    
}

template <typename T>
void Arrstack<T>::copy(const Arrstack &x){
    clear();
    int index = 0;
     while (x.t >= index)
    {
        push(x.s[index++]);
    }

}

template <typename T>
void Arrstack<T>::operator=(const Arrstack &x){
    copy(x);
}



#include <iostream>
#include <stdexcept>
using namespace std;

// ... StackEmpty, StackFull, and Arrstack class definitions here ...

int main() {
    int capacity_a1, capacity_a2, capacity_myStack;

    cout << "Enter the capacity of stack a1: ";
    cin >> capacity_a1;
    Arrstack<int> a1(capacity_a1);

    cout << "Enter the capacity of stack a2: ";
    cin >> capacity_a2;
    Arrstack<int> a2(capacity_a2);

    cout << "Enter the capacity of myStack: ";
    cin >> capacity_myStack;
    Arrstack<int> myStack(capacity_myStack);

    int choice;

    try {
        while (true) {
            cout << "Menu:" << endl;
            cout << "1. Push element to myStack" << endl;
            cout << "2. Pop element from myStack" << endl;
            cout << "3. Display myStack" << endl;
            cout << "4. Clear myStack" << endl;
            cout << "5. Copy to myStack from a1" << endl;
            cout << "6. Assign a2 to mystack" << endl;
            cout << "7. Exit" << endl;
            cout << "Enter your choice: ";

            cin >> choice;

            if (choice == 1) {
                int element;
                cout << "Enter element to push: ";
                cin >> element;
                myStack.push(element);
                cout << "Pushed element: " << element << endl;
            } else if (choice == 2) {
                myStack.pop();
                cout << "Popped element" << endl;
            } else if (choice == 3) {
                cout << "myStack: ";
                myStack.display();
                cout << endl;
            } else if (choice == 4) {
                myStack.clear();
                cout << "myStack cleared" << endl;
            } else if (choice == 5) {
                int ab;
                while (ab!=1)
                {
                    int element;
                    cout << "Enter element to push to a1: ";
                    cin >> element;
                    a1.push(element);
                    cout<<"want to enter more in stack a1? 1 for no else any number";
                    cin>>ab;
                }
                
                
                myStack.copy(a1);
                cout << "Copied from a1 to myStack" << endl;
            } else if (choice == 6) {
                int cd=0;
                while (cd!=1)
                {
                    int element;
                    cout << "Enter element to push to a2: ";
                    cin >> element;
                    a2.push(element);
                    cout<<"want to enter more in stack a1? 1 for no else any number";
                    cin>>cd;
                }
                myStack=a2;
                cout << "Assigned a2 to mystack" << endl;
            } else if (choice == 7) {
                break;  
            } else {
                cout << "Invalid choice. Try again." << endl;
            }
        }
    } catch (const StackEmpty& e) {
        cerr << "StackEmpty Exception: " << e.what() << endl;
    } catch (const StackFull& e) {
        cerr << "StackFull Exception: " << e.what() << endl;
    }

    return 0;
}
