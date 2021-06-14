// DFS, �ùķ��̼� ����
// �Ϸ縶�� ������ �� ����� �α� ���̰� L�� �̻�, R�� ������ ��,
// DFS�� �����Ͽ� Connected Components�� ���Ѵ�.
// �̰��� ���ؿ� ���� ���� ������ ī��Ʈ �ϸ� ������ ��, ī��Ʈ �� ���� ����Ѵ�.

// ��¥ �� ������ �ð��� ���� ���ȴ�. 
// �Ժη� contunue �� ���� ����. if�� �ȿ� continue�� �� ���� ���� �帧�� �ٽ� �ѹ� �����غ���!!!
// if�� �ȿ� continue�� ���� �� ������, connected components �� ���� vector �� clear() ����� �����Ű�� ���ؼ� ��� ������ �߻��Ͽ���.

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