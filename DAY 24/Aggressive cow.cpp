// TC O(nlogm) SC O(1)
#include<bits/stdc++.h>
bool isposs(vector < int > inp,int cows,int dist) {
  int n = inp.size();
  int lastplace = inp[0];
  int cow=1;
  for (int i = 1; i < n; i++) {
    if (inp[i] -lastplace>= dist) {
      cow++;
        lastplace=inp[i];
      
    }
  }
    if(cow>=cows)return true;
  return false;
}
int chessTournament(vector<int> pos , int n ,  int c){
	sort(pos.begin(),pos.end());
    int h=pos[n-1]-pos[0];
    int s=0;

    while(s<=h){
        int mid=s+(h-s)/2;
        if(isposs(pos,c,mid)){
            s=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return h;
}
