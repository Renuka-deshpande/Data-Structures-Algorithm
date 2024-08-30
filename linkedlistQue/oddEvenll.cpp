#include <bits/stdc++.h>
using namespace std;

struct Node
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

Node* odd_even(Node* head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* odd=head;
    Node* even=head->next;
    Node* evenhead=even;

    while (even!=NULL &&  even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;

        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    return head;
    //TIME COMPLEXITY=O(N)//SPACE COMPLEXITY=O(1)
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    head = odd_even(head);
    print(head);

    return 0;
}
