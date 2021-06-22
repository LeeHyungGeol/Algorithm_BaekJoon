// �÷��̵� ����(�ִܰŸ�) ����
// ��� �������� �ٸ� ��� ���������� �ִ� ��θ� ��� ���ϴ� �˰���

// ���⼭�� ���� ���� �ٸ���.
// ��� �������� �ٸ� ��� ���������� '����'�� ���ϴ� ����

// �л����� Ű�� ���� ����� �־��� ��, �ڽ��� Ű�� �� ��°���� �� �� �ִ� �л����� ��� �� ������ ����Ͽ� ����ϴ� ���α׷��� �ۼ�
// �ڽ��� Ű�� �˷���, �ڽ��� ������ �ٸ� ��� �л����� ���踦 �˾ƾ� �Ѵ�.
// graph[i][j] = 1 �� i �� j �� ������ �� ��,
// (graph[i][j] != INF || graph[j][i] != INF) ������ �����ϴ� 
// �ڽ��� ������ �ٸ� ��� ���� ���谡 �ִ� ���(if(cnt == N - 1))�� ����� ������ ���ϸ� �ȴ�.

// ��, ���⼭�� '�ִ� �Ÿ�' �� �ƴ� '����'�� ���ϴ� ���̱� ������,
// (i == j) �� ���, continue�� �ϰų� ���谡 ���ٴ� �ǹ̷� �ִܰŸ� 0�� �ƴ� ���谡 ���ٴ� �ǹ��� 'INF'�� ó������� �Ѵ�.

#include <iostream>
#define INF 1e9

using namespace std;

int N, M;
int graph[501][501] = { 0, };

void floyd_warshall();

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			//graph[i][j] = INF;
			graph[i][j] = (i == j) ? 0 : INF;
		}
	}

	for (int i = 0; i < M; ++i) {
		int from, to;
		cin >> from >> to;
		graph[from][to] = 1;
	}

	floyd_warshall();

	int answer = 0;

	for (int i = 1; i <= N; ++i) {
		int cnt = 0;		
		for (int j = 1; j <= N; ++j) {
			if (i == j) {
				continue;
			}
			if (graph[i][j] != INF || graph[j][i] != INF) {
				++cnt;
			}
		}
		if (cnt == N - 1) {
			++answer;
		}
	}

	cout << answer << '\n';

	return 0;
}

void floyd_warshall() {
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	return;
}