class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0];
        int max_profit=0;
        
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]>min_val) {
                max_profit = max(max_profit, prices[i]-min_val);
            } else {
                min_val=prices[i];
            }
        }
        
        return max_profit;
    }
};