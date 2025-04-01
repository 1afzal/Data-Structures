#include <bits/stdc++.h>
using namespace std;

struct ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int data1, ListNode* next1){
        data = data1;
        next = next1;
    }
    ListNode(int data1){
        data = data1;
        next = nullptr;
    }
};

ListNode* printLL(ListNode* head){
    if(head == nullptr){
        cout << "Empty list" << endl;
        return head;
    }
    ListNode* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}

vector<int> LLtoVector(ListNode* head){
    vector<int> ans;
    ListNode* temp = head;
    while(temp != nullptr){
        ans.push_back(temp->data);
        temp = temp->next;
    }
    return ans;
}

ListNode* delHead(ListNode* head){
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}

ListNode* delTail(ListNode* head){
    if(head == nullptr) {
        return nullptr;
    }
    if(head->next == nullptr) {
        delete head;
        return nullptr;
    }

    ListNode* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;  // Set the new tail's next to nullptr
    return head;
}

ListNode* delKth(ListNode* head, int k){
  if(head == NULL){
    return NULL;
  }

  if(k == 1){
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head; 
  }
  ListNode* temp = head;

  for(int i=0;temp != NULL && i < k-2;i++){
    temp = temp -> next;
  }
  if(temp == NULL || temp->next == NULL){
    return NULL;
  }

  // 10 -> K -> 20
  //go to 10 
  //next = temp->next->next; (20)
  //now delete middle Kth value and link temp to next
  ListNode* next = temp->next->next;
  delete temp->next;
  temp->next = next;

  return head;
}

ListNode* delX(ListNode* head, int X){
  if(head == NULL){
    return NULL;
  }
   //if first node value itself is X 
  if(head->data == X){
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  
  ListNode* temp = head;
  ListNode* prev = NULL;
  //we connect previous to next of temp and then delete temp.
  while(temp != NULL){
    if(temp->data == X){
      prev->next = temp->next; 
      delete temp;
      return head;
    }
    prev = temp;
    temp = temp->next;
    
  }
  return head;
}

ListNode* insertHead(ListNode* head, int val){
  ListNode* newNode = new ListNode(val);
  newNode->next = head;
  head = newNode;
  return head;
}

ListNode* insertTail(ListNode* head, int val){
    if(head == NULL){
        return NULL;
    }
    ListNode* temp = head;

    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    ListNode* newNode = new ListNode(val);
    temp->next = newNode;
    newNode->next = nullptr;
    return head;
}

// Function to clean up the entire linked list
void deleteList(ListNode* head) {
    ListNode* current = head;
    ListNode* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

int main(){
    ListNode* node1 = new ListNode(10);
    ListNode* node2 = new ListNode(20);
    ListNode* node3 = new ListNode(30);
    ListNode* node4 = new ListNode(40);
    ListNode* node5 = new ListNode(50);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    cout << "Original linked list:" << endl;
    printLL(node1);

    // Delete head test
    cout << "After deleting head of linked list:" << endl;
    ListNode* newHead = delHead(node1);
    printLL(newHead);  // Now newHead is node2 (20)

    // Delete tail test
    cout << "After deleting tail of linked list:" << endl;
    ListNode* afterTailDel = delTail(newHead);
    printLL(afterTailDel);  // List should be 20, 30, 40

    // Clean up remaining nodes properly
    deleteList(afterTailDel);

    ListNode* insertedHead = insertHead(node1, 69);
    printLL(newHead);

    ListNode* newTail = insertTail(node1 , 69);
    printLL(newTail);

    return 0;
}