// 그리디(탐욕법) 문제
// [백준 골드 3] 저울(2437번) 문제와 똑같다. 같이 풀어볼 것

// sum은 sum까지의 숫자를 전부 표현할 수 있다는 의미

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long sum = 1;
vector<int> coins;

int main() {
	cin >> N;

	coins.resize(N, 0);

	for (int i = 0; i < N; ++i) {
		cin >> coins[i];
	}

	sort(coins.begin(), coins.end());

	for (int i = 0; i < N; ++i) {
		if (sum < coins[i]) {
			break;
		}

		sum += coins[i];
	}

	cout << sum << '\n';

	return 0;
}