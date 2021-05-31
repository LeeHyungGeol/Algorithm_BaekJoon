// dfs, dp ����
// dp 2���� �迭�� �Ź� ���� �����ϸ鼭 ���� �볪�� ���� �̹� �볪�� ������ Ŭ �� ���� �����Ѵ�.
// dp[x][y] = n : �Ǵٰ� x,y �� ���� �� �ִ�� �� �� �ִ� ���� n �� �ǹ��Ѵ�.

// [���� ��� 4] 1520�� ������ �� ������ ����ϴ�.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<int> bambooForest[501];
int dp[501][501] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int dfsAll();
int dfs(int x, int y);

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int temp;
			cin >> temp;
			bambooForest[i].push_back(temp);
			dp[i][j] = 1;
		}
	}

	int answer = dfsAll();

	cout << answer << '\n';

	return 0;
}

int dfsAll() {
	int answer = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			answer = max(answer, dfs(i, j));
		}
	}
	
	return answer;
}

int dfs(int x, int y) {
	if (dp[x][y] != 1) {
		return dp[x][y];
	}

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			if (bambooForest[x][y] < bambooForest[nx][ny]) {
				dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
			}
		}
	}

	return dp[x][y];
}