//규칙에 따라 포도주를 마실 때, 최대로 마실 수 있는 포도주의 양을 구하는 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//bottom-up방식
int main() {

	vector<int> wine;
	int N, x, dp[10001] = { 0 };//dp 테이블
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		wine.push_back(x);
	}
	dp[0] = wine[0];
	dp[1] = wine[0] + wine[1];
	dp[2] = max(max(wine[0] + wine[1], wine[1] + wine[2]), wine[0] + wine[2]);
	//dp[2] = max(wine[0] + wine[1], wine[1] + wine[2]);
	//dp[2] = max(dp[2], wine[0] + wine[2]);
	for (int i = 3; i < N; ++i) {
		dp[i] = max(max(wine[i] + wine[i - 1] + dp[i - 3], wine[i] + dp[i - 2]), dp[i - 1]);
		//dp[i] = wine[i] + wine[i - 1] + dp[i - 3];
		//dp[i] = max(dp[i], wine[i] + dp[i - 2]);
		//dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[N - 1] << '\n';
	return 0;
}