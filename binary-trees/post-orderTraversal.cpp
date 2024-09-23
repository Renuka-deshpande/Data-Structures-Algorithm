// DFS-->Post-Order Traversal ---left->right->root
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

void print(Node *root)
{
    cout << root->data << " ";
}
void postorder(Node *root)
{
    Node *head = root;
    if (head == nullptr)
    {
        return;
    }
    postorder(head->left);
    postorder(head->right);
    print(head);
}
int main()
{
    Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->left->right->left = new Node(1);
     cout<<"Postorder Traversal: "<<endl;
    postorder(root);
    return 0;
}