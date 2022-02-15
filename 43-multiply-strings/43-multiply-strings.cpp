class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2== "0") return "0";
        if(num1.length()<num2.length())
            return multiply(num2, num1);
        
        vector<vector<char>> res;
        int mx = 0;
        
        for(int i=num2.length()-1; i>=0; i--) {
            int carry = 0;
            vector<char> vec;
            for(int k=0; k<num2.length()-i-1; k++) {
                vec.push_back('0');
            }
            for(int j=num1.length()-1; j>=0; j--) {
                string s = to_string(((int)num2[i]-48)*((int)num1[j]-48)+carry);
                if(s.length()>1) {
                    vec.push_back(s[1]);
                    carry = (int)s[0]-48;
                } else {
                    vec.push_back(s[0]);
                    carry = 0;
                }
            }
            if(carry>0) {
                vec.push_back(to_string(carry)[0]);
            }
            res.push_back(vec);
            if(vec.size()>mx)
                mx = vec.size();
        }
        
        int carry = 0;
        string s = "";
        
        for(int i=0; i<mx; i++) {
            int tmp = 0;
            for(int j=0; j<res.size(); j++) {
                if(res[j].size()>i) {
                    tmp += (int)res[j][i]-48;
                }
            }
            tmp += carry;
            if(tmp>9) {
                s += to_string(tmp%10);
                carry = tmp/10;
            } else {
                s+=to_string(tmp);
                carry = 0;
            }
        }
        
        if(carry>0) {
            s += to_string(carry);
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};