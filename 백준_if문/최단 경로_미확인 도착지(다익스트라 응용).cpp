//https://hydroponicglass.tistory.com/69  //다익스트라 2번 사용
//https://dev-jk.tistory.com/38  //다익스트라 1번 사용
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[2001]; // graph 초기화
int dStart[2001] = { 0 };
int dG[2001] = { 0 };
int dH[2001] = { 0 };
int n, m, t, start, g, h;
void Dijkstra(int start, int *d);

int main() {
	//테스트 케이스 숫자
	int T;
	cin >> T;	
	//테스트 케이스 만큼
	for (int i = 0; i < T; ++i) {
		//init(초기화)
		cin >> n >> m >> t;
		cin >> start >> g >> h;

		int a, b, d;
		int essentailDistance = 0;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> d;
			if ((a == g && b == h) || (b == g && a == h))
				essentailDistance = d;
			graph[a].push_back({ b, d });//a와 b 사이에 길이 d의 양방향 도로가 있다 했기 때문에
			graph[b].push_back({ a, d });//방향성이 없는 그래프이므로 양방향으로 처리해준다.
		}

		int end = 0;
		vector<int> candidates;
		for (int i = 0; i < t; ++i) {
			cin >> end;
			candidates.push_back(end);
		}
		//Dijkstra 3번 사용
		Dijkstra(start, dStart); //g, h를 필수로 지난다.
		Dijkstra(g, dG); //start -> g -> h -> end 
		Dijkstra(h, dH); //start -> h -> g -> end

		//후보자들 오름차순 정렬
		sort(candidates.begin(), candidates.end());
		//후보자들 차례대로 넣으면서 거리 비교 후, 출력
		for (int i = 0; i < candidates.size(); ++i) {
			end = candidates[i];
			if (dStart[end] == dStart[g] + essentailDistance + dH[end])
				cout << candidates[i] << ' ';
			else if (dStart[end] == dStart[h] + essentailDistance + dG[end])
				cout << candidates[i] << ' ';
		}
		cout << '\n';

		candidates.clear();//candidates 정보가 매번 갱신되기 때문에 vector<int> candidates 사용 전에 clear()

		for (int i = 0; i <= n; ++i)//graph 정보가 매번 갱신되기 때문에 vector<pair<int, int>> graph[2001] 사용 전에 clear()
			graph[i].clear();

	}
	return 0;
}
void Dijkstra(int start, int *d) {
	fill(d, d + 2001, INF); //거리 배열 초기화
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start}); //거리, 시작 노드
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first; //현재 노드까지의 거리 
		int cur = pq.top().second; //현재 노드

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
