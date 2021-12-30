class Solution {
public:
    int smallestRepunitDivByK(int k) {
        set<int> seen_remainder;
        int length = 1;
        int remainder = 1;
        seen_remainder.insert(remainder);
        
        while(remainder%k!=0) {
            remainder = (remainder*10)+1;
            remainder = remainder%k;
            
            if(seen_remainder.find(remainder) != seen_remainder.end())
                return -1;
            else
                seen_remainder.insert(remainder);
            
            length++;
        }
        
        return length;
    }
};