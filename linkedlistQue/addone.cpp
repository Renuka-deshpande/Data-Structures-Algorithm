#include <bits/stdc++.h>
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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int helper(Node *temp)
{
    // base case
    if (temp == NULL)
    {
        return 1;
    }
    int carry = helper(temp->next);
    temp->data += carry;
    if (temp->data < 10)
    {
        return 0;
    }
    temp->data = 0;
    return 1;
    // TIME COMPLEXITY=O(N)
    // SPACE COMPLEXITY=O(n)
}

Node *addone(Node *head)
{
    int carry = helper(head);
    if (carry == 1)
    {
        Node *newhead = new Node(1);
        newhead->next = head;
        head = newhead;
    }
    return head;
}

int main()
{
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(9);

    head = addone(head);
    print(head);

    return 0;
}
