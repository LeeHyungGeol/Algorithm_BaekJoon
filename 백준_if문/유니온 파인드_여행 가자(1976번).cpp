//BFS, DFS 뿐만 아니라 유니온 파인드로도 두 정점이 연결되어 있는지를 확인할 수 있습니다.
//사이클 판별 알고리즘 : 그래프에 포함되어 있는 간선의 개수가 E개일 때, 모든 간선에 대하여 find 와 union 함수를 호출하는 방식으로 동작
//-- ""간선에 방향성이 없는 무향 그래프에서만 동작한다"" --
#include <iostream>
using namespace std;
int N;// 도시의 수 N이 주어진다. N은 200이하
int M;//여행 계획에 속한 도시들의 수 M이 주어진다. M은 1000이하
int parent[201] = { 0 };
int findParent(int x);
void unionParent(int a, int b);
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		parent[i] = i;
	int x;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> x;
			if (x == 1)
				unionParent(i, j);
		}
	}
	int a, b;
	cin >> a;
	for (int i = 2; i <= M; ++i) {
		cin >> b;
		if (findParent(a) == findParent(b))
			continue;
		else {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
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