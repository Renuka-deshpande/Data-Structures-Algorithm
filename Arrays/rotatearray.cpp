#include<bits/stdc++.h>
using namespace std;

void rotation(vector<int>& arr,int p){
    int n=arr.size();
    p=p%n;

    reverse(arr.begin(),arr.begin()+p);
    reverse(arr.begin()+p,arr.end());
    reverse(arr.begin(),arr.end());

}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9};
    int p=4;
    rotation(arr,p);

    for (int i = 0; i <arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
