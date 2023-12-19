#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int el, Node *ptr = NULL)
    {
        next = ptr;
        value = el;
    }
};

class Linkedlist
{
private:
    Node *head;

public:
    Linkedlist()
    {
        head = NULL;
    }
    bool isempty()
    {
        return head == NULL;
    }
    void addelement(int el);
    void delete_element(int el);
    void display()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->value << " ";
            ptr = ptr->next;
        }
    }
};

void Linkedlist::addelement(int el)
{
    if (isempty() || el < head->value)
    {
        head = new Node(el, head);
    }
    else
    {
        Node *current = head;
        while (current->next != NULL && current->next->value < el)
        {
            current = current->next;
        }

        current->next = new Node(el, current->next);
    }
}
void Linkedlist::delete_element(int el)
{
    if (head != NULL)
    {
        if (head->next == NULL && head->value == el)
        {
            delete head;
            head = NULL;
        }
        else if (head->value == el)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL && temp->next->value != el)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "Element not found";
            }
            else
            {
                Node *temp2 = temp->next->next;
                delete temp->next;
                temp->next = temp2;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    Linkedlist l1;
    l1.addelement(5);
    l1.addelement(2);
    l1.addelement(9);
    l1.addelement(199);
    l1.addelement(7);
    l1.display();
    cout << endl;
    l1.delete_element(7);

    l1.delete_element(199);
    l1.delete_element(2);
    l1.display();
    return 0;
}