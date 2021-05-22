// DFS를 이용한 Connected Components를 구하는 문제
// 단, 시간에 따른 Connected Components를 구하는 문제로
// Connected Components가 2개 이상이 되면 바로 결과를 출력하고,
// 2차원 배열의 요소 모두가 0이 될 때까지 Connected Components가 1이라면 0을 출력

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, result = 0, answer = 0;
int iceberg[301][301] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[301][301];
bool melted[301][301];

int getConnectedComponents();
void dfs(int x, int y);
void iceMeltPerYears();

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> iceberg[i][j];
		}
	}

	while (true) {
		memset(visited, false, sizeof(visited));
		memset(melted, false, sizeof(melted));
		result = getConnectedComponents();
		if (result == 1) {
			iceMeltPerYears();
			++answer;
			continue;
		}
		else if (result == 0) {
			answer = 0;
			break;
		}
		else {
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}

int getConnectedComponents() {
	int components = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			// 빙산이 0이 아니고, 방문하지 않았을 때
			// Connected Components 를 계산한다.
			if (iceberg[i][j] != 0 && !visited[i][j]) {
				dfs(i, j);
				++components;
			}
		}
	}

	return components;
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 경계 조건과 방문 조건을 잊지 말자!
		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (iceberg[nx][ny] != 0 && !visited[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
}

// 빙산이 0인 곳들을 찾아다니면서 0이라면
// 그 주위의 동서남북으로 빙산을 -1만큼 줄인다.
// 단, 빙산이 양수일때만 줄인다. 아니면 음수로 될 수도 있기 때문에
// 이중 for문을 돌면서 빙하를 녹인 것이기 때문에, 
// 이전에 녹아서 0이 되면, 
// 계속해서 다음 반복문에 빙하를 녹일 수 있기 때문에
// melted 2차원 배열을 사용하여 한번 녹았는지 안녹았는지 확인한다.
void iceMeltPerYears() {

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			if (iceberg[x][y] == 0 && !melted[x][y]) {
				for (int i = 0; i < 4; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (0 <= nx && nx < N && 0 <= ny && ny < M) {
						if (iceberg[nx][ny] > 0) {
							melted[nx][ny] = true;
							--iceberg[nx][ny];
						}
					}
				}
			}
		}
	}

	return;
}