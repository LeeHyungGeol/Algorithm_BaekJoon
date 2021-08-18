// 최단경로(다익스트라) 문제

// 1번 노드에서 중간지점(P)을 경유해서 목적지(V)까지 가는 거리랑 
// 1번 노드에서 바로 목적지(V)까지 가는 거리를 비교한다.

// 다익스트라 알고리즘의 시작점을 달리해서 2번 돌린다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

int V, E, P;
vector<pii> Graph[5001];
vector<int> Dist;

void dijkstra(int start);

int main() {
	cin >> V >> E >> P;

	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		Graph[a].push_back({ b,c });
		Graph[b].push_back({ a,c });
	}

	dijkstra(1); // 1번에서 P번, 1번에서 V번
	
	int last = Dist[V];
	
	dijkstra(P); // P번에서 1번, P번에서 V번

	int first = Dist[1], last2 = Dist[V];

	if (first + last2 <= last) {
		cout << "SAVE HIM" << '\n';
	}
	else {
		cout << "GOOD BYE" << '\n';
	}

	return 0;
}

void dijkstra(int start) {
	priority_queue<pii> pq;

	pq.push({ 0, start });

	Dist.assign(V + 1, INF);
	Dist[start] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (Dist[cur] < dist) {
			continue;
		}

		for (pii next : Graph[cur]) {
			int cost = next.second + dist;
			int nextNode = next.first;

			if (Dist[nextNode] > cost) {
				Dist[nextNode] = cost;
				pq.push({ -cost, nextNode });
			}
		}
	}

	return;
}