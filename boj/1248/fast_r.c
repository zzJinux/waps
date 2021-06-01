#include <stdio.h>
#include <stdlib.h>

int N, A, arr[10];

void go(int n) {
	if(n==0) {
		for(int i=0; i<N; ++i) {
			fprintf(stderr, "%2d ", arr[i]);
		}
		fputc('\n', stderr);
		fflush(stderr);

		printf("%d\n", N);
		for(int i=0; i<N; ++i) {
			int sum=0;
			for(int j=i; j<N; ++j) {
				sum+=arr[j];
				if(sum>0) {
					putchar('+');
				}
				else if(sum<0) {
					putchar('-');
				}
				else {
					putchar('0');
				}
			}
		}
		putchar('\n');
		fflush(stdout);
		return;
	}

	for(int x=-A; x<=A; ++x) {
		arr[n-1] = x;
		go(n-1);
	}
}

int main(int argc, char *argv[]) {
	A = strtol(argv[1], NULL, 10);
	N = strtol(argv[2], NULL, 10);

	go(N);
	puts("0");
	fflush(stdout);
	return 0;
}

