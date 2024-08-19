#include <bits/stdc++.h>
using namespace std;

void bubblesort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}
int main()
{
    int arr[] = {20, 56, 7, 32, 21};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubblesort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
// TimeComplexity-- O(n^2)-->worst case  O(n)-->best case