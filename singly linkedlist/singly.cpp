#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T info;
    node<T> *next;
    node(T el, node<T> *a = NULL)
    {
        info = el;
        next = a;
    }
};

template <class T>
class linkedlist
{
private:
    node<T> *head;
    node<T> *tail;

public:
    linkedlist()
    {
        head = tail = NULL;
    }
    ~linkedlist();
    bool isempty()
            {
        return head == NULL;
    }
    void add_head(T el);
    void add_tail(T el);
    void insert(T el, int a);
    void del_head();
    void del_tail();
    void del_element(T el);
    T del_position(int a);
    bool search(T el){
        node<T> * temp;
        for (temp=head; temp!=NULL && !(temp->info=el); temp=temp->next);
        return(temp!=NULL);
        

    }
   linkedlist<T>  operator+(const linkedlist<T> &l1) const
    {
        linkedlist<T> ans;
        node<T> *x1 = head;
        while (x1 != NULL)
        {
            ans.add_tail(x1->info);
            x1 = x1->next;
        }

        node<T> *x2 = l1.head;
        while (x2 != NULL)
        {
            ans.add_tail(x2->info);
            x2 = x2->next;
        }

        return ans;
    }
    void operator=(const linkedlist l1)
    {
        linkedlist<int> ans;
        node<T> *x1 = head;
        while (x1 != NULL)
        {
            node<T> *temp = x1;
            x1 = x1->next;
            delete temp;
        }

        node<T> *x2 = l1.head;
        while (x2 != NULL)
        {
            add_tail(x2->info);
            x2 = x2->next;
        }
    }
    void display();
    void reverse();
    int count();
};

template <class T>
linkedlist<T>::~linkedlist()
{
    node<T> *p;
    while (!isempty())
    {
        p = head->next;
        delete head;
        head = p;
    }
}

template <class T>
void linkedlist<T>::add_head(T el)
{
    head = new node<T>(el, head); // a node made must have a value and address of next
        if (tail == NULL)        // if (head->next==NULL)
    {
        tail = head;
    }
}

template <class T>
void linkedlist<T>::add_tail(T el)
{
    if (tail != NULL)
    {
        tail->next = new node<T>(el);
        tail = tail->next;
    }
    else
    {
        head = tail = new node<T>(el);
    }
}

// template <class T>
// void linkedlist<T>::add_tail(T el){
//     if (head!=NULL)
//     {
//         node<T> *temp= new node<T>(el);
//         node<T> *n;
//         for (n=head; n->next!=NULL; n=n->next);
//         n->next=temp;
//     }
//     else{
//         head=new node<T>(el);
//     }
// }   this method is used when we dont have a tail given

template <class T>
void linkedlist<T>::del_head()
{
    if (!isempty())
    {
        node<T> *temp = head;
        head = head->next;
        if (head == NULL) // it is required because if we have only 1 value then head and tail are same
        {
            tail = NULL; // so if we delete the head then also the tail pointer will be pointing to the old value which will cause error
            // as no such area exist as head is already deleted so it is must to make tail as null before deleting head if only 1 value
        }

        delete temp;
    }
    else
    {
        cout << "empty linkedlist";
    }
}

template <class T>
void linkedlist<T>::del_tail()
{
    if (!isempty())
    {
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            node<T> *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
    }
    else
    {
        cout << "Empty linkedlist" << endl;
    }
}

/*

    <--- WHEN Tail is not provided --->>
template <class T>
void linkedlist<T>::del_tail()
{
    if (!isempty)
    {
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            node<T> *temp = head;
            for (; temp->next->next != NULL; temp = temp->next)
                ;
            delete temp->next;
            temp->next=NULL;

            // other way of doing it:-
            // for (; temp->next != NULL; temp = temp->next)
            //     ;
            // node<T> *temp2 = head;
            // for (; temp2->next != temp; temp2 = temp2->next)
            //     ;
            // temp2->next = NULL;
            // delete temp;
        }
    }
}
*/


template <class T>
void linkedlist<T>::del_element(T el)
{
    if (head !=NULL)
    {
        if (head == tail && head->info == el)
        {
            delete head;
            head = tail = NULL;
        }
        else if (el == head->info)
        {
            node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            node<T> *pred, *temp;
            pred = head;
            temp = head->next;
            while (temp != NULL && temp->info != el)
            {
                pred = pred->next;
                temp = temp->next;
            }
            if (temp != NULL)
            {
                pred->next = temp->next;
                if (temp == tail)
                {
                    tail = pred;
                    tail->next=NULL;
                }
            }
            delete temp;
        }
    }
}

template <class T>
void linkedlist<T>::insert(T el, int a)
{
    if (!isempty() && a <= count() + 1)
    {
        int count = 2 ;
        if (head !=NULL)
        {
            if (head == tail && a == 1)
            {
                head->next = new node<T>(el);
                tail = head->next;
            }
            else if (a == 1)
            {
                node<T> *temp = new node<T>(el, head);
                head = temp;
            }
            else
            {
                node<T> *pred, *temp;
                pred = head;
                temp = head->next;
                while (temp != NULL && a != count)
                {
                    pred = pred->next;
                    temp = temp->next;
                    count++;
                }
                if (temp != NULL)
                {
                    pred->next = new node<T>(el, temp);
                }
                if (this->count() + 1 == a)
                {
                    tail->next = new node<T>(el);
                    tail = tail->next;
                }
            }
        }
    }
    else if (a > count() + 1)
    {
        cout << "Could not be added in linked list as it only have " << count() << " elements";
    }

    else
    {
        cout << "Linked list is empty";
    }
}

