class Pair implements Comparable<Pair>{
    private int cnt;
    private String word;
    
    public Pair(int cnt, String word) {
        this.cnt = cnt;
        this.word = word;
    }
    
    public int getCnt() {
        return this.cnt;
    }
    
    public String getWord() {
        return this.word;
    }
    
    @Override
    public int compareTo(Pair a) {
        if(this.cnt == a.cnt) {
            return this.word.compareTo(a.word);
        }
        
        return this.cnt > a.cnt ? -1:1;
    }
}

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        List<String> res = new ArrayList<String>();
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
        Map<String,Integer> map = new HashMap<String,Integer>();
        
        for(int i=0; i<words.length; i++) {
            int cnt = map.containsKey(words[i]) ? map.get(words[i]):1;
            map.put(words[i], cnt+1);
        }
        
        for(String word : map.keySet()){
            pq.add(new Pair(map.get(word), word));
        }
        
        while(k>0) {
            res.add(pq.poll().getWord());
            k--;
        }
        
        return res;
    }
}