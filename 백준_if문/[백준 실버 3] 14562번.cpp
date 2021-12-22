#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Node {
	int cur, end, count;
}Node;

int S, T, C;
vector<bool> Visited;

int bfs();

int main() {
	cin >> C;

	for (int c = 0; c < C; ++c) {
		cin >> S >> T;

		int result = bfs();
		
		cout << result << '\n';
	}

	return 0;
}

int bfs() {
	int result = 0;
	queue<Node> q;
	Visited.assign(202, false);

	q.push({ S, T, 0 });
	Visited[S] = true;

	while (!q.empty()) {
		int cur = q.front().cur;
		int end = q.front().end;
		int count = q.front().count;
		q.pop();

		if (cur == end) {
			result = count;
			break;
		}

		if (1 <= (cur + cur) && (cur + cur) <= 100 && 1 <= (T + 3) && (T + 3) <= 100 && !Visited[cur + cur]) {
			Visited[cur + cur] = true;
			end += 3;
			q.push({ cur + cur, end, count + 1 });
		}

		if (1 <= (cur + 1) && (cur + 1) <= 100 && !Visited[cur + 1]) {
			Visited[cur + 1] = true;
			q.push({ cur + 1, end, count + 1 });
		}
	}

	return result;
}