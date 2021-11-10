#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> P, D, Answer;

int main() {
	cin >> N >> K;

	P.assign(N + 1, 0);
	D.assign(N + 1, 0);
	Answer.assign(N + 1, 0);

	for (int i = 1; i <= N; ++i) {
		cin >> P[i];
	}

	for (int i = 1; i <= N; ++i) {
		cin >> D[i];
	}

	for (int i = 0; i < K; ++i) {
		for (int i = 1; i <= N; ++i) {
			Answer[D[i]] = P[i];
		}
		for (int i = 1; i <= N; ++i) {
			P[i] = Answer[i];
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << Answer[i] << ' ';
	}
	cout << '\n';

	return 0;
}