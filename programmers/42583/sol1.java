import java.util.ArrayDeque;

class Truck {
    int leave; int weight;
}

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int N = truck_weights.length;
        var deque = new ArrayDeque<Truck>(bridge_length);

        int curIdx = 0, time=1, load=0;
        while(curIdx < N) {
            if(load + truck_weights[curIdx] > weight) {
                var leavingT = deque.poll();
                time = leavingT.leave;
                load -= leavingT.weight;
                continue;
            }
            var tr = new Truck();
            tr.leave = time + bridge_length;
            tr.weight = truck_weights[curIdx];
            deque.add(tr);
            load += tr.weight;
            ++time;
            ++curIdx;

            if(deque.peek().leave <= time) {
                load -= deque.poll().weight;
            }
        }
        return deque.peekLast().leave;
    }
}
