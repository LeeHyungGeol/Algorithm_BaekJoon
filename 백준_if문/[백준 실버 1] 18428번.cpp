// DFS/BFS, 조합 문제
// 연구소 문제 시리즈와 비슷하다. 빈칸 중에서 3개를 고르는 nC3 을 수행한 후,
// 선생님('T')를 기준으로 상, 하, 좌, 우 를 돌아다니면서, 장애물('O') 가 있으면 건너 뛰고, 학생('S') 가 있는지 찾는다.
// 만약 학생을 못 찾았으면 감시 피하기 성공이므로, flag = true 
// 학생을 찾았다면 감시 피하기 실패이므로 그곳에서 바로 return 을 해주는 것이 좋다.

// 원하는 경우가 감시를 피하는 경우(학생 찾기 실패 하거나 장애물이 있는 경우) 이므로 
// 조합을 돌리는 DFS 함수에서 원하는 경우가 나왔을 때 if 문으로 boolean 값을 잘 설정해주는 것이 중요하다.

// 또한 상, 하, 좌, 우 를 한칸씩 이동하는 경우가 아니라, 방향을 보는 전체를 탐색해야 하기 때문에,
// 이전 문제들 보다 더 신박했다.
// 방향을 보는 전체를 탐색해야 할 때, 어떻게 처리해주는지 생각하고 배울 수 있는 문제.

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

		// check 했는데 학생이 없었으므로, 감시 피하기 성공한 경우
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
			// 학생이 있으면 감시 피하기 실패 이므로 바로 return
			if (isStudent(x, y, i)) {
				return true;
			}
		}
	}

	// 학생이 없다면 감시 피하기 성공!
	return false;
}

bool isStudent(int x, int y, int direction) {
	// 상
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

	// 하
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

	// 좌
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

	// 우
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