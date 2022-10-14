class Solution {
    public boolean isPalindrome(String s) {
        for(int i=0; i<s.length()/2; i++) {
            if(s.charAt(i) != s.charAt(s.length()-i-1)) return false;
        }
        
        return true;
    }
    
    public String breakPalindrome(String palindrome) {
        if(palindrome.length()==1) return "";
        
        for(int i=0; i<palindrome.length(); i++) {
            if(palindrome.charAt(i) != 'a') {
                if(!isPalindrome(palindrome.substring(0,i) + 'a' + palindrome.substring(i+1)))
                    return palindrome.substring(0,i) + 'a' + palindrome.substring(i+1);
            }
        }
        
        return palindrome.substring(0, palindrome.length()-1) + 'b';
    }
}