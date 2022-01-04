Node* reverseDLL(Node * head)
{
    if((head == NULL) || (head->next == NULL)) return head;
    
    Node *curr = head, *temp;
    while(curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        
        curr = curr->prev;
    }
    
    return temp->prev;
}
