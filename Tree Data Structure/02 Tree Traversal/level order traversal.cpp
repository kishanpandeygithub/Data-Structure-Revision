#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data =data;
        this->left =NULL;
        this->right =NULL;
    }
};
Node* create(){
    int data;
    cout<<"\nEnter the Data : ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root = new Node(data);
    //to insert the left node
    cout<<"\nEnter the left Node fo the "<< root->data;
    root->left = create();
    //to insert the right node
    cout<<"\nEnter the right Node fo the "<< root->data;
    root->right = create();
    return root;
}
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp =q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main(){
    Node * root =create();
    levelOrderTraversal(root);
    return 0;
}