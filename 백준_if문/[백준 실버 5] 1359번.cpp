// 수학, 조합 문제
// nCr을 구하는 수학식을 구현하고,
// 문제에서 질문한 확률을 구하는 문제

// 참고 : https://happy-family.tistory.com/entry/%EB%B0%B1%EC%A4%801359-%EB%B3%B5%EA%B6%8C%EB%B8%8C%EB%A1%A0%EC%A6%881

#include <iostream>

using namespace std;

typedef long long ll;

int N, M, K;
double Answer = 0.0;

ll Combination(int n, int r);
ll combination(int n, int r);

int main() {
	cin >> N >> M >> K;

	double nCm = combination(N, M);
	
	while (M >= K) {
		if (N - M < M - K) {
			++K;
			continue;
		}
		else {
			double temp = combination(M, K) * combination(N - M, M - K);
			Answer += temp / nCm;
			++K;
		}
	}

	cout << fixed;
	cout.precision(16);
	cout << Answer << '\n';

	return 0;
}

ll Combination(int n, int r) {
	int p = 1;
	int c = 1;
	while (r > 0) {
		c *= n--;
		p *= r--;
	}

	return c / p;
}

ll combination(int n, int r) {
	if (n == r || r == 0) {
		return 1;
	}
	else {
		return combination(n - 1, r - 1) + combination(n - 1, r);
	}
}
