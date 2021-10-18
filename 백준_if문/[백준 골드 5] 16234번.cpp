#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, L, R, Answer;
const int Dx[] = { -1,1,0,0 };
const int Dy[] = { 0,0,-1,1 };
vector<pii> Nodes;
vector<vector<int>> Arr;
vector<vector<bool>> Visited;

void dfsAll();
void dfs(int x, int y);
void move();

int main() {
	cin >> N >> L >> R;

	Arr.resize(N, vector<int>(N, 0));
	Visited.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Arr[i][j];
		}
	}

	dfsAll();

	cout << Answer << '\n';

	return 0;
}

void dfsAll() {
	bool flag = true;

	while (flag) {
		flag = false;
		Visited.assign(N, vector<bool>(N, false));
		Nodes.clear();

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!Visited[i][j]) {
					Nodes.push_back({ i,j });

					dfs(i, j);

					if (Nodes.size() > 1) {
						move();
						flag = true;
					}
				}
				Nodes.clear();
			}
		}
		
		if (flag) {
			++Answer;
		}
	}

	return;
}

void dfs(int x, int y) {
	Visited[x][y] = true;

	for (int i = 0; i < 4; ++i) {
		int nx = x + Dx[i];
		int ny = y + Dy[i];

		if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) continue;
		if (Visited[nx][ny]) continue;
		int diff = abs(Arr[x][y] - Arr[nx][ny]);
		if (!(L <= diff && diff <= R)) continue;
		Nodes.push_back({ nx, ny });
		dfs(nx, ny);
	}
}

void move() {
	int sum = 0;

	for (auto n : Nodes) {
		sum += Arr[n.first][n.second];
	}

	for (auto n : Nodes) {
		Arr[n.first][n.second] = sum / Nodes.size();
	}

	return;
}