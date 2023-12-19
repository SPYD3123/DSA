#include <iostream>
#include <stdexcept>
using namespace std;

class StackEmpty : public runtime_error
{
public:
    StackEmpty(const string &err) : runtime_error(err) {}
};

class StackFull : public runtime_error
{
public:
    StackFull(const string &err) : runtime_error(err) {}
};

template <typename T>
class Arrstack
{
    enum
    {
        DEF_CAPACITY = 100
    };

public:
    Arrstack(int cap = DEF_CAPACITY);
    int size() const;
    bool empty() const;
    const T &top() const throw(StackEmpty);
    void push(const T &e) throw(StackFull);
    T pop() throw(StackEmpty);
    void display();
    void display(int a);
    void clear();
    void reverse();
    T *s;
    int capacity;
    int t;
};

template <typename T>
Arrstack<T>::Arrstack(int cap) : s(new T[cap]), capacity(cap), t(-1){};

template <typename T>
int Arrstack<T>::size() const
{
    return t + 1;
}

template <typename T>
bool Arrstack<T>::empty() const
{
    return (t < 0);
}

template <typename T>
const T &Arrstack<T>::top() const throw(StackEmpty)
{
    if (empty())
    {
        throw StackEmpty("TOP OF THE EMTPY STACK");
    }
    else
    {
        return s[t];
    }
}
template <typename T>
void Arrstack<T>::push(const T &e) throw(StackFull)
{
    if (size() == capacity)
    {
        throw StackFull("push to full stack");
    }
    else
    {
        s[++t] = e;
    }
}
template <typename T>
T Arrstack<T>::pop() throw(StackEmpty)
{
    if (empty())
    {
        throw StackEmpty("pop from empty stack");
    }
    else
    {
        return s[t--];
    }
}

template <typename T>
void Arrstack<T>::display()
{
    int a = 0;
    while (a <= t)
    {
        cout << s[a++] << " ";
    }
}

template <typename T>
void Arrstack<T>::display(int b)
{
    int a = 0;
    while (a <= t)
    {
        cout << s[a++];
    }
}

template <typename T>
void Arrstack<T>::clear()
{
    while (t > -1)
    {
        pop();
    }
}
template <typename T>
void Arrstack<T>::reverse()
{
    int copy = t;
    int i = 0;
    while (i < copy)
    {
        T temp = s[i];
        s[i++] = s[copy];
        s[copy--] = temp;
    }
}

void addtwonumbers()
{
    Arrstack<int> a;
    Arrstack<int> b;
    string num1;
    cout << "Enter your num1 ";
    getline(cin, num1);
    int m = num1.size();
    char *n1 = &num1[0];
    string num2;
    cout << "Enter your num2 ";
    getline(cin, num2);
    int n = num2.size();
    char *n2 = &num2[0];
    int i = 0;
    while (i < m)
    {
        if (isdigit(n1[i]))
        {
            a.push(int(n1[i] - '0'));
        }
        i++;
    }
    int j = 0;
    while (j < n)
    {
        if (isdigit(n2[j]))
        {
            b.push(int(n2[j] - '0'));
        }
        j++;
    }
    Arrstack<int> ans;
    int carry = 0;

    while (!a.empty() || !b.empty() || carry)
    {
        int num1 = (!a.empty()) ? a.pop() : 0;
        int num2 = (!b.empty()) ? b.pop() : 0;
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        ans.push(sum % 10);
    }

    cout << "Sum of the two numbers is: ";
    ans.reverse();
    ans.display(1);
    cout<<endl;
}

int main()
{
    Arrstack <int> z;
    int choice;
    do
    {
        cout << "Menu:" << endl;
        cout << "1. Reverse a Stack" << endl;
        cout << "2. Add Two Large Numbers" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice== 1){
            int n;
            cout << "Enter the number of elements in the stack: ";
            cin >> n;
            cout << "Enter elements of the stack: ";
            for (int i = 0; i < n; ++i)
            {
                int element;
                cin >> element;
                z.push(element);
            }
            cout<<"Orignal stack "<<endl;
            z.display();
            z.reverse();
            cout<<endl;
            cout << "reversed stack" << endl;
            z.display();
            cout<<endl;
        }
        else if (choice==2)
        {
            addtwonumbers();
        }
            
        else if (choice==3)
        {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }

        else{
            cout << "Invalid choice. Please try again." << endl;
        }
            
        
    } while (choice != 3);
}
