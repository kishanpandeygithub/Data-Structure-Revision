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

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// program to find the size of the tree
void size(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    count++;
    size(root->left, count);
    size(root->right, count);
}
// second metheod
int TreeSize(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void countNonLeaves(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    count++;
    countNonLeaves(root->left, count);
    countNonLeaves(root->right, count);
}

void countLeaves(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    countLeaves(root->left, count);
    countLeaves(root->right, count);
}

void sum(Node *root, int &add)
{
    if (root == NULL)
    {
        return;
    }
    add += root->data;
    sum(root->left, add);
    sum(root->right, add);
}

void TreeSize(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    count++;
    TreeSize(root->left, count);
    TreeSize(root->right, count);
}
int main()
{
    queue<Node *> q;
    int data;
    cout << "Enter the root node :";
    cin >> data;
    Node *root = NULL;
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
        cout << "Inter the left data " << temp->data << " ";
        cin >> data;
        if (data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }
        cout << "Inter the rigth Node " << temp->data << " ";
        cin >> data;
        if (data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }

    inorder(root);
    int count = 0;
    size(root, count);
    cout << count;
}