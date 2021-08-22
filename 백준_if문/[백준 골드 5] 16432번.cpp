#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> Answer;
vector<vector<int>> Graph;
vector<vector<bool>> Visited;

void dfsAll();
void dfs(int index, int cur);

int main() {
	cin >> N;

	Graph.resize(N);
	Visited.resize(N, vector<bool>(10, false));

	for (int i = 0; i < N; ++i) {
		int size;
		cin >> size;
		for (int j = 0; j < size; ++j) {
			int num;
			cin >> num;
			Graph[i].push_back(num);
		}
	}

	dfsAll();

	if ((int)Answer.size() < N) {
		cout << "-1" << '\n';
		return 0;
	}

	for (int i = 0; i < Answer.size(); ++i) {
		cout << Answer[i] << '\n';
	}

	return 0;
}

void dfsAll() {
	for (int i = 0; i < Graph[0].size(); ++i) {
		int start = Graph[0][i];

		if (!Visited[0][start]) {
			Answer.clear();

			dfs(0, start);
			
			if (Answer.size() == N) {
				break;
			}
		}
	}
	return;
}

void dfs(int index, int cur) {
	if (index == N) {
		return;
	}

	Answer.push_back(cur);

	if ((int)Answer.size() == N) {
		return;
	}

	Visited[index][cur] = true;
	
	for (int i = 0; i < Graph[index + 1].size(); ++i) {
		int next = Graph[index + 1][i];

		if (next != cur && !Visited[index + 1][next]) {
			dfs(next, index + 1);
		}
	}
}