/*vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    priority_queue<int>pq;
    vector<int>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(a[i]+b[j]);
        }
    }
    for(int i=0;i<k;i++){
        int a=pq.top();
        pq.pop();
        v.push_back(a);
    }
    return v;
}*/

// M2 TC O(nlogn)
vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int C) {
    vector<int> ans;
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    priority_queue<pair<int, pair<int, int>>> pq; // A[i]+B[j], <i, j>
    set<pair<int, int>> vis; // i, j
    
    pq.push({A[0]+B[0], {0 ,0}});
    vis.insert({0, 0});
    
    for(int i=0; i<C; ++i) {
        auto p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        
        if(p.second.first+1 < n && vis.find({p.second.first+1, p.second.second}) == vis.end()) {
            vis.insert({p.second.first+1, p.second.second});
            int x = A[p.second.first+1] + B[p.second.second];
            pq.push({x, {p.second.first+1, p.second.second}});
        }
        if(p.second.second+1 < n && vis.find({p.second.first, p.second.second+1}) == vis.end()) {
            vis.insert({p.second.first, p.second.second+1});
            int x = A[p.second.first] + B[p.second.second+1];
            pq.push({x, {p.second.first, p.second.second+1}});
        }
    }
    
    return ans;
}
