// 서로소집합(Disjoint Set, Union-Find) 문제
// 두 사람 사이의 경로가 없는 경우 : findParent(a) != findParent(b)
// 두 사람 사이의 경로가 있는 경우 : findParent(a) == findParent(b)

// N이 10^6, K가 10^5, M이 10^5 이고, TestCase마저 여러개 이므로 입력과 출력에 시간을 많이 할애하므로, 입출력 시간을 줄여주는 코드가 필요하다.

#include <iostream>
#include <vector>

using namespace std;

int T, N, K, M;
vector<int> Parent;

int findParent(int x);
void unionParent(int a, int b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> N >> K;

		Parent.resize(N, 0);

		for (int i = 0; i < N; ++i) {
			Parent[i] = i;
		}

		for (int i = 0; i < K; ++i) {
			int a, b;
			cin >> a >> b;
			unionParent(a, b);
		}

		cin >> M;

		cout << "Scenario " << t << ":" << '\n';

		for (int i = 0; i < M; ++i) {
			int u, v;
			cin >> u >> v;
			if (findParent(u) == findParent(v)) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}

		cout << '\n';
	}

	return 0;
}

int findParent(int x) {
	if (x != Parent[x]) {
		Parent[x] = findParent(Parent[x]);
	}
	return Parent[x];
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