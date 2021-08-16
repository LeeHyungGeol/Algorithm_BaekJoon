// ����, bfs ����

// ������ �����ϴ� �Ͱ� �����ϴ� �κ� ��� ������� ����
// ����� ������ ���� ���ʿ��� ������, �����ʿ��� ������ �����ư��鼭 �ϴµ�
// �̰��� for���� ����(int i = 0;)�� �̿��ϸ� ���� ������ �� �ִ�.(if(i % 2 == 0))

// bfs�� �̿��Ͽ� ����⸦ ���� �� ���� �پ� �ִ�(x == R - 1) �̳׶��� Visited �迭�� type 1�� �����ϰ�,
// �� ������ ����⿡ �η����� ���� ���߿� ���ִ� �̳׶��� �Ȱ��� bfs�� Ž���ϸ� �̹��� type 2�� �����Ѵ�.

// ���߿� ���ִ� �̳׶��� for��(for(int i = 0; i < Cluster.size(); ++i))�� ����, ��ĭ, ��ĭ�� ����������.
// �̶�, nx, ny�� ������ ����Ÿ� ���� ���� ����̰�, Visited[x][y] == 1�̸� ���� �پ��ִ� �̳׶��� ���� ����̱� ������ 
// Graph[x][y]�� 'x'�� �ٲ��� �� return�Ѵ�.

// ���� : https://conkjh032.tistory.com/307

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

		// ¦��, ����->������
		if (i % 2 == 0) {
			for (int y = 0; y < C; ++y) {
				if (Graph[x][y] == 'x') {
					Graph[x][y] = '.';
					break;
				}
			}
		}
		// Ȧ��, ������->����
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