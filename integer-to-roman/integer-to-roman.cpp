class Solution {
public:
    string getRomanThousandsPlace(int n) {
        string s = "";
        for(int i=0; i<n; i++) s += 'M';
        return s;
    }
    
    string getRoman(int n, int place) {
        string s = "";
        
        if(n<=3 || (n>=5 && n<9)) {
            if(n>=5) {
                s+= place == 100 ? 'D' : place==10?'L':'V';
                n=n-5;
            }
            
            for(int i=0; i<n; i++)
                s+= place == 100 ? 'C' : place==10?'X':'I';
            
            return s;
        }
        
        if(n==4) return place == 100 ? "CD" : place==10? "XL":"IV";
        
        return place == 100 ? "CM" : place==10?"XC":"IX";
    }
    
    string intToRoman(int num) {
        string s = to_string(num);
        int i=0;
        string res = "";
        
        if(s.length()==4) {
            res += getRomanThousandsPlace(s[i]-'0');
            i++;
        }
        
        while(i<s.length()) {
            res += getRoman(s[i]-'0', pow(10, s.length()-i-1));
            i++;
        }
        
        return res;
    }
};