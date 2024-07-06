Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;

    while(current!=NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }