// 최단경로(다익스트라) 문제

// parent[next] = cur : next의 parent는 cur이다.
// Tree는 노드의 개수가 'N개'일 때, 간선의 개수는 항상 'N-1개'이다.

#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<pii> Graph[1001];
vector<int> Parent;
vector<int> Dist;

void dijkstra(int start);

int main() {
	cin >> N >> M;

    Dist.resize(N + 1, INF);
    Parent.resize(N + 1, 0);

	for (int i = 0; i < M; ++i) {
		int a, b, cost;
		cin >> a >> b >> cost;
		Graph[a].push_back({ b, cost });
		Graph[b].push_back({ a, cost });
	}

    dijkstra(1);

    cout << N - 1 << '\n';

    for (int i = 2; i <= N; ++i) {
        cout << i << ' ' << Parent[i] << '\n';
    }

	return 0;
}

void dijkstra(int start) {
    priority_queue<pii> pq;

    pq.push({ 0, start });
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
            int nextWeight = Graph[cur][i].second;
            int cost = dist + nextWeight;

            if (cost < Dist[next]) {
                Dist[next] = cost;
                // next의 parrent는 cur이다.
                Parent[next] = cur;
                pq.push({ -cost, next });
            }
        }
    }

    return;
}