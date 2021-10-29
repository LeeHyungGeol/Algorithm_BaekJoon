#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef struct Node {
	int x, y;
}Node;

int N, Answer = INT_MAX;
vector<Node> Coords;
vector<vector<int>> Arr;
vector<vector<int>> TempArr;

bool inRange(int x, int y, int d1, int d2);
void fillElections();

int main() {
	cin >> N;

	Arr.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int d1 = 1; d1 <= j; ++d1) {
				for (int d2 = 1; d2 < N - j; ++d2) {
					if (inRange(i, j, d1, d2)) {
						Coords.clear();
						Coords.push_back({ i,j });
						Coords.push_back({ i + d1, j - d1});
						Coords.push_back({ i + d2, j + d2 });
						Coords.push_back({ i + d1 + d2, j - d1 + d2 });
						fillElections();
					}
				}
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}

bool inRange(int x, int y, int d1, int d2) {
	if (x + d1 >= N || y - d1 < 0) return false;
	if (x + d2 >= N || y + d2 >= N) return false;
	if (x + d1 + d2 >= N || y + d2 - d1 < 0)return false;
	return true;
}

void fillElections() {
	TempArr.assign(N, vector<int>(N, 5));

	int cnt = 0;
	for (int i = 0; i < Coords[1].x; ++i) {
		if (i >= Coords[0].x) ++cnt;
		for (int j = 0; j <= Coords[0].y - cnt; ++j) {
			TempArr[i][j] = 1;
		}
	}

	cnt = 0;
	for (int i = 0; i <= Coords[2].x; ++i) {
		if (i > Coords[0].x) ++cnt;
		for (int j = Coords[0].y + 1 + cnt; j < N; ++j) {
			TempArr[i][j] = 2;
		}
	}

	cnt = 0;
	for (int i = N - 1; i >= Coords[1].x; --i) {
		if (i < Coords[3].x) ++cnt;
		for (int j = Coords[3].y - 1 - cnt; j >= 0; --j) {
			TempArr[i][j] = 3;
		}
	}

	cnt = 0;
	for (int i = N - 1; i > Coords[2].x; --i) {
		if (i <= Coords[3].x) ++cnt;
		for (int j = Coords[3].y + cnt; j < N; ++j) {
			TempArr[i][j] = 4;
		}
	}

	vector<int> totalSum(6, 0);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			totalSum[TempArr[i][j]] += Arr[i][j];
		}
	}

	sort(totalSum.begin(), totalSum.end());

	Answer = min(Answer, abs(totalSum[1] - totalSum.back()));
}