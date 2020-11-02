// ��ǥ���� DP ���� �� �ϳ��� "���� ����"
// "ȿ������ ȭ�� ���� ����"�� �����. Ai = min(Ai, Ai-k + 1) or Ai = INF
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
	//	for (int j = K; j >= 1; --j) { //j�� �賶�� ���Ը� K���� 1���� �������� ������� �Ѵ�.
	//		if (j - w[i] >= 0)
	//			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	//	}
	//}
	//cout << dp[K] << '\n';
	cout << dp2[N][K] << '\n';
	return 0;
}