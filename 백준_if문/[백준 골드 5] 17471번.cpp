#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1e9

int N, Answer = MAX;
vector<int> Arr;
vector<vector<int>> Graph;
vector<bool> Select;
vector<bool> Visited;

void dfs(int startIndex, int cnt);
bool check();
bool isConnected(vector<int>& arr, bool flag);

int main() {
	cin >> N;

	Arr.resize(N + 1, 0);
	Graph.resize(N + 1);
	Select.resize(N + 1, false);

	for (int i = 1; i <= N; ++i) {
		cin >> Arr[i];
	}

	for (int i = 1; i <= N; ++i) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			int next;
			cin >> next;
			Graph[i].push_back(next);
			Graph[next].push_back(i);
		}
	}

	dfs(1, 0);

	if (Answer == MAX) {
		cout << "-1" << '\n';
	}
	else {
		cout << Answer << '\n';
	}
	return 0;
}

void dfs(int startIndex, int cnt) {
	if (cnt >= 1) {
		if (check()) {
			int sum1 = 0, sum2 = 0;

			for (int i = 1; i <= N; ++i) {
				if (Select[i]) {
					sum1 += Arr[i];
				}
				else {
					sum2 += Arr[i];
				}
			}

			Answer = min(Answer, abs(sum1 - sum2));
		}
	}

	for (int i = startIndex; i <= N; ++i) {
		if (Select[i]) {
			continue;
		}
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}

bool check() {
	vector<int> a, b;

	for (int i = 1; i <= N; ++i) {
		if (Select[i]) {
			a.push_back(i);
		}
		else {
			b.push_back(i);
		}
	}

	if (a.empty() || b.empty()) {
		return false;
	}

	if (!isConnected(a, true)) {
		return false;
	}

	if (!isConnected(b, false)) {
		return false;
	}

	return true;
}

bool isConnected(vector<int>& arr, bool flag) {
	Visited.assign(N + 1, false);
	queue<int> q;

	Visited[arr[0]] = true;
	q.push(arr[0]);

	int cnt = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : Graph[cur]) {
			if (!Visited[next] && Select[next] == flag) {
				++cnt;
				Visited[next] = true;
				q.push(next);
			}
		}
	}

	if (arr.size() == cnt) {
		return true;
	}
	return false;
}