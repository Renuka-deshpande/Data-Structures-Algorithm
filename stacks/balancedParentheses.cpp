#include <bits/stdc++.h>
using namespace std;
bool balanced_parentheses(string s, int x)
{
    stack<char> st;
    for (auto it : s)
    {
        if (it == '(' || it == '{' || it == '[')
        {
            st.push(it);
        }
        else
        {
            if (st.empty())
                return false; // Checking if stack is empty before accessing top
            char ch = st.top();
            st.pop();
            if ((it == ')' and ch == '(') or (it == ']' and ch == '[') or (it == '}' and ch == '{'))
            {
                continue;
            }
            else
                return false;
        }
    }
    return st.empty(); // Stack should be empty if balanced
}
int main()
{
    string s = "()[{}()]";
    int size = s.size();
    if (balanced_parentheses(s, size))
    {
        cout << "balanced" << endl;
    }
    else
    {
        cout << "unbalanced" << endl;
    }
}