//메모이제이션으로 N을 1로 바꾸기 위해 주어진 연산을 몇 번 사용하는지 계산하는 문제
#include <iostream>
#include <algorithm>
using namespace std;

//bottom-up방식
long long int dp[1000001] = { 0 }; //d, dp, memo, cache, table 등등..

int main() {
	int N;
	cin >> N;
	for (int i = 2; i <= N; ++i) {
		//dp[i] = min(dp[i], dp[i - 1] + 1); //dp의 값들을 초기화 할 때, INF로 설정하면 사용 가능
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}
	cout << dp[N] << '\n';
	return 0;
}