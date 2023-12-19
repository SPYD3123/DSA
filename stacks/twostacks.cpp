#include <iostream>
#include <math.h>

using namespace std;

template<class T,int size>
class arrstack
{
private:
    int top1,top2;
    T* nums = new T[size];
public:
    arrstack(){
        top1=-1;
        top2=size/2-1;
    }
    ~arrstack(){
        delete nums;
    }
    void pushStack1(T el){
        if (top1+1==size/2)
        {
            cout<<"No space in Stack 1"<<endl;
            return;
        }
        nums[++top1] = el;
    }
    void pushStack2(T el){
        if (top2+1==size)
        {
            cout<<"No space in Stack 2"<<endl;
            return;
        }
        nums[++top2] = el;
    }
    const T popStack1(){
        if (top1==-1)
        {
            cout<<"Empty Stack 1"<<endl;
            return -1;
        }
        return nums[top1--];
    }
    const T popStack2(){
        if (top2==size/2-1)
        {
            cout<<"Empty Stack 2"<<endl;
            return -1;
        }
        return nums[top2--];
    }
    void displayStack1(){
        for (int i = 0; i <= top1; i++)
        {
            cout<<nums[i]<<" ";            
        }
        cout<<endl;
    }
    void displayStack2(){
        for (int i = size/2; i <= top2; i++)
        {
            cout<<nums[i]<<" ";            
        }
        cout<<endl;
    }
    void menu() {
        int choice;
        T element;

        do {
            cout << "Array Stack Menu:" << endl;
            cout << "1. Push to Stack 1" << endl;
            cout << "2. Push to Stack 2" << endl;
            cout << "3. Pop from Stack 1" << endl;
            cout << "4. Pop from Stack 2" << endl;
            cout << "5. Display Stack 1" << endl;
            cout << "6. Display Stack 2" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter element to push to Stack 1: ";
                    cin >> element;
                    pushStack1(element);
                    break;
                case 2:
                    cout << "Enter element to push to Stack 2: ";
                    cin >> element;
                    pushStack2(element);
                    break;
                case 3:
                    cout << "Popped from Stack 1: " << popStack1() << endl;
                    break;
                case 4:
                    cout << "Popped from Stack 2: " << popStack2() << endl;
                    break;
                case 5:
                    cout << "Stack 1: ";
                    displayStack1();
                    break;
                case 6:
                    cout << "Stack 2: ";
                    displayStack2();
                    break;
                case 0:
                    cout << "Exiting the menu." << endl;
                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
                    break;
            }
        } while (choice != 0);
    }
};

int main(int argc, char const *argv[])
{
    arrstack<int,100> x;
    x.menu();
    return 0;
}
