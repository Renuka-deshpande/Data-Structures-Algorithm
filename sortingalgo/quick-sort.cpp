#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    int pivoot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivoot)
        {
            count++;
        }
    }
    int pivotindex = s + count;
    swap(arr[s], arr[pivotindex]);

    int i = s, j = e;

    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] < pivoot)
        {
            i++;
        }
        while (arr[j] > pivoot)
        {
            j--;
        }
        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
}

void quick_sort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pivot = partition(arr, s, e);

    quick_sort(arr, s, pivot - 1);

    quick_sort(arr, pivot + 1, e);
}

int main()
{
    vector<int> arr = {35, 50, 15, 25, 80, 20, 90};
    int n = arr.size();
    int s = 0;
    int e = n - 1;

    quick_sort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}