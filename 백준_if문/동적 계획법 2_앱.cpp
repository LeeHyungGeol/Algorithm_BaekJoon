//다이나믹 프로그래밍(Dynamic Programming): 동적 계획법 - "중복되는 연산을 줄이자"
// 1. 큰 문제를 작은 문제로 나눌 수 있다.
// 2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int app[101] = { 0 };
int m[101] = { 0 };
//long long int dp[10000001] = { 0 };
int main() {

	int N, sum = 0;
	long long int M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; ++i) {
		cin >> app[i];
	}
	for (int i = 1; i <= N; ++i) {
		cin >> m[i];
		sum += m[i];
	}
	vector<long long int> dp(N * sum, 0);
	for (int i = 1; i <= N; ++i) { //index: 비용(cost)(m[i]), dp[i]: 앱 메모리(app[i]) 
		for (int j = sum; j >= m[i]; --j) {
			if (j - m[i] >= 0)
				dp[j] = max(dp[j], dp[j - m[i]] + app[i]);
		}
	}
	/*for (int i = 1; i <= N; ++i) {
		for (int j = M; j >= app[i]; --j) {
			if (j - app[i] >= 0)
				dp[j] = max(dp[j], dp[j - app[i]] + m[i]);
		}
	}*/
	for (int i = 1; i <= sum; ++i) { 
		if (dp[i] >= M) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}