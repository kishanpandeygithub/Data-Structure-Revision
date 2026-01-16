#include <iostream>
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

Node *Create()
{
    int data;
    cout << "Enter the data";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    // filling the data
    Node *node = new Node(data);
    // linking the left node
    cout << "Enter the left node";
    node->left = Create();
    // linking the right node
    cout << "Enter the right node";
    node->right = Create();
    return node;
}
// this is the program to make the node in the tree
int main()
{
    Node *root = Create();
}