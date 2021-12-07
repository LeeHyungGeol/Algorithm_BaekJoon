// Arr[n] = n층 계단의 점수, Dp[n] = n층 계단 까지의 최댓값
// N-2 번째 계단 까지의 최댓값 + N번째 계단 , N-3번째 계단까지의 최댓값 + N-1번째 계단 + N번째 계단 중 최댓값
// => Dp[N] = max(Dp[N - 2] + Arr[N], Dp[N - 3] + Arr[N - 1] + Arr[N]);

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> Dp;
vector<int> Arr;

int main() {
	cin >> N;

	Arr.resize(N + 1);
	Dp.resize(N + 1);

	for (int i = 1; i <= N; ++i) {
		cin >> Arr[i];
	}

	Dp[1] = Arr[1];
	Dp[2] = Arr[1] + Arr[2];
	Dp[3] = max(Arr[1] + Arr[3], Arr[2] + Arr[3]);

	for (int i = 4; i <= N; ++i) {
		Dp[i] = max(Dp[i - 2] + Arr[i], Dp[i - 3] + Arr[i - 1] + Arr[i]);
	}

	cout << Dp[N] << '\n';

	return 0;
}