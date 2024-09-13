#include<bits/stdc++.h>
using namespace std;
class ministack{
    public:
    stack<int> st;
    int mini=INT16_MAX;
    void push(int val)
    {
        if(st.empty()){
            mini=val;
            st.push(val);}
        else if(val>mini){st.push(val);}
        else{
            st.push(2*val-mini);
            mini=val;
        }
    }

    void pop(){
        if(st.empty()){return ;}
        int n=st.top();
        st.pop();
        if(n<mini){
            mini=2*mini-n;
        }
    }

    int top(){
        int n=st.top();
        if(mini<n){return n;}
        return mini;
    }

    int getmini(){
        return mini;
    }

};

int main(){
    ministack ms;
    ms.push(3);
    ms.push(3);
    ms.push(5);
    cout << "Minimum: " << ms.getmini() << endl;  // Should print 3
    ms.push(2);
    ms.push(1);
    cout << "Minimum: " << ms.getmini() << endl;  // Should print 1
    ms.pop();
    cout << "Top: " << ms.top() << endl;          // Should print 2
    cout << "Minimum: " << ms.getmini() << endl;  // Should print 2
    ms.pop();
    cout << "Minimum: " << ms.getmini() << endl;  // Should print 3
    return 0;
}