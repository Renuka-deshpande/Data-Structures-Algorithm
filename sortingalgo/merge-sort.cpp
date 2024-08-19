#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = s + ((e - s) / 2);
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];  // created a dynamic array of lenght=len1
    int *second = new int[len2]; // created a dynamic array of length=len2

    // copy values of left part of array in newly created array
    int mainindex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainindex++];
    }

    // copy values of right part of array in newly created array
    int k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // merge to sorted array
    int index1 = 0;
    int index2 = 0;
    mainindex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainindex++] = first[index1++];
        }
        else
        {
            arr[mainindex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainindex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainindex++] = second[index2++];
    }

    //free the dynamic memory
    delete []first;
    delete []second;
}
void mergesort(int arr[], int s, int e)
{
    int mid = s + ((e - s) / 2);

    // base case
    if (s >= e)
    {
        return;
    }

    // left part of array
    mergesort(arr, s, mid);

    // right part of array
    mergesort(arr, mid + 1, e);

    // calling merge func to finally merge the 2 sorted arrays
    merge(arr, s, e);
}

int main()
{
    int arr[] = {21, 32, 12, 2, 4, 66, 8, 10};
    int s = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    int e = n - 1;
    mergesort(arr, s, e);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
//timecomplexity---O(nlogn)