// bfs, ����, ���Ʈ����

// 1. ��� ��ĭ(0)�� ���Ͽ� ��ǥ���� �����Ѵ�.
// 2. ��� ��ĭ�� ���Ͽ� ��� ����� ������ 0�� 2�� �̾� 1�� ������� ��
// 3. ������ ��쿡 ���Ͽ� ���� �� �ִ� ���� ������ ���Ѵ�.
// 3-1. �̶� bfs�� �����µ� �ѹ��̶� 0�� ������ ���� ���� �� �����Ƿ� flag=false�� �ش� ��츦 üũ���� �� 0�� return�Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M, Answer;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<bool>> Visited;
vector<vector<int>> Graph;
vector<pii> Temp, Empty, Enemy;
vector<bool> Select;

void dfs(int startIndex, int cnt);
int check();
int bfs(int x, int y);

int main() {
	cin >> N >> M;

	Graph.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> Graph[i][j];
			if (Graph[i][j] == 0) {
				Empty.push_back({ i,j });
			}
			else if (Graph[i][j] == 2) {
				Enemy.push_back({ i,j });
			}
		}
	}

	/*for (int i = 0; i < Temp.size(); ++i) {
		int x = Temp[i].first;
		int y = Temp[i].second;

		for (int j = 0; j < 4; ++j) {
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (Graph[nx][ny] == 2) {
					Empty.push_back({ x, y });
					break;
				}
			}
		}
	}*/

	Select.resize((int)Empty.size(), false);

	dfs(0, 0);

	cout << Answer << '\n';

	return 0;
}

void dfs(int startIndex, int cnt) {
	if (cnt == 2) {
		int result = check();
		Answer = max(Answer, result);
		return;
	}

	for (int i = startIndex; i < (int)Select.size(); ++i) {
		if (Select[i]) {
			continue;
		}
		Select[i] = true;
		Graph[Empty[i].first][Empty[i].second] = 1;
		dfs(i, cnt + 1);
		Select[i] = false;
		Graph[Empty[i].first][Empty[i].second] = 0;
	}
}

int check() {
	Visited.assign(N, vector<bool>(M, false));

	int cnt = 0;

	for (int i = 0; i < Enemy.size(); ++i) {
		int x = Enemy[i].first;
		int y = Enemy[i].second;

		if (!Visited[x][y]) {
			cnt += bfs(x, y);
		}
	}

	return cnt;
}

int bfs(int x, int y) {
	queue<pii> q;
	int cnt = 1;
	bool flag = true;

	q.push({ x,y });
	Visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (!Visited[nx][ny] && Graph[nx][ny] == 2) {
					Visited[nx][ny] = true;
					++cnt;
					q.push({ nx, ny });
				}
				else if (Graph[nx][ny] == 0) {
					flag = false;
				}
			}
		}
	}

	if (flag) {
		return cnt;
	}
	else {
		return 0;
	}
}