#include <iostream>
#include <algorithm>
#define INF 100001
using namespace std;
int V, E;
int graph[401][401] = { 0 };
int main() {

	cin >> V >> E;
	for (int i = 0; i <= V; ++i) {
		for (int j = 0; j <= V; ++j) {
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}

	//입력(input)
	int a, b, c;
	for (int i = 0; i < E; ++i) {
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	//Floyd_Warshall Algorithm
	for (int k = 1; k <= V; ++k) {//각 단계마다 특정한 노드 k를 거쳐가는 경우를 기준으로 확인한다.
		for (int i = 1; i <= V; ++i) {//i에서 j로 가는 최단 거리보다 i에서 k를 거쳐 j로 가는 최단거리가 더 짧은지 검사
			for (int j = 1; j <= V; ++j) {
				graph[i][j] = min(graph[i][j],
								graph[i][k] + graph[k][j]);
			}
		}
	}
	int minDistance = INF;
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (i != j) {
				if (minDistance > graph[i][j] + graph[j][i])
					minDistance = graph[i][j] + graph[j][i];
			}
		}
	}

	if (minDistance >= INF)
		cout << "-1" << '\n';
	else
		cout << minDistance << '\n';
	return 0;
}