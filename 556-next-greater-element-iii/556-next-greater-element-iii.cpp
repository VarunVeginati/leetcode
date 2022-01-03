class Solution {
public:
    vector<int> get_elements(int n) {
        vector<int> vec;
        while(n>0) {
            vec.push_back(n%10);
            n=n/10;
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
    
    long to_n(vector<int> vec) {
        long res=0;
        
        for(int i=0; i<vec.size(); i++) {
            res = (res*long(10))+long(vec[i]);
        }
        
        return res;
    }
    
    int nextGreaterElement(int n) {
        vector<int> nums = get_elements(n);
        
        int a=-1;
        int b;
        int i;
        int k;
        
        for(i=nums.size()-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                a = nums[i];
                break;
            }
        }
        
        if(a==-1) return -1;
        
        if(nums[i+1] > a) {
            b=nums[i+1];
            k=i+1;
        }
        
        for(int j=i+2; j<nums.size(); j++) {
            if(nums[j]>a && nums[j]<=b) {
                b=nums[j];
                k=j;
            }
        }
        
        nums[k] = a;
        nums[i] = b;
        
        vector<int> res = {nums.begin(), nums.begin()+i+1};
        
        for(int q=nums.size()-1; q>=i+1; q--) res.push_back(nums[q]);
        
        long ans = to_n(res);
        if(ans>2147483647) return -1;
        else return ans;
    }
};