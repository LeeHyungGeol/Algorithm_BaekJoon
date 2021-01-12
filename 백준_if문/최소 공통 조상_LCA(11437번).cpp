//�ּ� ���� ����(LCA) ã�� �˰��� //LCA: Lowest Common Ancestor

//1. ��� ��忡 ���� ����(depth)�� ���//DFS �̿�
//2. �ּ� ���� ������ ã�� �� ��带 Ȯ���Ѵ�.
//		2-1) ���� �� ����� ����(depth)�� �����ϵ��� �Ž��� �ö󰣴�.
//		2-2) ���Ŀ� �θ� ������ ������ �ݺ������� �� ����� �θ� �������� �Ž��� �ö󰣴�.
//3. ��� LCA(a, b) ���꿡 ���Ͽ� 2���� ������ �ݺ��Ѵ�.

//"""LCA �⺻"""
//�� �������� �θ� �������� �Ž��� �ö󰡱� ���� �־��� ��� O(N)�� �ð� ���⵵�� �䱸�ȴ�.
//���� ��� ������ ó���� ���� �ð� ���⵵�� O(N*M)�̴�.

#include <iostream>
#include <vector>
using namespace std;
int N, M;//N(2 �� N �� 50,000)���� ����, �� ����� �� M(1 �� M �� 10,000)
int d[50001] = { 0 };
bool isDepthCounted[50001];
int parent[50001] = { 0 };
vector<int> graph[50001];
void dfs(int cur, int depth) {//root������ �����ؼ� �� ����� ����(depth)�� ����ϴ� DFS
	d[cur] = depth;//���̸� ���
	isDepthCounted[cur] = true;//���� ����� ���̰� ���Ǿ���.

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (isDepthCounted[next]) continue;//������ ����(depth)�� ���� ���� �ִٸ� continue
		parent[next] = cur;//�ڽ� ���(next)�� �θ� ���(parent)�� ���� ���(cur)
		dfs(next, depth + 1);
	}
}
int LCA(int a, int b) {//��� a�� ��� b�� �ּ� ���� ������ ã�� �Լ�
	while (d[a] != d[b]) {//�� ����� ���̰� ���������� �θ�� �Ž��� �ö󰣴�.
		if (d[a] > d[b])
			a = parent[a];
		else
			b = parent[b];
	}
	while (a != b) {//��尡 ���������� �θ�� �Ž��� �ö󰣴�.
		a = parent[a];
		b = parent[b];
	}
	return a;
}

int main() {//-1272ms
	ios_base::sync_with_stdio(false);//-816ms
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int from, to;
	for (int i = 1; i <= N - 1; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	//root���� 1�� ���
	dfs(1, 0);//��� ��忡 ���� ����(depth)�� ���

	cin >> M;
	int a, b, ans = 0;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		ans = LCA(a, b);
		cout << ans << '\n';
	}
	return 0;
}

