class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_num=INT_MAX;
        int second_num=INT_MAX;
        
        for(int num: nums) {
            if(num < first_num)
                first_num = num;
            else if(num > first_num && num < second_num)
                second_num = num;
            else if(num > first_num && num > second_num)
                return true;
        }
        
        return false;
    }
};