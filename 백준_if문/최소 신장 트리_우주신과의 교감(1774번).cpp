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
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
int N;//���ֽŵ��� ����(N<=1,000)
int M;//�̹� ����� �ŵ���� ����� ����(M<=1,000)
int parent[1001];
vector<pair<double, pii>> graph;
double dist(const pii& a, const pii& b);
int findParent(int x);
void unionParent(int a, int b);
int main() {
	cin >> N >> M;
	int x, y;
	vector<pii> gods(N + 1);
	for (int i = 1; i <= N; ++i) {
		parent[i] = i;
		cin >> x >> y;
		gods[i] = { x, y };
	}

	int idx1, idx2;
	for (int i = 1; i <= M; ++i) {
		cin >> idx1 >> idx2;
		unionParent(idx1, idx2);
	}

	for (int i = 1; i <= N - 1; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			graph.push_back({ dist(gods[i], gods[j]), { i, j } });
		}
	}
	sort(graph.begin(), graph.end());

	double result = 0;
	for (int i = 0; i < graph.size(); ++i) {
		double cost = graph[i].first;
		int a = graph[i].second.first;
		int b = graph[i].second.second;
		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			result += cost;
		}
	}
	cout << fixed;//�Ҽ��� �Ʒ� ���� �����ϴ� ǥ��
	cout.precision(2);//precision(): �ڸ����� �����ϴ� �Լ�
	cout << result << '\n';
	return 0;
}
double dist(const pii& a, const pii& b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
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