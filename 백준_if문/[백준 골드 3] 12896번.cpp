// Ʈ��(Ʈ���� ����), dfs 2��

// Ʈ���� ���� : Ʈ������ �Ÿ��� ���� �� �������� �Ÿ�
// ������ �������� 1�� ��带 �������� ���� �� ������ ���� ��� �� �ϳ��̴�.

// ù��° ���� ��带 ���ϱ� ���ؼ�, ������ ����� 1�� ��忡�� dfs�� ������. �̶�, 1�� ��忡�� ���� �� ���� ��� �ϳ��� ���Ѵ�.(maxIndex)
// �ٽ� �ѹ�, maxIndex���� ���� �� ���� ��带 ���ϱ� ���ؼ� maxIndex�� �������� dfs�� ������.
// �׸��� 2��° dfs���� ������ �Ÿ��� Ʈ���� ������ �ȴ�.

#include <iostream>
#include <vector>

using namespace std;

int N, Answer, maxIndex;
vector<vector<int>> Tree;
vector<bool> Visited;

void dfs(int cur, int curCost);

int main() {
	cin >> N;

	Tree.resize(N + 1);
	Visited.resize(N + 1, false);
	
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	dfs(1, 0);
	
	Visited.assign(N + 1, false);
	
	dfs(maxIndex, 0);
	
	cout << Answer - (Answer/2) << '\n';

	return 0;
}

void dfs(int cur, int curCost) {
	Visited[cur] = true;

	if (Answer < curCost) {
		Answer = curCost;
		maxIndex = cur;
	}

	for (int i = 0; i < Tree[cur].size(); ++i) {
		int next = Tree[cur][i];

		if (!Visited[next]) {
			dfs(next, curCost + 1);
		}
	}
}

