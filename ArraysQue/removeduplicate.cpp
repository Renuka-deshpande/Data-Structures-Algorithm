#include <bits/stdc++.h>
using namespace std;

int removeduplicate(int arr[], int n)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]); //"set" automatically maintains unique elements and sorts them in ascending order.
    }

    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " " << endl;
    }

    int index = 0;
    for (auto itr : st)
    {
        arr[index] = itr;
        index++;
    }
    return index;
}
int main()
{
    int arr[] = {1, 1, 52, 12, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "size of array after removing of duplicate element is: " << removeduplicate(arr, n);
    return 0;
}
//tc O(nlogn+n) sc O(n)