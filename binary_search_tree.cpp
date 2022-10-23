#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node* left=NULL;
    Node* right=NULL;


};
class BinaryTreeSearch {

public:
    Node* root=NULL;
  
    Node* insert(Node* r, int item) {
        if (r == NULL) {
            Node *newNode=new Node();
            newNode->value = item;
            r = newNode;

        }
        else if (item < r->value)
            r->left = insert(r->left, item);
        else
            r->right = insert(r->right, item);

        return r;
    }
    void insert(int value){
        root = insert(root, value);
    }
    void preorder(Node* r){
        if (r == NULL)
            return;
        cout << r->value << "\t";
        preorder(r->left);
        preorder(r->right);
    }
    void inorder(Node* r) {
        if (r == NULL)
            return;
        preorder(r->left);
        cout << r->value << "\t";
        preorder(r->right);
    }
    void postorder(Node* r) {
        if (r == NULL)
            return;
        preorder(r->left);
        preorder(r->right);
        cout << r->value << "\t";
    }
    Node* maxValue(Node* r) {
        if (r == NULL)
            return NULL;
        else if (r->right == NULL)
            return r;
        else
            return maxValue(r->right);
    }
    
    Node* minValue(Node* r)
    {
        if (r == NULL)
            return NULL;
        else if (r->left == NULL)
            return r;
        else
            return minValue(r->left);
    }

    Node* search(Node* r, int item)
    {
        if (r == NULL)
            return NULL;
        else if (r->value == item)
            return r;
        else if (item < r->value)
            return	search(r->left, item);
        else
            return search(r->right, item);
    }

    bool search(int item)
    {
        Node* result = search(root, item);

        if (result == NULL)
            return false;
        else
            return true;
    }
    Node* Delete(Node* r, int item)
    {
        if (r == NULL) // Empty Tree
            return NULL;
        if (item < r->value) // Item exists in left sub tree
            r->left = Delete(r->left, item);
        else if (item > r->value) // item exists in right sub tree
            r->right = Delete(r->right, item);
        else
        {
            if (r->left == NULL && r->right == NULL) // leaf node
                r = NULL;
            else if (r->left != NULL && r->right == NULL) // one child on the left
            {
                r->value = r->left->value;
                delete r->left;
                r->left = NULL;
            }
            else if (r->left == NULL && r->right != NULL) // one child on the right
            {
                r->value = r->right->value;
                delete r->right;
                r->right = NULL;
            }
            else
            {
                Node* max = maxValue(r->left);
                r->value= max->value;
                r->left = Delete(r->left, max->value);

            }

        }
        return r;
    }


};

int main()
{
    BinaryTreeSearch b;
    b.insert(45);
    b.insert(15);
    b.insert(79);
    b.insert(90);
    b.insert(10);
    b.insert(55);
    b.insert(12);
    b.insert(20);
    b.insert(50);
    cout << "order is : " << "\n";
    b.preorder(b.root);
    cout << "\n----------------------------\n";
    b.inorder(b.root);
    cout << "\n----------------------------\n";
    b.postorder(b.root);
    cout << "\n----------------------------\n";

    int m;
    cin >> m;
    if (b.search(m))
        cout << "value is found\n";
    else
        cout << "value not found\n";
}

