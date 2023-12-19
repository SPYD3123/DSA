#include <iostream> 
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;
    node(int el,node* l=NULL, node* r=NULL)
    {
        val = el;
        left =l;
        right = r;
    }
};

class binarySearchTree{
    private:
    node* root;
    void addelement(int el){
        if(root==NULL){
            root=new node(el);
        }
        else{
            node* temp=root;
            node* prev;
            while (temp!=NULL)
            {
                if (el> temp->val)
                {
                    prev=temp;
                    temp=temp->right;
                }
                else{
                    prev=temp;
                    temp=temp->left;
                }
            }
            if (el>prev->val)
            {
                prev->right=new node(el);
            }
            else{
                prev->left=new node(el);
            }
            
            
            
        }
    }

    void Inorder(node* root){
        if (root!=NULL)
        {
            Inorder(root->left);
            cout<<root->val<<" ";
            Inorder(root->right);
        }
        
    }
    void Preorder(node* root){
        if (root!=NULL)
        {
            cout<<root->val<<" ";
            Preorder(root->left);
            Preorder(root->right);
        }
        
    }
    void Postorder(node* root){
        if (root!=NULL)
        {
            Postorder(root->left);
            Postorder(root->right);
            cout<<root->val<<" ";
        }
        
    }

node* searchelement(node* temp, int el){
    while (temp != NULL && temp->val != el) {
        if (el > temp->val) {
            temp = temp->right;
        } else if (el < temp->val) {
            temp = temp->left;
        }
    }

    return temp; // Return the result, which can be NULL if the element is not found
}

int calculateTreeHeight(node* n) {
        if (n == NULL) {
            return 0;
        }
        int leftHeight = calculateTreeHeight(n->left);
        int rightHeight = calculateTreeHeight(n->right);
        return 1 + max(leftHeight, rightHeight);
    }

void delete_Elem(int el) {
    node* temp = root;
    node* prev = nullptr;

    // Search for the node to delete
    while (temp != NULL && temp->val != el) {
        prev = temp;
        if (el > temp->val) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }

    // If the element is not found, do nothing
    if (temp == NULL) {
        return;
    }

    // Case 1: Node with no children (Leaf Node)
    if (temp->left == NULL && temp->right == NULL) {
        if (prev == NULL) {
            // If the root is the only node in the tree
            delete root;
            root = NULL;
        } else if (prev->left == temp) {
            delete temp;
            prev->left = NULL;
        } else {
            delete temp;
            prev->right = NULL;
        }
    }
    // Case 2: Node with one child
    else if (temp->left == NULL || temp->right == NULL) {
        node* child = (temp->left != NULL) ? temp->left : temp->right;

        if (prev == NULL) {
            // If deleting the root
            delete temp;
            root = child;
        } else if (prev->left == temp) {
            delete temp;
            prev->left = child;
        } else {
            delete temp;
            prev->right = child;
        }
    }
    // Case 3: Node with two children
    else {
        node* successor = temp->right;
        node* successorParent = temp;

        // Find the leftmost node in the right subtree
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        // Copy the value of the successor to the current node
        temp->val = successor->val;

        // Delete the successor (which is the leftmost node in the right subtree)
        if (successorParent->left == successor) {
            if (successor->right==NULL)
            {              
            delete successor;
            successorParent->left = NULL; 
            }
            else{
                successorParent->left = successor->right; 
                delete successor;
            }
            

        } else {
            successorParent->right = successor->right;
            delete successor;
        }
    }
}

    public:
    binarySearchTree(){
        root=NULL;
    }
    void addelm(int el){
        addelement(el);
    }
    void printin(){
        Inorder(root);
    }
    void printpre(){
        Preorder(root);
    }
    void printpost(){
        Postorder(root);
    }
    void search(int el){
       if (searchelement(root,el)==NULL)
       {
        cout<<"does not exist";
       }
       else{
        cout<<"Exist";
       }
       
    }
    void del(int el){
        delete_Elem(el);
    }
    int treeHeight() {
        return calculateTreeHeight(root);
    }

};
int main(int argc, char const *argv[])
{
    binarySearchTree T;
    T.addelm(30);
    T.addelm(5);
    T.addelm(3);
    T.addelm(2);
    T.addelm(15);
    T.addelm(20);
    // T.addelm(6);
    T.addelm(40);
    T.del(5);
    T.printin();
    cout<<endl;
    T.printpost();
    cout<<endl;
    T.printpre();
    T.search(4);
    return 0;
}
