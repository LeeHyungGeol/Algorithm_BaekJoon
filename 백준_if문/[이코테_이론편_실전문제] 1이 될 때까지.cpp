#include <iostream>
#include <vector>

using namespace std;

int N, K, cnt;
void solution1();
void solution2();

int main() {
	cin >> N >> K;

	//solution1();

	solution2();

	cout << cnt << '\n';

	return 0;
}

void solution1() {
	while (N >= K) {
		while (N % K != 0) {
			--N;
			++cnt;
		}

		N /= K;
		++cnt;
	}

	while (N > 1) {
		--N;
		++cnt;
	}

	return;
}

void solution2() {
	while (true) {
		int target = (N / K) * K;
		cnt += N - target;
		N = target;
		
		if (N < K) {
			break;
		}

		N /= K;
		++cnt;
	}

	cnt += N - 1;
}