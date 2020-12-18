//��ǥ��鿡�� MST�� ����� ����
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
typedef pair<double, double> pdd;
int n;// ���� ���� n�� �־�����. (1 �� n �� 100)
int parent[101];
vector<pair<double, pdd>> graph;
int findParent(int x);
void unionParent(int a, int b);
double dist(const pdd& a, const pdd& b);
int main() {
	cin >> n;
	double a, b, result = 0;
	vector<pdd> stars(n + 1);
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		cin >> a >> b;
		stars[i] = { a, b };
	}
	//��� ���� ���� �Ÿ� ���ϱ�
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) 
			graph.push_back({ dist(stars[i], stars[j]), { i, j } });	
	}
	sort(graph.begin(), graph.end());
	
	for (int i = 0; i < graph.size(); ++i) {
		double cost = graph[i].first;
		int idx1 = graph[i].second.first;
		int idx2 = graph[i].second.second;
		if (findParent(idx1) != findParent(idx2)) {
			unionParent(idx1, idx2);
			result += cost;
		}
	}
	cout << fixed;//�Ҽ��� �Ʒ� ���� �����ϴ� ǥ��
	cout.precision(2);//precision(): �ڸ����� �����ϴ� �Լ�
	cout << result << '\n';
	return 0;
}
double dist(const pdd& a, const pdd& b) {
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