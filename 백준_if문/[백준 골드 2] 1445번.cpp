// �ִܰ��(���ͽ�Ʈ��) ����

// ����ġ�� ��ĭ(.), ������ ĭ(g), ������ ��ó ĭ�� ���� �ܼ��� 1,2,3���� �ξ��ٰ� Ʋ�ȴ�.
// �ش������� ������ ��, ������ ��ó ĭ�� N*N �� ������ �� ���� ������ 1 ĭ�� ������ ���� �� �Ⱦ��ϱ� ������, ������ ĭ�� ����ġ�� �ξ� �� ũ�� ����־�� �Ѵ�.
// ���� ��ĭ(.) = 0, ������ �� ĭ = 1, ������ ĭ(g) = ū ���̰� �� ������ ū ������ �������ְ�, ���ͽ�Ʈ�� �˰������� �ִ� �Ÿ��� �����־���

// �ʹݿ� ������ ��ó�� 4ĭ�� ó�����ִ� ���� �Է¹��� �� ó�����־��ٰ�, ��� 2% ���� Ʋ�ȴ�.
// �ʱ� �Է� ���� ���� �������� '�ߺ� ó��' �Ǵ� �Ϳ� ���� ������ ���ؼ� ó��������!!

#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9
// N*N �� �ִ� ���� ũ�� �ȴ�.
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