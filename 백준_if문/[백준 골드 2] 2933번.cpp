// 구현, bfs 문제

// 문제를 이해하는 것과 구현하는 부분 모두 힘들었던 문제
// 막대기 던지는 것을 왼쪽에서 오른쪽, 오른쪽에서 왼쪽을 번갈아가면서 하는데
// 이것을 for문의 변수(int i = 0;)을 이용하면 쉽게 구현할 수 있다.(if(i % 2 == 0))

// bfs를 이용하여 막대기를 던진 후 땅에 붙어 있는(x == R - 1) 미네랄을 Visited 배열에 type 1로 저장하고,
// 그 다음에 막대기에 부러지고 남은 공중에 떠있는 미네랄을 똑같이 bfs로 탐색하며 이번엔 type 2로 저장한다.

// 공중에 떠있는 미네랄을 for문(for(int i = 0; i < Cluster.size(); ++i))을 돌며, 한칸, 한칸씩 내려보낸다.
// 이때, nx, ny가 범위를 벗어나거면 땅에 닫은 경우이고, Visited[x][y] == 1이면 땅에 붙어있는 미네랄에 닫은 경우이기 때문에 
// Graph[x][y]를 'x'로 바꿔준 후 return한다.

// 참고 : https://conkjh032.tistory.com/307

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> pii;

int R, C, N;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<int> Throws;
vector<vector<char>> Graph;
vector<vector<int>> Visited;
vector<pii> Cluster;

void moveMineral();
void bfs(int x, int y, int type);

int main() {
	cin >> R >> C;

	Graph.resize(R, vector<char>(C, ' '));

	for (int i = 0; i < R; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); ++j) {
			Graph[i][j] = str[j];
		}
	}

	cin >> N;

	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		Throws.push_back(x);
	}

	for (int i = 0; i < Throws.size(); ++i) {
		int x = R - Throws[i];

		// 짝수, 왼쪽->오른쪽
		if (i % 2 == 0) {
			for (int y = 0; y < C; ++y) {
				if (Graph[x][y] == 'x') {
					Graph[x][y] = '.';
					break;
				}
			}
		}
		// 홀수, 오른쪽->왼쪽
		else if (i % 2 != 0) {
			for (int y = C - 1; y >= 0; --y) {
				if (Graph[x][y] == 'x') {
					Graph[x][y] = '.';
					break;
				}
			}
		}
		moveMineral();
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << Graph[i][j];
		}
		cout << '\n';
	}

	return 0;
}

void moveMineral() {
	Visited.assign(R, vector<int>(C, 0));

	for (int y = 0; y < C; ++y) {
		if (Graph[R - 1][y] == 'x' && !Visited[R - 1][y]) {
			bfs(R - 1, y, 1);
		}
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (Graph[i][j] == 'x' && Visited[i][j] == 0) {
				bfs(i, j, 2);
				break;
			}
		}
	}

	while (true) {
		if (Cluster.size() == 0) {
			break;
		}

		vector<pii> temp;

		for (int i = 0; i < Cluster.size(); ++i) {
			int nx = Cluster[i].first + 1;
			int ny = Cluster[i].second;

			if (!(0 <= nx && nx < R && 0 <= ny && ny < C) || Visited[nx][ny] == 1) {
				for (int j = 0; j < Cluster.size(); ++j) {
					Graph[Cluster[j].first][Cluster[j].second] = 'x';
				}
				return;
			}

			temp.push_back({ nx, ny });
		}

		Cluster = temp;
	}

	return;
}

void bfs(int x, int y, int type) {
	Cluster.clear();

	queue<pii> q;

	q.push({ x,y });
	Visited[x][y] = type;

	if (type == 2) {
		Graph[x][y] = '.';
		Cluster.push_back({ x, y });
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (0 <= nx && nx < R && 0 <= ny && ny < C) {
				if (Visited[nx][ny] == 0 && Graph[nx][ny] == 'x') {
					if (type == 2) {
						Cluster.push_back({ nx, ny });
						Graph[nx][ny] = '.';
					}
					Visited[nx][ny] = type;
					q.push({ nx, ny });
				}
			}
		}
	}

	return;
}