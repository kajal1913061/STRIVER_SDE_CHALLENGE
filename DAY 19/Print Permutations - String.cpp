#include<bits/stdc++.h>
// Recursion TC O(n!*n) SC O(n)
void solve(string &s,string ds,int freq[],vector<string>&ans){
    if(ds.size()==s.size()){
        ans.push_back(ds);
        return ;
    }
    for(int i=0;i<s.size();i++){
        if(!freq[i]){
            ds.push_back(s[i]);
           freq[i]=1;
            solve(s,ds,freq,ans);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
vector<string> findPermutations(string &s) {
   
    vector<string>ans;
    if(s.size()==0)return ans;
  int freq[s.size()]={0};     
   // string ds="";
  
    solve(s,"",freq,ans);
    return ans;
}

// Backtracting TC O(n!*n) SC O(1)

void solve(string s,int idx,vector<string>&ans){
    if(idx==s.size()){
        ans.push_back(s);
        return;
    }
    for(int i=idx;i<s.size();i++){
        swap(s[i],s[idx]);
        solve(s,idx+1,ans);
       swap(s[i],s[idx]);
        // swap(s[idx],s[i]);
    }
}
vector<string> findPermutations(string &s) {
    vector<string>ans;
    solve(s,0,ans);
}
    return ans;

}
