#include<functional>
int main() {
	decltype(std::function{solution})::result_type ans;

	ans = solution({"1", "-", "3", "+", "5", "-", "8"});
	cout << ans << "\n";

	ans = solution({"5", "-", "3", "+", "1", "+", "2", "-", "4"});
	cout << ans << "\n";
	return 0;
}

