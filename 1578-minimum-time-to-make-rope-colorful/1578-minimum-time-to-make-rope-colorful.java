class Solution {
    public int minCost(String colors, int[] neededTime) {
        int time = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        
        for(int i=0; i<colors.length(); i++) {
            pq.add(neededTime[i]);
            if(i!=colors.length()-1 && colors.charAt(i) != colors.charAt(i+1)) {
                while(pq.size()>1) {
                    time += pq.poll();
                }
                pq.clear();
            }
        }
        
        while(pq.size()>1) {
            time += pq.poll();
        }
        
        return time;
    }
}