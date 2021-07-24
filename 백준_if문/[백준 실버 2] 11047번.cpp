// 그리디(탐욕법) 문제
// 동전의 조건이 특별해서 동적 프로그래밍보다 빠르게 답을 찾을 수 있는 문제
// 모든 동전의 가치가 배수의 관계로 이루어져 있기 때문에 그리디 방법이 통한다.

// 만약 동전의 가치가 서로 배수의 관계가 아니었다면, 그리디 문제가 아닌 DP(다이나믹 프로그래밍) 문제가 된다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, cnt;
vector<int> coins;

int main() {
	cin >> N >> K;

	coins.resize(N, 0);

	for (int i = 0; i < N; ++i) {
		cin >> coins[i];
	}

	sort(coins.rbegin(), coins.rend());

	for (int coin : coins) {
		cnt += K / coin;
		K %= coin;
	}

	cout << cnt << '\n';

	return 0;
}