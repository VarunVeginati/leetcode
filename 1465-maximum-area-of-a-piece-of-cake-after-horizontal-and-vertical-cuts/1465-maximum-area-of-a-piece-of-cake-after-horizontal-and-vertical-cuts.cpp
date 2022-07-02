class Solution {
public:
    
    int getModulo(long long a, long long b) {
        long long modulo = pow(10,9) + 7;
        return (a*b)%modulo;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        pair<int, int> hp = make_pair(0, h);
        pair<int, int> wp = make_pair(0, w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int area;
        
        int mx_h = horizontalCuts[0];
        
        for(int i=1; i<horizontalCuts.size(); i++) {
            mx_h = max(mx_h, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        
        mx_h = max(mx_h, h-horizontalCuts.back());
        
        int mx_w = verticalCuts[0];
        
        for(int i=1; i<verticalCuts.size(); i++) {
            mx_w = max(mx_w, verticalCuts[i]-verticalCuts[i-1]);
        }
        
        mx_w = max(mx_w, w-verticalCuts.back());
                
        return getModulo(mx_h, mx_w);
    }
};