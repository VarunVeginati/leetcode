class Solution {
    Map<String,Set<Character>> hm = new HashMap<String, Set<Character>>();
    Set<Integer> dupSet = new HashSet<Integer>();
    int mx = 0;
    
    boolean isUnique(List<Set<Character>> vec, String s) {
        for(int i=0; i<s.length(); i++) {
            Character c = s.charAt(i);
            for(int j=0; j<vec.size(); j++) {
                if(vec.get(j).contains(c)) return false;
            }
        }
        
        return true;
    }
    
    void bt(List<Set<Character>> vec, List<String> arr, int size, int start) {
        for(int i=start; i<arr.size(); i++) {
            if(!dupSet.contains(i) && isUnique(vec, arr.get(i))) {
                vec.add(hm.get(arr.get(i)));
                mx = Math.max(mx, size+arr.get(i).length());
                bt(vec, arr, size+arr.get(i).length(), i+1);
                vec.remove(vec.size()-1);
            }
        }
    }
    
    public int maxLength(List<String> arr) {
        
        for(int i=0; i<arr.size(); i++) {
            Set<Character> st = new HashSet<Character>();
            boolean flag = true;
            
            for(int j=0; j<arr.get(i).length(); j++) {
                if(st.contains(arr.get(i).charAt(j))) {
                    dupSet.add(i);
                    flag = false;
                    break;
                }
                st.add(arr.get(i).charAt(j));
            }
            
            if(flag) hm.put(arr.get(i), st);
        }
        
        List<Set<Character>> vec = new ArrayList<Set<Character>>();
        
        bt(vec, arr, 0, 0);
        
        return mx;
    }
}