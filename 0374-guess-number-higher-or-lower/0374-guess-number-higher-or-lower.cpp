/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int bS(int l, int h) {
        int mid = l + (h-l)/2;
        
        int result = guess(mid);
        
        if(result==0) return mid;
        if(result==-1) return bS(l, mid-1);
        
        return bS(mid+1, h);
    }
    
    int guessNumber(int n) {
        return bS(1, n);
    }
};