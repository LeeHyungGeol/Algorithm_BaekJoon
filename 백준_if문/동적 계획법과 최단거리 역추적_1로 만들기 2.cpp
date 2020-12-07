#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
typedef long long int ll;
using namespace std;
int N;
ll dp[1000001] = { 0 };
ll mem[1000001] = { 0 };
vector<ll> v;
//최적의 값이 어느 곳으로 부터 온 것인지를 기록하면서 한다.
int main() {
	ll value = 0;
	cin >> N;
	mem[1] = 1;
	for (int i = 2; i <= N; ++i) {
		dp[i] = dp[i - 1] + 1;
		mem[i] = i - 1;
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i / 2] + 1;
				mem[i] = i/2;
			}
		}
		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
				mem[i] = i/3;
			}
		}
	}
	cout << dp[N] << '\n';
	
	/*for (int i = 1; i <= N; ++i) {
		cout << dp[i] << ' ';
	}*/
	cout << N << ' ';
	value = N;
	for (int i = N; i >= 1; --i) {
		if (value == i) {
			cout << mem[i] << ' ';
			value = mem[i];
			if (value == 1)
				break;
		}
	}
	//value = mem[N];
	/*while (value > 0) {
		cout << value << ' ';
		value = mem[value];
	}*/
	cout << '\n';

	return 0;
}