#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

typedef struct Enemy {
	int x, y, dist;
}Node;
typedef pair<int, int> pii;

int N, M, D, Answer;
vector<vector<int>> Arr;
vector<vector<int>> TempArr;
vector<vector<bool>> Visited;
vector<pii> Archers;
vector<pii> Enemies;
vector<bool> Select;

void dfs(int startIndex, int cnt);
int playCastleDefense();
bool isFinish();
int shootEnemies();
void moveEnemies();
int getDist(int x, int y, int nx, int ny);
bool compare(const Enemy& a, const Enemy& b);

int main() {
	cin >> N >> M >> D;

	Arr.resize(N, vector<int>(M, 0));
	Select.resize(M, false);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> Arr[i][j];
		}
	}

	dfs(0, 0);
	
	cout << Answer << '\n';

	return 0;
}

void dfs(int startIndex, int cnt) {
	if (cnt == 3) {
		Archers.clear();
		for (int i = 0; i < Select.size(); ++i) {
			if (Select[i]) {
				Archers.push_back({ N,i });
			}
		}
		int result = playCastleDefense();
		Answer = max(Answer, result);
		return;
	}

	for (int i = startIndex; i < Select.size(); ++i) {
		if (Select[i]) continue;
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}

int playCastleDefense() {
	int result = 0;
	TempArr = Arr;

	while (true) {
		Enemies.clear();
		Visited.assign(N, vector<bool>(M, false));

		if (isFinish()) break;
		result += shootEnemies();
		moveEnemies();
	}

	return result;
}

bool isFinish() {
	bool flag = true;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (TempArr[i][j] == 1) {
				flag = false;
				Enemies.push_back({ i,j });
			}
		}
	}

	return flag;
}

int shootEnemies() {
	vector<pii> deads;
	int result = 0;

	for (pii archer : Archers) {
		int x = archer.first;
		int y = archer.second;
		vector<Enemy> candidates;

		for (pii enemy : Enemies) {
			int nx = enemy.first;
			int ny = enemy.second;
			int dist = getDist(x, y, nx, ny);

			if (dist <= D) {
				candidates.push_back({ nx,ny,dist });
			}
		}
		
		int size = candidates.size();

		if (size > 1) {
			sort(candidates.begin(), candidates.end(), compare);
			deads.push_back({ candidates.front().x, candidates.front().y });
		}
		else if (size == 1) {
			deads.push_back({ candidates.front().x, candidates.front().y });
		}
	}

	for (pii dead : deads) {
		int x = dead.first;
		int y = dead.second;

		if (!Visited[x][y]) {
			Visited[x][y] = true;
			TempArr[x][y] = 0;
			++result;
		}
	}

	return result;
}

void moveEnemies() {
	for (int i = Enemies.size() - 1; i >= 0; --i) {
		int x = Enemies[i].first;
		int y = Enemies[i].second;

		if (TempArr[x][y] == 0) continue;
		if (x == N - 1) TempArr[x][y] = 0;
		else {
			TempArr[x][y] = 0;
			TempArr[x + 1][y] = 1;
		}
	}
}

int getDist(int x, int y, int nx, int ny) {
	return abs(x - nx) + abs(y - ny);
}

bool compare(const Enemy& a, const Enemy& b) {
	if (a.dist == b.dist) {
		return a.y < b.y;
	}
	return a.dist < b.dist;
}