// 플로이드 워셜(최단거리) 문제
// 모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구하는 알고리즘

// 여기서는 아주 조금 다르다.
// 모든 지점에서 다른 모든 지점까지의 '관계'를 구하는 문제

// 학생들의 키를 비교한 결과가 주어질 때, 자신의 키가 몇 번째인지 알 수 있는 학생들이 모두 몇 명인지 계산하여 출력하는 프로그램을 작성
// 자신의 키를 알려면, 자신의 제외한 다른 모든 학생과의 관계를 알아야 한다.
// graph[i][j] = 1 을 i 와 j 의 관계라고 할 때,
// (graph[i][j] != INF || graph[j][i] != INF) 조건을 만족하는 
// 자신의 제외한 다른 모든 노드와 관계가 있는 경우(if(cnt == N - 1))인 노드의 개수를 구하면 된다.

// 단, 여기서는 '최단 거리' 가 아닌 '관계'를 구하는 것이기 때문에,
// (i == j) 의 경우, continue를 하거나 관계가 없다는 의미로 최단거리 0이 아닌 관계가 없다는 의미인 'INF'로 처리해줘야 한다.

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