import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) throws Exception {
        var vis = new boolean[completion.length];
    
    	Arrays.sort(completion);
    
    	for(String parti : participant) {
            
            int i = 0, j = completion.length;
            while(i < j) {
                int m = (i+j)/2;
                int d = completion[m].compareTo(parti);
                if(d == 0) {
                    if(vis[m]) i = m+1;
                    else j = m;
                } else if(d > 0) {
                    j = m;
                } else if(d < 0) {
                    i = m+1;
                }
            }
            
            if(i < completion.length && completion[i].equals(parti)) vis[i] = true;
            else return parti;
        }
        
        throw new Exception("unreachable");
    }
}

