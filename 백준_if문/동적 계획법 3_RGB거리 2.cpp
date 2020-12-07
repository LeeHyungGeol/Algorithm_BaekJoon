//집이 원형으로 배열된 RGB거리 문제
//https://cooling.tistory.com/4
#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;
int RGB[1001][3] = { 0 };
int dp[1001][3] = { 0 };
int N;
int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> RGB[i][j];
		}
	}
	int answer = INF;//
	
	for (int first = 0; first < 3; ++first) {

		dp[1][0] = INF;//red
		dp[1][1] = INF;//green
		dp[1][2] = INF;//blue
		dp[1][first] = RGB[1][first];//first

		for (int i = 2; i <= N; ++i) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + RGB[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + RGB[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + RGB[i][2];
		}

		for (int i = 0; i < 3; ++i) {
			if (first == i)
				continue;
			answer = min(answer, dp[N][i]);
		}
	}
	cout << answer << '\n';
	return 0;
}