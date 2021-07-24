// �׸���(Ž���) ����
// ������ ������ Ư���ؼ� ���� ���α׷��ֺ��� ������ ���� ã�� �� �ִ� ����
// ��� ������ ��ġ�� ����� ����� �̷���� �ֱ� ������ �׸��� ����� ���Ѵ�.

// ���� ������ ��ġ�� ���� ����� ���谡 �ƴϾ��ٸ�, �׸��� ������ �ƴ� DP(���̳��� ���α׷���) ������ �ȴ�.

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