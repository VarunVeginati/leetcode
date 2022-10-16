class Solution {
    public String similarRGB(String color) {
        return "#" + getClosestHex(color.substring(1,3)) + getClosestHex(color.substring(3,5)) + getClosestHex(color.substring(5));
    }
    
    public String getClosestHex(String s) {
        int hex = getHexValue(s);
        int val = hex/17;
        
        int a = getHexValue(String.valueOf(getChar(val)) + String.valueOf(getChar(val)));
        int b = getHexValue(String.valueOf(getChar(val+1)) + String.valueOf(getChar(val+1)));
        
        if((Math.abs(a-hex)) < Math.abs(b-hex)) return String.valueOf(getChar(val)) + String.valueOf(getChar(val));
        else return String.valueOf(getChar(val+1)) + String.valueOf(getChar(val+1));
    }
    
    public int getHexValue(String s) {
        return getValue(s.charAt(1)) + getValue(s.charAt(0))*16;
    }
    
    public int getValue(char c) {
        if((int) (c-'0') <=9) return (int) (c-'0');
        
        return (int) (c-'a'+10);
    }
    
    public char getChar(int n) {
        if(n<=9) return (char) (n+'0');
        
        return (char) (n-10+'a');
    }
}