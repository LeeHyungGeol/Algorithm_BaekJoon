//https://www.crocus.co.kr/637
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string.h>
#define MAX 100001
using namespace std;
int N; // 현재 점 N(0 ≤ N ≤ 100,000)
int K; //점 K(0 ≤ K ≤ 100,000)
int visited[100001];
//bool boolVisited[100001];// "0 ~ 100,000" 이 사이의 점을 방문했나 안했나의 기준으로 BFS를 수행
stack<int> s;
void bfs(int start, int end);
int main() {
	cin >> N >> K;
	bfs(N, K);
	return 0;
}
void bfs(int start, int end) {
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	memset(visited, -1, sizeof(visited));

	while (!q.empty()) {
		int x = q.front().first;
		int answer = q.front().second;
		q.pop();
		if (x == end) {
			cout << answer << '\n';
			int index = end;
			while (index != start) {
				s.push(index);
				index = visited[index];
			}
			s.push(start);
			while (!s.empty()) {
				cout << s.top() << ' ';
				s.pop();
			}
			cout << '\n';
			return;
		}

		if (x + 1 < MAX && visited[x + 1] == -1) {
			visited[x + 1] = x;
			q.push({ x + 1, answer + 1 });
		}
	
		if (0 <= x - 1 && visited[x - 1] == -1) {
			visited[x - 1] = x;
			q.push({ x - 1, answer + 1 });
		}

		if (x * 2 < MAX && visited[x * 2] == -1) {
			visited[x * 2] = x;
			q.push({ x * 2, answer + 1 });
		}
	}
	return;
}
