// BFS�� �ִܰŸ� Ž������
// �ٸ�, ���̷��� ���� N�� �� M���� �����Ͽ�(nCm) ������ �Ͽ�,
// �ּ� �ð����� ���̷����� ��Ʈ���� ������ ���ؾ� �Ѵ�.
// Ȱ��ȭ�� ���̷����� ��Ȱ��ȭ�� ���̷����� �ִ� ������ ���� Ȱ��ȭ ��Ű�� ����, ���̷����� �۶߸� �ð����� ������� �ʴ´�.

// ���� �ð��� ����ϴ� 2���� �迭�� ������ �Ѵ�. ó���� �Է� ���� 2���� �迭�� �ذ��Ϸ��ٰ� �ð��� ���� �ɷȴ�.
// ���������� [���� �ǹ� 1] 7569�� �丶�� ������ ����� ������� �����Ѵ�.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAX 1e9

using namespace std;

typedef pair<int, int> pii;

int N, M, answer = MAX, emptyPlace = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int laboratory[51][51] = { 0, };
int visited[51][51] = { 0, };
vector<bool> Select;
vector<pii> virus;
queue<pii> selectedVirus;

void dfs(int startIndex, int cnt);
void bfs();

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> laboratory[i][j];
			if (laboratory[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (laboratory[i][j] == 0) {
				++emptyPlace;
			}
		}
	}

	Select.resize(virus.size());

	dfs(0, 0);

	if (answer == MAX) {
		cout << "-1" << '\n';
	}
	else {
		cout << answer << '\n';
	}

	return 0;
}

// DFS�� ���� ����
void dfs(int startIndex, int cnt) {
	// �ϳ��� ������ �ϼ��Ǿ��� ��
	if (cnt == M) {
		// bfs() �ϱ� ���� �迭 �ʱ�ȭ
		memset(visited, -1, sizeof(visited));

		for (int i = 0; i < virus.size(); ++i) {
			// ���õ� ���̷����鸸 ����
			if (Select[i]) {
				int x = virus[i].first;
				int y = virus[i].second;
				// Queue�� �ִ´�.
				selectedVirus.push(virus[i]);
				// ���õ�, Ȱ�����̷����� 
				// �湮�ߴٰ� ǥ��
				visited[x][y] = 0;
			}
		}

		// BFS ���� ����
		bfs();

		return;
	}

	for (int i = startIndex; i < virus.size(); ++i) {
		if (Select[i] == true) {
			continue;
		}
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}

void bfs() {

	while (!selectedVirus.empty()) {
		int x = selectedVirus.front().first;
		int y = selectedVirus.front().second;

		selectedVirus.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// ���簢�� ���� ���� �ְ�, ���� �ƴϸ�, ���� �湮���� ���� ����
			if (0 <= nx && nx < N && 0 <= ny && ny < N && laboratory[nx][ny] != 1 && visited[nx][ny] == -1) {
				visited[nx][ny] = visited[x][y] + 1;
				selectedVirus.push({ nx, ny });
			}
		}
	}

	int totalTime = 0;
	bool flag = true;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			// ��ĭ�̾��� ���� �߿���
			if (laboratory[i][j] == 0) {
				// ���� �湮���� ���� ���� �ִٸ� ���̷��� ���� ������ ��
				if (visited[i][j] == -1) {
					flag = false;
					break;
				}
				else {
					totalTime = max(totalTime, visited[i][j]);
				}
			}
		}
	}

	if (flag) {
		answer = min(answer, totalTime);
	}
}

void bfs2() {
	int infectedPlace = 0, totalTime = 0;

	while (!selectedVirus.empty()) {
		int x = selectedVirus.front().first;
		int y = selectedVirus.front().second;

		selectedVirus.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// ���簢�� ���� �ȿ� �ְ�, ���� �ƴϰ�, �������� ���� ����
			if (0 <= nx && nx < N && 0 <= ny && ny < N && laboratory[nx][ny] != 1 && visited[nx][ny] == -1) {
				visited[nx][ny] = visited[x][y] + 1;
				if (laboratory[nx][ny] == 0) {
					totalTime = max(totalTime, visited[nx][ny]);
					++infectedPlace;
				}
				selectedVirus.push({ nx,ny });
			}
		}
	}

	if (emptyPlace == infectedPlace) {
		answer = min(answer, totalTime);
	}
}
