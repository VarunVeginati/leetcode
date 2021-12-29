class Solution {
public:
    int arrangeCoins(int n) {
        long a = 1+(long(8)*n);
        int sqr = sqrt(a);
        return (sqr-1)/2;
    }
};