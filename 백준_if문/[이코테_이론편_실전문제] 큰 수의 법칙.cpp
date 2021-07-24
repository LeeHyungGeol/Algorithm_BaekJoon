#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, cnt, answer;
vector<int> nums;

int main() {
	cin >> N >> M >> K;

	nums.resize(N, 0);

	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}

	sort(nums.rbegin(), nums.rend());

	int first = nums[0], second = nums[1];

	cnt = (M / (K + 1)) * K;
	cnt += (M % (K + 1));

	answer += cnt * first;
	answer += (M - cnt) * second;

	cout << answer << '\n';

	return 0;
}