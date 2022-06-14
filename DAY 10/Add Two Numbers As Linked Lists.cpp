Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node *dummy=new Node(0);
    Node *l1=head1,*l2=head2,*cur=dummy;
    int carry=0;
    while(l1 || l2){
        int x=(l1!=NULL)?l1->data:0;
        int y=(l2!=NULL)?l2->data:0;
        int sum=x+y+carry;
        carry=sum/10;
        cur->next=new Node(sum%10);
        cur=cur->next;
        
        if(l1)l1=l1->next;
        if(l2)l2=l2->next;
    }
    if(carry>0)cur->next=new Node(carry);
    return dummy->next;
}
