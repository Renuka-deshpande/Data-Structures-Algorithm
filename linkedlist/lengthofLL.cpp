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

int lengthofll(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// Function to delete the linked list to avoid memory leaks
void deleteLinkedList(Node *head)
{
    Node *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *head = Array2LL(arr);
    cout << lengthofll(head);

    deleteLinkedList(head);

    return 0;
}