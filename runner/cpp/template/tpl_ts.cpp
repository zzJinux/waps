#include<functional>
int main() {
	std::decltype(std::function{solution})::result_type ans;

	ans = solution();
	cout << ans << "\n";
	return 0;
}

