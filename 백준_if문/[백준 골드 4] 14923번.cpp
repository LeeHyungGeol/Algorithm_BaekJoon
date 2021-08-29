// 3차원 bfs

// (백준 골드 4) 벽 부수고 이동하기(2206번) 과 완전히 똑같은 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

int N, M, Hx, Hy, Ex, Ey, Answer;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<int>> Graph;
bool Visited[1001][1001][2];

int bfs();

int main() {
	cin >> N >> M >> Hx >> Hy >> Ex >> Ey;

	Graph.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> Graph[i][j];
		}
	}

	Answer = bfs();
	
	cout << Answer << '\n';

	return 0;
}

int bfs() {
	queue<piiii> q;
	q.push({ {Hx - 1, Hy - 1},{0, 0} });
	Visited[Hx - 1][Hy - 1][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int broken = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (x == Ex - 1 && y == Ey - 1) {
			return cnt;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (Graph[nx][ny] == 1 && broken == 0) {
					Visited[nx][ny][broken + 1] = true;
					q.push({ {nx,ny},{broken + 1, cnt + 1} });
				}
				else if (Graph[nx][ny] == 0 && !Visited[nx][ny][broken]) {
					Visited[nx][ny][broken] = true;
					q.push({ {nx,ny},{broken, cnt + 1} });
				}
			}
		}
	}

	return -1;
}