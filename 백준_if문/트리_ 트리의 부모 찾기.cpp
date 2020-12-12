//루트가 1인 트리가 주어질 때, 각 노드의 부모를 구하는 문제
//트리 문제라고 해서 무조건 트리를 구현할 필요 없다!!!!!
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N; //노드의 개수 N (2 ≤ N ≤ 100,000)
bool visited[100001];
int parent[100001];
vector<int> tree[100001];
void dfs(int cur);
void bfs(int start);
int main() {
	ios_base::sync_with_stdio(false);// - 없으면 120ms
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> N;
	for (int i = 0; i < N-1; ++i) {
		cin >> a >> b;
		tree[a].push_back(b);//주어진 노드들이 부모 - 자식 순서가 아니라 랜덤으로 주어지기 때문에, 
		tree[b].push_back(a);//양방향으로 넣어줘야 한다.		
	}

	//dfs(1); //1이 무조건 루트 노드라고 했기 때문에, 1부터 시작
	bfs(1);
	for (int i = 2; i <= N; ++i) {
		cout << parent[i] << '\n';
	}
	return 0;
}
void dfs(int cur) {//dfs-60ms
	visited[cur] = true; //현재 보고 있는 cur 노드 방문 표시
	
	for (int i = 0; i < tree[cur].size(); ++i) {
		int next = tree[cur][i];
		if (!visited[next]) {
			parent[next] = cur; //next의 parent는 현재 보고 있는 cur
			dfs(next);
		}
	}
}
void bfs(int start) {//bfs-52ms
	queue<int> q;
	q.push(start);
	visited[start] = true; //시작 노드 방문 표시

	while (!q.empty()) {
		int cur = q.front();

		q.pop();
		for (int i = 0; i < tree[cur].size(); ++i) {
			int next = tree[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				parent[next] = cur;//next의 parent는 현재 보고 있는 cur
				q.push(next);
			}
		}
	}
}