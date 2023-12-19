#include <iostream>

using namespace std;

template <class T>
class node
{
public:
    T info;
    node<T> *next;
    node(T el, node<T> *ptr = NULL)
    {
        info = el;
        next = ptr;
    }
};

template <class T>
class Cirlist
{
private:
    node<T> *back;

public:
    Cirlist()
    {
        back = NULL;
    }

    ~Cirlist();

    bool isempty()
    {
        return (back == NULL);
    }

    void add_front(T el)
    {
        if (isempty())
        {
            back = new node<T>(el);
            back->next = back;
        }
        else
        {
            back->next = new node<T>(el, back->next);
        }
    }

    void add_back(T el)
    {
        if (isempty())
        {
            back = new node<T>(el);
            back->next = back;
        }
        else
        {
            back->next = new node<T>(el, back->next);
            back = back->next;
        }
    }

    T delete_front()
    {
        node<T> *temp = back->next;
        T el = temp->info;

        if (back->next == back)
        {
            back = NULL;
        }
        else
        {
            back->next = temp->next;
        }

        delete temp;
        return el;
    }

    T delete_back()
    {
        T el = back->info;

        if (back->next == back)
        {
            delete back;
            back = NULL;
        }
        else
        {
            node<T> *temp = back->next;

            for (; temp->next != back; temp = temp->next)
                ;

            temp->next = back->next;

            delete back;
            back = temp;
        }

        return el;
    }

    void delete_node(T el)
    {
        if (back != NULL)
        {
            if (back == back->next && el == back->info)
            {
                delete back;
                back = NULL;
            }
            else if (el == back->next->info)
            {
                node<T> *temp = back->next;
                back->next = temp->next;
                delete temp;
            }
            else
            {
                node<T> *pred, *temp;

                for (pred = back->next, temp = pred->next; temp != back->next && !(temp->info == el);
                     pred = pred->next, temp = temp->next)
                    ;

                if (temp != back->next)
                {
                    pred->next = temp->next;

                    if (temp == back)
                    {
                        back = pred;
                    }
                    delete temp;
                }
            }
        }
    }

    void reverse()
    {
        if (isempty())
        {
            return;
        }

        node<T> *q, *r, *s, *last;

        last = q = back->next;
        back->next = NULL;
        r = NULL;

        do
        {
            s = r;
            r = q;
            q = q->next;

            r->next = s;
            last->next = r;
        } while (q != NULL);

        back = last;
    }

    bool search(T el)
    {
        node<T> *temp = back;
        for (node<T> *p = back; p != NULL; p = p->next)
        {
            if (p->info == el)
            {
                temp = p;
                break;
            }
        }
        return temp;
    }

int count_node()
        {
            int count = 0;
            node<T> *p = back -> next;

            do
            {
                count++;
                p = p -> next;
            }
            while(p != back -> next);
            return count;
        }

    void display()
    {
        node<T> *j = back->next;

        do
        {
            cout << j->info << " ";
            j = j->next;

            cout << " ";
        } while (j != back->next);

        cout << endl;
        return;
    }
    void add_position(T el, T aftervalue)
    {
        if (isempty())
        {
            cout << "List is empty. Cannot insert after element " << aftervalue << "." << endl;
            return;
        }

        node<T> *a = back->next;
        bool check = false;

        do
        {
            if (a->info == aftervalue)
            {
                node<T> *temp = new node<T>(el);
                temp->next = a->next;
                a->next = temp;
                check = true;
                break;
            }
            a = a->next;
        } while (a != back->next);

        if (!check)
        {
            cout << "Element " << aftervalue << " not found in the list. Cannot insert after it." << endl;
        }
    }

Cirlist<T> concat(const Cirlist<T>& B) {
        Cirlist<T> result;

        node<T>* current = back->next;
        do {
            result.add_back(current->info);
            current = current->next;
        } while (current != back->next);

         current = B.back->next;
        do {
            result.add_back(current->info);
            current = current->next;
        } while (current != B.back->next);

    return result;
}


};

template <class T>
Cirlist<T>::~Cirlist()
{
    node<T> *p, *q;
    p = back->next;
    while (!(p == back))
    {
        q = p;
        p = p->next;
        delete q;
    }
    delete back;
}


int main()
{
    Cirlist<int> l1;
    Cirlist<int> l2;

    int choice;
    int value, afterValue;

    while (true)
    {
        cout << "\nCircular Linked List Menu:" << endl;
        cout << "1. Add Element to Front" << endl;
        cout << "2. Add Element to Back" << endl;
        cout << "3. Add Element to 3rd Position" << endl;
        cout << "4. Delete Front Element" << endl;
        cout << "5. Delete Back Element" << endl;
        cout << "6. Delete Specific Element" << endl;
        cout << "7. Search Element" << endl;
        cout << "8. Count Nodes" << endl;
        cout << "9. Reverse List" << endl;
        cout << "10. Display List" << endl;
        cout << "11. Concatenate Lists" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter element to add to front: ";
            cin >> value;
            l1.add_front(value);
            cout<<"Added to front "<<endl;
        }
        else if (choice == 2)
        {
            cout << "Enter element to add to back: ";
            cin >> value;
            l1.add_back(value);
            cout<<"Added to back "<<endl;
        }
        else if (choice == 3)
        {
            cout << "Enter element to add: ";
            cin >> value;
            cout << "Enter element after which to add: ";
            cin >> afterValue;
            l1.add_position(value, afterValue);
            cout<<"element added next to the value you entered "<<endl;
        }
        else if (choice == 4)
        {
            if (!l1.isempty())
            {
                int deleted = l1.delete_front();
                cout << "Deleted element from front: " << deleted << endl;
            }
            else
            {
                cout << "List is empty." << endl;
            }
        }
        else if (choice == 5)
        {
            if (!l1.isempty())
            {
                int deleted = l1.delete_back();
                cout << "Deleted element from back: " << deleted << endl;
            }
            else
            {
                cout << "List is empty." << endl;
            }
        }
        else if (choice == 6)
        {
            cout << "Enter element to delete: ";
            cin >> value;
            l1.delete_node(value);
            cout<<"Node deleted"<<endl;
        }
        else if (choice == 7)
        {
            cout << "Enter element to search: ";
            cin >> value;
            if (l1.search(value))
            {
                cout << "Element found in the list." << endl;
            }
            else
            {
                cout << "Element not found in the list." << endl;
            }
        }
        else if (choice == 8)
        {
            cout << "Number of nodes in the list: " << l1.count_node() << endl;
        }
        else if (choice == 9)
        {
            l1.reverse();
            cout << "List reversed." << endl;
            l1.display();
        }
        else if (choice == 10)
        {
            cout << "Elements in the list: ";
            l1.display();
        }
        else if (choice == 11)
        {
            cout << "Enter the number of values for the second list: ";
            cin >> value;
            for (int i = 0; i < value; i++)
            {
                int val;
                cout << "Enter " << i + 1 << "st element for the second list: ";
                cin >> val;
                l2.add_back(val);
            }

            Cirlist<int> concatenated = l1.concat(l2);
            cout << "Concatenated List: ";
            concatenated.display();
            cout << "\n";
        }
        else if (choice == 0)
        {
            cout << "Exiting the program." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
