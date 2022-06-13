LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
	LinkedListNode<int> *prev=NULL;
	LinkedListNode<int> *cur=head;
	LinkedListNode<int> *ford=NULL;
	while(cur!=NULL){
		ford=cur->next;
		cur->next=prev;
		prev=cur;
		cur=ford;
		
	}
	return prev;
    
}
