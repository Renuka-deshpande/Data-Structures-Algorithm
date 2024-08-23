#include <iostream>
#include <vector>
using namespace std;
//Remove duplicate from sorted array
int remove_duplicate(vector<int> &arr, int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}
int main()
{
    vector<int> arr = {1, 1, 1,2, 2, 2, 2, 3, 3};
    int n = arr.size();
    cout << remove_duplicate(arr, n);
    return 0;
}
//tc o(n) sc O(1)
