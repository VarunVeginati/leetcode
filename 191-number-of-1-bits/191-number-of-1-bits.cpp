class Solution {
public:
    int hammingWeight(uint32_t n) {
        int s = 0;
        while(n>0) {
            if(n%2!=0)
                s+=1;
            n=n/2;
        }
        
        // cout << s << endl;
        
        return s;
    }
};