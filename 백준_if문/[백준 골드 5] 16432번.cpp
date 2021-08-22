// dfs문제

// 항상 범위에 주의하자!!
// 답을 찾은 경우에 flag 혹은 dfs함수의 반환형을 bool로 하여,
// 답이 아닌 경우에 대하여 처리를 잘하자.

#include <iostream>
#include <vector>

using namespace std;

int N;
bool Flag = false;
vector<int> Answer;
vector<vector<int>> Graph;
vector<vector<bool>> Visited;

void dfsAll();
void dfs(int index, int cur);

int main() {
	cin >> N;

	Answer.resize(N + 1, 0);
	Graph.resize(N+1, vector<int>(10, 0));
	Visited.resize(N+2, vector<bool>(10, false));

	for (int i = 0; i < N; ++i) {
		int size;
		cin >> size;

		for (int j = 0; j < size; ++j) {
			int num;
			cin >> num;
			Graph[i][num] = 1;
		}
	}

	dfsAll();
	
	if(!Flag) {
		cout << "-1" << '\n';
	}

	return 0;
}
void dfsAll() {
	for (int i = 1; i <= 9; ++i) {
		if (Graph[0][i] == 1 && !Flag) {
			Visited[0][i] = true;
			Answer.clear();
			dfs(0, i);
		}
	}
	return;
}

void dfs(int index, int cur) {
	if (Flag) {
		return;
	}
	if (index == N) {
		for (int i = 0; i < Answer.size(); ++i) {
			cout << Answer[i] << '\n';
		}
		Flag = true;
		return;
	}

	for (int next = 1; next <= 9; ++next) {
		if (cur != next && Graph[index][cur] == 1 && !Visited[index + 1][next]) {
			Visited[index + 1][next] = true;
			Answer.push_back(cur);
			dfs(index + 1, next);
			Answer.pop_back();
			
			if (Flag) {
				return;
			}
		}
	}
}