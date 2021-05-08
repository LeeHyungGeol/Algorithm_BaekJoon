#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

//���� ����N, ���� ����M�� �־�����. 
//N�� 2�̻� 100,000������ �����̰�, M�� 1�̻� 1,000,000������ ����
int v, e;
int result = 0, cnt = 0;
int parent[100001] = { 0, };
vector<piii> graph;

int find(int x) {
	if (x != parent[x]) {
		return parent[x] = find(parent[x]);
	}
	return x;
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) {
		parent[b] = a;
	} else {
		parent[a] = b;
	}
}

int main() {
	cin >> v >> e;

	for (int i = 1; i <= v; ++i) {
		parent[i] = i;
	}

	for (int i = 0; i < e; ++i) {
		int a, b, cost;
		cin >> a >> b >> cost;

		graph.push_back({ cost, { a, b} });
	}

	sort(graph.begin(), graph.end());

	for (int i = 0; i < graph.size(); ++i) {
		int cost = graph[i].first;
		int a = graph[i].second.first;
		int b = graph[i].second.second;

		if (find(a) != find(b)) {
			Union(a, b);
			result += cost;
			++cnt;
			// �ּ� ���� Ʈ��(������ ���� == ������ ���� - 1)�� ���� ��
			// ������ ������ �����ϸ� �ּ� ������� 2���� ������ ���� �� �ִ�.
			if (cnt == v - 1) {
				result -= cost;
				break;
			}
		}
	}

	cout << result << '\n';

	return 0;
}