#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1e9

int d[801] = {0};
vector<pair<int, int>> graph[801];
vector<pair<int, int>> distCount;
int N, E; 
void Dijkstra(int start, int v, int w);
int main() {
	int a, b, c;
	cin >> N >> E;
	for (int i = 0; i < E; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });//방향성이 없는 그래프이므로 양방향으로 처리해준다.
		graph[b].push_back({ a,c });
	}
	int v1, v2;
	cin >> v1 >> v2;

	Dijkstra(1, v1, v2);
	Dijkstra(v1, v2, N); //1 -> v1 -> v2 -> N 
	Dijkstra(v2, v1, N); //1 -> v2 -> v1 -> N

	//for (int i = 0; i < distCount.size(); ++i) {
	//	cout << "distCount[i].first : " << distCount[i].first << " distCount[i].second : " << distCount[i].second << '\n';
	//}

	long long int minDistance = min(distCount[0].first + distCount[1].first + distCount[2].second,
								distCount[0].second + distCount[1].second + distCount[2].first);
	if (minDistance >= INF || minDistance < 0) //INF를 세번 더하면 오버플로우가 발생하여 음수로 바뀌는 경우 발생
		cout << "-1" << '\n';
	else
		cout << minDistance << '\n';
	return 0;
}
void Dijkstra(int start, int v, int w) {
	fill(d, d + 801, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최소 힙
	pq.push({ 0, start }); // 거리, 시작 노드
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int cur = pq.top().second;

		pq.pop();
		if (d[cur] < dist)
			continue;
		for (int i = 0; i < graph[cur].size(); ++i) {
			int cost = dist + graph[cur][i].second;
			if (cost < d[graph[cur][i].first]) {
				d[graph[cur][i].first] = cost;
				pq.push({ cost, graph[cur][i].first });
			}
		}
	}
	
	distCount.push_back({ d[v], d[w] });
}