#include <bits/stdc++.h>
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

// function to convert array to linkedlist
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

// print
void printll(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

// DELETING HEAD
Node *removehead(Node *head)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// DELETING TAIL
Node *delete_tail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// DELETING K index ELEMENT
Node *deletek(Node *head, int k)
{
    if (head == NULL)
        return head;

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// DELETING K ELEMENT I/P A VALUE
Node *deleteEl(Node *head, int el)
{
    if(head==NULL)return head;
    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==el){
            prev->next=   prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
return head;
}

int main()
{
    vector<int> arr = {10, 92, 38, 4, 55, 566, 97};
    Node *head = Array2LL(arr);
    head=deleteEl(head,566);
    printll(head);

    return 0;
}
