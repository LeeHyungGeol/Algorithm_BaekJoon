//최소 신장 트리: """가장 적은 개수의 간선으로 모든 정점을 연결""" + """사이클이 존재하지 않는 부분 그래프"""
//최소 신장 트리 사용 목적: 모든 노드가 연결되어 있지만, 일부 간선은 사용하지 않아도 될 때, 최소한의 비용으로 구성되는 신장 트리를 찾아야 할 때
//크루스칼 알고리즘: 대표적인 최소 신장 트리 알고리즘 - 그리디 알고리즘으로 분류
//크루스칼 알고리즘 구체적인 동작 과정: 1. 간선 데이터를 비용에 따라 "오름차순"으로 정렬
//										2. 간선을 하나씩 확인하며 현재의 간선이 사이클을 발생시키는지 확인
//										- 사이클이 발생하지 않는 경우에만 최소 신장 트리에 포함시킨다.
//										3. 모든 간선에 대하여 2의 과정을 반복한다.
//최종적으로 만들어지는 최소 신장 트리에 포함된 간선의 개수:"" 전체 노드의 개수 - 1""이다. 트리가 가지고 있는 특성, 사이클 존재 X
//크루스칼 알고리즘 성능: 간선의 개수가 E개일 때, O(ElogE) : 간선을 오름차순 정렬할 때, 가장 시간이 많이 든다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;//국가의 수 N(2 ≤ N ≤ 1 000)
int M;//비행기의 종류 M(1 ≤ M ≤ 10 000) 
int parent[1001];
vector<pair<int, pair<int, int>>> graph;
int findParent(int x);
void unionParent(int a, int b);
int main() {
	int T;
	cin >> T;
	for (int j = 0; j < T; ++j) {
		int result = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; ++i)
			parent[i] = i;
		int a, b, c = 0;
		for (int i = 1; i <= M; ++i) {
			cin >> a >> b;
			graph.push_back({ c, { a , b } });
		}

		//sort(graph.begin(), graph.end());
		for (int i = 0; i < graph.size(); ++i) {
			int cost = graph[i].first;
			int a = graph[i].second.first;
			int b = graph[i].second.second;
			if (findParent(a) != findParent(b)) {
				unionParent(a, b);
				result += 1;
			}
		}

		cout << result << '\n';
	}
	return 0;
}
int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}