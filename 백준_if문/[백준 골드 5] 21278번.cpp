#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N, M, answer = INF;
vector<piii> building;
vector<vector<int>> graph;
vector<bool> Select;

void solution1();
void solution2();
void floyd_warshall();
int getDistance(int first, int second);
void dfs(int startIndex, int cnt);
bool compare(const piii& a, const piii& b);

int main() {
	cin >> N >> M;

	graph.resize(N + 1, vector<int>(N + 1, INF));
	Select.resize(N + 1, false);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j) {
				graph[i][j] = 0;
			}
		}
	}

	floyd_warshall();

	// solution1();

	solution2();
	
	return 0;
}

void floyd_warshall() {
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	return;
}

void solution1() {
	int first=0, second=0;

	for (int i = 1; i <= N - 1; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			int ret = getDistance(i, j);

			if (answer > ret) {
				answer = ret;
				first = i;
				second = j;
			}
		}
	}

	cout << first << " " << second << " " << 2*answer << '\n';

	return;
}

int getDistance(int first, int second) {
	int d = 0;

	for (int i = 1; i <= N; ++i) {
		d += min(graph[first][i], graph[second][i]);
	}

	return d;
}

void solution2() {
	dfs(1, 0);

	sort(building.begin(), building.end(), compare);

	cout << building[0].second.first << ' ' << building[0].second.second << ' ' << 2 * building[0].first << '\n';

	return;
}

void dfs(int startIndex, int cnt) {
	if (cnt == 2) {
		vector<int> temp;
		for (int i = 1; i < Select.size(); ++i) {
			if (Select[i]) {
				temp.push_back(i);
			}
		}

		int sum = 0;

		for (int i = 1; i <= N; ++i) {
			int first = graph[temp[0]][i];
			int second = graph[temp[1]][i];

			sum += min(first, second);
		}
		
		building.push_back({ sum, { temp[0], temp[1] } });
		
		return;
	}

	for (int i = startIndex; i < Select.size(); ++i) {
		if (Select[i]) {
			continue;
		}
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}

bool compare(const piii& a, const piii& b) {
	if (a.first == b.first) {
		if (a.second.first == b.second.first) {
			return a.second.second < b.second.second;
		}
		else {
			return a.second.first < b.second.first;
		}
	}
	return a.first < b.first;
}
