// 대표적인 DP 문제 중 하나인 "냅색 문제"
// "효율적인 화폐 구성 문제"와 비슷함. Ai = min(Ai, Ai-k + 1) or Ai = INF
//https://chanhuiseok.github.io/posts/improve-6/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp2[101][100001] = { 0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v[101] = { 0 };
	int w[101] = { 0 };
	//int dp2[101][100001] = { 0 };
	//int dp[100001] = { 0 };
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (j - w[i] >= 0)
				dp2[i][j] = max(dp2[i - 1][j], dp2[i - 1][j - w[i]] + v[i]);
			else
				dp2[i][j] = dp2[i - 1][j];
		}
	}
	//for (int i = 1; i <= N; ++i) {
	//	for (int j = K; j >= 1; --j) { //j는 배낭의 무게를 K부터 1까지 역순으로 살펴봐야 한다.
	//		if (j - w[i] >= 0)
	//			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	//	}
	//}
	//cout << dp[K] << '\n';
	cout << dp2[N][K] << '\n';
	return 0;
}