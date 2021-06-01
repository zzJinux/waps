class Solution {
    public int solution(int[] money) {
        int N = money.length;
        int a1 = 0, a2 = money[0]; // robbed
        int b1, b2 = 0; // not
        for(int i=1; i<N; ++i) {
            b1 = b2;
            b2 = (a1 > a2 ? a1 : a2);
            a1 = a2;
            a2 = b1 + money[i];
            // a3 = b2 + money[i];
            // b3 = (a1 > a2 ? a1 : a2);
            // a1 = a2; a2 = a3;
            // b1 = b2; b2 = b3;
        }

        int answer = b2;
        a1 = 0; a2 = 0;
        b2 = 0;
        for(int i=1; i<N; ++i) {
            b1 = b2;
            b2 = (a1 > a2 ? a1 : a2);
            a1 = a2;
            a2 = b1 + money[i];
            // a3 = b2 + money[i];
            // b3 = (a1 > a2 ? a1 : a2);
            // a1 = a2; a2 = a3;
            // b1 = b2; b2 = b3;
        }
        int a = (a1 > a2 ? a1 : a2);
        return answer > a ? answer : a;
    }
}
