Node *firstNode(Node *head)
{
	Node *slow=head,*fast=head;
    if(head==NULL || head->next==NULL)return NULL;
    while(slow && fast){
        fast=fast->next;
        if(fast)fast=fast->next;
        slow=slow->next;
        if(slow==fast)break;
       }
    if(slow!=fast)return NULL;
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
