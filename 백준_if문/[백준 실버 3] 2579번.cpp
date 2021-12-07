// Arr[n] = n�� ����� ����, Dp[n] = n�� ��� ������ �ִ�
// N-2 ��° ��� ������ �ִ� + N��° ��� , N-3��° ��ܱ����� �ִ� + N-1��° ��� + N��° ��� �� �ִ�
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