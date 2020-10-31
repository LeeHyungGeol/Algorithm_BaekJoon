// 대표적인 DP 문제 중 하나인 "냅색 문제"
// 효율적인 화폐 구성 문제와 비슷함. Ai = min(Ai, Ai-k + 1) or Ai = INF
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	int v[101] = { 0 };
	int w[101] = { 0 };
	//int dp[101][100001] = { 0 };
	int dp[100001] = { 0 };
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> w[i] >> v[i];
	}
	/*for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}*/
	for (int i = 1; i <= N; ++i) {
		for (int j = K; j >= 1; --j) {
			if (j - w[i] >= 0)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[K] << '\n';
	return 0;
}