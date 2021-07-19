// dfs����
// Directed Graph���� cycle�Ǻ� ����
// ���� �׷������� cycle �Ǻ��� ��������, �񿬰� �׷������� cycle�Ǻ��� ��ٷο� ���� �־���.
// �ᱹ, �湮 ������ �ƴ����� �Ǻ��ϴ� ���� �߿��ߴ�. 
// �߰��� return���� �߸� �Ἥ �ð� �ʰ� ������ ��� ������ �ߴ�.

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