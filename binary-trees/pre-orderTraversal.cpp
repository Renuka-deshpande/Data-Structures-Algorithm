// DFS-->Pre-Order Traversal ---root->left->right
#include <iostream>
using namespace std;
struct Node
{
public:
    int data;
    Node *right, *left;
    Node(int data1)
    {
        data = data1;
        right = left = nullptr;
    }
};

void print(Node* root){
    cout<<root->data<<" ";
}
void preorder(Node* root){
    Node* head=root;
    if(head==nullptr){return;}
    print(head);
    preorder(head->left);
    preorder(head->right);

}
int main()
{
Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->left->right->left = new Node(1);
    cout<<"Pre order Traversal: "<<endl;
    preorder(root);
    return 0;
}