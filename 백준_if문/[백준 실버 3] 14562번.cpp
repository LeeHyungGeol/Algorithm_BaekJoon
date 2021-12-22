#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Node {
	int cur, end, count;
}Node;

int S, T, C;

int bfs();
int dfs(int cur, int end, int count);

int main() {
	cin >> C;

	for (int c = 0; c < C; ++c) {
		cin >> S >> T;

		// int result = bfs();
		int result = dfs(S, T, 0);

		cout << result << '\n';
	}

	return 0;
}

int dfs(int cur, int end, int count) {
	if (cur > end) return 100;
	else if (cur == end) return count;
	else {
		int min1 = dfs(cur * 2, end + 3, count + 1);
		int min2 = dfs(cur + 1, end, count + 1);
		return min(min1, min2);
	}
}

int bfs() {
	int result = T - S;
	queue<Node> q;
	q.push({ S, T, 0 });

	while (!q.empty()) {
		int cur = q.front().cur;
		int end = q.front().end;
		int count = q.front().count;
		q.pop();

		if (cur == end) {
			result = min(result, count);
			break;
		}

		if (!(cur > end)) {
			q.push({ cur * 2, end + 3, count + 1 });
			q.push({ cur + 1, end, count + 1 });
		}
	}

	return result;
}