//BFS : 간선의 비용이 모두 같을 때, 최단 거리를 탐색하기 위해 사용할 수 있는 알고리즘
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N, M;
bool visited[101][101];
int graph[101][101] = { 0 };
int vecX[5] = { 0,-1,1,0,0 };
int vecY[5] = { 0,0,0,1,-1 };
int bfs(int x, int y);
int main() {
	
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%1d", &graph[i][j]);
		}
	}
	cout << bfs(1, 1) << '\n';

	return 0;
}
int bfs(int x, int y) {
	queue<pair<int, int>> que;
	que.push({ x,y });
	visited[x][y] = true;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 1; i <= 4; ++i) {
			int newX = x + vecX[i];
			int newY = y + vecY[i];
			if (newX <= 0 || newX > N || newY <= 0 || newY > M)
				continue;
			if (visited[newX][newY] == true || graph[newX][newY] == 0)//graph[newX][newY] == 0
				continue;
			if (visited[newX][newY] == false) {//graph[newX][newY] == 1 && visited[newX][newY]==false
				visited[newX][newY] = true;
				graph[newX][newY] = graph[x][y] + 1;
				que.push({ newX,newY });
			}
		}
	}
	return graph[N][M];
}