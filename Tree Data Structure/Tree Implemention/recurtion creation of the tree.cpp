#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *create()
{
    int data;
    cout << "\nEnter the data :";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    Node *root = new Node(data);
    cout << "\nEnter the left data: ";
    root->left = create();
    cout << "\nEnter the right data: ";
    root->right = create();
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}
int main()
{
    Node *root = create();
    inorder(root);
}