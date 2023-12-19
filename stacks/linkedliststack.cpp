#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};
template <class T>
class LinkedListStack
{
private:
    Node<T> *top;

public:
    LinkedListStack()
    {
        top = nullptr;
    }
    void push(T el)
    {
        Node<T> *newNode = new Node<T>(el);
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if (top != nullptr)
        {
            Node<T> *temp = top;
            top = top->next;
            delete temp;
        }
        else
        {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }
    void reverse()
    {
        Node<T> *prev = nullptr;
        Node<T> *current = top;
        Node<T> *next = nullptr;
        while (current != nullptr)
        {

            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        top = prev;
    }
    void clear()
    {
        while (top != nullptr)
        {
            Node<T> *temp = top;
            top = top->next;
            delete temp;
        }
    }
    void display()
    {
        Node<T> *current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    ~LinkedListStack()
    {
        clear();
    }
};
int main(int argc, char const *argv[])
{
    LinkedListStack<int> stack;
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Reverse stack\n"; // Added option for reversing the stack
        cout << "4. Clear stack\n";
        cout << "5. Display stack\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int element;
            cout << "Enter element to push: ";
            cin >> element;

            stack.push(element);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.reverse();
            cout << "Stack reversed successfully." << endl;
            break;
        case 4:
            stack.clear();
            break;
        case 5:
            stack.display();
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}