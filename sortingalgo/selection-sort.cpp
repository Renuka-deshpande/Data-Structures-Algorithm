#include <bits/stdc++.h>
using namespace std;

void selectionsort(int arr[], int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        int mini = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}
int main()
{
    int arr[] = {20, 56, 7, 32, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr, n);
    //display
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
//Time complexity--O(n^2)--->(best+worst)case 