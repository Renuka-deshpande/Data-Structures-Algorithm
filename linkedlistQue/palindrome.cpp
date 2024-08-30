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

bool palindrome(Node *head)
{
    Node *temp = head;
    stack<int> st;

    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->data != st.top())
        {
            return false;
        }
        temp = temp->next;
        st.pop();
    }
    return true;
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

bool checkpalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newhead = reverselinkedlist(slow->next);
    Node *first = head;
    Node *second = newhead;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverselinkedlist(newhead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
        
        reverselinkedlist(newhead);
        return true;
    
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);
    bool isPalindrome = checkpalindrome(head);
    cout << (isPalindrome ? "list is a plaindrome" : "list is not a palindrome");
    return 0;
}