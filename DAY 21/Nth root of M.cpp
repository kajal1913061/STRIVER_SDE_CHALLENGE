
// M1 using binary search
double findNthRootOfM(int n, long long m) {
	
	 double low = 1;
    double high = m;
    double eps = 1e-7; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(pow(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
	return low;
}
// M2
double findNthRootOfM(int n, long long m) {
    // Write your code here.
    double t=1.000000/n;
    double ans=pow(m,t);
    return ans;
}
