class Solution {
public:
    
    int get_first_digit(int n) {
        string s = to_string(n);
        return (int)s[0]-48;
    }
    
    static bool compare(int a, int b) {  
        stringstream ss1(to_string(a)+to_string(b));
        stringstream ss2(to_string(b)+to_string(a));
        long s1 = 0;
        long s2 = 0;
        
        ss1 >> s1;
        ss2 >> s2;
        
        return s1>s2;
    }
    
    string get_string(string s, vector<int> vec) {
        for(int i=0; i<vec.size(); i++) {
            s += to_string(vec[i]);
        }
        stringstream ss(s);
        long s1 = 0;
        ss >> s1;
        
        if(s1==0) return "0";        
        return s;
    }
    
    string largestNumber(vector<int>& vec) {
        // int n = nums.size();
        // map<int, vector<int>> m; 
        
        // for(int i=0; i<n; i++) {
        //     m[get_first_digit(nums[i])].push_back(nums[i]);
        // }
        
        string res = "";
        
        // for(int i=9; i>=0; i--) {
            // vector<int> vec = m[i];
            // if(vec.size()>0) {
                sort(vec.begin(), vec.end(), compare);
                res = get_string(res, vec);
            // }
        // }
        
        return res;
    }
};