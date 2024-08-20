#include <iostream>
using namespace std;
int largest_element(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << "largest element of array is: " << largest;
}
int main()
{
    int arr[] = {1, 7, 3, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    largest_element(arr, n);

    return 0;
}