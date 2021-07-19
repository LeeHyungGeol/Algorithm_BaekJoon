// dfs, bfs 혹은 플로이드 워셜로 풀 수 있는 문제

#include <iostream>
#include <vector>

using namespace std;

int N;
int graph[100][100] = { 0, };

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> graph[i][j];
		}
	}

	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (graph[i][k] && graph[k][j]) {
					graph[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}