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
                Parent[next] = cur;
                pq.push({ -cost, next });
            }
        }
    }

    return;
}