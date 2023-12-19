#include <iostream>
using namespace std;

class polynode
{
public:
    int coeff;
    int power;
    polynode *next;
    polynode(int c, int p, polynode *s= NULL)
    {
        coeff = c;
        power = p;
        next = s;
    }
};

class polyadd
{
private:
    polynode *head, *tail;
public:
    polyadd(){
        head=tail= NULL;
    }
    void add_tail(int c, int p);
    void add_polys(polyadd p1,polyadd p2);
    void display();

};

void polyadd::add_tail(int c,int p){
    if (tail!=NULL)
    {
        tail->next=new polynode(c,p);
        tail=tail->next;
    }
    else{
        head=tail=new polynode(c,p);
    }
    
}
void polyadd::add_polys(polyadd p1, polyadd p2){
    polynode *n1=p1.head;
    polynode *n2=p2.head;
    while (n1!=NULL && n2!=NULL)
    {
        if (n1->power > n2->power)
        {
            add_tail(n1->coeff, n1->power);
            n1=n1->next;
        }
        else if (n1->power<n2->power){
            add_tail(n2->coeff,n2->power);
            n2=n2->next;
        }
        else{
            add_tail(n1->coeff+n2->coeff,n1->power);
            n1=n1->next;
            n2=n2->next;
        }
    }
    while (n1!=NULL)
    {
        add_tail(n1->coeff,n1->power);
        n1=n1->next;
    }
    while (n2!=NULL)
    {
        add_tail(n2->coeff,n2->power);
        n2=n2->next;
    }    
}
void polyadd::display(){
    polynode *n=head;
    while (n!=NULL)
    {
        cout<<n->coeff<<"x"<<"^"<<n->power;
        n=n->next;
        if (n!=NULL)
        {
            cout<<" + ";
        }
    }   
}

int main()
{
    polyadd addition,p1,p2;
    cout<<"Enter the 1st polynomial in descending order of the power"<<endl;
    int a;
    int c;
    int p;
    while (a!=0)
    {
        if (a==1)
        {
            cout<<"make sure that the power of next polynomial must be lower than the previous one"<<endl;
        }
        
        cout<<"Enter the coefficient ";
        cin>>c;
        cout<<"Enter the power ";
        cin>>p;
        p1.add_tail(c,p);
        cout<<"Polynomial entered so far:-"<<endl;
        p1.display();
        cout<<endl;
        cout<<"Do you want to continue adding"<<endl<<"Enter 1 for yes and 0 for no ";
        cin>>a;
        cout<<endl;
    }

    a=2;
    cout<<"Enter the 2nd polynomial in descending order of the power"<<endl; 

    while (a!=0)
    {
        if (a==1)
        {
            cout<<"make sure that the power of next polynomial must be lower than the previous one"<<endl;
        }
        
        cout<<"Enter the coefficient ";
        cin>>c;
        cout<<"Enter the power ";
        cin>>p;
        p2.add_tail(c,p);
        cout<<"Polynomial entered so far:-"<<endl;
        p2.display();
        cout<<endl;
        cout<<"Do you want to continue adding"<<endl<<"Enter 1 for yes and 0 for no ";
        cin>>a;
        cout<<endl;
    }

    cout<<"Polynomial 1:- "<<endl;
    p1.display();
    cout<<endl;
    cout<<"Polynomial 2:- "<<endl;
    p2.display();
    cout<<endl;
    cout<<"Sum of 2 polynomials is:- ";
    addition.add_polys(p1,p2);
    cout<<endl;
    addition.display();
    return 0;
}
    