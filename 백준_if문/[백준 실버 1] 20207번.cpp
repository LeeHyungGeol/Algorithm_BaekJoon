#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Answer;
int Days[366];

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int from, to;
		cin >> from >> to;

		for (int j = from; j <= to; ++j) {
			++Days[j];
		}
	}

	int width = 0, height = 0;

	for (int i = 1; i <= 365; ++i) {
		if (Days[i]) {
			++width;
			height = max(height, Days[i]);
		}
		if (Days[i] == 0 || i == 365) {
			Answer += width * height;
			width = 0;
			height = 0;
		}
	}

	cout << Answer << '\n';

	return 0;
}