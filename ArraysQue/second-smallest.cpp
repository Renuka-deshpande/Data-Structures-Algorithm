#include <bits/stdc++.h>
using namespace std;
int second_smallest(vector<int> &arr, int n)
{
    int smallest = arr[0];
    int s_smallest = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            s_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < s_smallest)
        {
            s_smallest = arr[i];
        }
    }
    return s_smallest;
}

int main()
{
    vector<int> arr = {2, 4, 5, 6, 7, 8, 9};
    int n = arr.size();
    cout << second_smallest(arr, n);

    return 0;
}