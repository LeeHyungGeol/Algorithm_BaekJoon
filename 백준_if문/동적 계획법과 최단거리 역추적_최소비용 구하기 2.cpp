//������ ����ġ�� ���� �� �ִܰ�θ� ����ϴ� ����
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <stack>
#define INF 1e9//10��
using namespace std;
int n; //n(1��n��1,000)���� ����
int m; //m(1��m��100,000)���� ����
int from, to;
vector<pair<int, int>> graph[100001];
int d[100001];
int visited[100001] = { 0 };//visited[a] = b �� �ǹ� : "a�� ������ �ּ� ������� �����ϱ� ���ؼ��� b�������� �;� �Ѵ�."
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
	//memset(d, INF, sizeof(d)); //d[] table�� ũ�Ⱑ 10�� ���� �� ���� memset() ��� �Ұ�! fill() ����ϱ� 
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