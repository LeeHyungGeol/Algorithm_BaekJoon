//https://hydroponicglass.tistory.com/69  //���ͽ�Ʈ�� 2�� ���
//https://dev-jk.tistory.com/38  //���ͽ�Ʈ�� 1�� ���
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[2001]; // graph �ʱ�ȭ
int dStart[2001] = { 0 };
int dG[2001] = { 0 };
int dH[2001] = { 0 };
int n, m, t, start, g, h;
void Dijkstra(int start, int *d);

int main() {
	//�׽�Ʈ ���̽� ����
	int T;
	cin >> T;	
	//�׽�Ʈ ���̽� ��ŭ
	for (int i = 0; i < T; ++i) {
		//init(�ʱ�ȭ)
		cin >> n >> m >> t;
		cin >> start >> g >> h;

		int a, b, d;
		int essentailDistance = 0;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> d;
			if ((a == g && b == h) || (b == g && a == h))
				essentailDistance = d;
			graph[a].push_back({ b, d });//a�� b ���̿� ���� d�� ����� ���ΰ� �ִ� �߱� ������
			graph[b].push_back({ a, d });//���⼺�� ���� �׷����̹Ƿ� ��������� ó�����ش�.
		}

		int end = 0;
		vector<int> candidates;
		for (int i = 0; i < t; ++i) {
			cin >> end;
			candidates.push_back(end);
		}
		//Dijkstra 3�� ���
		Dijkstra(start, dStart); //g, h�� �ʼ��� ������.
		Dijkstra(g, dG); //start -> g -> h -> end 
		Dijkstra(h, dH); //start -> h -> g -> end

		//�ĺ��ڵ� �������� ����
		sort(candidates.begin(), candidates.end());
		//�ĺ��ڵ� ���ʴ�� �����鼭 �Ÿ� �� ��, ���
		for (int i = 0; i < candidates.size(); ++i) {
			end = candidates[i];
			if (dStart[end] == dStart[g] + essentailDistance + dH[end])
				cout << candidates[i] << ' ';
			else if (dStart[end] == dStart[h] + essentailDistance + dG[end])
				cout << candidates[i] << ' ';
		}
		cout << '\n';

		candidates.clear();//candidates ������ �Ź� ���ŵǱ� ������ vector<int> candidates ��� ���� clear()

		for (int i = 0; i <= n; ++i)//graph ������ �Ź� ���ŵǱ� ������ vector<pair<int, int>> graph[2001] ��� ���� clear()
			graph[i].clear();

	}
	return 0;
}
void Dijkstra(int start, int *d) {
	fill(d, d + 2001, INF); //�Ÿ� �迭 �ʱ�ȭ
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start}); //�Ÿ�, ���� ���
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first; //���� �������� �Ÿ� 
		int cur = pq.top().second; //���� ���

		pq.pop();
		if (d[cur] < dist)
			continue;
		for (int i = 0; i < graph[cur].size(); ++i) {
			int cost = dist + graph[cur][i].second;
			if (cost < d[graph[cur][i].first]) {
				d[graph[cur][i].first] = cost;
				pq.push({ cost, graph[cur][i].first });
			}				
		}
	}
}
