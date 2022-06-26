class Solution {
// private:
//     vector<int> cards;
//     map<pair<int,int>, int> memo;
    
public:
    
//     int dp(int i, int j, int k, int sum) {
//         if(k==0) {
//             return sum;
//         }
        
//         if(memo.find(make_pair(i,j)) != memo.end()) return memo[make_pair(i,j)];
        
//         memo[make_pair(i,j)] = sum+max(dp(i+1, j, k-1, cards[i]), dp(i, j-1, k-1, cards[j]));
        
//         return memo[make_pair(i,j)];
//     }
    
    int maxScore(vector<int>& cardPoints, int k) {
        // cards = cardPoints;
        // return dp(0, cardPoints.size()-1, k, 0);
        
        int maxSum = 0;
        int sum = 0;
        int i;
        
        for(i=0; i<k; i++) {
            sum += cardPoints[i];
        }
        
        if(k==cardPoints.size()) return sum;
        
        maxSum = sum;
        
        for(int j=cardPoints.size()-1; j>=cardPoints.size()-k; j--) {
            i--;
            sum = sum-cardPoints[i];
            sum+= cardPoints[j];
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};