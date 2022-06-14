// Input--> k= 1   1 2 3 4 5 6 -1
//Output-->       2 3 4 5 6 -1


// 2 methods to solve this qust -->> TC O(N) SC O(1)
/*
1. Using slow and fast pointer.
2. counting the leng and and then subt k from it .Run the loop from starting to len-k and return the node.
*/
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(head==NULL || K==0)
           return head;
       
    
    LinkedListNode<int> *slow=head;
    LinkedListNode<int> *fast=head;
    for(int i=0;i<K;i++)
    {
        fast=fast->next;
    }
    
    if(fast==NULL)                    // if first element to be remove
    {
        return head->next;
    }
    
    while(fast->next!=NULL)       // move both pointers maintaining same diff
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;             // skip the nth node
     return head;
/* 

 if(head == NULL || K ==0)return head;
    int n=0;
    LinkedListNode<int>* cur=head;
    
    //calculate the length of linked list
    while(cur){
        n++;
        cur=cur->next;
    }
    //we have to delete k-n th from first 
    K =n-K;
    cur = head;
    LinkedListNode<int>* prev=NULL;
    while( K--){
        prev =cur;
        cur = cur -> next;
       
    }
    if(prev!= NULL){
        prev->next = cur -> next;
    }
    else{
        head=head -> next;
    }
    return head;
*/
}
