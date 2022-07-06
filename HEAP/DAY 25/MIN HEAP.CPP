#include<bits/stdc++.h>

void heapify(vector<int>&a,int i){
    int smallest=i,n=a.size();
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]<a[smallest])smallest=left;
    if(right<n && a[right]<a[smallest])smallest=right;
    if(smallest!=i){
        swap(a[i],a[smallest]);
        heapify(a,smallest);
    }
}
void insert(vector<int>&a,int val){
    int n=a.size();
    if(n==0)a.push_back(val);
    else
    {
        a.push_back(val);
        for(int i=(n/2)-1;i>=0;i--){
            heapify(a,i);
        }
    }
}

int del(vector<int>&a){
   
    int n=a.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(a,i);
    }
    int temp=a[0];
     swap(a[0],a[n-1]);
    a.pop_back();
    for(int i=n/2-1;i>=0;i--){
        heapify(a,i);
    }
    return {temp};
}




vector<int> minHeap(int n, vector<vector<int>>& q) {
  vector<int>ans;
    vector<int>a;
    int sz=q.size();
    for(int i=0;i<sz;i++){
        if(q[i][0]==0){
            insert(a,q[i][1]);
        }
        if(q[i][0]==1){
            ans.push_back(del(a));
        }
    }
    return ans;
}



// M2
#include<bits/stdc++.h>
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    multiset<int>st;
    vector<int>ans;
    for(auto &it : q){
        if(it[0] == 1){
            auto it = st.begin();
            ans.push_back(*it);
            st.erase(it);
        }else{
            st.insert(it[1]);
            
        }
    }
    return ans;
}
