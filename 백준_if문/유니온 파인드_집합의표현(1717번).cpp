//���Ͽ� ���ε�(disjoint set)�� ���� �˾ƺ��� ����
//����Ŭ �Ǻ� �˰��� : �׷����� ���ԵǾ� �ִ� ������ ������ E���� ��, ��� ������ ���Ͽ� find �� union �Լ��� ȣ���ϴ� ������� ����
//-- ""������ ���⼺�� ���� ���� �׷��������� �����Ѵ�"" --
#include <iostream>
using namespace std;
int n;//n(1 �� n �� 1,000,000)
int m;//m(1 �� m �� 100,000) : �Է����� �־����� ������ ����
int parent[1000001] = { 0 };
int findParent(int x);
void unionParent(int a, int b);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
	}
	int Cases, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> Cases >> a >> b;
		if (Cases == 0) 
			unionParent(a, b);
		else {
			if (findParent(a) == findParent(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
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