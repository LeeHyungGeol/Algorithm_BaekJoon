// 트리 문제
// 생각은 쉬웠는데, 구현하는 것이 매우 복잡했던 문제
// 각각의 노드의 부모노드, 깊이(depth)를 전부 구하고
// 배열의 index를 node 번호로 사용해야 한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, K;
vector<int> Parent;
vector<int> Depth;
vector<int> Arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Arr.assign(1000001, 0);
	Parent.assign(1000001, 0);
	Depth.assign(1000001, 0);

	while (true) {

		cin >> N >> K;

		if (N == 0 && K == 0) {
			break;
		}

		for (int i = 0; i < N; ++i) {
			cin >> Arr[i];
		}

		int parent = Arr[0];
		int depth = 0;
		queue<pii> Q;

		Q.push({ parent, depth });

		for (int i = 1; i < N; ++i) {
			if (Arr[i] - Arr[i - 1] > 1) {
				parent = Q.front().first;
				depth = Q.front().second;
				Q.pop();
			}

			Parent[Arr[i]] = parent;
			Depth[Arr[i]] = depth + 1;
			Q.push({ Arr[i], depth + 1 });
		}

		int cnt = 0;

		for (int i = 0; i < N; ++i) {
			if (Depth[Arr[i]] == Depth[K]) {
				int a = Parent[Arr[i]];
				int b = Parent[K];
				if (a != b && Parent[a] == Parent[b]) {
					++cnt;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}