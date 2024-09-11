#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    string data;

public:
    Node(string data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(string data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

class browser
{
    Node *currentpage;

public:
    browser(string &homepage)
    {
        currentpage = new Node(homepage);
    }
    void visit(string &url)
    {
        Node *newpage = new Node(url);
        currentpage->next = newpage;
        newpage->prev = currentpage;
        currentpage = newpage;
    }

    string back(int steps)
    {
        while (steps)
        {
            if (currentpage->prev)
            {
                currentpage = currentpage->prev;
                steps--;
            }
            else
            {
                break;
            }
        }
        return currentpage->data;
    }

    string forward(int steps)
    {
        while (steps)
        {
            if (currentpage->next)
            {
                currentpage = currentpage->next;
                steps--;
            }
            else
            {
                break;
            }
        }
        return currentpage->data;
    }
};
