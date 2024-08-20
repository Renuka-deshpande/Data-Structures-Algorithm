#include<bits/stdc++.h>
using namespace std;

int second_largest(vector<int>& arr,int n){
    int largest=arr[0];
    int slargest=-1;
    for (int i = 1; i <n; i++)
    {
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest=arr[i];
        }
    }
    return slargest;
}
int main(){
    vector<int> arr={2,1,5,6,7,8,9};
    int n= arr.size();
    cout<<second_largest(arr,n);
    return 0;
}