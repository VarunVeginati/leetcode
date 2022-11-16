class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        long divid = dividend;
        long divis = divisor;
        
        bool sign = true;
        if(dividend<0 && divisor>0) sign = false;
        if(dividend>0 && divisor<0) sign =false;
        
        if(dividend < 0) divid = dividend*(long)-1;
        if(divisor < 0) divis = divisor*(long)-1;
        
        if(divis>divid) return 0;
        
        long ans = 1;
        long sum = divis;
        
        while(sum<divid) {
            sum = sum*2;
            ans = ans*2;
        }
        
        if(sum==divid) return sign? ans:-1*ans;
        
        long res = ans/2 + divide(divid-sum/2 , divis);
        
        return sign?res:-1*res;
    }
};