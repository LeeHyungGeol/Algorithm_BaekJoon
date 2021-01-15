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
#include <cstring>//memset
using namespace std;
int parent[10001] = { 0 };
int d[10001] = { 0 };
bool isDepthCounted[10001];
vector<int> graph[10001];
void dfs(int cur, int depth) {
	isDepthCounted[cur] = true;
	d[cur] = depth;
	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (isDepthCounted[next]) continue;
		dfs(next, depth + 1);
	}
}
int LCA(int a, int b) {
	while (d[a] != d[b]) {
		if (d[a] > d[b])
			a = parent[a];
		else
			b = parent[b];
	}
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}
int T, N;//Ʈ���� �����ϴ� ����� ��(2 �� N �� 10,000)
int main() {
	cin >> T;
	for (int t = 0; t < T; ++t) {
		memset(d, 0, sizeof(d));
		memset(parent, 0, sizeof(parent));
		memset(isDepthCounted, false, sizeof(isDepthCounted));
		memset(graph, 0, sizeof(graph));

		cin >> N;
		int A, B;
		for (int i = 1; i <= N - 1; ++i) {
			cin >> A >> B;
			graph[A].push_back(B);
			graph[B].push_back(A);
			parent[B] = A;
		}

		int root = -1;
		for (int i = 1; i <= N; i++) {
			if (parent[i] == 0) {
				root = i;
				break;
			}
		}

		dfs(root, 0);

		int v1, v2;
		cin >> v1 >> v2;
		cout << LCA(v1, v2) << '\n';
	}
	return 0;
}
