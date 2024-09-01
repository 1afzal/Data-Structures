#include <bits/stdc++.h>
using namespace std;

class Node
{
 public:
    int data;
    Node* next;
    Node* back;

 public:
    Node(int data1 , Node* next1 , Node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) //constructor with only 1 parameter (data/Val)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

Node* Convert(vector <int> Arr)
{
    Node* head = new Node(Arr[0]);
    Node* prev = head;

    for(int i=1 ; i<Arr.size();i++)
    {
        Node* NewNode = new Node(Arr[i],nullptr,prev);
        prev->next = NewNode;
        prev = NewNode;
    }
    return head; 
}

void printDLL(Node* head)
{
    Node* temp = head;

    while(temp != nullptr)
    {
        cout<<temp->data<<"->";
        temp = temp->next;        
    }
}

Node* InsertBeforeHead(Node* head,int val)
{
    //since before head so this node should point to head and back should point to nullptr
    Node* NewNode = new Node(val,head,nullptr) ;//(data , next , prev)
    head->back = NewNode;
    return  NewNode;
}

Node* InsertBeforeLast(Node* head,int val)
{
    if(head->next == nullptr)
    {
        return InsertBeforeHead(head,val);
    }
    Node* LastNode = head;

    while(LastNode->next != nullptr)
    {
        LastNode = LastNode->next;
    }
    Node* prev = LastNode->back;
    Node* NewNode = new Node(val,LastNode,prev);

    prev->next = NewNode;
    LastNode->back = NewNode;

    return head;
}
Node* InsertKthPos(Node* head , int val ,int k)
{
    int cnt = 0;
    Node* temp = head;

    while(temp->next != nullptr)
    {
        cnt++;
        if(cnt== k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* NewNode = new Node(val , temp , prev);
    prev->next = NewNode;
    temp->back = NewNode;
    return head;
}

Node* deleteFirst(Node* head)
{
    if(head == nullptr || head->next == nullptr )
    {
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

int main()
{
    vector <int> Arr {10,20,30,40,50};
    Node* head = Convert(Arr);  //converts from Array (vector) to LinkedList 

    cout<<"Linked list values are: "<<endl;
    printDLL(head);
    cout<<endl;

    head = InsertBeforeHead(head,100);
    cout<<"Linked list values after inserting new head: "<<endl;
    printDLL(head);

    head = InsertBeforeLast(head,69);
    cout<<endl;

    cout<<"List after adding new node before last node"<<endl;

    printDLL(head);
    cout<<endl;

    cout<<"List after adding new node before last node"<<endl;
    head = InsertKthPos(head,999,3);
    printDLL(head);

    
    

    return 0;
}