class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return false;
        
        int peak = 0;
        
        for(int i=1; i<arr.size()-1; i++) {
            if(arr[i]<=arr[i-1]) return false;
            else if(arr[i]>arr[i+1]) {
                peak = i;
                break;
            }
        }
        
        if(peak == 0) return false;
        
        for(int i=peak+1; i<arr.size(); i++) {
            if(arr[i]>=arr[i-1]) return false;
        }
        
        return true;
    }
};