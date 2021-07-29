// �׸���(Ž���) ����
// [���� ��� 3] ����(2437��) ������ �Ȱ���. ���� Ǯ� ��

// sum�� sum������ ���ڸ� ���� ǥ���� �� �ִٴ� �ǹ�

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