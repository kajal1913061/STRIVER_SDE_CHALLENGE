Node *findMiddle(Node *head) {
    int len=0;
    Node *temp=head;
    while(head){
        len++;
        head=head->next;
    }
    int  k=ceil(len/2);

   
    while(k--){
       temp=temp->next; 
    }
    return temp;
}
