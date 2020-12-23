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

typedef long long int ll;
typedef pair<int, int> pii;
vector<pair<ll, pii>> graph;
int N;// N (1 �� N �� 1000)
int parent[1001];
int findParent(int x);
void unionParent(int a, int b);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	ll w;
	for (int i = 1; i <= N; ++i) {
		parent[i] = i;
		for (int j = 1; j <= N; ++j) {
			cin >> w;
			if (w != 0 && i < j)//�밢���� �������� ��Ī�� �̷�� ������
				graph.push_back({ w,{i,j} });
		}
	}
	sort(graph.begin(), graph.end());
	ll result = 0;
	for (int i = 0; i < graph.size(); ++i) {
		ll cost = graph[i].first;
		int a = graph[i].second.first;
		int b = graph[i].second.second;
		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			result += cost;
		}
	}
	cout << result << '\n';
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