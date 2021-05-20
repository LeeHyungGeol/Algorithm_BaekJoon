#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAX 1e9

using namespace std;

typedef pair<int, int> pii;

int N, M, answer = MAX;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int laboratory[51][51] = { 0, };
int visited[51][51] = { 0, };
vector<bool> Select;
vector<pii> virus;
queue<pii> selectedVirus;

void dfs(int startIndex, int cnt);
void bfs();

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> laboratory[i][j];
			if (laboratory[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	Select.resize(virus.size());

	dfs(0, 0);

	if (answer == MAX) {
		cout << "-1" << '\n';
	}
	else {
		cout << answer << '\n';
	}

	return 0;
}

// DFS로 조합 구현
void dfs(int startIndex, int cnt) {
	// 하나의 조합이 완성되었을 때
	if (cnt == M) {
		// bfs() 하기 전에 배열 초기화
		memset(visited, -1, sizeof(visited));

		for (int i = 0; i < virus.size(); ++i) {
			// 선택된 바이러스들만 수행
			if (Select[i]) {
				int x = virus[i].first;
				int y = virus[i].second;
				// Queue에 넣는다.
				selectedVirus.push(virus[i]);
				// 선택된, 활성바이러스들 
				// 방문했다고 표시
				visited[x][y] = 0;
			}
		}

		// BFS 수행 시작
		bfs();

		return;
	}

	for (int i = startIndex; i < virus.size(); ++i) {
		if (Select[i] == true) {
			continue;
		}
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}

void bfs() {

	while (!selectedVirus.empty()) {
		int x = selectedVirus.front().first;
		int y = selectedVirus.front().second;

		selectedVirus.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 정사각형 범위 내에 있고, 벽이 아니며, 아직 방문하지 않은 곳들
			if (0 <= nx && nx < N && 0 <= ny && ny < N && laboratory[nx][ny] != 1 && visited[nx][ny] == -1) {
				visited[nx][ny] = visited[x][y] + 1;
				selectedVirus.push({ nx, ny });
			}
		}
	}

	int totalTime = 0;
	bool flag = true;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			// 벽이 아니라면
			if (laboratory[i][j] == 0 || laboratory[i][j] == 2) {
				// 아직 방문하지 않은 곳이 있다면 바이러스 전파 실패한 것
				if (visited[i][j] == -1) {
					flag = false;
					break;
				}
				else {
					totalTime = max(totalTime, visited[i][j]);
				}
			}
		}
	}

	if (flag) {
		answer = min(answer, totalTime);
	}
}
