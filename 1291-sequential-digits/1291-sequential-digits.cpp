class Solution {
public:
    
    int construct(int start, int n) {
        int sum = 0;
        for(int i=start; i<start+n; i++) {
            sum = (sum*10) + (i);
        }
        
        return sum;
    }
    
    int construct_1s(int n) {
        int sum = 0;
        for(int i=1; i<=n; i++) {
            sum = (sum*10) + (1);
        }
        
        return sum;
    }
    
    int total_digits(int n) {
        int cnt = 0;
        while(n>0) {
            cnt++;
            n=n/10;
        }
        
        return cnt;
    }
    
    int starting_digit(int n) {
        while(n>=10) {
            n=n/10;
        }
        
        return n;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        int n_l = total_digits(low);
        int n_h = total_digits(high);
        int start = starting_digit(low);
        
        vector<int> vec;
        
        for(int i=n_l; i<=n_h; i++) {
            int a = i==n_l? construct(start,i):construct(1,i);
            if(i==n_l && (i+start>10)) {
                continue;
            }
            int b = construct_1s(i);
            while(a<low) {
                a=a+b;
            }
            while(a%10 != 0 && a<=high) {
                vec.push_back(a);
                a=a+b;
            }
        }
        
        return vec;
    }
};