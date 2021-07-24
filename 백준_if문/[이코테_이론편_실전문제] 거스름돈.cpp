#include <iostream>

using namespace std;

int N, cnt;
int coins[] = { 500, 100, 50, 10 };

int main() {
	cin >> N;

	for (int coin : coins) {
		cnt += N / coin;
		N %= coin;
	}

	cout << cnt << '\n';

	return 0;
}