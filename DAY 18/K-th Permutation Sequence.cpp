// Using STL TC O(n!*n)

#include<bits/stdc++.h>
string kthPermutation(int n, int k) {
   string s="";
    for(int i=1;i<=n;i++){
        s+=to_string(i);
    }
    if(k==1)return s;
    if(k==0)return "";
    string nxt;
    int K=1;
    while(next_permutation(s.begin(),s.end())&&K<k){
        nxt=s;
        K++;
    }
  return nxt;     
}

// Using recursion TC O(N! * N) +O(N! Log N!) SC O(n)

#include<bits/stdc++.h>
void solve(string s,int idx,vector<string>&ans){
    if(idx==s.size()){
        ans.push_back(s);
        return;
    }
    for(int i=idx;i<s.size();i++){
        swap(s[i],s[idx]);
        solve(s,idx+1,ans);
        swap(s[i],s[idx]);
    }
}
string kthPermutation(int n, int k) {
   string s;
    vector<string>ans;
    for(int i=1;i<=n;i++){
        s+=to_string(i);
    }
    solve(s,0,ans);
    sort(ans.begin(),ans.end());
    auto it=ans.begin()+(k-1);
    return *it;
}

// using looping TC O(n^2) SC O(n)

string kthPermutation(int n, int k) {
    int fact=1;
    vector<int>num;
    string ans;
    for(int i=1;i<n;i++){
        fact*=i;
        num.push_back(i);
    }
    num.push_back(n);
    k=k-1;
    while(1){
        ans+=to_string(num[k/fact]);
        num.erase(num.begin()+k/fact);
        if(num.size()==0)break;
        k=k%fact;
        fact/=num.size();
    }
    return ans;
}

