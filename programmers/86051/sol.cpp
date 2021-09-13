#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
	int sum=0;
	for(int a : numbers) {
		sum += a;
	}
    return 45-sum;
}
