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

	//�Է�(input)
	int a, b, c;
	for (int i = 0; i < E; ++i) {
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	//Floyd_Warshall Algorithm
	for (int k = 1; k <= V; ++k) {//�� �ܰ踶�� Ư���� ��� k�� ���İ��� ��츦 �������� Ȯ���Ѵ�.
		for (int i = 1; i <= V; ++i) {//i���� j�� ���� �ִ� �Ÿ����� i���� k�� ���� j�� ���� �ִܰŸ��� �� ª���� �˻�
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