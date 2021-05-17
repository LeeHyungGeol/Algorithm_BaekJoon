// DFS 문제
// 특별한 조건이 붙는 Connected Components를 구하는 문제
// DFS를 2번 돌린다.

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N;
vector<char> graph[501];
bool visited[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

pii getComponents();
void normalDFS(int x, int y, char curColor);
void colorBlindnessDFS(int x, int y, char curColor);

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char c;
			cin >> c;
			graph[i].push_back(c);
		}
	}

	pii components = getComponents();

	cout << components.first << " " << components.second << '\n';

	return 0;
}

pii getComponents() {
	pii components = { 0,0 };

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j]) {
				char curColor = graph[i][j];
				normalDFS(i, j, curColor);
				++components.first;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		fill(visited[i], visited[i] + N, false);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j]) {
				char curColor = graph[i][j];
				colorBlindnessDFS(i, j, curColor);
				++components.second;
			}
		}
	}

	return components;
}

void normalDFS(int x, int y, char curColor) {
	visited[x][y] = true;

	//dfs를 상하좌우로 진행할 때는 이중 포문이 아닌 단일 포문으로 진행시킨다.
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 경계 조건과 방문 조건을 잊지 말자!
		if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny]) {
			if (curColor == graph[nx][ny]) {
				normalDFS(nx, ny, curColor);
			}
		}
	}
}

void colorBlindnessDFS(int x, int y, char curColor) {
	visited[x][y] = true;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny]) {
			if (curColor == graph[nx][ny]) {
				colorBlindnessDFS(nx, ny, curColor);
			}
			else if ((curColor == 'R' || curColor == 'G') && (graph[nx][ny] == 'R' || graph[nx][ny] == 'G')) {
				colorBlindnessDFS(nx, ny, curColor);
			}
		}
	}
}