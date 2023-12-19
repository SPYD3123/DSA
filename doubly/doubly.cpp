#include <iostream>
using namespace std;
template <class T> 
class node
{
public:
    node<T> *prev;
    node<T> *next;
    T info;
    node(T el, node<T> *a=NULL, node<T> *b=NULL){
        prev=a;
        next=b;
        info=el;
    }
};

template <class T>
class doubly{
    private:
        node<T> *head;
        node<T> *tail;
    public:
        doubly(){
            head=tail=NULL;
        }
        bool ismepty(){
            return head==NULL;
        }
        void add_head(T el);
        void add_tail(T el);
        void display();
        void insert(T el, int a);
        int count();
        void del_head();
        void del_tail();
        void del_position(int a);
        node<T> * search(T el);
        doubly<T> concatenate(const doubly<T> B);
        void del_element(T el);
        void reverse();
        

};

template <class T>
void doubly<T>::add_head(T el){
    head=new node<T>(el,NULL,head);
    
       if (tail==NULL)  //head->next==NULL
       {
        tail=head;
       }
       else{
        head->next->prev=head;
       }

}

template <class T>
void doubly<T>::add_tail(T el){
    if (tail==NULL)
    {
        head=tail=new node<T>(el);
    }
    else{
        tail=new node<T>(el,tail,NULL);
        tail->prev->next=tail;
    }
    
}
template <class T>
void doubly<T>::insert(T el, int a){
    if (!ismepty())
    {
        
        if (a==1)
        {
            add_head(el);
        }
        else if (a==count()+1)
        {
            add_tail(el);
        }
        else if (a>1 && a<count()+1)
        {
            node<T> *temp=head;
            int count=2;
            while (count!=a )
            {
                count++;
                temp=temp->next;
            }
            node<T> *b= new node<T>(el,temp,temp->next);
            temp->next=b;
            b->next->prev=b;
            
        }
        else{
            cout<<"value of I is out of range";
        }
        
        
    }
}

template <class T>
int doubly<T>::count(){
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
void doubly<T>::del_head(){
    if (!ismepty())
    {
        if (head==tail)
        {
            delete head;
            head=tail=NULL;
        }
        else{
            node<T> *temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;
        }
    }
    else{
        cout<<"List is empty";
    }
    
}

template <class T>
void doubly<T>::del_tail(){
    if (!ismepty())
    {
        if (head==tail)
        {
            delete tail;
            head=tail=NULL;
        }
        else{
            tail=tail->prev;
            delete tail->next;
            tail->next=NULL;
        }
    }
    else{
        cout<<"List is empty";
    }
    
}

template <class T>
void doubly<T>::del_position(int a){
    if (!ismepty())
    {
        if (a==1)
        {
            del_head();
        }
        else if (a==count())
        {
            del_tail();
        }
        else if (a>1 && a<count())
        {
            node<T> *temp=head->next;
            int count=2;
            while (count!=a )
            {
                count++;
                temp=temp->next;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            
            
        }
        else{
            cout<<"value of I is out of range";
        }
        
    }
}

template <class T>
node<T>* doubly<T>::search(T el) {
    node<T>* temp;
    for (temp = head; temp != nullptr; temp = temp->next) {
        if (temp->info == el) {
            return temp; 
        }
    }
    return nullptr; 
}


template <class T>
void doubly<T>::del_element(T el)
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
            head->prev=NULL;
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
                if (temp == tail)
                {
                    tail = pred;
                    tail->next=NULL;
                }
                else{
                    pred->next = temp->next;
                    pred->next->prev=pred;
                }


            }
            delete temp;
        }
    }
}


template <class T>
doubly<T> doubly<T>::concatenate(const doubly<T> B) {
    doubly<T> result;

    node<T>* current = head;
    while (current != nullptr) {
        result.add_tail(current->info);
        current = current->next;
    }

    current = B.head;
    while (current != nullptr) {
        result.add_tail(current->info);
        current = current->next;
    }

    return result;
}

template <class T>
void doubly<T>::reverse(){
    if (ismepty()|| head==tail)
    {
        return;
    }
    node<T> * var=head;
    node<T> *temp=NULL;
    while (var!=NULL)
    {
        temp=var->prev;
        var->prev=var->next;
        var->next=temp;
        var=var->prev;
    }
    head=temp->prev;

    node<T> *p=head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    tail=p;
    
}


template <class T>
void doubly<T>::display(){
    node<T> *e=head;
    while(e!=NULL){
        cout<<e->info<<" ";
        e=e->next;
    }
}
int main()
{
    doubly<int> A;
    bool exitMenu = false;

    while (!exitMenu)
    {
        cout << "\nDoubly Linked List Menu:\n";
        cout << "1. Add to Head\n";
        cout << "2. Add to Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Head\n";
        cout << "5. Delete from Tail\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search for an Element\n";
        cout << "8. Delete an Element\n";
        cout << "9. Concatenate with Another List\n";
        cout << "10. Display the List\n";
        cout << "11. Reverse the List\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        int value, position;
        node<int>* result;
        doubly<int> B;

        if (choice == 1)
        {
            cout << "Enter the value to add: ";
            cin >> value;
            A.add_head(value);
            cout<<"Added to head"<<endl;
        }
        else if (choice == 2)
        {
            cout << "Enter the value to add: ";
            cin >> value;
            A.add_tail(value);
            cout<<"Added to tail"<<endl;
        }
        else if (choice == 3)
        {
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the position to insert at: ";
            cin >> position;
            A.insert(value, position);
            cout<<"inserted"<<endl;
        }
        else if (choice == 4)
        {
            A.del_head();
            cout<<"Head deleted"<<endl;
        }
        else if (choice == 5)
        {
            A.del_tail();
            cout<<"Tail deleted"<<endl;
        }
        else if (choice == 6)
        {
            cout << "Enter the position to delete: ";
            cin >> position;
            A.del_position(position);
            cout<<"position deleted"<<endl;
        }
        else if (choice == 7)
        {
            cout << "Enter the value to search for: ";
            cin >> value;
            result = A.search(value);
            if (result != nullptr)
                cout << "Element found in the list.\n";
            else
                cout << "Element not found in the list.\n";
        }
        else if (choice == 8)
        {
            cout << "Enter the value to delete: ";
            cin >> value;
            A.del_element(value);
            cout<<"Element deleted"<<endl;
        }
        else if (choice == 11)
        {
            A.reverse();
            cout << "List reversed.\n";
            A.display();
            cout<<endl;
        }
        else if (choice == 10)
        {
            cout << "Doubly Linked List: ";
            A.display();
            cout << "\n";
        }
        else if (choice == 9)
        {
            cout << "Enter the number of values for the second list: ";
            cin >> value;
            for (int i = 0; i < value; i++)
            {
                int val;
                cout << "Enter " << i + 1 << "st element for the second list: ";
                cin >> val;
                B.add_tail(val);
            }

            doubly<int> concatenated = A.concatenate(B);
            cout << "Concatenated List: ";
            concatenated.display();
            cout << "\n";
        }
        else if (choice == 12)
        {
            exitMenu = true;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
