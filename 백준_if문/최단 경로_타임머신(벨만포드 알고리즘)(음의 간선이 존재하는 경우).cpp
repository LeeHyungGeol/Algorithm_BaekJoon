#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

//시간 : O(VE)

#define INF 1e9 //10억
int N, M;
vector<tuple<int, int, int>> graph;
long long int d[501]; //최대 노드의 수: 500
bool Bellman_Ford(int start);

int main() {
	cin >> N >> M;//N: 노드, M: 간선
	int a, b, c;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		graph.push_back(make_tuple(a, b, c));
	}
	fill(d, d + 501, INF);
	bool negativeCycle = Bellman_Ford(1);
	if (negativeCycle) {//음의 간선이 존재해서 음의 순환이 존재하는 경우
		cout << "-1" << '\n';
		return 0;
	}
	else {
		for (int i = 2; i <= N; ++i) {
			if (d[i] == INF)
				cout << "-1" << '\n';
			else
				cout << d[i] << '\n';
		}
	}
	return 0;
}
bool Bellman_Ford(int start) {
	d[start] = 0; //시작점, 자기 자신 까지의 거리는 0
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {//매 반복마다 "모든 간선"을 확인한다.	
			int cur, next, cost;
			tie(cur, next, cost) = graph[j];
			// 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
			if (d[cur] != INF && d[cur] + cost < d[next]) {//한번 방문하여 처리된 노드의 최단 거리는 고정되어 더이상 바뀌지 않는다.
				d[next] = d[cur] + cost;
				if (i == N - 1)//N번째에서 값이 갱신된다면 음의 순환이 존재
					return true;
			}
		}
	}
	return false;
}