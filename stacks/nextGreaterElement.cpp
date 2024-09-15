#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> next_greater(vector<int> &num)
    {
        int size = num.size();
        vector<int> nge(size, -1);
        stack<int> st;
        for (int i = size - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= num[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                nge[i] = st.top();
            }
            st.push(num[i]);
        }

        return nge;
    }
};
int main()
{
    solution obj;
    vector<int> v{6, 0, 8, 1, 3};
    vector<int> res = obj.next_greater(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}