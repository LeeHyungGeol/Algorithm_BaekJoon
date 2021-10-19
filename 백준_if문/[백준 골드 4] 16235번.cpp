#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N, M, K, Answer;
int Dx[] = { -1,-1,-1,0,0,1,1,1 };
int Dy[] = { -1,0,1,-1,1,-1,0,1 };
vector<vector<int>> Food;
vector<vector<int>> Arr;
deque<int> Trees[10][10];
vector<int> DeadTrees[10][10];

void spring();
void summer();
void fall();
void winter();

int main() {
	cin >> N >> M >> K;

	Arr.assign(N, vector<int>(N, 0));
	Food.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Food[i][j];
			Arr[i][j] = 5;
		}
	}

	for (int i = 0; i < M; ++i) {
		int r, c, age;
		cin >> r >> c >> age;
		Trees[r-1][c-1].push_back(age);
	}

	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			Answer += Trees[i][j].size();
		}
	}

	cout << Answer << '\n';
	
	return 0;
}

void spring() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int size = Trees[i][j].size();

			while (size--) {
				int age = Trees[i][j].front();
				Trees[i][j].pop_front();

				if (Arr[i][j] < age) {
					DeadTrees[i][j].push_back(age);
					continue;
				}
				Arr[i][j] -= age;
				Trees[i][j].push_back(age + 1);
			}
		}
	}
}

void summer() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < DeadTrees[i][j].size(); ++k) {
				Arr[i][j] += DeadTrees[i][j][k] / 2;
			}
			DeadTrees[i][j].clear();
		}
	}
}

void fall() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < Trees[i][j].size(); ++k) {
				int age = Trees[i][j][k];

				if (age % 5 == 0) {
					for (int d = 0; d < 8; ++d) {
						int nx = i + Dx[d];
						int ny = j + Dy[d];

						if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) continue;
						Trees[nx][ny].push_front(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			Arr[i][j] += Food[i][j];
		}
	}
}