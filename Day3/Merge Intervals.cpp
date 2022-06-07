// TC O(nlogn) SC O(n)

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{  if(intervals.size()==0)return intervals;
      vector<vector<int>>ans;
     sort(intervals.begin(),intervals.end());// accd to start
     vector<int>cur=intervals[0];
        for(int i=0;i<intervals.size();i++){
            if(cur[1]<intervals[i][0]){
                ans.push_back(cur);
                cur=intervals[i];}
            else
                cur[1]=max(intervals[i][1],cur[1]);
        }
        ans.push_back(cur);
        return ans;
}
