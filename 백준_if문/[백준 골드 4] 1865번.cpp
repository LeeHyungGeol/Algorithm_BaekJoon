// 최단거리(벨만포드) 문제
// 벨만포드 알고리즘: 음의 간선이 존재할 때 적용할 수 있는 최단거리 알고리즘

// if(d[cur] != INF) 의 조건문이 필요 없는 이유
// 위의 조건문을 사용하는 이유는 그래프가 연결 되어 있지 않을 때, 단절되었음을 표시하기 위해서 사용하는 것이다.
// 즉, 그래프가 연결되었냐 연결되지 않았냐를 판단하는 것이기 때문에
// 이 문제에선 단순히 그래프의 음의 순환(싸이클)만을 판단하는 것이기 때문에, 
// d 배열의 값을 어느 값으로 초기화 해도 상관이 없다.

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int TC, N, M, W;
int d[501] = { 0, };
vector<piii> graph;

bool bellman_ford();

int main() {
	cin >> TC;

	for (int tc = 0; tc < TC; ++tc) {
		cin >> N >> M >> W;

		graph.clear();
		fill(d, d + 501, -1);

		for (int i = 0; i < M; ++i) {
			int S, E, T;
			cin >> S >> E >> T;
			graph.push_back({ S, {E, T} });
			graph.push_back({ E, {S, T} });
		}
		
		for (int i = 0; i < W; ++i) {
			int S, E, T;
			cin >> S >> E >> T;
			graph.push_back({ S, {E, -T} });
		}

		bool flag = bellman_ford();
	
		if (flag) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

	}

	return 0;
}

bool bellman_ford() {
	//d[1] = 0;
	bool flag = false;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < graph.size(); ++j) {
			int cur = graph[j].first;
			int next = graph[j].second.first;
			int cost = graph[j].second.second;

			if (d[cur] + cost < d[next]) {
				d[next] = d[cur] + cost;
				
				if (i == N - 1) {
					flag = true;
				}
			}
		}
	}

	return flag;
}