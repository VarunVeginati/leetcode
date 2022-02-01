class Solution {
public:
    int trailingZeroes(int n) {
        int twos = 0;
        int fives = 0;
        
        for(int i=1; i<=n; i++) {
            int a = i;
            while(a%2==0) {
                twos++;
                a=a/2;
            }
            while(a%5==0) {
                fives++;
                a=a/5;
            }
        }
        
        return min(twos,fives);
    }
};