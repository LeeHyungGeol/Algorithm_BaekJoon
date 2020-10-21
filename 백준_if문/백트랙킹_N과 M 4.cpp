#include <iostream>
using namespace std;

int N, M; //(1 ≤ M ≤ N ≤ 8)
int answer[8 + 1];
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

	for (int i = 1; i <= N; ++i) { //1부터 N까지 숫자 사용
		if (answer[x - 1] <= i) {
			answer[x] = i;
			backtracking(x + 1);
		}
	}
}
