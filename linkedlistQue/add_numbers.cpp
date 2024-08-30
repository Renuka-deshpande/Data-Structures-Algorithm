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

Node *addTwonumbers(Node *num1, Node *num2)
{
    Node *dummyHead = new Node(-1);
    Node *current = dummyHead;
    Node *temp1 = num1;
    Node *temp2 = num2;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1)
        {
            sum += temp1->data;
        }
        if (temp2)
        {
            sum += temp2->data;
        }

        Node *newnode = new Node(sum % 10);
        carry = sum / 10;

        current->next = newnode;
        current = current->next;

        if (temp1)
        {
            temp1 = temp1->next;
        }
        if (temp2)
        {
            temp2 = temp2->next;
        }
    }
    if (carry)
    {
        Node *newnode = new Node(carry);
        current->next = newnode;
    }

    return dummyHead->next;
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
    Node *head = NULL;
    head = new Node(2);
    head->next = new Node(4, nullptr);
    head->next->next = new Node(6, nullptr);
    Node *head2 = NULL;
    head2 = new Node(3);
    head2->next = new Node(8, nullptr);
    head2->next->next = new Node(7, nullptr);
    head=addTwonumbers(head,head2);
    print(head);
}