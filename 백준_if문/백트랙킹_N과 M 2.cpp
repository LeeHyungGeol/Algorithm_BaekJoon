#include <iostream>
using namespace std;

int N, M; //(1 ¡Â M ¡Â N ¡Â 8)
int answer[8 + 1] = { 0 };
void backtracking(int x);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	backtracking(1);

	return 0;
}
void backtracking(int x) {
	if (x == M + 1) {
		for (int i = 1; i <= M; ++i) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i) {
		if (answer[x - 1] < i) {
			answer[x] = i;
			backtracking(x + 1);
		}
	}
}
