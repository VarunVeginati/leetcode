class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend==Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;
        
        boolean positive = (dividend<0 && divisor<0) || (dividend>0 && divisor>0);
        
        Long dividend_long = Long.valueOf(dividend);
        Long divisor_long = Long.valueOf(divisor);
        
        dividend_long = Math.abs(dividend_long);
        divisor_long = Math.abs(divisor_long);
        
        if(dividend_long < divisor_long) return 0;
        List<List<Long>> list = new ArrayList<List<Long>>();
        list.add(new ArrayList<Long>(Arrays.asList(Long.valueOf(divisor_long),Long.valueOf(1))));
        
        while(list.get(list.size()-1).get(0) <= dividend_long) {
            Long first = list.get(list.size()-1).get(0);
            Long second = list.get(list.size()-1).get(1);
            list.add(new ArrayList<Long>(Arrays.asList(first+first, second+second)));
        }
        
        int ans = 0;
        int i=list.size()-1;
        
        while(i>=0 && dividend_long>=divisor_long) {
            if(list.get(i).get(0) <= dividend_long) {
                ans += list.get(i).get(1);
                dividend_long -= list.get(i).get(0);
            }
            i--;
        }
        
        return positive ? ans : -ans;
    }
}