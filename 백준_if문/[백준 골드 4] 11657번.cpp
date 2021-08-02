// 최단경로(벨만포드) 문제
// 전체 N-1 번을 반복 -> 매 반복 마다 '모든 간선의 정보(M개)'를 확인

#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef long long ll;

int N, M;
vector<piii> Graph;
vector<ll> Dist;

bool bellmanFord(int start);

int main() {
	cin >> N >> M;

	Dist.resize(N + 1, INF);

	for (int i = 0; i < M; ++i) {
		int a, b, cost;
		cin >> a >> b >> cost;
		Graph.push_back({ a, { b, cost } });
	}

	bool negativeCycle = bellmanFord(1);

	if (negativeCycle) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 2; i <= N; ++i) {
			if (Dist[i] == INF) {
				cout << -1 << '\n';
			}
			else {
				cout << Dist[i] << '\n';
			}
		}
	}

	return 0;
}

bool bellmanFord(int start) {
	Dist[start] = 0;

	// 전체 N-1 번을 반복
	for (int i = 0; i < N; ++i) {
		// 매 반복 마다 모든 간선 정보를 확인
		for (int j = 0; j < M; ++j) {
			int cur = Graph[j].first;
			int next = Graph[j].second.first;
			int weight = Graph[j].second.second;

			if (Dist[cur] != INF && Dist[next] > Dist[cur] + weight) {
				Dist[next] = Dist[cur] + weight;

				if (i == N - 1) {
					return true;
				}
			}
		}
	}

	return false;
}
