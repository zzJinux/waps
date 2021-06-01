class Solution {
public:
	int reverse(int _x) {
		int neg=0, M=0x7fFFffFF;
		unsigned x = _x;
		if(_x<0) {
			neg=1;
			x=~x+1;
		}
		int a=0, b=0;
		for(; x; x/=10) {
			a=a*10+b; b=x%10;
		}
		if(a>M/10 || a==M/10 && b>M%10+neg) return 0;
		else return neg?-a*10-b:a*10+b;
	}
};
