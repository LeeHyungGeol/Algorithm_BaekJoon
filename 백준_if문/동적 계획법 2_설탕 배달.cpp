//다이나믹 프로그래밍(Dynamic Programming): 동적 계획법 - "중복되는 연산을 줄이자"
// 1. 큰 문제를 작은 문제로 나눌 수 있다.
// 2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다.
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000
using namespace std;
int main() {
	int arr[3] = { 0,3,5 }; //5 Kg 봉지, 3 Kg 봉지
	int N;//설탕 무게 (3 ≤ N ≤ 5000)
	cin >> N;
	vector<int> dp(N + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= 2; ++i) {
		for (int j = arr[i]; j <= N; ++j) {
			if (dp[j - arr[i]] != INF)//(i-k) 원을 만드는 방법이 존재하는 경우
				dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	if (dp[N] == INF)
		cout << "-1" << '\n';
	else
		cout << dp[N] << '\n';

	return 0;
}