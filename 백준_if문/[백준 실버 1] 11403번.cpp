// dfs, bfs 혹은 플로이드 워셜로 풀 수 있는 문제


// 플로이드 워셜 풀이
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

//-----------------------------------------------------------------------------------------------

// dfs풀이

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> graph[100];
vector<bool> visited;

void dfs(int cur);

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				graph[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		visited.assign(N, false);
		
		dfs(i);

		for (int j = 0; j < N; ++j) {
			cout << visited[j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

void dfs(int cur) {
	// 여기에 visited를 갱신해주는 것이 아니다!

	for (int next : graph[cur]) {
		if (!visited[next]) {
			// cur에서 next로 도달할 수 있는 것을 찾는 것이므로 if문 안에서 visited배열을 갱신한다.
			visited[next] = true;
			dfs(next);
		}
	}

	return;
}