template <class T>
T linkedlist<T>::del_position(int a)
{
    if (!isempty() && a <= count() )
    {
        int count = 2;
        if (head !=NULL)
        {
            if (head == tail && a == 1)
            {
                T el=head->info;
                delete head;
                head=tail=NULL;
                return el;
            }
            else if (a == 1)
            {
                T el=head->info;
                node<T> * temp=head;
                head = head->next;
                delete temp;
                return el;
            }
            else
            {
                node<T> *pred, *temp;
                pred = head;
                temp = head->next;
                while (temp != NULL && a != count)
                {
                    pred = pred->next;
                    temp = temp->next;
                    count++;
                }
                if (temp != NULL)
                {
                    pred->next = temp->next;
                    if (temp==tail)
                    {
                        tail=pred;
                        tail->next==NULL;
                    }
                    
                }
            }
        }
    }
    else if (a > count())
    {
        cout << "Location is out of linked list"<<endl;
    }

    else
    {
        cout << "Linked list is empty"<<endl;
    }
}
template <class T>
void linkedlist<T>::display(){
    node<T> *n=head;
    while (n!=NULL)
    {
        cout<<n->info<<" ";
        n=n->next;
    }   
    cout<<endl;
}
template <class T>
int linkedlist<T>::count(){
    node<T> *n=head;
    int count=0;
    while (n!=NULL)
    {
        n=n->next;
        count++;
    }   
    return count;
}
template <class T>
void linkedlist<T>::reverse(){
    if (isempty())
    {
        cout<<"Empty";
    }
    node<T> *q,*r,*s;
    q=head;
    r=NULL;
    while (q!=NULL)
    {
        s=r;
        r=q;
        q=q->next;
        r->next=s;
    }
    head=r;
    node<T> *temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    tail=temp;

}

int main()
{
    linkedlist<int> l1;
    int num_val;
    cout<< endl << "Enter number of values for 1st list : ";
    cin >> num_val;
    cout << endl;
    for (int i = 0; i < num_val; i++)
    {
        int val;
        cout << "Enter " << i + 1 << "st element : ";
        cin >> val;
        l1.add_tail(val);
    }

    while (true)
    {
        cout << endl << "Functions to Perform on The Linked List :" << endl << endl 
        << "0 - Exit" << endl 
        << "1 - Add to head" << endl 
        << "2 - Add to tail" << endl 
        << "3 - Add to position" << endl 
        << "4 - Display" << endl 
        << "5 - Delete head" << endl 
        << "6 - Delete tail" << endl 
        << "7 - Delete position" << endl 
        << "8 - Search element" << endl 
        << "9 - Remove element" << endl 
        << "10 - Concatenate Lists" << endl 
        << "11 - Count elements" << endl 
        << "12 - Reverse list" << endl;

        int value;
        cout << endl << "Enter function to perform : ";
        cin >> value;

        if (value == 0)
        {
            return 0;
        }
        else if (value == 1)
        {
            int num;
            cout << "Enter value to add : ";
            cin >> num;
            l1.add_head(num);
            cout<<"New list:- "<<endl;
            l1.display();
        }
        else if (value == 2)
        {
            int num;
            cout << "Enter value to add : ";
            cin >> num;
            l1.add_tail(num);
                        cout<<"New list:- "<<endl;
            l1.display();
        }
        else if (value == 3)
        {
            int num;
            cout << "Enter value to add : ";
            cin >> num;
            int pos;
            cout << "Enter position to add : ";
            cin >> pos;
            l1.insert(num, pos);
                        cout<<"New list:- "<<endl;
            l1.display();
        }
        else if (value == 4)
        {
            l1.display();
            
        }
        else if (value == 5)
        {
            l1.del_head();
                        cout<<"New list:- "<<endl;
            l1.display();
        }
        else if (value == 6)
        {
            l1.del_tail();
                        cout<<"New list:- "<<endl;
            l1.display();
        }
        else if (value == 7)
        {
            int num;
            cout << "Enter positon to remove : ";
            cin >> num;
            l1.del_position(num);
            
        }
        else if (value == 8)
        {
            int num;
            cout << "Enter value to search : ";
            cin >> num;
            if(l1.search(num)==1){
                cout<<"Present"<<endl;
            }
            else{
                cout<<"not present"<<endl;
            }
        }
        else if (value == 9)
        {
            int num;
            cout << "Enter value to remove : ";
            cin >> num;
            l1.del_element(num);
            cout<<"New list:- "<<endl;
            l1.display();
        }
        else if (value == 10)
        {
            linkedlist<int> l2;
            int num_val;
            cout << "Enter number of values for 2nd list :";
            cin >> num_val;
            for (int i = 0; i < num_val; i++)
            {
                int val;
                cout << "Enter " << i + 1 << "st element : ";
                cin >> val;
                l2.add_tail(val);
            }
            linkedlist<int> l3;
            l3 = l1+l2;
            l3.display();
        }
        else if (value == 11)
        {
            cout<<l1.count();

        }
        else if (value == 12)
        {
            l1.reverse();
            l1.display();
        }
        else{
            cout<<"Invalid input try again"<<endl;
        }
    }

    return 0;
}






