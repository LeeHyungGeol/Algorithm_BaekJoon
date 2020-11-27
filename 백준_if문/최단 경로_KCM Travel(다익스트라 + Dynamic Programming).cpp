//https://sina-sina.tistory.com/101
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M, K;
vector<pair<int, pair<int, int>>> graph[101];
int dist[101][10001] = { 0 };
void DijkstraDP();

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> M >> K;
		//테스트케이스가 T번 있으므로 시작할때마다 graph 및 dist 를 초기화
		for (int i = 1; i <= N; ++i) {
			graph[i].clear();
			for (int j = 1; j <= M; ++j) {
				dist[i][j] = INF;
			}
		}

		//input(입력)
		int u, v, c, d;
		for (int i = 0; i < K; ++i) {
			cin >> u >> v >> c >> d;
			graph[u].push_back({ v, {c, d} });
		}

		DijkstraDP();

		int answer = INF;
		for (int i = 1; i <= M; ++i) {
			if (answer > dist[N][i])
				answer = dist[N][i];
			//cout << dist[N][i] << '\n';
		}

		if (answer == INF)
			cout << "Poor KCM" << '\n';
		else
			cout << answer << '\n';
	}
	return 0;
}
void DijkstraDP() {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	dist[1][0] = 0; //start는 1번 노드
	pq.push({ 0,{1, 0} });//거리, 시작 노드, 비용

	while (!pq.empty()) {
		int cur = pq.top().second.first; //현재 노드
		int cur_dist = pq.top().first;//현재 노드까지 오는데 드는 거리
		int cur_cost = pq.top().second.second;//현재 노드까지 오는데 쓴 비용
		
		pq.pop();
		if (dist[cur][cur_cost] < cur_dist)
			continue;
		if (cur_cost > M)
			continue;
		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = cur_cost + graph[cur][i].second.first;
			int next_dist = cur_dist + graph[cur][i].second.second;
			if (next_cost <= M) {
				if (next_dist < dist[next][next_cost]) {

					//현재 큐에 넣을 cost 값보다 높은 cost부분들은 현재 넣는 cost값보다 작거나 같은 거리 값을 가질 수 있다. 
					//따라서 현재 cost값보다 큰 부분에서 현재 dist보다 크다면 다 덮어써주면 가지치기를 하는 효과를 얻을 수 있다.
					// 최적화 부분 - 시작
					for (int j = next_cost + 1; j <= M; j++) {
						if (dist[next][j] <= next_dist) 
							break;
						dist[next][j] = next_dist;
					}
					// 최적화 부분 - 끝

					dist[next][next_cost] = next_dist;
					pq.push({ next_dist, {next, next_cost } });
				}
			}
		}
	}

}