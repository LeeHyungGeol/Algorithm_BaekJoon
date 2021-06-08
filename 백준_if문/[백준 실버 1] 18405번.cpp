// vector.erase(vec0.begin() + 2);      // 벡터의 특정 위치 데이터 삭제
// vector.insert(vec0.begin() + 2, 99); // 벡터의 특정 위치에 데이터 삽입

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N, K, S, X, Y, answer = 0;
int laboratory[201][201] = { 0, };
int visited[201][201] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<piii> virus;

void bfsForSeconds();
void bfs();

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> laboratory[i][j];
			if (laboratory[i][j] != 0) {
				virus.push_back({ laboratory[i][j], { i,j } });
			}
		}
	}

	sort(virus.begin(), virus.end());

	cin >> S >> X >> Y;

	bfsForSeconds();

	cout << laboratory[X - 1][Y - 1] << '\n';

	return 0;
}

void bfsForSeconds() {
	for (int s = 0; s < S; ++s) {
		bfs();
	}

	return;
}

void bfs() {
	vector<piii> temp;

	while (!virus.empty()) {
		int virusType = virus.front().first;
		int x = virus.front().second.first;
		int y = virus.front().second.second;

		visited[x][y] = true;

		virus.erase(virus.begin());

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					laboratory[nx][ny] = virusType;
					temp.push_back({ virusType, {nx, ny} });
				}
			}
		}
	}

	virus = temp;
	return;
}