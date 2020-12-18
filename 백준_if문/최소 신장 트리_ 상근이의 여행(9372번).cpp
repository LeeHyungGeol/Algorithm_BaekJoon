//�ּ� ���� Ʈ��: """���� ���� ������ �������� ��� ������ ����""" + """����Ŭ�� �������� �ʴ� �κ� �׷���"""
//�ּ� ���� Ʈ�� ��� ����: ��� ��尡 ����Ǿ� ������, �Ϻ� ������ ������� �ʾƵ� �� ��, �ּ����� ������� �����Ǵ� ���� Ʈ���� ã�ƾ� �� ��
//ũ�罺Į �˰���: ��ǥ���� �ּ� ���� Ʈ�� �˰��� - �׸��� �˰������� �з�
//ũ�罺Į �˰��� ��ü���� ���� ����: 1. ���� �����͸� ��뿡 ���� "��������"���� ����
//										2. ������ �ϳ��� Ȯ���ϸ� ������ ������ ����Ŭ�� �߻���Ű���� Ȯ��
//										- ����Ŭ�� �߻����� �ʴ� ��쿡�� �ּ� ���� Ʈ���� ���Խ�Ų��.
//										3. ��� ������ ���Ͽ� 2�� ������ �ݺ��Ѵ�.
//���������� ��������� �ּ� ���� Ʈ���� ���Ե� ������ ����:"" ��ü ����� ���� - 1""�̴�. Ʈ���� ������ �ִ� Ư��, ����Ŭ ���� X
//ũ�罺Į �˰��� ����: ������ ������ E���� ��, O(ElogE) : ������ �������� ������ ��, ���� �ð��� ���� ���.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;//������ �� N(2 �� N �� 1 000)
int M;//������� ���� M(1 �� M �� 10 000) 
int parent[1001];
vector<pair<int, pair<int, int>>> graph;
int findParent(int x);
void unionParent(int a, int b);
int main() {
	int T;
	cin >> T;
	for (int j = 0; j < T; ++j) {
		int result = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; ++i)
			parent[i] = i;
		int a, b, c = 0;
		for (int i = 1; i <= M; ++i) {
			cin >> a >> b;
			graph.push_back({ c, { a , b } });
		}

		//sort(graph.begin(), graph.end());
		for (int i = 0; i < graph.size(); ++i) {
			int cost = graph[i].first;
			int a = graph[i].second.first;
			int b = graph[i].second.second;
			if (findParent(a) != findParent(b)) {
				unionParent(a, b);
				result += 1;
			}
		}

		cout << result << '\n';
	}
	return 0;
}
int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}