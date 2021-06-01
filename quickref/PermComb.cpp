#include <iostream>
#include <vector>

template<typename T>
struct CombUtil {
	std::vector<T> const &elements;

	CombUtil(std::vector<T> const &elements): elements(elements) {}

	void processAll(int K) {
		std::vector<T> working(K);
		processRecur(0, 0, K, working);
	}

	void processRecur(int pickFrom, int nextLoc, int K, std::vector<T> &working) {
		if(nextLoc == K) {
			process(working);
			return;
		}

		for(int i=pickFrom; i<elements.size(); ++i) {
			working[nextLoc] = elements[i];
			// K-(nextLoc+1): # of slots to fill
			// N-(i+1)      : # of remaining elements
			if(K-nextLoc <= elements.size()-i) {
				processRecur(i+1, nextLoc+1, K, working);
			}
		}
		
	}

	void process(std::vector<T> &v) {
		for(auto e:v) {
			std::cout << e;
		}
		std::cout << std::endl;
	}
};

int main() {

	std::vector<int> example{1,2,3,4,5,6};
	CombUtil<int> cm(example);

	cm.processAll(3);
}


