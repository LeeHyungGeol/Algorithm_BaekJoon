// DFS�� �̿��� Connected Components�� ���ϴ� ����
// ��, �ð��� ���� Connected Components�� ���ϴ� ������
// Connected Components�� 2�� �̻��� �Ǹ� �ٷ� ����� ����ϰ�,
// 2���� �迭�� ��� ��ΰ� 0�� �� ������ Connected Components�� 1�̶�� 0�� ���

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, result = 0, answer = 0;
int iceberg[301][301] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[301][301];
bool melted[301][301];

int getConnectedComponents();
void dfs(int x, int y);
void iceMeltPerYears();

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> iceberg[i][j];
		}
	}

	while (true) {
		memset(visited, false, sizeof(visited));
		memset(melted, false, sizeof(melted));
		result = getConnectedComponents();
		if (result == 1) {
			iceMeltPerYears();
			++answer;
			continue;
		}
		else if (result == 0) {
			answer = 0;
			break;
		}
		else {
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}

int getConnectedComponents() {
	int components = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			// ������ 0�� �ƴϰ�, �湮���� �ʾ��� ��
			// Connected Components �� ����Ѵ�.
			if (iceberg[i][j] != 0 && !visited[i][j]) {
				dfs(i, j);
				++components;
			}
		}
	}

	return components;
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// ��� ���ǰ� �湮 ������ ���� ����!
		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (iceberg[nx][ny] != 0 && !visited[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
}

// ������ 0�� ������ ã�ƴٴϸ鼭 0�̶��
// �� ������ ������������ ������ -1��ŭ ���δ�.
// ��, ������ ����϶��� ���δ�. �ƴϸ� ������ �� ���� �ֱ� ������
// ���� for���� ���鼭 ���ϸ� ���� ���̱� ������, 
// ������ ��Ƽ� 0�� �Ǹ�, 
// ����ؼ� ���� �ݺ����� ���ϸ� ���� �� �ֱ� ������
// melted 2���� �迭�� ����Ͽ� �ѹ� ��Ҵ��� �ȳ�Ҵ��� Ȯ���Ѵ�.
void iceMeltPerYears() {

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			if (iceberg[x][y] == 0 && !melted[x][y]) {
				for (int i = 0; i < 4; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (0 <= nx && nx < N && 0 <= ny && ny < M) {
						if (iceberg[nx][ny] > 0) {
							melted[nx][ny] = true;
							--iceberg[nx][ny];
						}
					}
				}
			}
		}
	}

	return;
}