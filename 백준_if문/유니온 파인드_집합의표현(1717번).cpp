//유니온 파인드(disjoint set)에 대해 알아보는 문제
//사이클 판별 알고리즘 : 그래프에 포함되어 있는 간선의 개수가 E개일 때, 모든 간선에 대하여 find 와 union 함수를 호출하는 방식으로 동작
//-- ""간선에 방향성이 없는 무향 그래프에서만 동작한다"" --
#include <iostream>
using namespace std;
int n;//n(1 ≤ n ≤ 1,000,000)
int m;//m(1 ≤ m ≤ 100,000) : 입력으로 주어지는 연산의 개수
int parent[1000001] = { 0 };
int findParent(int x);
void unionParent(int a, int b);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
	}
	int Cases, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> Cases >> a >> b;
		if (Cases == 0) 
			unionParent(a, b);
		else {
			if (findParent(a) == findParent(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
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