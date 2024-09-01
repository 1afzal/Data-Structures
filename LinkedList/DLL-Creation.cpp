#include <bits/stdc++.h>
using namespace std;

class Node
{
    int val;
    Node* next; //next pointer 
    Node* back; //back pointer 
    

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

int main()
{
    int A[] = {10,20,30,40};
    return 0;
}
