// DFS, 시뮬레이션 문제
// 하루마다 인접한 두 노드의 인구 차이가 L명 이상, R명 이하일 때,
// DFS를 실행하여 Connected Components를 구한다.
// 이것을 기준에 맞지 않을 때까지 카운트 하며 수행한 후, 카운트 된 답을 출력한다.

// 진짜 뻘 짓으로 시간을 많이 날렸다. 
// 함부로 contunue 를 쓰지 말자. if문 안에 continue를 쓸 때는 로직 흐름을 다시 한번 생각해보자!!!
// if문 안에 continue를 쓰는 것 때문에, connected components 에 대한 vector 를 clear() 제대로 수행시키지 못해서 계속 오류가 발생하였다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, L, R, answer = 0;
int land[50][50] = { 0, };
bool visited[50][50];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<pii> cooperations;

void dfsAll();
void dfs(int x, int y);
void populationMovement();

int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> land[i][j];
		}
	}

	dfsAll();

	cout << answer << '\n';

	return 0;
}

void dfsAll() {
	bool flag = true;
	
	while (flag) {
		cooperations.clear();

		for (int i = 0; i < N; ++i) {
			fill(visited[i], visited[i] + N, false);
		}

		flag = false;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!visited[i][j]) {
					cooperations.push_back({ i,j });
					
					dfs(i, j);
			
					if (cooperations.size() != 1) {
						populationMovement();
						flag = true;
					}
				}
				cooperations.clear();
			}
		}

		if (flag) {
			++answer;
		}
	}

	return;
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!visited[nx][ny] && 0 <= nx && nx < N && 0 <= ny && ny < N) {
			int diff = abs(land[x][y] - land[nx][ny]);
			
			if (L <= diff && diff <= R) {
				cooperations.push_back({ nx, ny });
				dfs(nx, ny);
			}
		}
	}

	return;
}

void populationMovement() {
	int sum = 0;
	
	for (int i = 0; i < cooperations.size(); ++i) {
		int x = cooperations[i].first;
		int y = cooperations[i].second;

		sum += land[x][y];
	}
	
	int avg = sum / cooperations.size();

	for (int i = 0; i < cooperations.size(); ++i) {
		int x = cooperations[i].first;
		int y = cooperations[i].second;

		land[x][y] = avg;
	}

	return;
}