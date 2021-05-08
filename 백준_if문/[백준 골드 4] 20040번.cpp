#include <iostream>

using namespace std;

int v, e;
// 점의 개수를 나타내는 정수 3 ≤ n ≤ 500,000
int parent[500001] = { 0, };

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
	// v : 점의 개수를 나타내는 정수 3 ≤ n ≤ 500,000
	// e : 진행된 차례의 수를 나타내는 정수 3 ≤ m ≤ 1,000,000
	cin >> v >> e;

	// 모든 노드의 부모를 자기 자신으로 초기화
	for (int i = 1; i <= v; ++i) {
		parent[i] = i;
	}

	int cycle = 0;

	for (int i = 0; i < e; ++i) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b)) {
			cycle = i + 1;
			break;
		}
		else {
			Union(a, b);
		}
	}
	
	cout << cycle << '\n';

	return 0;
}