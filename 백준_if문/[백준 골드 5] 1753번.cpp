#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

// 정점의 개수 V와 간선의 개수 E가 주어진다.
// (1≤V≤20,000, 1≤E≤300,000)
int v, e, start;
vector<pii> graph[20001];
int d[20001] = { 0, };

void dijkstra(int start);

int main() {
	cin >> v >> e;
	cin >> start;

	for (int i = 0; i < e; ++i) {
		int a, b, cost;
		cin >> a >> b >> cost;
		graph[a].push_back({ b, cost });
	}

	//memset(d, INF, sizeof(d));
	fill(d, d + 20001, INF);

	dijkstra(start);

	for (int i = 1; i <= v; ++i) {
		if (d[i] == INF) {
			cout << "INF" << '\n';
		}
		else {
			cout << d[i] << '\n';
		}
	}

	return 0;
}

void dijkstra(int start) {
	priority_queue<pii> pq;

	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;

		pq.pop();

		if (d[now] < dist) {
			continue;
		}

		for (int i = 0; i < graph[now].size(); ++i) {
			int cost = dist + graph[now][i].second;
			int next = graph[now][i].first;

			if (cost < d[next]) {
				d[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}
}