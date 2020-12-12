//��Ʈ�� 1�� Ʈ���� �־��� ��, �� ����� �θ� ���ϴ� ����
//Ʈ�� ������� �ؼ� ������ Ʈ���� ������ �ʿ� ����!!!!!
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N; //����� ���� N (2 �� N �� 100,000)
bool visited[100001];
int parent[100001];
vector<int> tree[100001];
void dfs(int cur);
void bfs(int start);
int main() {
	ios_base::sync_with_stdio(false);// - ������ 120ms
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> N;
	for (int i = 0; i < N-1; ++i) {
		cin >> a >> b;
		tree[a].push_back(b);//�־��� ������ �θ� - �ڽ� ������ �ƴ϶� �������� �־����� ������, 
		tree[b].push_back(a);//��������� �־���� �Ѵ�.		
	}

	//dfs(1); //1�� ������ ��Ʈ ����� �߱� ������, 1���� ����
	bfs(1);
	for (int i = 2; i <= N; ++i) {
		cout << parent[i] << '\n';
	}
	return 0;
}
void dfs(int cur) {//dfs-60ms
	visited[cur] = true; //���� ���� �ִ� cur ��� �湮 ǥ��
	
	for (int i = 0; i < tree[cur].size(); ++i) {
		int next = tree[cur][i];
		if (!visited[next]) {
			parent[next] = cur; //next�� parent�� ���� ���� �ִ� cur
			dfs(next);
		}
	}
}
void bfs(int start) {//bfs-52ms
	queue<int> q;
	q.push(start);
	visited[start] = true; //���� ��� �湮 ǥ��

	while (!q.empty()) {
		int cur = q.front();

		q.pop();
		for (int i = 0; i < tree[cur].size(); ++i) {
			int next = tree[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				parent[next] = cur;//next�� parent�� ���� ���� �ִ� cur
				q.push(next);
			}
		}
	}
}