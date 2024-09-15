#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    vector<int>PreviousSmallerElement(vector<int>& arr){
        int n=arr.size();
        vector<int> pse(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(arr[i]);
        }
        return pse;
    }

};

int main(){
    solution obj;
    vector<int> v{4,5,2,10,8};
    vector<int>result=obj.PreviousSmallerElement(v);
    cout<<"Previous Smaller Elemnet :  "<<endl;
    for(int i=0; i<result.size();i++){
        cout<<result[i]<<" ";
    }
}