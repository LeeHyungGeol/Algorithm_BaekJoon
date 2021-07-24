#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer;
vector<vector<int>> cards;
vector<int> mins;

int main() {
	cin >> N >> M;

	cards.resize(N, vector<int>(M, 0));
	mins.resize(N, 0);

	for (int i = 0; i < N; ++i) {
		int Min = 10001;

		for (int j = 0; j < M; ++j) {
			cin >> cards[i][j];
			Min = min(Min, cards[i][j]);
		}

		answer = max(answer, Min);
	}

	cout << answer << '\n';

	return 0;
}