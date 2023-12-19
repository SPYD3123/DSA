#include <iostream>
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;
    node(int el)
    {
        val = el;
        left = NULL;
        right = NULL;
    }
};
class binarySearchTree
{
private:
    node *root;
    void addElem_root(int el)
    {
        if (root == NULL)
        {
            node *p = new node(el);
            root = p;
        }
        else
        {
            node *p = new node(el);
            node *q = root;
            while (q != NULL)
            {
                if (el < q->val)
                {
                    if (q->left == NULL)
                    {
                        q->left = p;
                        return;
                    }
                    q = q->left;
                }
                else if (el > q->val)
                {
                    if (q->right == NULL)

                    {
                        q->right = p;
                        return;
                    }
                    q = q->right;
                }
                else
                {
                    return;
                }
            }
        }
    }
    void printTreeInOrder(node *root)
    {
        if (root != NULL)
        {
            printTreeInOrder(root->left);
            cout << root->val << " ";
            printTreeInOrder(root->right);
        }
    }
    void printTreePostOrder(node *root)
    {
        if (root != NULL)
        {
            printTreePostOrder(root->left);
            printTreePostOrder(root->right);
            cout << root->val << " ";
        }
    }
    void PrintTreePreOrder(node *root)
    {
        if (root != NULL)
        {
            cout << root->val << " ";
            PrintTreePreOrder(root->left);
            PrintTreePreOrder(root->right);
        }
    }
    void removeElem_root(int el)
    {
        node *p = search(el);
        if (p == NULL)
        {
            return;
        }

        else if (p->right == NULL && p->left == NULL)
        {
            delete_Elem(el);
        }
        else if (p->right == NULL && p->left != NULL)
        {
            node *prev = searchPrev(el);
            if (prev->right->val == el)
            {
                prev->right = p->left;
            }
            else if (prev->left->val == el)
            {
                prev->left = p->left;
            }
        }
        else
        {
            node *prev = searchPrev(el);
            node *q = p;
            q = q->right;
            while (q->left != NULL)
            {
                q = q->left;
            }
            prev->val = q->val;
            delete_Elem(el);
        }
    }
    node *searchPrev(int el)
    {
        node *p = root;
        node *prev = root;
        while (p->val != el)
        {
            if (p == NULL)
            {
                return NULL;
            }
            if (p->val > el)
            {
                prev = p;
                p = p->left;
            }
            else
            {
                prev = p;
                p = p->right;
            }
        }

        return prev;
    }
    node *search(int el)
    {
        node *p = root;
        while (p->val != el)
        {
            if (p == NULL)
            {
                return NULL;
            }
            if (p->val > el)
            {
                if (p->left == NULL)
                {
                    return NULL;
                }
                p = p->left;
            }
            else
            {
                if (p->right == NULL)
                {
                    return NULL;
                }
                p = p->right;
            }
        }
        return p;
    }
    void delete_Elem(int el)
    {
        node *prev = root;
        node *p = root;
        while (p->val != el)
        {
            if (el < p->val)
            {
                prev = p;
                if (p->left == NULL)
                {
                    prev->left = NULL;
                    return;
                }
                p = p->left;
            }
            else if (el > p->val)
            {
                prev = p;

                if (p->right == NULL)
                {
                    prev->right = NULL;
                    return;
                }
                p = p->right;
            }
            else
            {
                return;
            }
        }
        if (prev->val > el)
        {
            prev->left = NULL;
        }
        else
        {
            prev->right = NULL;
        }
    }

public:
    binarySearchTree()
    {
        root = NULL;
    }
    void addElem(int el)
    {
        addElem_root(el);
    }
    void removeELem(int el)
    {
        removeElem_root(el);
    }
    void printInorder()
    {
        printTreeInOrder(root);
        cout << endl;
    }
    void printPreorder()
    {
        PrintTreePreOrder(root);
        cout << endl;
    }
    void printPostorder()
    {
        printTreePostOrder(root);
        cout << endl;
    }
    string searchElem(int el)

    {
        return search(el) == NULL ? "Not Exists" : "Exist";
    }
};
void displayMenu()
{
    cout << "===============================\n";
    cout << "Binary Search Tree Menu:\n";
    cout << "1. Add Element\n";
    cout << "2. Remove Element\n";
    cout << "3. Search Element\n";
    cout << "4. Print Inorder Traversal\n";
    cout << "5. Print Preorder Traversal\n";
    cout << "6. Print Postorder Traversal\n";
    cout << "7. Exit\n";
    cout << "===============================\n";
    cout << "Enter your choice: ";
}
int main(int argc, char const *argv[])
{
    binarySearchTree bst;
    int choice, element;
    do
    {
        displayMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to add: ";
            cin >> element;
            bst.addElem(element);
            cout << "Element added successfully.\n";
            break;
        case 2:
            cout << "Enter element to remove: ";
            cin >> element;
            bst.removeELem(element);
            cout << "Element removed successfully.\n";
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> element;
            cout << "Result: " << bst.searchElem(element) << endl;
            break;
        case 4:
            cout << "Inorder Traversal: ";
            bst.printInorder();

            break;
        case 5:
            cout << "Preorder Traversal: ";
            bst.printPreorder();
            break;
        case 6:
            cout << "Postorder Traversal: ";
            bst.printPostorder();
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
        cout << "\n-----------------------------------\n";
    } while (choice != 7);
    return 0;
}