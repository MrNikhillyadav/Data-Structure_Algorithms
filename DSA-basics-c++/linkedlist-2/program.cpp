#include <iostream>
using namespace std;

class ListNode {
    public :
        int data;
        ListNode* next;

        ListNode(int data){
            this->data = data;
            this -> next = NULL;
        }
};

void printLinkedList(ListNode* head) {
    ListNode* temp = head; 
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


bool hasCycle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if( fast == slow) return true;
    }
    return false;
}

// remove the cycle in the linkedlist
void removeCycle(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;

    while( true){
        slow = slow -> next;
        fast = fast->next->next;
        if( slow == fast) break;;
    }

    slow = head;

    while(slow -> next != fast -> next){
        slow = slow -> next;
        fast = fast->next; 
    }
    fast->next = NULL;
    return;
}


int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);
    head->next->next->next->next->next->next = head->next->next;

    // detect cycle in LL (infinte loop)
    hasCycle(head) ? cout << "cycle found" << endl : cout << "cycle not found" << endl;
    
    
    // remove cycle and print
    removeCycle(head);

    hasCycle(head) ? cout << "cycle found": cout << "cycle not found"<< endl;
    printLinkedList(head);

    return 0;
}