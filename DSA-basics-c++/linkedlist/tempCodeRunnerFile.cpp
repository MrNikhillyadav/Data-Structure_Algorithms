    head = new ListNode(1);
    head -> next =  new ListNode(2);
    head -> next-> next =  new ListNode(3);

    insertAtHead(head, 0);
    insertAtTail(head,4);
    insertAtIndex(head, 1, 25);

    printListNode(head);
    deleteAtHead(head);