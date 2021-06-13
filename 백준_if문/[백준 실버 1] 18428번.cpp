// DFS/BFS, ���� ����
// ������ ���� �ø���� ����ϴ�. ��ĭ �߿��� 3���� ���� nC3 �� ������ ��,
// ������('T')�� �������� ��, ��, ��, �� �� ���ƴٴϸ鼭, ��ֹ�('O') �� ������ �ǳ� �ٰ�, �л�('S') �� �ִ��� ã�´�.
// ���� �л��� �� ã������ ���� ���ϱ� �����̹Ƿ�, flag = true 
// �л��� ã�Ҵٸ� ���� ���ϱ� �����̹Ƿ� �װ����� �ٷ� return �� ���ִ� ���� ����.

// ���ϴ� ��찡 ���ø� ���ϴ� ���(�л� ã�� ���� �ϰų� ��ֹ��� �ִ� ���) �̹Ƿ� 
// ������ ������ DFS �Լ����� ���ϴ� ��찡 ������ �� if ������ boolean ���� �� �������ִ� ���� �߿��ϴ�.

// ���� ��, ��, ��, �� �� ��ĭ�� �̵��ϴ� ��찡 �ƴ϶�, ������ ���� ��ü�� Ž���ؾ� �ϱ� ������,
// ���� ������ ���� �� �Ź��ߴ�.
// ������ ���� ��ü�� Ž���ؾ� �� ��, ��� ó�����ִ��� �����ϰ� ��� �� �ִ� ����.

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N;
char hallway[6][6];
char temp[6][6];
bool flag;
vector<bool> Select;
vector<pii> spaces;
vector<pii> teachers;

void dfs(int startIndex, int cnt);
bool check();
bool isStudent(int x, int y, int direction);

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> hallway[i][j];
			if (hallway[i][j] == 'X') {
				spaces.push_back({ i, j });
			}
			else if (hallway[i][j] == 'T') {
				teachers.push_back({ i, j });
			}
		}
	}

	Select.resize(spaces.size());

	dfs(0, 0);

	if (flag) {
		cout << "YES" << '\n';
	}
	else {
		cout << "NO" << '\n';
	}

	return 0;
}

void dfs(int startIndex, int cnt) {
	if (cnt == 3) {

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				temp[i][j] = hallway[i][j];
			}
		}

		for (int i = 0; i < spaces.size(); ++i) {
			if (Select[i]) {
				int x = spaces[i].first;
				int y = spaces[i].second;
				temp[x][y] = 'O';
			}
		}

		// check �ߴµ� �л��� �������Ƿ�, ���� ���ϱ� ������ ���
		if (!check()) {
			flag = true;
		}

		return;
	}

	for (int i = startIndex; i < spaces.size(); ++i) {
		if (Select[i]) {
			continue;
		}
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}

bool check() {
	for (int i = 0; i < teachers.size(); ++i) {
		int x = teachers[i].first;
		int y = teachers[i].second;

		for (int i = 0; i < 4; ++i) {
			// �л��� ������ ���� ���ϱ� ���� �̹Ƿ� �ٷ� return
			if (isStudent(x, y, i)) {
				return true;
			}
		}
	}

	// �л��� ���ٸ� ���� ���ϱ� ����!
	return false;
}

bool isStudent(int x, int y, int direction) {
	// ��
	if (direction == 0) {
		for (int i = x; i >= 0; --i) {
			if (temp[i][y] == 'S') {
				return true;
			}
			if (temp[i][y] == 'O') {
				return false;
			}
		}

		return false;
	}

	// ��
	if (direction == 1) {
		for (int i = x; i < N; ++i) {
			if (temp[i][y] == 'S') {
				return true;
			}
			if (temp[i][y] == 'O') {
				return false;
			}
		}

		return false;
	}

	// ��
	if (direction == 2) {
		for (int i = y; i >= 0; --i) {
			if (temp[x][i] == 'S') {
				return true;
			}
			if (temp[x][i] == 'O') {
				return false;
			}
		}

		return false;
	}

	// ��
	if (direction == 3) {
		for (int i = y; i < N; ++i) {
			if (temp[x][i] == 'S') {
				return true;
			}
			if (temp[x][i] == 'O') {
				return false;
			}
		}

		return false;
	}
}