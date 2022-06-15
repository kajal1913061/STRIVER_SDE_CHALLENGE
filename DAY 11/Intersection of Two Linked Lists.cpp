 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Brtue force TC O(n^m) SC O(1)
    /*     ListNode *temp;
        while(headA!=NULL){
           temp=headB;
            while(temp!=NULL){
                if(temp==headA)return temp;
                temp=temp->next;
            }
            headA=headA->next;
        }
        return 0; 
        */
        
        // using hashmap TC o(n+m) SC o(n)
   /*     unordered_map<ListNode*,int>m;
        while(headA){
            m[headA]++;
            headA=headA->next;
        }
       
        
        while(headB){
            if(m[headB]>0)return headB;
            headB=headB->next;
        }
        
     return NULL;   */
        
        // Lenght difference  TC O(N+M) SC O(1)
      /*  ListNode *pa=headA,*pb=headB;
        int a=0,b=0;
        while(pa){
            a++;
            pa=pa->next;
        }
        while(pb){
            b++;
            pb=pb->next;
        }
        int d=abs(a-b);
        if(a>b){
            while(d--){
                headA=headA->next;
            }
        }
        else{
            while(d--){
                headB=headB->next;
            }
        }
        while(headA && headB){
            if(headA==headB)return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL; */
        
        // 2 pointer TC O(n+m) SC O(1)
        ListNode *Ha=headA,*Hb=headB;
        while(Ha!=Hb){
            Ha=Ha?Ha->next:headB;
            Hb=Hb?Hb->next:headA;
        }
       return Ha; 
    }
