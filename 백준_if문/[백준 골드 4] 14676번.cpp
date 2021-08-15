// ��������, ���� ����

// ��Ȯ�ϰ� �������� ������ �ƴ�����, ���� �׷������� ������ �ְ� node���� ���� ��Ű�� ������ Ȱ���ϴ� ��������.

// ��������(topologicalSort)������ Indegree[](��������)�� ������ �ٽ� �ѹ� ��Ȯ�ϰ� ¤��� ���� ��������.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M, K;
vector<int> Indegree;
vector<int> Buildings;
vector<vector<int>> Graph;

void topologicalSort();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> K;

	Buildings.resize(N + 1, 0);
	Indegree.resize(N + 1, 0);
	Graph.resize(N + 1);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		Graph[a].push_back(b);
		++Indegree[b];
	}

	topologicalSort();

	return 0;
}

void topologicalSort() {
	bool flag = true;

	for (int i = 0; i < K; ++i) {
		int info, building;
		cin >> info >> building;

		// �ǹ��� �Ǽ��� ��
		if (info == 1) {
			// ���� �ǹ��� ���������� 0�� �ƴϴ� == ���� �ǹ��� �տ� �ִ� �ǹ��� ���� �ʾҴ�.
			if (Indegree[building] != 0) {
				flag = false;
				break;
			}
			else {
				++Buildings[building];

				// ������ �ǹ� ������ 1���� ���� next�� �������� ������ �����ش�.
				// �ǹ��� ������ ������ ���� �ֱ� ������, 1���� ���� ó�����ش�.
				if (Buildings[building] == 1) {
					for (int next : Graph[building]) {
						--Indegree[next];
					}
				}
			}
		}
		else {
			// ������ �ǹ� ������ 0���� ���, �ǹ��� �ı��� �� �ִ� ������ ���� ���̹Ƿ�, ����
			if (Buildings[building] == 0) {
				flag = false;
				break;
			}
			else {
				--Buildings[building];

				// ������ �ǹ� ������ 0���� ���, next�� ���������� �׿� ���� �ٽ� �÷��ش�.
				// ���� ������ �ǹ� ������ 0�̹Ƿ�, ������ ������ �ǹ��� �� ������ �������� �Ѵ�.
				// (Indegree[next]�� ����̸� next�� �ǹ��� ���� �� ���ٴ� �ǹ�)
				if (Buildings[building] == 0) {
					for (int next : Graph[building]) {
						++Indegree[next];
					}
				}
			}
		}
	}

	if (flag) {
		cout << "King-God-Emperor" << '\n';
	}
	else {
		cout << "Lier!" << '\n';
	}

	return;
}
