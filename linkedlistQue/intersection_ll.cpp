#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *intersection(Node *head1, Node *head2)
{
    unordered_set<Node*> mpp;//:map does not support direct usage of pointers as keys in this context. You need to use std::unordered_set for efficient lookups.
    Node *temp = head1;
    while (temp != NULL)
    {
        mpp.insert(temp) ;
        temp = temp->next;
    }
    Node* temp2=head2;
    while(temp2!=NULL){
        if(mpp.find(temp2)!=mpp.end()){
            return temp2;
        }
        temp2=temp2->next;
    }
    return NULL;
}


void print(Node *head)
{
     if (head == nullptr) {
        cout << "No intersection found" << endl;
        return;
    }

    cout << "Intersection node data: " << head->data << endl;

}

int main()
{
    
    Node* common = new Node(4, new Node(6));
    Node* head1 = new Node(3, new Node(1, common));
    Node* head2 = new Node(1, new Node(2, common));

    Node* head=intersection(head1,head2);
    print(head);
    return 0;
}