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
		//�׽�Ʈ���̽��� T�� �����Ƿ� �����Ҷ����� graph �� dist �� �ʱ�ȭ
		for (int i = 1; i <= N; ++i) {
			graph[i].clear();
			for (int j = 1; j <= M; ++j) {
				dist[i][j] = INF;
			}
		}

		//input(�Է�)
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
	dist[1][0] = 0; //start�� 1�� ���
	pq.push({ 0,{1, 0} });//�Ÿ�, ���� ���, ���

	while (!pq.empty()) {
		int cur = pq.top().second.first; //���� ���
		int cur_dist = pq.top().first;//���� ������ ���µ� ��� �Ÿ�
		int cur_cost = pq.top().second.second;//���� ������ ���µ� �� ���
		
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

					//���� ť�� ���� cost ������ ���� cost�κе��� ���� �ִ� cost������ �۰ų� ���� �Ÿ� ���� ���� �� �ִ�. 
					//���� ���� cost������ ū �κп��� ���� dist���� ũ�ٸ� �� ������ָ� ����ġ�⸦ �ϴ� ȿ���� ���� �� �ִ�.
					// ����ȭ �κ� - ����
					for (int j = next_cost + 1; j <= M; j++) {
						if (dist[next][j] <= next_dist) 
							break;
						dist[next][j] = next_dist;
					}
					// ����ȭ �κ� - ��

					dist[next][next_cost] = next_dist;
					pq.push({ next_dist, {next, next_cost } });
				}
			}
		}
	}

}