#include <stdio.h>
int main() {
	int a, b;
	char _b[4];
	scanf("%d %s", &a, _b);
	sscanf(_b, "%d", &b);
	printf("%d\n%d\n%d\n%d", a*(_b[2]-'0'), a*(_b[1]-'0'), a*(_b[0]-'0'), a*b);
	return 0;
}
