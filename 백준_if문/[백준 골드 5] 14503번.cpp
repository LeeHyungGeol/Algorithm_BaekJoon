// 구현, 시물레이션 문제
// 이코테_게임 개발 문제와 똑같다. 
// 1. 북, 동, 남, 서 의 4가지 방향, 2. 방향을 그대로 보면서 한칸 후퇴하는 방법, 
// 3. 벽인지 빈칸인지, 4. 청소했는지 안했는지(방문했는지 안했는지)
// 이러한 사항들을 구현해낼 수 있는지 물어보는 문제

// 나중에 꼭 다시 한번 풀어볼 것!!

#include <iostream>
#include <vector>

using namespace std;

int N, M, x, y, direction, cnt, answer;
// 북, 동, 남, 서
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<vector<int>> graph;
vector<vector<bool>> visited;

void turnLeft();

int main() {
	cin >> N >> M;

	cin >> x >> y >> direction;

	graph.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> graph[i][j];
		}
	}

	visited[x][y] = true;
	++answer;

	while (true) {
		turnLeft();

		int nx = x + dx[direction];
		int ny = y + dy[direction];
		
		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (!visited[nx][ny] && graph[nx][ny] != 1) {
				visited[nx][ny] = true;
				x = nx;
				y = ny;
				cnt = 0;
				++answer;
				continue;
			}
			else if(graph[nx][ny] == 1) {
				++cnt;
			}
			else if (visited[nx][ny]) {
				++cnt;
			}
		}

		if (cnt == 4) {
			nx = x - dx[direction];
			ny = y - dy[direction];

			if (graph[nx][ny] == 0) {
				x = nx;
				y = ny;
			}
			else {
				break;
			}

			cnt = 0;
		}
	}

	cout << answer << '\n';

	return 0;
}

void turnLeft() {
	--direction;

	if (direction == -1) {
		direction = 3;
	}

	return;
}