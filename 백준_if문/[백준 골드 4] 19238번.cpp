#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
#include <deque>

using namespace std;

typedef pair<int, int> pii;
typedef struct Node {
	int sx, sy, ex, ey, startDist;

	bool operator < (const Node& other) const {
		if (startDist == other.startDist) {
			if (sx == other.sx) {
				return sy < other.sy;
			}
			return sx < other.sx;
		}
		return startDist < other.startDist;
	}
}Node;

int N, M, Fuel;
pii Taxi;
int Arr[22][22];
int Dist[22][22];
bool Visited[22][22];
const int Dx[] = { -1,1,0,0 };
const int Dy[] = { 0,0,-1,1 };
deque<Node> Customers;

void bfsAll(int x, int y);
int bfs(Node start);

int main() {
	cin >> N >> M >> Fuel;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> Arr[i][j];
			if (Arr[i][j] == 1) Arr[i][j] = -1;
		}
	}

	int x, y;
	cin >> x >> y;
	Taxi = { x,y };

	for (int i = 1; i <= M; ++i) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		Customers.push_back({ sx,sy,ex,ey,0 });
		Arr[sx][sy] = i;
	}

	while (!Customers.empty()) {
		bfsAll(Taxi.first, Taxi.second); // 거리들 찾기
		
		sort(Customers.begin(), Customers.end());
		
		Node shortest = Customers.front();
		int endDistance = bfs(shortest);
		
		Fuel -= shortest.startDist;

		if (shortest.startDist < 0) {
			Fuel = -1;
			break;
		}

		if (Fuel < 0) {
			Fuel = -1;
			break;
		}

		Fuel -= endDistance;

		if (endDistance == 0) {
			Fuel = -1;
			break;
		}

		if (Fuel < 0) {
			Fuel = -1;
			break;
		}

		// 성공할 시에
		Customers.pop_front();
		Arr[shortest.sx][shortest.sy] = 0;
		Taxi = { shortest.ex, shortest.ey };
		Fuel += 2 * endDistance;
	}

	cout << Fuel << '\n';

	return 0;
}

void bfsAll(int x, int y) {
	queue<pii> q;
	memset(Visited, false, sizeof(Visited));
	memset(Dist, -1, sizeof(Dist));

	q.push({ x,y });
	Visited[x][y] = true;
	Dist[x][y] = 0;
	int cnt = 0;

	if (Arr[x][y] >= 1) {
		++cnt;
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (cnt == Customers.size()) {
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = cx + Dx[i];
			int ny = cy + Dy[i];

			if (!(1 <= nx && nx <= N && 1 <= ny && ny <= N)) continue;
			if (Visited[nx][ny]) continue;
			if (Arr[nx][ny] == -1) continue;
			Dist[nx][ny] = Dist[cx][cy] + 1;
			Visited[nx][ny] = true;
			if (Arr[nx][ny] >= 1) ++cnt;
			q.push({ nx,ny });
		}
	}

	for (int i = 0; i < Customers.size(); ++i) {
		Customers[i].startDist = Dist[Customers[i].sx][Customers[i].sy];
	}
}

int bfs(Node start) {
	queue<pii> q;
	memset(Visited, false, sizeof(Visited));
	memset(Dist, 0, sizeof(Dist));

	int result = 0;
	Visited[start.sx][start.sy] = true;
	q.push({ start.sx, start.sy });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == start.ex && y == start.ey) {
			result = Dist[x][y];
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = x + Dx[i];
			int ny = y + Dy[i];

			if (!(1 <= nx && nx <= N && 1 <= ny && ny <= N)) continue;
			if (Visited[nx][ny]) continue;
			if (Arr[nx][ny] == -1) continue;
			Dist[nx][ny] = Dist[x][y] + 1;
			Visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	return result;
}