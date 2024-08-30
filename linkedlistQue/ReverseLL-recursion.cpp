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

Node *reverselinkedlist(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newhead = reverselinkedlist(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newhead;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head = reverselinkedlist(head);
    print(head);

    return 0;
}
// TIME COMPLEXITY=O(N)
// SPACE COMPLEXITY=O(N)due to recursive stack