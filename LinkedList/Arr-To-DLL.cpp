#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* next; //next pointer 
    Node* back; //back pointer 
    
    public:
    Node(int val1 , Node* next1 , Node* back1) //constructor with all parameters
    {
        val = val1;
        next = next1;
        back = back1;
    }

    Node(int val1) //constructor with only 1 parameter (data/Val)
    {
        val = val1;
        next = nullptr;
        back = nullptr;
    }
};

Node* ConvertArrToDLL(vector <int> A)
{
    Node* head = new Node(A[0]);
    Node* prev = head;

    for(int i = 0; i<A.size() ;i++)
    {
        Node* NewNode = new Node(A[i],nullptr,prev);
        prev->next = NewNode;
        prev = NewNode;
    }
    return head;
}

Node* PrintDLL(Node* head)
{
    Node* temp = head;

    while(temp != nullptr)
    {
        cout<<temp->val;
        cout<<endl;
        temp = temp->next;
    }
}
int main()
{
    vector <int> A = {10,20,30,40,50};

    Node* head = ConvertArrToDLL(A);
    cout<<endl;
    cout<<PrintDLL(head);
    
    //cout<<head->val;

    return 0;
}
