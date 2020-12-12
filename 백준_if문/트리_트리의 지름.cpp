//https://kyu9341.github.io/algorithm/2020/03/12/algorithm1967/
//����ġ�� �ִ� Ʈ���� ������ ���ϴ� ����
//Ʈ���� �����ϴ� ��� ��� �߿��� ���� �� ���� ���̸� Ʈ���� �����̶� �Ѵ�.
// - Ʈ���� ������ Ž�� 2������ ���� �� �ִ�.
// -- ������ �� ���� u���� ��� ���������� �Ÿ��� ���Ѵ�. �� ��, ���� �� �Ÿ��� ������ w��� �Ѵ�.
// -- w���� ��� ���������� �Ÿ��� ���Ѵ�. �� ��, ���� �� �Ÿ��� ���� v�� ���Ѵ�.
// -- �� ��, u�� v������ �Ÿ��� Ʈ���� �����̴�.
//bfs�� dfs �Ѵ� �����ϴ�.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>//memset or #include <cstring>
#define INF 1e9
using namespace std;
int n; //����� ���� n(1 �� n �� 10,000)
int maxDistance = 0;
int maxIndex = 0;
vector<pair<int, int>> tree[10001];
int d[10001];
bool visited[10001];
void dfs(int cur, int cur_cost);
int bfs(int start);
int main() {
	int a, b, c;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}
	
	//int index = bfs(1); //-12ms
	//int maxDistanceIndex = bfs(index);
	dfs(1, 0); //-12ms
	memset(visited, false, sizeof(visited));
	dfs(maxIndex, 0);
	cout << maxDistance << '\n';
	return 0;
}
void dfs(int cur, int cur_cost) { //-12ms

	visited[cur] = true;

	if (maxDistance < cur_cost) {
		maxDistance = cur_cost;
		maxIndex = cur;
	}

	for (int i = 0; i < tree[cur].size(); ++i) {
		int next = tree[cur][i].first;
		int next_cost = tree[cur][i].second;
		if (!visited[next])
			dfs(next, cur_cost + next_cost);
	}

}
int bfs(int start) { //-12ms
	memset(visited, false, sizeof(visited));
	memset(d, 0, sizeof(d));
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();

		q.pop();
		for (int i = 0; i < tree[cur].size(); ++i) {
			int next = tree[cur][i].first;
			int next_cost = tree[cur][i].second;
			if (!visited[next]) {
				visited[next] = true;
				d[next] = d[cur] + next_cost;
				q.push(next);
			}
		}
	}
	int index = -1;
	for (int i = 1; i <= n; ++i) {
		if (d[i] > maxDistance) {
			maxDistance = d[i];
			index = i;
		}
	}
	return index;
}