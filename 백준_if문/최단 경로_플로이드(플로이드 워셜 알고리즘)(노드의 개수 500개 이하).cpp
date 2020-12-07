#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9 //10��
#define FOR(i, b, e) for(int i=b;i<e;++i)
//�ð� : O(N^3)
//�÷��̵� ���� �˰����� ����ؾ� �ϴ� ��� ����� ������ �ִ� 500��

using namespace std;
int graph[101][101] = { 0 };
int n, m;

int main() {
	cin >> n >> m;

	//init(�ʱ�ȭ)
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
	//input(�Է�)
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		if (c < graph[a][b])
			graph[a][b] = c;
	}

	//Floyd_Warshall Algorithm
	for (int k = 1; k <= n; ++k) {//�� �ܰ踶�� Ư���� ��� k�� ���İ��� ��츦 �������� Ȯ���Ѵ�.
		for (int i = 1; i <= n; ++i) {//i���� j�� ���� �ִ� �Ÿ����� i���� k�� ���� j�� ���� �ִܰŸ��� �� ª���� �˻�
			for (int j = 1; j <= n; ++j) {
				graph[i][j] = min(graph[i][j],
									graph[i][k] + graph[k][j]);
			}
		}
	}

	//���
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