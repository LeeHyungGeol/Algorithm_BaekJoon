#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9 //10억
#define FOR(i, b, e) for(int i=b;i<e;++i)
//시간 : O(N^3)
//플로이드 워셜 알고리즘을 사용해야 하는 경우 노드의 개수는 최대 500개

using namespace std;
int graph[101][101] = { 0 };
int n, m;

int main() {
	cin >> n >> m;

	//init(초기화)
	for (int i = 0; i <= n; ++i) {
		fill(graph[i], graph[i] + 101, INF);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == j)
				graph[i][j] = 0;
		}
	}

	//for (int i = 0; i <= V; ++i) {
	//	for (int j = 0; j <= V; ++j) {
	//		if (i == j)
	//			graph[i][j] = 0;
	//		else
	//			graph[i][j] = INF;
	//	}
	//}

	int a, b, c;
	//input(입력)
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		if (c < graph[a][b])
			graph[a][b] = c;
	}

	//Floyd_Warshall Algorithm
	for (int k = 1; k <= n; ++k) {//각 단계마다 특정한 노드 k를 거쳐가는 경우를 기준으로 확인한다.
		for (int i = 1; i <= n; ++i) {//i에서 j로 가는 최단 거리보다 i에서 k를 거쳐 j로 가는 최단거리가 더 짧은지 검사
			for (int j = 1; j <= n; ++j) {
				graph[i][j] = min(graph[i][j],
									graph[i][k] + graph[k][j]);
			}
		}
	}

	//출력
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (graph[i][j] == INF)
				cout << "0" << ' ';
			else
				cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}