// 최단거리(플로이드 워셜) 문제

// 플로이드 워셜 문제는 항상 모든 지점에서 다른 모든 지점까지의 `관계` 
// 즉, 연결되어 있냐, 연결되어 있지 않냐 / 갈 수 있냐, 없냐의 문제로 나온다.

// 이 문제에선 살짝 꼬아서, Graph[a][b]의 값이 0이면 갈 수 있다는 의미이다.
// Graph[a][b] = 0 : a에서 b로 갈 수 있다라는 의미
// 입력을 받을 때, 
// b가 0 이면(단방향), Graph[u][v] = 0 으로 입력(u에서 v로 갈 수 있으므로)
// Graph[v][u] 는 1 이다. 단방향을 양방향으로 바꿔야 하므로 1 로 입력

// b가 1 이면(양방향), Graph[u][v] = 0, Graph[v][u] = 0, 애초에 양방향이므로 둘 다 갈 수 있기 때문이다. 

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, M, K;
vector<vector<int>> Graph;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	Graph.resize(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j) {
				Graph[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < M; ++i) {
		int u, v, b;
		cin >> u >> v >> b;
		Graph[u][v] = 0;
		Graph[v][u] = (b == 0) ? 1 : 0;
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
			}
		}
	}

	cin >> K;

	for (int i = 0; i < K; ++i) {
		int s, e;
		cin >> s >> e;
		cout << Graph[s][e] << '\n';
	}

	return 0;
}