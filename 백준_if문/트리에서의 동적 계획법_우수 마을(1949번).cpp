#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>//memset
using namespace std;
int N;// (1¡ÂN¡Â10,000)
int arr[10001] = { 0 };
int dp[10001][2] = { 0 };
vector<int> tree[10001];
int func(int cur, int select, int prev);
int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	int from, to;
	for (int i = 1; i <= N - 1; ++i) {
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}
	memset(dp, -1, sizeof(dp));
	int ret1 = func(1, 1, -1);
	int ret2 = func(1, 0, -1);
	cout << max(ret1, ret2) << '\n';
	return 0;
}
int func(int cur, int select, int prev) {
	if (dp[cur][select] != -1) return dp[cur][select];

	if (select) {
		dp[cur][select] = arr[cur];
		for (int i = 0; i < tree[cur].size(); ++i) {
			int next = tree[cur][i];
			if (next != prev) {
				dp[cur][select] += func(next, false, cur);
			}
		}
	}
	else {
		dp[cur][select] = 0;
		for (int i = 0; i < tree[cur].size(); ++i) {
			int next = tree[cur][i];
			if (next != prev) {
				int ret1 = func(next, true, cur);
				int ret2 = func(next, false, cur);
				dp[cur][select] += max(ret1, ret2);
			}
		}
	}
	return dp[cur][select];
}
