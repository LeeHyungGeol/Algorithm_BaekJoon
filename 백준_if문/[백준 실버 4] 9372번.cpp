// 최소 신장 트리(MST : Minimum Spanning Tree) 문제

// 여기서는 간선의 비용이 없는 최소 신장 트리를 만들어야 한다.
// 말 그대로 간선의 개수가 N-1 개인 트리를 만들면 된다.

#include <iostream>
#include <vector>

using namespace std;

int N, M, T;
vector<int> Parent;

int findParent(int x);
void unionParent(int a, int b);

int main() {
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> N >> M;

		Parent.resize(N + 1, 0);

		for (int i = 1; i <= N; ++i) {
			Parent[i] = i;
		}

		int answer = 0;

		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			if (findParent(a) != findParent(b)) {
				unionParent(a, b);
				++answer;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) {
		Parent[b] = a;
	}
	else {
		Parent[a] = b;
	}
}

int findParent(int x) {
	if (x != Parent[x]) {
		Parent[x] = findParent(Parent[x]);
	}
	return Parent[x];
}
