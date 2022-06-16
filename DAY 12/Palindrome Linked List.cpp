// M1 using extra space vector
bool isPalindrome(LinkedListNode<int> *head) {
    vector<int>v;
    LinkedListNode<int> *temp=head;
    while(temp){
        v.push_back(temp->data);
        temp=temp->next;
    }
    vector<int>x=v;
    reverse(v.begin(),v.end());
    if(x==v)return true;
    return false;

}

// M2 -->reverse ll after middle of ll and then compare head and after middle of ll
LinkedListNode<int> *reverseList(LinkedListNode<int> *head){
    LinkedListNode<int> *pre=NULL;
    LinkedListNode<int> *nex=NULL;
    
    while(head!=NULL){
        nex=head->next;
        head->next=pre;
        pre=head;
        head=nex;
    }
    return pre;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL || head->next==NULL){
        return true;
    }
    LinkedListNode<int> *slow=head;
    LinkedListNode<int> *fast=head;
    
    // Find Middle of The Linked List
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    // Reverse the Linked List
    slow->next=reverseList(slow->next);
    
    //Move slow to right half
    slow=slow->next;
    
    //Check If Left Half elements are equal to right half elements
    while(slow!=NULL){
        if(head->data!=slow->data){
            return false;
        }
        head=head->next;
        slow=slow->next;
    }
    return true;

}
