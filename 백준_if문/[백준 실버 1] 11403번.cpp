// dfs, bfs Ȥ�� �÷��̵� ���ȷ� Ǯ �� �ִ� ����


// �÷��̵� ���� Ǯ��
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

// dfsǮ��

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
	// ���⿡ visited�� �������ִ� ���� �ƴϴ�!

	for (int next : graph[cur]) {
		if (!visited[next]) {
			// cur���� next�� ������ �� �ִ� ���� ã�� ���̹Ƿ� if�� �ȿ��� visited�迭�� �����Ѵ�.
			visited[next] = true;
			dfs(next);
		}
	}

	return;
}