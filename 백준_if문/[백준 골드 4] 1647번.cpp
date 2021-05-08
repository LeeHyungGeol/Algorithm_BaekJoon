#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

//집의 개수N, 길의 개수M이 주어진다. 
//N은 2이상 100,000이하인 정수이고, M은 1이상 1,000,000이하인 정수
int v, e;
int result = 0, cnt = 0;
int parent[100001] = { 0, };
vector<piii> graph;

int find(int x) {
	if (x != parent[x]) {
		return parent[x] = find(parent[x]);
	}
	return x;
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) {
		parent[b] = a;
	} else {
		parent[a] = b;
	}
}

int main() {
	cin >> v >> e;

	for (int i = 1; i <= v; ++i) {
		parent[i] = i;
	}

	for (int i = 0; i < e; ++i) {
		int a, b, cost;
		cin >> a >> b >> cost;

		graph.push_back({ cost, { a, b} });
	}

	sort(graph.begin(), graph.end());

	for (int i = 0; i < graph.size(); ++i) {
		int cost = graph[i].first;
		int a = graph[i].second.first;
		int b = graph[i].second.second;

		if (find(a) != find(b)) {
			Union(a, b);
			result += cost;
			++cnt;
			// 최소 신장 트리(간선의 개수 == 정점의 개수 - 1)로 만든 후
			// 마지막 간선만 제거하면 최소 비용으로 2개의 마을을 만들 수 있다.
			if (cnt == v - 1) {
				result -= cost;
				break;
			}
		}
	}

	cout << result << '\n';

	return 0;
}