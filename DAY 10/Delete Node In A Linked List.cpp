/* 
NOTE:
• The reference to the head of the linked list is not given.
• The node to be deleted is not a tail node.
• The value of each node in the Linked List is unique.
• It is guaranteed that the node to be deleted is present in the linked list.


*/
// M1
void deleteNode(LinkedListNode<int> * node) {
  swap(node->data,node->next->data);
    node->next=node->next->next;
}

// M2
while(node->next!=NULL)
        {
            node->val=node->next->val;
            if(node->next->next==NULL)
            node->next=NULL;
            else
            node=node->next;
        }
