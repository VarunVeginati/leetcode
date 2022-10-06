class Pair implements Comparable<Pair>{
    public int timeStamp;
    public String value;
    
    public Pair(int timeStamp, String value) {
        this.timeStamp = timeStamp;
        this.value = value;
    }
    
    public int compareTo(Pair p1) {
        return this.timeStamp>p1.timeStamp?1:-1;
    }
    
    public int getTimeStamp() {
        return this.timeStamp;
    }
    
    public String getValue() {
        return this.value;
    }
}

class TimeMap {
    Map<String, ArrayList<Pair>> hm = new HashMap<String, ArrayList<Pair>>();
    
    public TimeMap() {
        
    }
    
    public void set(String key, String value, int timestamp) {
        if(hm.containsKey(key)) {
            hm.get(key).add(new Pair(timestamp, value));
        } else {
            hm.put(key, new ArrayList<Pair>());
            hm.get(key).add(new Pair(timestamp, value));
        }
    }
    
    public String getLowerBound(ArrayList<Pair> timeArray, int l, int r, int target) {
        while(l<r) {
            int mid = l + ((r-l)/2);
            
            if(timeArray.get(mid).getTimeStamp() == target) {
                return timeArray.get(mid).getValue();
            } else if(target > timeArray.get(mid).getTimeStamp() && target < timeArray.get(mid+1).getTimeStamp()) {
                return timeArray.get(mid).getValue();
            } else if(target > timeArray.get(mid).getTimeStamp()){
                return getLowerBound(timeArray, mid+1, r, target);
            } else {
                return getLowerBound(timeArray, l, mid-1, target);
            }
        }
        
        return "";
    }
    
    public String get(String key, int timestamp) {
        if(!hm.containsKey(key)) return "";
        ArrayList<Pair> pl= hm.get(key);
        
        if(timestamp < pl.get(0).getTimeStamp()) return "";
        if(timestamp >= pl.get(pl.size()-1).getTimeStamp()) return pl.get(pl.size()-1).getValue();
        
        return getLowerBound(pl, 0, pl.size()-1, timestamp);
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */