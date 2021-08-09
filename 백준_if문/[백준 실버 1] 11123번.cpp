// dfs문제
// connected components문제

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T, H, W, Answer;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<char>> Graph;
vector<vector<bool>> Visited;

int dfsAll();
int dfs(int x, int y, char sheep);

int main() {
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> H >> W;

		Graph.assign(H, vector<char>(W));

		for (int i = 0; i < H; ++i) {
			string str;
			cin >> str;
			for (int j = 0; j < W; ++j) {
				Graph[i][j] = str[j];
			}
		}

		Answer = dfsAll();

		cout << Answer << '\n';
	}

	return 0;
}

int dfsAll() {
	int components = 0;
	Visited.assign(H, vector<bool>(W, false));

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (!Visited[i][j] && Graph[i][j] == '#') {
				dfs(i, j, Graph[i][j]);
				++components;
			}
		}
	}

	return components;
}

int dfs(int x, int y, char sheep) {
	int nodes = 0;
	Visited[x][y] = true;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < H && 0 <= ny && ny < W) {
			if (!Visited[nx][ny] && Graph[nx][ny] == sheep) {
				nodes += dfs(nx, ny, sheep);
			}
		}
	}

	return nodes;
}