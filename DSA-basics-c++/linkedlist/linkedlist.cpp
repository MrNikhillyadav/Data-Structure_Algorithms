#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printLinkedList(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << endl;
        temp = temp -> next; 
    }
}


void insertAtHead(Node*& head, int val){

    Node* n = new Node(val);

    n -> next = head;
    head = n;

}

Node* getTail(Node* head){
    while(head->next != NULL){
        head = head -> next;
    }

    return head;
}

void insertAtTail(Node* head, int val){
    Node* n = new Node(val);
    Node* tail = getTail(head);
    tail -> next = n;
}

Node* getPrevNode(Node* head, int j){
    int k = 0;
    while(k < j){
        head = head -> next;
        k++;
    }

    return head;
}

void insertAtIndex(Node*& head, int index, int val){

    if(index == 0){
        insertAtHead(head,val);
        return;
    }

    Node* n = new Node(val);
    Node* prev = getPrevNode(head,index-1);

    if(prev == NULL){
        return;
    }

    n -> next = prev -> next;
    prev-> next = n;

}


int main(){

    
    Node* head = new Node(1);
    head -> next = new Node(2);
    head -> next->next = new Node(3);
    
    insertAtHead(head, 0);
    // printLinkedList(head);
    
    insertAtTail(head,4);
    insertAtIndex(head,2,25);
    insertAtIndex(head,0,50);
    printLinkedList(head);


    return 0;
}