//rotating the array elements to the left by 'p' positions.
#include <bits/stdc++.h>
using namespace std;

void rotatearray(vector<int> &arr, int p)
{
    int n = arr.size();
    p=p%n; //Adjust p to handle cases where p is larger than the size of the array.
    int k = 0;
    vector<int> temp(n);

    for (int i = p; i < n; i++)
    {
        temp[k++] = arr[i];
    }
    for (int i = 0; i < p; i++)
    {
        temp[k++] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int p ;
    cin>>p;

    rotatearray(arr, p);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
//tc-o(n)
//sc-o(1)