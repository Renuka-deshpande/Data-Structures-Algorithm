#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *back;
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data2)
    {
        data = data2;
        next = nullptr;
        back = nullptr;
    }
};

// ARAAY TO DOUBLY LINKEDLIST
Node *Array2Dll(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// PRINT
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// DELETE HEAD
Node *deletehead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return nullptr;
    }
    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

//DELETE TAIL
Node *deletetail(Node* head){
    if(head==NULL || head->next==NULL){
        return nullptr;
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev_tail=tail->back;
    prev_tail->next=nullptr;
    tail->next=nullptr;
    delete tail;
    return head;

}

//DELETE Kth ELEMENT 
Node * deletekelement(Node* head,int k){
    if(head==NULL){
        return nullptr;
    }
    int count=0;
    Node* Knode=head;
    while(Knode!=NULL){
        count++;
      
        if(count==k){
            break;
        } 
         Knode=Knode->next;
    }
    Node* prev=Knode->back;
    Node* front=Knode->next;

    if(prev==NULL && front==NULL){
        delete Knode;
        return nullptr;
    }
   else if(prev==NULL){
      return  deletehead(head);
    }
    else if(front==NULL){
        return deletetail(head);
    }

    prev->next=front;
    front->back=prev;
    Knode->next=nullptr;
    Knode->back=nullptr;
    delete Knode;
    return head;
}

//DELETE NODE
void deletenode(Node* temp){
     Node* prev=temp->back;
     Node* front=temp->next;
     if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        delete temp;
        return;
     }
     prev->next=front;
     front->back=prev ;
     temp->next=temp->back=nullptr;
     delete temp;
}
int main()
{
    vector<int> arr = {1, 3, 4, 6, 7};
    Node *head = Array2Dll(arr);
    deletenode(head->next);
    print(head);
    return 0;
}