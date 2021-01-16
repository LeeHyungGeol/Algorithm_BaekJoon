//https://jason9319.tistory.com/95

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
#include <algorithm>
using namespace std;
#define LOG 21
typedef pair<int, int> pii;
int N, K;//(2 �� N �� 100,000), (1 �� K �� 100,000)
int parent[100001][LOG];
int MIN[100001][LOG];
int MAX[100001][LOG];
int d[100001];
bool isDepthCounted[100001];
vector<pii> graph[100001];
void dfs(int cur, int depth) {
	d[cur] = depth;
	isDepthCounted[cur] = true;

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i].second;
		if (isDepthCounted[next]) continue;
		parent[next][0] = cur;
		MIN[next][0] = graph[cur][i].first;
		MAX[next][0] = graph[cur][i].first;
		dfs(next, depth + 1);
	}
}
void setParent() {
	dfs(1, 0);
	for (int i = 1; i < LOG; ++i) {
		for (int j = 1; j <= N; ++j) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			MIN[j][i] = min(MIN[j][i - 1], MIN[parent[j][i - 1]][i - 1]);
			MAX[j][i] = max(MAX[j][i - 1], MAX[parent[j][i - 1]][i - 1]);
		}
	}
}
pii LCA(int a, int b) {
	int retMin = 10000001;//������ ���̴� 1,000,000���� �۰ų� ���� ���� �����̴�.
	int retMax = -1;
	if (d[a] > d[b])
		swap(a, b);
	for (int i = LOG - 1; i >= 0; --i) {
		if (d[b] - d[a] >= 1 << i) {
			retMin = min(retMin, MIN[b][i]);
			retMax = max(retMax, MAX[b][i]);
			b = parent[b][i];
		}
	}

	if (a == b) return { retMin, retMax };
	for (int i = LOG - 1; i >= 0; --i) {
		if (parent[a][i] != parent[b][i]) {
			retMin = min(retMin, min(MIN[a][i], MIN[b][i]));
			retMax = max(retMax, max(MAX[a][i], MAX[b][i]));
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	retMin = min(retMin, min(MIN[a][0], MIN[b][0]));
	retMax = max(retMax, max(MAX[a][0], MAX[b][0]));
	return { retMin, retMax };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int from, to, dist;
	for (int i = 1; i <= N - 1; ++i) {
		cin >> from >> to >> dist;
		graph[from].push_back({ dist, to });
		graph[to].push_back({ dist, from });
	}
	setParent();

	cin >> K;
	int a, b;
	for (int i = 0; i < K; ++i) {
		cin >> a >> b;
		cout << LCA(a, b).first << " " << LCA(a, b).second << '\n';
	}
	return 0;
}