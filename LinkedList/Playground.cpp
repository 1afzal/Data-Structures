#include <bits/stdc++.h>

using namespace std;

// Define ListNode class 
class ListNode {
public:
    int data;   
    ListNode* next;     
    ListNode* back;     

    ListNode(int data1, ListNode* next1, ListNode* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    ListNode(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
ListNode* convertArr2DLL(vector<int> arr) {
    // Create the head node 
    ListNode* head = new ListNode(arr[0]);
    // Initialize 'prev' to head node
    ListNode* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        // Create a new node 
        ListNode* temp = new ListNode(arr[i], nullptr, prev);
        // Update 'next' pointer
        prev->next = temp; 
         // Move 'prev' 
        prev = temp;       
    }
    // Return head 
    return head;  
}

// Function to print the elements of the doubly linked list
void print(ListNode* head) {
    while (head != nullptr) {
        // Print the data in the current node
        cout << head->data << " ";  
         // Move to the next node
        head = head->next;         
    }
}

class Solution {
public:
    // Function to insert new node before head
    ListNode* insertBeforeHead(ListNode* head, int val) {
        // Create new node with data as val
        ListNode* newHead = new ListNode(val, head, nullptr);
        head->back = newHead;

        return newHead;
    }
};

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    ListNode* head = convertArr2DLL(arr);
    
    print(head);
    cout << endl << "Doubly Linked List After Inserting 6 before head: " << endl;
    Solution solution;
    head = solution.insertBeforeHead(head, 6);
    print(head);

    return 0;
}
