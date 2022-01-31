class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        if(numerator==0) return "0";
        string out = "";
        if(numerator<0 && denominator<0) {
            numerator = abs(numerator);
            denominator = abs(denominator);
        } else if(numerator<0 || denominator<0) {
            numerator = abs(numerator);
            denominator = abs(denominator);
            out += "-";
        }
        out += to_string(numerator/denominator);
        if(numerator%denominator == 0) return out;
        int dot_pos = out.length();
        out += '.';
        int z = dot_pos;
        numerator = (numerator%denominator)*10;
        map<int,int> m;
        
        while(numerator > 0 && m.find(numerator)==m.end()) {
            z++;
            out += to_string(numerator/denominator);
            m[numerator] = z;
            numerator = (numerator%denominator)*10;
        }
        
        if(numerator>0) {
            string res = "";
            for(int i=0; i<m[numerator]; i++)
                res += out[i];
            res += '(';
            for(int i=m[numerator]; i<out.length(); i++)
                res += out[i];
            res += ')';
            return res;
        }
        
        return out;
    }
};