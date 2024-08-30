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

Node *sort012(Node *head)
{
    Node *temp = head;
    int count0 = 0, count1 = 0, count2 = 0;
    while (temp != nullptr)
    {
        if (temp->data == 0)
            count0++;
        else if (temp->data == 1)
            count1++;
        else
            count2++;

        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr)
    {
        if (count0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
    // tc-O(2n)
    // sc-O(n)
}

Node *Sort_012(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *temp = head;

    Node *zerohead = new Node(-1);
    Node *onehead = new Node(-1);
    Node *twohead = new Node(-1);

    Node *zero = zerohead;
    Node *one = onehead;
    Node *two = twohead;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (onehead->next) ? onehead->next : twohead->next;
    one->next = twohead->next;
    two->next = nullptr;

    Node *newhead = zerohead->next;

    delete zerohead, onehead, twohead;

    return newhead;
    //tc-O(n)  sc-O(1)
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
    Node *head = new Node(0);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(2);

    // head= sort012(head);
    head = Sort_012(head);
    print(head);

    return 0;
}
