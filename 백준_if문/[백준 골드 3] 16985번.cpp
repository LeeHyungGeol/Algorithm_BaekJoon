// bfs, 

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX 5
#define INF 1e9

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int Answer = INF;
int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { -1,1,0,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 }; 
vector<bool> Select;
vector<int> RotateOrder, PileOrder;
vector<vector<vector<int>>> TempGraph, Graph;

void dfsPileOrder(int cnt);
void dfsRotateOrder(int cnt);
void pile();
void rotate(vector<vector<int>>& arr);
int bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Graph.resize(MAX);

	for (int i = 0; i < MAX; ++i) {
		Graph[i].resize(MAX, vector<int>(MAX));
		for (int j = 0; j < MAX; ++j) {
			for (int k = 0; k < MAX; ++k) {
				cin >> Graph[i][j][k];
			}
		}
	}

	Select.resize(MAX, false);
	PileOrder.resize(MAX, -1);
	RotateOrder.resize(MAX, -1);

	dfsPileOrder(0);

	if (Answer == INF) {
		cout << -1 << '\n';
	}
	else {
		cout << Answer << '\n';
	}
	return 0;
}

// 순열
void dfsPileOrder(int cnt) {
	if (cnt == MAX) {
		pile();
		dfsRotateOrder(0);
		return;
	}

	for (int i = 0; i < 5; ++i) {
		if (Select[i]) {
			continue;
		}
		Select[i] = true;
		PileOrder[cnt] = i;
		dfsPileOrder(cnt + 1);
		Select[i] = false;
	}
}

void pile() {
	TempGraph.clear();
	TempGraph.resize(MAX);

	for (int i = 0; i < MAX; ++i) {
		TempGraph[i] = Graph[PileOrder[i]];
	}

	return;
}

// 중복순열
void dfsRotateOrder(int cnt) {
	if (cnt == MAX) {
		int result = bfs();

		if (result != -1) {
			if (Answer > result) {
				Answer = result;
			}
		}
		return;
	}

	for (int i = 0; i < 4; ++i) {
		rotate(TempGraph[cnt]);
		// RotateOrder[cnt] = i;
		dfsRotateOrder(cnt + 1);
	}
}

// 시계방향으로 90도 만큼 회전
void rotate(vector<vector<int>>& arr) {
vector<vector<int>> temp(MAX, vector<int>(MAX));

	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			temp[j][MAX - i - 1] = arr[i][j];
		}
	}

	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			arr[i][j] = temp[i][j];
		}
	}
}

int bfs() {
	if (TempGraph[0][0][0] == 0 || TempGraph[4][4][4] == 0) {
		return -1;
	}

	int dist[MAX][MAX][MAX];

	memset(dist, -1, sizeof(dist));

	queue<piii> q;

	q.push({ 0, {0, 0} });
	dist[0][0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second.first;
		int z = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (0 <= nx && nx < MAX && 0 <= ny && ny < MAX && 0 <= nz && nz < MAX) {
				if (TempGraph[nz][nx][ny] == 1 && dist[nz][nx][ny] == -1) {
					dist[nz][nx][ny] = dist[z][x][y] + 1;
					q.push({ nx,{ny, nz} });
				}
			}
		}
	}

	return dist[4][4][4];
}