//BFS, DFS �Ӹ� �ƴ϶� ���Ͽ� ���ε�ε� �� ������ ����Ǿ� �ִ����� Ȯ���� �� �ֽ��ϴ�.
//����Ŭ �Ǻ� �˰��� : �׷����� ���ԵǾ� �ִ� ������ ������ E���� ��, ��� ������ ���Ͽ� find �� union �Լ��� ȣ���ϴ� ������� ����
//-- ""������ ���⼺�� ���� ���� �׷��������� �����Ѵ�"" --
#include <iostream>
using namespace std;
int N;// ������ �� N�� �־�����. N�� 200����
int M;//���� ��ȹ�� ���� ���õ��� �� M�� �־�����. M�� 1000����
int parent[201] = { 0 };
int findParent(int x);
void unionParent(int a, int b);
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		parent[i] = i;
	int x;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> x;
			if (x == 1)
				unionParent(i, j);
		}
	}
	int a, b;
	cin >> a;
	for (int i = 2; i <= M; ++i) {
		cin >> b;
		if (findParent(a) == findParent(b))
			continue;
		else {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
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