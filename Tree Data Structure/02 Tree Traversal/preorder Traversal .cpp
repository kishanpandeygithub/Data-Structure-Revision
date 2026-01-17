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

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    queue<Node *> q;
    int data;
    cout << "Enter the root node :";
    cin >> data;
    Node *root =NULL;
    if (data != -1)
    {
        Node *newNode = new Node(data);
        q.push(newNode);
        root = newNode;
    }

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Inter the left data " << temp->data<<" ";
        cin >> data;
        if (data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }
        cout << "Inter the rigth Node " << temp->data<<" ";
        cin >> data;
        if (data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }

    preorder(root);
}