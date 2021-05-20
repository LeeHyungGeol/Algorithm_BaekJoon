// BFS로 최단거리 탐색문제
// 다만, 바이러스 개수 N개 중 M개를 선택하여(nCm) 조합을 하여,
// 최소 시간으로 바이러스를 퍼트리는 조합을 구해야 한다.
// 활성화된 바이러스가 비활성화된 바이러스가 있는 곳으로 가서 활성화 시키는 것은, 바이러스가 퍼뜨린 시간으로 계산하지 않는다.

// 따로 시간을 계산하는 2차원 배열을 만들어야 한다. 처음에 입력 받은 2차원 배열로 해결하려다가 시간이 오래 걸렸다.
// 개인적으로 [백준 실버 1] 7569번 토마토 문제와 비슷한 문제라고 생각한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAX 1e9

using namespace std;

typedef pair<int, int> pii;

int N, M, answer = MAX, emptyPlace = 0;
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
			else if (laboratory[i][j] == 0) {
				++emptyPlace;
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
			// 빈칸이었던 곳들 중에서
			if (laboratory[i][j] == 0) {
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

void bfs2() {
	int infectedPlace = 0, totalTime = 0;

	while (!selectedVirus.empty()) {
		int x = selectedVirus.front().first;
		int y = selectedVirus.front().second;

		selectedVirus.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 정사각형 범위 안에 있고, 벽이 아니고, 감염되지 않은 곳들
			if (0 <= nx && nx < N && 0 <= ny && ny < N && laboratory[nx][ny] != 1 && visited[nx][ny] == -1) {
				visited[nx][ny] = visited[x][y] + 1;
				if (laboratory[nx][ny] == 0) {
					totalTime = max(totalTime, visited[nx][ny]);
					++infectedPlace;
				}
				selectedVirus.push({ nx,ny });
			}
		}
	}

	if (emptyPlace == infectedPlace) {
		answer = min(answer, totalTime);
	}
}
