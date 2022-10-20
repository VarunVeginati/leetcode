class Solution {
    String thousands(int n) {
        String str = "";
        for(int i=1; i<=n; i++) {
            str += 'M';
        }
        return str;
    }
    
    String hto(int n, double d) {
        String str = "";
        if(n<=3) {
            for(int i=1; i<=n; i++) {
                if(d==100) str += 'C';
                if(d==10) str += 'X';
                if(d==1) str += 'I';
            }
            return str;
        } else if(n==4) {
            if(d==100) return "CD";
            if(d==10) return "XL";
            if(d==1) return "IV";
        } else if(n<=8) {
            if(d==100) str += 'D';
            if(d==10) str += 'L';
            if(d==1) str += 'V';
            
            for(int i=1; i<=n-5; i++) {
                if(d==100) str += 'C';
                if(d==10) str += 'X';
                if(d==1) str += 'I';
            }
            return str;
        } else {
            if(d==100) return "CM";
            if(d==10) return "XC";
            if(d==1) return "IX";
            else return "";
        }
        return str;
    }
    
    public String intToRoman(int num) {
        String res = "";
        int i=0;
        
        while(num>0 && i<3) {
            res = hto(num%10, Math.pow(10,i)) + res;
            num = num/10;
            i++;
        }
        
        while(num>0) {
            res = thousands(num%10)+res;
            num = num/10;
        }
        
        return res;
    }
}