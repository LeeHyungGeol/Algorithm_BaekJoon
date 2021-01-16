//https://exponential-e.tistory.com/34

//�ּ� ���� ����(LCA) ã�� �˰��� //LCA: Lowest Common Ancestor

//1. ��� ��忡 ���� ����(depth)�� ���//DFS �̿�
//2. �ּ� ���� ������ ã�� �� ��带 Ȯ���Ѵ�.
//		2-1) ���� �� ����� ����(depth)�� �����ϵ��� �Ž��� �ö󰣴�.
//		2-2) ���Ŀ� �θ� ������ ������ �ݺ������� �� ����� �θ� �������� �Ž��� �ö󰣴�.
//3. ��� LCA(a, b) ���꿡 ���Ͽ� 2���� ������ �ݺ��Ѵ�.

//LCA ��ȭ
//�� ��尡 �Ž��� �ö󰡴� �ӵ��� ������ ����� ���
//2�� ���� ���·� �Ž��� �ö󰡵��� �ϸ� O(logN)�� �ð� ���⵵�� �����Ѵ�.
//�޸𸮸� ���� �� ����Ͽ� �� ��忡 ���Ͽ� 2^i��° �θ� ���� ������ ����Ѵ�.

#include <iostream>
#include <vector>
using namespace std;
// 2^20 = 1000000, 21�� �� ����� �� (2^i)��° �θ��ΰ�
//����Ʈ������ ��ü ��尡 100���� �ִٰ� ���������� �뷫 20�����̸� ����ϴϱ� 10���̸� ��� ���´�.
#define LOG 21
int N, M;//N(2 �� N �� 100,000)���� ����, �� ����� �� M(1 �� M �� 100,000)
int d[100001] = { 0 };
bool isDepthCounted[100001];
int parent[100001][LOG] = { 0 };
vector<int> graph[100001];
void dfs(int cur, int depth) {// ��Ʈ ������ �����Ͽ� ����(depth)�� ���ϴ� �Լ�
	d[cur] = depth;
	isDepthCounted[cur] = true;

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (isDepthCounted[next]) continue;//������ ���̸� ���� ���� �ִٸ� continue
		parent[next][0] = cur;//2^0=1, ��ĭ ���� �ִ� �θ� ���踸 �����Ѵ�.
		dfs(next, depth + 1);
	}
}
void setParent() {// ��ü �θ� ���踦 �����ϴ� �Լ�
	dfs(1, 0);//��Ʈ�� 1���̴�.

	// ���� j���� �迭�� ä�����鼭 ��ü �迭�� ä�� �� �ִ�.
	// i���� 2^(j+1)�� �̵��� ���� ������ i���� 2^j��*2�� �̵��ϴ� ��
	// parent[i][j+1] = parent[ parent[i][j] ][j]
	for (int j = 1; j < LOG; ++j) {
		for (int i = 1; i <= N; ++i) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}
int LCA(int a, int b) {// A�� B�� �ּ� ���� ������ ã�� �Լ�
	if (d[a] > d[b])//b��尡 �� ���� �����Ѵ�.
		swap(a, b);
	for (int i = LOG - 1; i >= 0;--i) {//���̰� �����ϵ��� b��带 �̵�
		if (d[b] - d[a] >= 1 << i)
			b = parent[b][i];
	}

	// �θ� ���������� 
	if (a == b) return a;
	for (int i = LOG - 1; i >= 0; --i) {
		// ������ ���� �Ž��� �ö󰡱�
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return parent[a][0];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int from, to;
	for (int i = 1; i <= N - 1; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	setParent();

	cin >> M;
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}

	return 0;
}
