#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M;
bool visited[1001][1001][2];
int d[1001][1001][2] = {0};
int graph[1001][1001] = {0};
int vecX[5] = { 0,1,-1,0,0 };
int vecY[5] = { 0,0,0,1,-1 };
int bfs();
int bfs2();

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%1d", &graph[i][j]);
		}
	}
	//cout << bfs() << '\n';
	cout << bfs2() << '\n';
}
int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> que;
	que.push({ {1,1},{0,1} });
	visited[1][1][0] = true;
	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int broken = que.front().second.first;
		int cnt = que.front().second.second;

		que.pop();
		if (x == N && y == M)
			return cnt;
		for (int i = 1; i <= 4; ++i) {
			int newX = x + vecX[i];
			int newY = y + vecY[i];
			if (newX <= N && newX > 0 && newY <= M && newY > 0) {
				if (graph[newX][newY] == 1 && broken == 0) {
					visited[newX][newY][broken + 1] = true;
					que.push({ {newX,newY},{broken + 1,cnt + 1} });
				}
				else if (graph[newX][newY] == 0 && visited[newX][newY][broken] == false) {
					visited[newX][newY][broken] = true;
					que.push({ {newX,newY},{broken,cnt + 1} });
				}
			}
		}
	}
	return -1;
}
int bfs2() {
	queue<pair<pair<int, int>, int>> que;
	que.push({ {1,1},0 });
	d[1][1][0] = 1;
	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int broken = que.front().second;
	
		que.pop();
		if (x == N && y == M)
			return d[x][y][broken];
		for (int i = 1; i <= 4; ++i) {
			int newX = x + vecX[i];
			int newY = y + vecY[i];
			if (newX <= N && newX >= 1 && newY <= M && newY >= 1) {
				if (graph[newX][newY] == 1 && broken == 0) {
					d[newX][newY][broken + 1] = d[x][y][broken] + 1;
					que.push({ {newX,newY},broken + 1 });
				}
				else if (graph[newX][newY] == 0 && d[newX][newY][broken] == 0) {
					d[newX][newY][broken] = d[x][y][broken] + 1;
					que.push({ {newX,newY},broken });
				}
			}	
		}
	}
	return -1;
}
