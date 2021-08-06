// 최단경로(다익스트라) 문제

// 가중치를 빈칸(.), 쓰레기 칸(g), 쓰레기 근처 칸에 따라서 단순히 1,2,3으로 두었다가 틀렸다.
// 극단적으로 보았을 때, 쓰레기 근처 칸을 N*N 번 지나는 것 보다 쓰레기 1 칸을 지나는 것을 더 싫어하기 때문에, 쓰레기 칸의 가중치를 훨씬 더 크게 잡아주어야 한다.
// 따라서 빈칸(.) = 0, 쓰레기 옆 칸 = 1, 쓰레기 칸(g) = 큰 차이가 날 정도로 큰 값으로 설정해주고, 다익스트라 알고리즘으로 최단 거리를 구해주었다

// 초반에 쓰레기 근처의 4칸을 처리해주는 것을 입력받을 때 처리해주었다가, 계속 2% 에서 틀렸다.
// 초기 입력 받을 때의 설정에서 '중복 처리' 되는 것에 대한 생각을 잘해서 처리해주자!!

#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9
// N*N 의 최댓값 보다 크면 된다.
#define Garbage 2500

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N, M, X, Y, FX, FY;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<int>> Graph;
vector<vector<int>> Dist;
vector<vector<char>> Input;

void dijkstra(int x, int y);

int main() {
	cin >> N >> M;

	Graph.resize(N, vector<int>(M, 0));
	Dist.resize(N, vector<int>(M, INF));
	Input.resize(N, vector<char>(M, ' '));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> Input[i][j];

			if (Input[i][j] == 'g') {
				Graph[i][j] = Garbage;
			}
			else if (Input[i][j] == 'F') {
				FX = i;
				FY = j;
			}
			else if (Input[i][j] == 'S') {
				X = i;
				Y = j;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (Graph[i][j] == Garbage) {
				for (int k = 0; k < 4; ++k) {
					int xx = i + dx[k];
					int yy = j + dy[k];
					
					if (0 <= xx && xx < N && 0 <= yy && yy < M && Graph[xx][yy] == 0) {
						Graph[xx][yy] = 1;
					}
				}
			}
		}
	}

	Graph[X][Y] = Graph[FX][FY] = 0;

	dijkstra(X, Y);

	cout << Dist[FX][FY] / Garbage << ' ' << Dist[FX][FY] % Garbage << '\n';

	return 0;
}

void dijkstra(int x, int y) {
	priority_queue<piii> pq;

	pq.push({ 0, {x,y} });
	Dist[x][y] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		pq.pop();

		if (cx == FX && cy == FY) {
			break;
		}

		if (Dist[cx][cy] < cost) {
			continue;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				int nextDist = cost + Graph[nx][ny];

				if (Dist[nx][ny] > nextDist) {
					Dist[nx][ny] = nextDist;
					pq.push({ -nextDist, {nx, ny} });
				}
			}
		}
	}

	return;
}