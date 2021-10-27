#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef struct Fish {
	int x, y, time;

	bool operator < (const Fish& other) const {
		if (time == other.time) {
			if (x == other.x) {
				return y < other.y;
			}
			return x < other.x;
		}
		return time < other.time;
	}
}Fish;
typedef struct Shark {
	int x, y, size, count;
}Shark;

int N, Answer;
const int Dx[] = { -1,1,0,0 };
const int Dy[] = { 0,0,-1,1 };
vector<vector<int>> Arr;
vector<Fish> Fishes;
Shark babyShark;

void bfs(int x, int y);

int main() {
	cin >> N;

	Arr.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Arr[i][j];
			if (Arr[i][j] == 9) {
				babyShark = { i,j,2,0 };
				Arr[i][j] = 0;
			}
		}
	}

	while (true) {
		bfs(babyShark.x, babyShark.y);

		if (Fishes.empty()) break;
		else {
			sort(Fishes.begin(), Fishes.end());
			Fish f = Fishes.front();

			++babyShark.count;
			Answer += f.time;
			Arr[f.x][f.y] = 0;
			babyShark.x = f.x;
			babyShark.y = f.y;

			if (babyShark.count == babyShark.size) {
				++babyShark.size;
				babyShark.count = 0;
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}

void bfs(int x, int y) {
	queue<pii> q;
	vector<vector<int>> Visited(N, vector<int>(N, 0));
	int distance = INT_MAX;
	Fishes.clear();

	q.push({ x,y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + Dx[i];
			int ny = cy + Dy[i];

			if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) continue;
			if (Visited[nx][ny]) continue;
			if (Arr[nx][ny] > babyShark.size) continue;
			Visited[nx][ny] = Visited[cx][cy] + 1;
			if (0 < Arr[nx][ny] && Arr[nx][ny] < babyShark.size && distance >= Visited[nx][ny]) {
				distance = Visited[nx][ny];
				Fishes.push_back({ nx,ny,Visited[nx][ny] });
			}
			q.push({ nx,ny });
		}
	}
}
