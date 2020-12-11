//간선에 가중치가 있을 때 최단경로를 출력하는 문제
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <stack>
#define INF 1e9//10억
using namespace std;
int n; //n(1≤n≤1,000)개의 도시
int m; //m(1≤m≤100,000)개의 버스
int from, to;
vector<pair<int, int>> graph[100001];
int d[100001];
int visited[100001] = { 0 };//visited[a] = b 의 의미 : "a번 정점에 최소 비용으로 도달하기 위해서는 b정점에서 와야 한다."
void dijkstra(int start, int end);
int main() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}
	cin >> from >> to;
	fill(d, d + 100001, INF);
	//memset(d, INF, sizeof(d)); //d[] table의 크기가 10만 정도 될 때는 memset() 사용 불가! fill() 사용하기 
	dijkstra(from, to);
	cout << d[to] << '\n';
	stack<int> s;
	int x = to;
	while (x != 0) {
		s.push(x);
		x = visited[x];
	}
	cout << s.size() << '\n';
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
	return 0;
}
void dijkstra(int start, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int cur = pq.top().second;

		pq.pop();
		if (d[cur] < dist)
			continue;
		for (int i = 0; i < graph[cur].size(); ++i) {
			int cost = dist + graph[cur][i].second;
			int next = graph[cur][i].first;
			if (cost < d[next]) {
				d[next] = cost;
				visited[next] = cur;
				pq.push({ cost, next });
			}
		}
	}
	return;
}