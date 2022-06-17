Node *rotate(Node *head, int k) {
  if(head == NULL||head->next == NULL) return head;
    // TC O(n*k) SC O(1)
     for(int i=0;i<k;i++) {
        Node* temp = head;
        while(temp->next->next != NULL)temp = temp->next;
        Node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}
