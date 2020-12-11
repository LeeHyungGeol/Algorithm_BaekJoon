#include <iostream>
#include <queue>
#include <string>
#include <string.h>
using namespace std;
#define mod 10000
int T, n, from, to;
bool visited[10001]; //""0000 ~ 9999 까지의 숫자를 방문했나 안했나로 BFS를 수행""
int D(int N);
int S(int N);
int L(int N);
int R(int N);
void bfs(int start, int end);

int main() {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> from >> to;
		memset(visited, false, sizeof(visited));//한 번의 TestCase 마다 memset해주기
		bfs(from, to);
	}

	return 0;
}
void bfs(int start, int end) {
	queue<pair<int, string>> q;
	q.push({ start,"" });
	visited[start] = true;
	while (!q.empty()) {
		int x = q.front().first;
		string answer = q.front().second;
		q.pop();
		if (x == end) {
			cout << answer << '\n';
			return;
		}
		int d, s, l, r;
		d = D(x);
		if (!visited[d]) {
			visited[d] = true;
			q.push({ d, answer + "D" });
		}

		s = S(x);
		if (!visited[s]) {
			visited[s] = true;
			q.push({ s, answer + "S" });
		}

		l = L(x);
		if (!visited[l]) {
			visited[l] = true;
			q.push({ l, answer + "L" });
		}

		r = R(x);
		if(!visited[r]) {
			visited[r] = true;
			q.push({ r, answer + "R" });
		}
	}
}
int D(int N) {
	return (N * 2) % mod;//modulo 연산은 몇번을 수행해도 상관없다.
}
int S(int N) {
	return N - 1 < 0 ? 9999 : N - 1;
}
int L(int N) {
	return (N % 1000) * 10 + N / 1000; /////
}
int R(int N) {
	return (N % 10) * 1000 + (N / 10);////
}
