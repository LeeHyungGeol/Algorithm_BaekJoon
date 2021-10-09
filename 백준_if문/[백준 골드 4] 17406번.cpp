#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, K, Answer = INT_MAX;
// µ¿, ³², ¼­, ºÏ
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
vector<bool> Select;
vector<vector<int>> Arr, ArrTemp;
vector<vector<int>> Query;

void dfs(int cnt, vector<int>& order);
void rotate(int q);
int turn(int startX, int startY, int endX, int endY, int x, int y, int dir);
void print();

int main() {
	cin >> N >> M >> K;

	Arr.resize(N + 1, vector<int>(M + 1, 0));
	Select.resize(K, false);
	Query.resize(K, vector<int>(3, 0));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> Arr[i][j];
		}
	}

	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> Query[i][j];
		}
	}

	vector<int> order;

	dfs(0, order);

	cout << Answer << '\n';

	return 0;
}

void dfs(int cnt, vector<int>& order) {
	if (cnt == K) {
		ArrTemp = Arr;
		for (int queryIndex : order) {
			rotate(queryIndex);
		}
		for (int i = 1; i <= N; ++i) {
			int sum = 0;
			for (int j = 1; j <= M; ++j) {
				sum += ArrTemp[i][j];
			}
			Answer = min(Answer, sum);
		}
		return;
	}

	for (int i = 0; i < K; ++i) {
		if (Select[i]) {
			continue;
		}
		order.push_back(i);
		Select[i] = true;
		dfs(cnt + 1, order);
		Select[i] = false;
		order.pop_back();
	}
}

void rotate(int q) {
	int x = 0, y = 0, dir = 0, swapTemp = 0;
	int startX = Query[q][0]-Query[q][2], startY = Query[q][1] - Query[q][2], endX = Query[q][0] + Query[q][2], endY = Query[q][1] + Query[q][2];
	int count = (abs(endX - startX) + 1) / 2;

	while (count--) {
		swapTemp = ArrTemp[startX][startY];
		x = startX, y = startY, dir = 0;

		while (true) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			int temp = ArrTemp[nx][ny];
			swap(swapTemp, ArrTemp[nx][ny]);
			swapTemp = temp;

			x = nx;
			y = ny;

			dir = turn(startX, startY, endX, endY, x, y, dir);

			if (x == startX && y == startY) {
				break;
			}
		}
		++startX;
		++startY;
		--endX;
		--endY;
	}
	return;
}

int turn(int startX, int startY, int endX, int endY, int x, int y, int dir) {
	if (x == startX && y == endY) {
		dir = 1;
	}
	else if (x == endX && y == endY) {
		return 2;
	}
	else if (x == endX && y == startY) {
		return 3;
	}
	return dir;
}

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << ArrTemp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}