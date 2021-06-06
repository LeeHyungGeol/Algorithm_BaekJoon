// BFS/DFS + 조합 문제
// 빈칸(0) 인 부분 중 3곳을 골라서 그에 해당하는 조합들을 전부 탐색하는 문제

// 조합을 위한 DFS 작성할때, return 문을 항상 기억하자!!!

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, M, answer = 0;
int laboratory[8][8] = { 0, };
int temp[8][8] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<bool> Select;
vector<pii> emptyPlace;
vector<pii> virus;

void dfs(int startIndex, int cnt);
void bfs();

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> laboratory[i][j];

			if (laboratory[i][j] == 0) {
				emptyPlace.push_back({ i,j });
			}
			else if (laboratory[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	Select.resize(emptyPlace.size());

	dfs(0, 0);

	cout << answer << '\n';

	return 0;
}

void dfs(int startIndex, int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				temp[i][j] = laboratory[i][j];
			}
		}

		for (int i = 0; i < emptyPlace.size(); ++i) {
			if (Select[i]) {
				int x = emptyPlace[i].first;
				int y = emptyPlace[i].second;
				temp[x][y] = 1;
			}
		}

		bfs();
		return;
	}

	for (int i = startIndex; i < emptyPlace.size(); ++i) {
		if (Select[i] == true) {
			continue;
		}
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}

void bfs() {
	queue<pii> q;

	for (int i = 0; i < virus.size(); ++i) {
		q.push(virus[i]);
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (temp[nx][ny] == 0) {
					temp[nx][ny] = 2;
					q.push({ nx,ny });
				}
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (temp[i][j] == 0) {
				++cnt;
			}
		}
	}

	answer = max(answer, cnt);
}