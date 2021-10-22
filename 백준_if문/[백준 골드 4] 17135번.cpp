#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

typedef struct Node {
	int x, y;
}Node;

int N, M, D, Answer;
vector<vector<int>> Arr;
vector<Node> Archers;
vector<bool> Select;

void dfs(int startIndex, int cnt);
void playCastleDefense();

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
	
	return 0;
}

void dfs(int startIndex, int cnt) {
	if (cnt == 3) {
		Archers.clear();
		for (int i = 0; i < Select.size(); ++i) {
			if (Select[i]) {
				Archers.push_back({ N + 1,i });
			}
		}
		playCastleDefense();
		return;
	}

	for (int i = startIndex; i < Select.size(); ++i) {
		if (Select[i]) continue;
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}

void playCastleDefense() {
	while (true) {
		
	}
}