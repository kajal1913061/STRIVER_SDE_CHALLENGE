
// TC O(N) SC O(1)
bool detectCycle(Node *head)
{
    if(head==NULL)return false;
	Node *slow=head,*fast=head;
    while(slow && fast){
        fast=fast->next;
        if(fast)fast=fast->next;
        else
            return false;
        slow=slow->next;
        if(slow==fast)return true;
    }
    return false;
    
}
