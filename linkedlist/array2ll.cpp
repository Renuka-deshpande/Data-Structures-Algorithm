#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    // constructor
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // constructor
    Node(int data2)
    {
        data = data2;
        next = nullptr;
    }

    // destructor
    ~Node()
    {
        delete next; // This will recursively delete all nodes
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

int main()
{
    vector<int> arr = {1, 3, 4, 6, 7};
    Node *head = Array2LL(arr); // cout << head->data << endl;
    printll(head);
   
    delete head;

    return 0;
}