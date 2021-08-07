// 구현, 브루트포스, 조합 문제
// 동, 서, 남, 북 방향 검색 구현
// 카메라의 서로 다른 방향을 선택하는 모든 조합을 구현

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1e9

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

int N, M, Answer = MAX;
vector<piiii> Cameras;
vector<vector<int>> Graph;
vector<vector<int>> Temp;

void dfs(int cnt);
void check();
int countSecretAreas();
void up(int x, int y);
void down(int x, int y);
void left(int x, int y);
void right(int x, int y);

int main() {
	cin >> N >> M;

	Graph.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> Graph[i][j];
			if (Graph[i][j] != 0 && Graph[i][j] != 6) {
				Cameras.push_back({ { i,j }, {Graph[i][j], -1} });
			}
		}
	}

	dfs(0);

	cout << Answer << '\n';

	return 0;
}

void dfs(int cnt) {
	if (cnt == (int)Cameras.size()) {
		check();
		Answer = min(Answer, countSecretAreas());
		return;
	}

	Cameras[cnt].second.second = 0;
	dfs(cnt + 1);

	Cameras[cnt].second.second = 1;
	dfs(cnt + 1);

	Cameras[cnt].second.second = 2;
	dfs(cnt + 1);

	Cameras[cnt].second.second = 3;
	dfs(cnt + 1);
}

void check() {
	Temp.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			Temp[i][j] = Graph[i][j];
		}
	}

	for (int i = 0; i < Cameras.size(); ++i) {
		if (Cameras[i].second.first == 1) {
			if (Cameras[i].second.second == 0) {
				right(Cameras[i].first.first, Cameras[i].first.second);
			}
			else if (Cameras[i].second.second == 1) {
				left(Cameras[i].first.first, Cameras[i].first.second);
			}
			else if (Cameras[i].second.second == 2) {
				down(Cameras[i].first.first, Cameras[i].first.second);
			}
			else if (Cameras[i].second.second == 3) {
				up(Cameras[i].first.first, Cameras[i].first.second);
			}
		}
		else if (Cameras[i].second.first == 2) {
			if (Cameras[i].second.second == 0 || Cameras[i].second.second == 1) {
				left(Cameras[i].first.first, Cameras[i].first.second);
				right(Cameras[i].first.first, Cameras[i].first.second);
			}
			else if (Cameras[i].second.second == 2 || Cameras[i].second.second == 3) {
				up(Cameras[i].first.first, Cameras[i].first.second);
				down(Cameras[i].first.first, Cameras[i].first.second);
			}
		}
		else if (Cameras[i].second.first == 3) {
			if (Cameras[i].second.second == 0) {
				up(Cameras[i].first.first, Cameras[i].first.second);
				right(Cameras[i].first.first, Cameras[i].first.second);
			}
			else if (Cameras[i].second.second == 1) {
				right(Cameras[i].first.first, Cameras[i].first.second);
				down(Cameras[i].first.first, Cameras[i].first.second);
			}
			else if (Cameras[i].second.second == 2) {
				down(Cameras[i].first.first, Cameras[i].first.second);
				left(Cameras[i].first.first, Cameras[i].first.second);
			}
			else if (Cameras[i].second.second == 3) {
				left(Cameras[i].first.first, Cameras[i].first.second);
				up(Cameras[i].first.first, Cameras[i].first.second);
			}
		}
		else if (Cameras[i].second.first == 4) {
			if (Cameras[i].second.second == 0) {
				left(Cameras[i].first.first, Cameras[i].first.second);
				up(Cameras[i].first.first, Cameras[i].first.second);
				right(Cameras[i].first.first, Cameras[i].first.second);
			}
			else if (Cameras[i].second.second == 1) {
				up(Cameras[i].first.first, Cameras[i].first.second);
				right(Cameras[i].first.first, Cameras[i].first.second);
				down(Cameras[i].first.first, Cameras[i].first.second);
			}
			else if (Cameras[i].second.second == 2) {
				right(Cameras[i].first.first, Cameras[i].first.second);
				down(Cameras[i].first.first, Cameras[i].first.second);
				left(Cameras[i].first.first, Cameras[i].first.second);
			}
			else if (Cameras[i].second.second == 3) {
				down(Cameras[i].first.first, Cameras[i].first.second);
				left(Cameras[i].first.first, Cameras[i].first.second);
				up(Cameras[i].first.first, Cameras[i].first.second);
			}
		}
		else if (Cameras[i].second.first == 5) {
			right(Cameras[i].first.first, Cameras[i].first.second);
			left(Cameras[i].first.first, Cameras[i].first.second);
			up(Cameras[i].first.first, Cameras[i].first.second);
			down(Cameras[i].first.first, Cameras[i].first.second);
		}

	}

	return;
}

int countSecretAreas() {
	int cnt = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (Temp[i][j] == 0) {
				++cnt;
			}
		}
	}
	return cnt;
}

void up(int x, int y) {
	// 북
	for (int i = x; i >= 0; --i) {
		if (Temp[i][y] == 6) {
			break;
		}
		if (Temp[i][y] <= 0) {
			Temp[i][y] = -1;
		}
	}
	return;
}
void down(int x, int y) {
	// 남
	for (int i = x; i < N; ++i) {
		if (Temp[i][y] == 6) {
			break;
		}
		if (Temp[i][y] <= 0) {
			Temp[i][y] = -1;
		}
	}
	return;
}
void left(int x, int y) {
	// 서
	for (int i = y; i >= 0; --i) {
		if (Temp[x][i] == 6) {
			break;
		}
		if (Temp[x][i] <= 0) {
			Temp[x][i] = -1;
		}
	}

	return;
}
void right(int x, int y) {
	// 동
	for (int i = y; i < M; ++i) {
		if (Temp[x][i] == 6) {
			break;
		}
		if (Temp[x][i] <= 0) {
			Temp[x][i] = -1;
		}
	}

	return;
}