#include <iostream>
using namespace std;

class ListNode {
    public :

        int data;
        ListNode* next;

        ListNode ( int data ){
            this->data = data;
            this->next = NULL;
        }
};

void printListNode(ListNode* head){

    ListNode* temp = head;

    while(temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtHead( ListNode*& head, int data){
    ListNode* n = new ListNode(data);
    n -> next = head;
    head = n;

}

ListNode* getTailNode(ListNode* head){
    if(head == NULL){
        return nullptr;
    }

    ListNode* temp = head;

    while( temp -> next != NULL){
        temp = temp -> next;
    }

    return temp;
}

void insertAtTail(ListNode* head, int data){
    ListNode* n = new ListNode(data);
    ListNode* tail = getTailNode(head);
    tail -> next = n;
}

ListNode* getPrevNode(ListNode* head, int i){
    ListNode* temp = head;
    int k = 0;
    while(k < i ){
        temp = temp -> next;
        k++;
    }

    return temp;

}

void insertAtIndex(ListNode* head, int index, int data){
    ListNode* n = new ListNode(data);
    ListNode* prev = getPrevNode(head,index -1);

    if(prev == NULL){
        return;
    }
    n -> next = prev -> next;
    prev ->next = n;
}

// pass head pointer by reference as head is being changed and should get reflected in main.
void deleteAtHead(ListNode*& head){
    ListNode* temp = head;

    if(head == NULL){
        return;
    }
    head = head -> next;
    delete temp;
}

void deleteAtTail(ListNode* head){
    // Edge case : if its an empty list, no nodes
    if(head == NULL){
        return;
    }

    // Edge case : If its a single node
    if( head -> next == NULL){
        deleteAtHead(head);
        return;
    }

    ListNode* prev = NULL;
    ListNode* tail = head;

    while(tail -> next != NULL){
        prev = tail;
        tail = tail -> next;
    }

    prev -> next = NULL;
    delete tail;
}

int ComputeIterativeLength(ListNode* head){
    if(head == NULL){
        return 0;
    }
    int i = 0;
    ListNode* temp = head;

    while(temp != NULL){
        i++;
        temp = temp -> next;
    }

    return i;

}

int ComputeRecursiveLength(ListNode* head){
    if (head == NULL){
        return 0;
    }

    int A = ComputeRecursiveLength(head -> next);
    return A + 1;
}

bool SearchLinkedListIteratively(ListNode* head, int target){
    ListNode* temp = head;

    if(head == NULL){
        return false;
    }

    while(temp != NULL){
        if(temp -> data == target){
           return true;
        }
        temp = temp -> next;
    }

    return false;
}

bool SearchLinkedListRecursively(ListNode* head, int target){
    if(head == NULL){
        return false;
    }

    if( head -> data == target){
        return true;
    }else {
        SearchLinkedListRecursively(head -> next, target);
    }
}

ListNode* ReverseLinkedListRecursive(ListNode* head){`
    if(head == NULL){
        return head;
    }

    if(head -> next == NULL){
        return head;
    }

    ListNode* revHead = ReverseLinkedListRecursive(head -> next);
    head -> next -> next = head;
    head -> next = NULL;

    return revHead;
    
}

int main(){
    // compute length of ll iteratively and recursively
    // search the linkedlist iteratively or recursively
    // reverse the linkedlist iteratively or recursively

    ListNode* head = new ListNode(1);
    head -> next =  new ListNode(2);
    head -> next-> next =  new ListNode(3);

    insertAtHead(head, 0);
    insertAtTail(head,4);
    insertAtIndex(head, 1, 25);

    // deleteAtHead(head);
    // deleteAtTail(head);
    
    // cout << "length of LL is: " << ComputeIterativeLength(head) << endl;
    // cout << "length of LL is: " << ComputeRecursiveLength(head) << endl;
    
    printListNode(head);
    // SearchLinkedListIteratively(head, 100) ? cout << "found" << endl : cout << "not found";
    // SearchLinkedListRecursively(head, 0) ? cout << "found" << endl : cout << "not found";
    
    head = ReverseLinkedListRecursive(head);
    printListNode(head);

    return 0;
}