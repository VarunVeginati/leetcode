class Solution {
public:
    int binary_search(long l, long r, long x) {
        while(r>=l) {
            long mid = (r+l)/2;
            
                
            if(mid*mid <= x && (mid+1)*(mid+1) > x) return mid;
            
            if((mid+1)*(mid+1) <= x) return binary_search(mid+1, r, x);
            
            return binary_search(l, mid-1, x);
        }
        return -1;
    }
    
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x==1) return 1;
        return binary_search(1, x/2, x);
    }
};