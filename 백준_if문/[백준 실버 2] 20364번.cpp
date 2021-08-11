// 트리(이진트리) 문제, Set도 사용가능

// 계속 2로 나누다가 이미 방문한 노드를 만나면 값을 지속적으로 갱신시켜준다.
// 오리가 1부터 맨 처음 방문한 노드를 출력하는 것이기 때문에, 값을 지속적으로 갱신 시켜주는 것
// 이 부분 때문에 애를 먹었다.

// while문을 다 돌고 나서도 값이 갱신된 것이 없다면, 처음 방문한 것이기 때문에 Visited[cur] = true로 갱신하고, 0을 출력한다.
// 값이 갱신되었다면, 갱신된 값을 출력한다.

// 이 문제는 Set을 이용해서도 풀 수 있다.

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, Q;
set<int> Set;
vector<bool> Visited;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;

	Visited.resize(N + 1, false);

	for (int i = 0; i < Q; ++i) {
		int cur;
		cin >> cur;
		int temp = 0;
		int j = cur;

		while (j) {
			if (Visited[j]) {
				temp = j;
			}
			j /= 2;
		}

		if (temp == 0) {
			Visited[cur] = true;
		}

		cout << temp << '\n';
	}
	
	return 0;
}