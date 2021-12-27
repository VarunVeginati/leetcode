class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        long bin = 1;
        
        while(num>0) {
            if(num%2 == 0) {
                res = res + (bin);
            }
            bin = bin*2;
            num = num/2;
        }
        
        return res;
    }
};