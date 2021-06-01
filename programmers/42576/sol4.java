import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion){
        var hm = new HashMap<String, Integer>();
        for(var elem : participant) {
            Integer val = hm.putIfAbsent(elem, 1);
            if(val != null) {
                hm.put(elem, val+1);
            }
        }
        
        for(var elem : completion) {
            Integer val = hm.get(elem);
            if(val == null) return elem;
            if(val - 1 == 0) hm.remove(elem);
            else hm.put(elem, val-1);
        }
        return (String)hm.keySet().toArray()[0];
    }
}
