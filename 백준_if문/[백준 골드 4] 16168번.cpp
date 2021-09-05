// dfs, ���Ϸ� ���

// ���Ϸ� ��ο� ���� �� �� �����غ��߰ڴ�.
// https://aren227.me/eulerian-circuit-and-trail/
// �ش� ��ũ�� ������ �� �Ǿ��ִ�. �ٽ� �ѹ� �� �о��.

#include <iostream>
#include <vector>

using namespace std;

int V, E;
bool Flag;
vector<vector<int>> Graph;
vector<vector<int>> Visited;

void dfs(int cur, int before, int cnt);

int main() {
	cin >> V >> E;

	Graph.resize(V + 1);
	Visited.resize(V + 1, vector<int>(V + 1, 0));

	for (int i = 0; i < E; ++i) {
		int a, b;
		cin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}

	for (int i = 1; i <= V; ++i) {
		dfs(i, i, 0);
		if (Flag) {
			break;
		}
	}

	if (Flag) {
		cout << "YES" << '\n';
	}
	else {
		cout << "NO" << '\n';
	}

	return 0;
}

void dfs(int cur, int before, int cnt) {
	if (cnt == E) {
		Flag = true;
		return;
	}

	for (int next : Graph[cur]) {
		if (Visited[cur][next] != before && Visited[next][cur] != before) {
			Visited[cur][next] = before;
			Visited[next][cur] = before;
			dfs(next, before, cnt + 1);
		}
	}
}