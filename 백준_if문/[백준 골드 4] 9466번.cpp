// dfs문제
// Directed Graph에서 cycle판별 문제
// 연결 그래프에서 cycle 판별은 쉬웠으나, 비연결 그래프에서 cycle판별은 까다로운 점이 있었다.
// 결국, 방문 중인지 아닌지를 판별하는 것이 중요했다. 
// 중간에 return문을 잘못 써서 시간 초과 문제로 계속 헛짓을 했다.

#include <iostream>
#include <vector>

using namespace std;

int T, n, cnt;
int graph[100001];
vector<bool> visited;
vector<bool> visitStack;

void dfsAll();
void dfs(int cur);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> n;

		cnt = 0;
		visited.assign(n + 1, false);
		visitStack.assign(n + 1, false);
		//fill(visited, visited + n + 1, false);
		//fill(visitStack, visitStack + n + 1, false);

		for (int i = 1; i <= n; ++i) {
			int to;
			cin >> to;
			graph[i] = to;
		}

		dfsAll();

		cout << n - cnt << '\n';
	}

	return 0;
}

void dfsAll() {
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	return;
}

void dfs(int cur) {
	visited[cur] = true;
	visitStack[cur] = true;

	int next = graph[cur];

	if (visited[next]) {
		if (visitStack[next]) {
			++cnt;
			for (int temp = next; temp != cur; temp = graph[temp]) {
				++cnt;
			}
			//return;
		}
	}
	else {
		dfs(next);
	}
	
	visitStack[cur] = false;

	return;
}