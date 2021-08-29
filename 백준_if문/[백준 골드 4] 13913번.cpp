#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int N, K, Answer;
int Visited[100001];
stack<int> S;

void bfs(int start, int end);

int main() {
	cin >> N >> K;

	memset(Visited, -1, sizeof(Visited));

	bfs(N, K);

	return 0;
}

void bfs(int start, int end) {
	queue<pii> q;

	q.push({ start, 0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == end) {
			cout << cnt << '\n';
			
			int next = end;
			
			while (next != start) {
				S.push(next);
				next = Visited[next];
			}

			S.push(start);

			while(!S.empty()) {
				cout << S.top() << ' ';
				S.pop();
			}

			return;
		}

		if (0 <= cur+1 && cur+1 <= 100000 && Visited[cur + 1] == -1) {
			Visited[cur + 1] = cur;
			q.push({ cur + 1, cnt + 1 });
		}

		if (0 <= cur - 1 && cur - 1 <= 100000 && Visited[cur - 1] == -1) {
			Visited[cur - 1] = cur;
			q.push({ cur - 1, cnt + 1 });
		}

		if (0 <= cur * 2 && cur * 2 <= 100000 && Visited[cur * 2] == -1) {
			Visited[cur * 2] = cur;
			q.push({ cur * 2, cnt + 1 });
		}
	}
}