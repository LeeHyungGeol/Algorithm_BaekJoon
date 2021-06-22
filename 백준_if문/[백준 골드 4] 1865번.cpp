// �ִܰŸ�(��������) ����
// �������� �˰���: ���� ������ ������ �� ������ �� �ִ� �ִܰŸ� �˰���

// if(d[cur] != INF) �� ���ǹ��� �ʿ� ���� ����
// ���� ���ǹ��� ����ϴ� ������ �׷����� ���� �Ǿ� ���� ���� ��, �����Ǿ����� ǥ���ϱ� ���ؼ� ����ϴ� ���̴�.
// ��, �׷����� ����Ǿ��� ������� �ʾҳĸ� �Ǵ��ϴ� ���̱� ������
// �� �������� �ܼ��� �׷����� ���� ��ȯ(����Ŭ)���� �Ǵ��ϴ� ���̱� ������, 
// d �迭�� ���� ��� ������ �ʱ�ȭ �ص� ����� ����.

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int TC, N, M, W;
int d[501] = { 0, };
vector<piii> graph;

bool bellman_ford();

int main() {
	cin >> TC;

	for (int tc = 0; tc < TC; ++tc) {
		cin >> N >> M >> W;

		graph.clear();
		fill(d, d + 501, -1);

		for (int i = 0; i < M; ++i) {
			int S, E, T;
			cin >> S >> E >> T;
			graph.push_back({ S, {E, T} });
			graph.push_back({ E, {S, T} });
		}
		
		for (int i = 0; i < W; ++i) {
			int S, E, T;
			cin >> S >> E >> T;
			graph.push_back({ S, {E, -T} });
		}

		bool flag = bellman_ford();
	
		if (flag) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

	}

	return 0;
}

bool bellman_ford() {
	//d[1] = 0;
	bool flag = false;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < graph.size(); ++j) {
			int cur = graph[j].first;
			int next = graph[j].second.first;
			int cost = graph[j].second.second;

			if (d[cur] + cost < d[next]) {
				d[next] = d[cur] + cost;
				
				if (i == N - 1) {
					flag = true;
				}
			}
		}
	}

	return flag;
}