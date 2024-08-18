#include<bits/stdc++.h>
using namespace std;

void rearrange(vector<int> &arr){
    int n=arr.size();
    int i=0;
    while(i<n){
        int correct=arr[i];
        if(arr[i]!=-1 && arr[i]!=arr[correct]){
            swap(arr[i],arr[correct]);
        }
        else{
            i++;
        }
    }

}


int main(){
    vector<int> arr= {1,-1,3,0,4,-1,6,-1,7,9};

    rearrange(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}