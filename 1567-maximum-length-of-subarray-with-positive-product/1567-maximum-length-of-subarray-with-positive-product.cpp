class Solution {
public:
    
    int max_of_nums(vector<int> nums) {
        int num_neg = 0;
        int last_neg;
        int first_neg = -1;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 0) {
                num_neg++;
                last_neg=i;
                if(first_neg==-1) first_neg = i;
            }
        }
        
        if(num_neg%2==0) return nums.size();
        else{
            int m = nums.size()-first_neg-1;
            int n = nums.size()-last_neg-1;
            int m_a =  max(first_neg, m);
            int n_a = max(last_neg, n);
            return max(m_a, n_a);
        }
    }
    
    int getMaxLen(vector<int>& nums) {
        int mx = 0;
        vector<int> vec;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=0){
                vec.push_back(nums[i]);
            } else if(vec.size()>0) { 
                mx = max(mx, max_of_nums(vec));
                vec = {};
            }
        }
        
        if(vec.size()>0) mx = max(mx, max_of_nums(vec));
        
        return mx;
    }
};