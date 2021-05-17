// DFS ����
// Ư���� ������ �ٴ� Connected Components�� ���ϴ� ����
// DFS�� 2�� ������.

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

	//dfs�� �����¿�� ������ ���� ���� ������ �ƴ� ���� �������� �����Ų��.
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// ��� ���ǰ� �湮 ������ ���� ����!
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