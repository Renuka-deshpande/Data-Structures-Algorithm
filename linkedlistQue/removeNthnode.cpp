// Removing Nth node from the end
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

Node *remove_Nthnode(Node *head, int index)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count == index)
    {
        Node *newhead = head->next;
        free(head);
        return head;
    }
    int res = count - index;
    temp = head;
    while (temp != NULL)
    {
        res--;
        if (res == 0)
        {
            break;
        }
        temp = temp->next;
    }
    Node *deletenode = temp->next;
    temp->next = temp->next->next;
    delete (deletenode);
    return head;
    // tc-O(len)+O(len-n)~O(2len)   sc-O(1)
}

Node *Nthnode_end(Node *head, int index)
{
    if (head == nullptr || index < 1)
        return head; // Edge case: Empty list or invalid index

    Node *fast = head;
    Node *slow = head;
    for (int i = 0; i < index; i++)
    {
        fast = fast->next;
    }
    if (fast == NULL)//removal of nth term from last 
    {
        return head->next;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *deletenode = slow->next;
    slow->next = slow->next->next;
    
    delete (deletenode);
    return head;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // head=remove_Nthnode(head,2);
    head = Nthnode_end(head, 5);
    print(head);
    // tc-O(len)  sc-O(1)
    return 0;
}