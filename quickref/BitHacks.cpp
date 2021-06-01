// calculate "popcount", Brian Kernighan's way
// 
// `v&=v-1` clears the LSB set.
unsigned pop_bk(unsigned v) {
	unsigned c;
	for(c=0;v;++c) v&=v-1;
	return c;
}

// iterate over all subsets of a bitset
// `A` is the original bitset
// This version excludes the empty set
for(unsigned s=A; s; s=(s-1)&A) {
	// Do something with `s`
}

// iterate over all combinations of K elements of N elements
unsigned b = (1<<K)-1;
while(b < 1<<N) {
	// b is, say, 010011100
	unsigned x = b&-b;
	unsigned y = b+x;  // y is 010100000
	// x             is 000000100
	// y             is 010100000
	// b&~y          is 000011100
	// (b&-y)/x >> 1 is 000000011
	// ... | y       is 010100011
	b = ((b&~y)/x >> 1) | y;
	// Do something with `b`
}
