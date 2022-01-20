class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MIN;
        
        for(int i=0; i<piles.size(); i++) {
            right = max(right, piles[i]);
        }
        
        while(left<right) {
            int mid = (left+right)/2;
            int cnt = 0;
            
            for(int i=0; i<piles.size(); i++) {
                if(piles[i]%mid==0) cnt += piles[i]/mid;
                else cnt += (piles[i]/mid)+1;
            }
            
            if(cnt<=h) right = mid;
            else left=mid+1;
        }
        
        return left;
    }
};