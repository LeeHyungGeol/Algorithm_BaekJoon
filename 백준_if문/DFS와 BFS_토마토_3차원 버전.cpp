//BFS�� �丶�並 ������ ����
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, H, cnt0 = 0, cnt1 = 0, cntday = 0;
queue<pair<pair<int, int>, pair<int, int>>> que;
bool visited[101][101][101];
int graph[101][101][101] = { 0 };
int vecZ[7] = {0, 0,0,0 ,0,-1,1 };
int vecX[7] = { 0,0,0 ,-1,1,0,0 };
int vecY[7] = { 0,-1,1,0,0,0,0 };
void bfs();

int main() {
	cin >> M >> N >> H;//����, ����, ����
	for (int i = 1; i <= H; ++i) {//����
		for (int j = 1; j <= N; ++j) {//����
			for (int k = 1; k <= M; ++k) {//����
				cin >> graph[i][j][k];
				if (graph[i][j][k] == 0)
					cnt0++;
				else if (graph[i][j][k] == 1) {
					cnt1++;
					que.push({ { i,j }, { k,0 } });
					visited[i][j][k] = true;
				}
			}
		}
	}
	if (cnt0 == 0 || cnt1 == 0) {
		cout << "0" << '\n';
		return 0;
	}
	else {
		bfs();
		for (int i = 1; i <= H; ++i) {//����
			for (int j = 1; j <= N; ++j) {//����
				for (int k = 1; k <= M; ++k) {//����
					if (visited[i][j][k] == false && graph[i][j][k] == 0) {
						cntday = -1;
						break;
					}
				}
			}
		}
		cout << cntday << '\n';
	}
	return 0;
}
void bfs() {
	while (!que.empty()) {
		int z = que.front().first.first;//����
		int x = que.front().first.second;//����
		int y = que.front().second.first;//����
		cntday = que.front().second.second;
		que.pop();
		for (int i = 1; i <= 6; ++i) {//N: ����, M: ����, H: ����
			int newZ = z + vecZ[i];
			int newX = x + vecX[i];
			int newY = y + vecY[i];
			if (newZ > H || newZ < 1 || newX > N || newX < 1 || newY>M || newY < 1)
				continue;
			if (graph[newZ][newX][newY] == 0 && visited[newZ][newX][newY] == false) {
				visited[newZ][newX][newY] = true;
				que.push({ { newZ,newX }, { newY,cntday + 1 } });
			}
		}			
	}
}