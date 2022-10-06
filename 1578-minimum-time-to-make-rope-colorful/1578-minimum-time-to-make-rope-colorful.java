class Solution {
    public int minCost(String colors, int[] neededTime) {
        int time = 0;
        int sum = 0;
        int mx = 0;
        
        for(int i=0; i<colors.length(); i++) {
            sum += neededTime[i];
            mx = Integer.max(mx, neededTime[i]);
            if(i!=colors.length()-1 && colors.charAt(i) != colors.charAt(i+1)) {
                time += sum-mx;
                sum = 0;
                mx = 0;
            }
        }
        
        return time+(sum-mx);
    }
}