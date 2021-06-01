import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) throws Exception {
        var vis = new boolean[completion.length];
        var harr = new int[completion.length];
        
        for(int i=0; i<harr.length; ++i) {
            harr[i] = completion[i].hashCode();
        }
    
    	Arrays.sort(harr);
    
    	for(String parti : participant) {
            int val = parti.hashCode();
            
            int i = 0, j = harr.length;
            while(i < j) {
                int m = (i+j)/2;
                if(harr[m] == val) {
                    if(vis[m]) i = m+1;
                    else j = m;
                } else if(harr[m] > val) {
                    j = m;
                } else if(harr[m] < val) {
                    i = m+1;
                }
            }
            
            if(i < harr.length && harr[i] == val) vis[i] = true;
            else return parti;
        }
        
        throw new Exception("unreachable");
    }
}
