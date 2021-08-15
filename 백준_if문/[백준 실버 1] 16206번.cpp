#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
queue<int> Cakes;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		Cakes.push(x);
	}

	int answer = 0;

	while (!Cakes.empty()) {
		int cur = Cakes.front();
		Cakes.pop();

		if (M == 0) {
			break;
		}

		if (cur == 10) {
			++answer;
			continue;
		}

		if (cur % 10 == 0 && (cur / 10) % 2 == 0) {
			cur /= 10;
			answer += cur;
			M -= (cur - 1);
			continue;
		}
		else if (cur > 10) {
			cur -= 10;
			Cakes.push(cur);
			--M;
			++answer;
		}
	}

	cout << answer << '\n';

	return 0;
}