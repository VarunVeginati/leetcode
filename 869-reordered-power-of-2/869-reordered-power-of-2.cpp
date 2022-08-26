class Solution {
public:
    bool isPossible(int n, map<int,int> m) {
        while(n>0) {
            int a = n%10;
            n=n/10;
            if(m.find(a)==m.end()) return false;
            else {
                m[a]--;
                if(m[a]==0) m.erase(a);
            }
        }
        
        return m.size()==0;
    }
    
    bool reorderedPowerOf2(int n) {
        map<int,int> m;
        
        while(n>0) {
            m[n%10]++;
            n=n/10;
        }
        
        for(int i=0; i<30; i++) {
            if(isPossible(pow(2,i), m)) return true;
        }
        
        return false;
    }
};