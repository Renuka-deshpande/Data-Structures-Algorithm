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

// INSERTION OF NEW HEAD OR INSERT BEFORE HEAD
Node *newhead(Node *head, int val)
{
    Node *newhead = new Node(val, head, nullptr);
    head->back = newhead;
    return newhead;
}

// INSERTION BEFORE TAIL
Node *insertbeforetail(Node *head, int val)
{
    if (head->next == NULL)
    {
        return newhead(head, val);
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;
    Node *newnode = new Node(val, tail, prev);
    prev->next = newnode;
    tail->back = newnode;
    return head;
}

// INSERTION BEFORE Kth Element
Node *insertbeforekelement(Node *head, int k, int val)
{
    if (k == 1)
    {
        return newhead(head, val);
    }
    Node *temp = head;
    int count = 0;
    while (temp->next != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *newnode = new Node(val, temp, prev);
    prev->next = newnode;
    temp->back = newnode;

    return head;
}

// INSERT BEFORE NODE
void insertbeforenode(Node *node, int val)
{
    Node *prev = node->back;
    Node *newnode = new Node(val, node, prev);
    prev->next = newnode;
    node->back = newnode;
}

int main()
{
    vector<int> arr = {1, 3, 4, 6, 7};
    Node *head = Array2Dll(arr);
    // head = insertbeforekelement(head, 3,45);
    insertbeforenode(head->next, 88);
    print(head);
    return 0;
}