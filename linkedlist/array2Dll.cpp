#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node* back;
    Node(int data1, Node *next1 , Node* back1)
    {
        data = data1;
        next = next1;
        back=back1;
    }
    Node(int data2)
    {
        data = data2;
        next = nullptr;
        back=nullptr;
    }
};

//ARAAY TO DOUBLY LINKEDLIST
Node* Array2Dll(vector<int>& arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for (int i =1; i < arr.size(); i++)
    {
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

//PRINT
void print(Node* head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1, 3, 4, 6, 7};
    Node* head=Array2Dll(arr);
    print(head);
    return 0;
}