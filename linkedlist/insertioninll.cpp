#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data2)
    {
        data = data2;
        next = nullptr;
    }
};

Node *Array2LL(vector<int> &arr)
{
    if (arr.empty())
    {
        return nullptr;
    }

    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printll(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

// INSERTING ELEMEENT AT 1ST
Node *insert_head(Node *head, int val)
{
    Node *temp = new Node(val, head);
    return temp;

    // or
    // return new Node(val,head)
}

// INSERTING TAIL
Node *insert_tail(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* newnode =new Node(val);
    temp->next=newnode;
    return head;
}

//insertion at specefic index
Node *insertposition(Node* head,int el,int index){
    if(head==NULL){
        if(index==1){
            return new Node(el);
        }
        else
        {
            return head;
        }
        
    }

    if(index==1){
        return new Node(el,head);
    }

    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        if(count==(index-1)){
            Node* x=new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {10, 92, 38, 4, 55, 566, 97};
    Node *head = Array2LL(arr);
    head = insertposition(head, 107,934);
    printll(head);
   return 0;
}