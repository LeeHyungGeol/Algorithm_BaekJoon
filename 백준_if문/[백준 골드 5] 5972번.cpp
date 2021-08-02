// 최단경로(다익스트라) 문제

#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<pii> Graph[50001];
vector<int> Dist;

void dijkstra(int start);

int main() {
	cin >> N >> M;

	Dist.resize(N+1, INF);

	for (int i = 0; i < M; ++i) {
		int a, b, cost;
		cin >> a >> b >> cost;
		Graph[a].push_back({ b, cost });
		Graph[b].push_back({ a, cost });
	}

	dijkstra(1);

	cout << Dist[N] << '\n';

	return 0;
}

void dijkstra(int start) {
	priority_queue<pii> pq;
	pq.push({0, start});
	Dist[start] = 0;
	
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (Dist[cur] < dist) {
			continue;
		}

		for (int i = 0; i < Graph[cur].size(); ++i) {
			int next = Graph[cur][i].first;
			int weight = Graph[cur][i].second;

			int cost = dist + weight;

			if (Dist[next] > cost) {
				Dist[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}

	return;
}