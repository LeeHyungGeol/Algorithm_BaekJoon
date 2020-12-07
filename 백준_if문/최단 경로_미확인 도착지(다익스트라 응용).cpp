//https://hydroponicglass.tistory.com/69  //다익스트라 2번 사용
//https://dev-jk.tistory.com/38  //다익스트라 1번 사용
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define inf 1e9
using namespace std;

vector<pair<int, int>> graph[2001]; // graph 초기화
int dstart[2001] = { 0 };
int dg[2001] = { 0 };
int dh[2001] = { 0 };
int n, m, t, start, g, h;
void dijkstra(int start, int *d);

int main() {
	//테스트 케이스 숫자
	int t;
	cin >> t;	
	//테스트 케이스 만큼
	for (int i = 0; i < t; ++i) {
		//init(초기화)
		cin >> n >> m >> t;
		cin >> start >> g >> h;

		int a, b, d;
		int essentaildistance = 0;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> d;
			if ((a == g && b == h) || (b == g && a == h))
				essentaildistance = d;
			graph[a].push_back({ b, d });//a와 b 사이에 길이 d의 양방향 도로가 있다 했기 때문에
			graph[b].push_back({ a, d });//방향성이 없는 그래프이므로 양방향으로 처리해준다.
		}

		int end = 0;
		vector<int> candidates;
		for (int i = 0; i < t; ++i) {
			cin >> end;
			candidates.push_back(end);
		}
		//dijkstra 3번 사용
		dijkstra(start, dstart); //g, h를 필수로 지난다.
		dijkstra(g, dg); //start -> g -> h -> end 
		dijkstra(h, dh); //start -> h -> g -> end

		//후보자들 오름차순 정렬
		sort(candidates.begin(), candidates.end());
		//후보자들 차례대로 넣으면서 거리 비교 후, 출력
		for (int i = 0; i < candidates.size(); ++i) {
			end = candidates[i];
			if (dstart[end] == dstart[g] + essentaildistance + dh[end])
				cout << candidates[i] << ' ';
			else if (dstart[end] == dstart[h] + essentaildistance + dg[end])
				cout << candidates[i] << ' ';
		}
		cout << '\n';

		candidates.clear();//candidates 정보가 매번 갱신되기 때문에 vector<int> candidates 사용 전에 clear()

		for (int i = 0; i <= n; ++i)//graph 정보가 매번 갱신되기 때문에 vector<pair<int, int>> graph[2001] 사용 전에 clear()
			graph[i].clear();

	}
	return 0;
}
void dijkstra(int start, int *d) {
	fill(d, d + 2001, inf); //거리 배열 초기화
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

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#define inf 1e9
//using namespace std;
//
//vector<pair<int, int>> graph[2001]; // graph 초기화
//int dstart[2001] = { 0 };
//int dmid[2001] = { 0 };
//int n, m, t, start, g, h;
//void dijkstra(int start, int *d);
//
//int main() {
//	//테스트 케이스 숫자
//	int t;
//	cin >> t;	
//	//테스트 케이스 만큼
//	for (int i = 0; i < t; ++i) {
//		//init(초기화)
//		cin >> n >> m >> t;
//		cin >> start >> g >> h;
//
//		int a, b, d;
//		int essentaildistance = 0;
//		for (int i = 0; i < m; ++i) {
//			cin >> a >> b >> d;
//			if ((a == g && b == h) || (b == g && a == h))
//				essentaildistance = d;
//			graph[a].push_back({ b, d });//a와 b 사이에 길이 d의 양방향 도로가 있다 했기 때문에
//			graph[b].push_back({ a, d });//방향성이 없는 그래프이므로 양방향으로 처리해준다.
//		}
//
//		int end = 0;
//		vector<int> candidates;
//		for (int i = 0; i < t; ++i) {
//			cin >> end;
//			candidates.push_back(end);
//		}
//		//dijkstra 2번 사용
//		dijkstra(start, dstart); //g, h를 필수로 지난다.
//		int mid1 = 0, mid2 = 0;
//		if (dstart[g] > dstart[h]) {
//			mid1 = h;			
//			mid2 = g;
//		}
//		else {
//			mid1 = g;
//			mid2 = h;
//		}
//		dijkstra(mid2, dmid);
//		//후보자들 오름차순 정렬
//		sort(candidates.begin(), candidates.end());
//		//후보자들 차례대로 넣으면서 거리 비교 후, 출력
//		for (int i = 0; i < candidates.size(); ++i) {
//			end = candidates[i];
//			if (dstart[end] == dstart[mid1] + essentaildistance + dmid[end])
//				cout << candidates[i] << ' ';
//		}
//		cout << '\n';
//
//		candidates.clear();//candidates 정보가 매번 갱신되기 때문에 vector<int> candidates 사용 전에 clear()
//
//		for (int i = 0; i <= n; ++i)//graph 정보가 매번 갱신되기 때문에 vector<pair<int, int>> graph[2001] 사용 전에 clear()
//			graph[i].clear();
//
//	}
//	return 0;
//}
//void dijkstra(int start, int *d) {
//	fill(d, d + 2001, inf); //거리 배열 초기화
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//	pq.push({0, start}); //거리, 시작 노드
//	d[start] = 0;
//
//	while (!pq.empty()) {
//		int dist = pq.top().first; //현재 노드까지의 거리 
//		int cur = pq.top().second; //현재 노드
//
//		pq.pop();
//		if (d[cur] < dist)
//			continue;
//		for (int i = 0; i < graph[cur].size(); ++i) {
//			int cost = dist + graph[cur][i].second;
//			if (cost < d[graph[cur][i].first]) {
//				d[graph[cur][i].first] = cost;
//				pq.push({ cost, graph[cur][i].first });
//			}				
//		}
//	}
//}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#define inf 1e9
//using namespace std;
//
//vector<pair<int, int>> graph[2001]; // graph 초기화
//int dstart[2001] = { 0 };
//int dmid[2001] = { 0 };
//int n, m, t, start, g, h;
//void dijkstra(int start, int* d);
//
//int main() {
//	//테스트 케이스 숫자
//	int t;
//	cin >> t;
//	//테스트 케이스 만큼
//	for (int i = 0; i < t; ++i) {
//		//init(초기화)
//		cin >> n >> m >> t;
//		cin >> start >> g >> h;
//
//		int a, b, d;
//		int essentaildistance = 0;
//		for (int i = 0; i < m; ++i) {
//			cin >> a >> b >> d;
//			d *= 2;
//			if ((a == g && b == h) || (b == g && a == h))
//				d -= 1;
//			graph[a].push_back({ b, d });//a와 b 사이에 길이 d의 양방향 도로가 있다 했기 때문에
//			graph[b].push_back({ a, d });//방향성이 없는 그래프이므로 양방향으로 처리해준다.
//		}
//
//		int end = 0;
//		vector<int> candidates;
//		for (int i = 0; i < t; ++i) {
//			cin >> end;
//			candidates.push_back(end);
//		}
//		//dijkstra 1번 사용
//		dijkstra(start, dstart); //g, h를 필수로 지난다.
//	
//		//후보자들 오름차순 정렬
//		sort(candidates.begin(), candidates.end());
//		//후보자들 차례대로 넣으면서 거리 비교 후, 출력
//		for (int i = 0; i < candidates.size(); ++i) {
//			end = candidates[i];
//			if ((dstart[end] % 2) != 0)
//				cout << candidates[i] << ' ';
//		}
//		cout << '\n';
//
//		candidates.clear();//candidates 정보가 매번 갱신되기 때문에 vector<int> candidates 사용 전에 clear()
//
//		for (int i = 0; i <= n; ++i)//graph 정보가 매번 갱신되기 때문에 vector<pair<int, int>> graph[2001] 사용 전에 clear()
//			graph[i].clear();
//
//	}
//	return 0;
//}
//void dijkstra(int start, int* d) {
//	fill(d, d + 2001, inf); //거리 배열 초기화
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//	pq.push({ 0, start }); //거리, 시작 노드
//	d[start] = 0;
//
//	while (!pq.empty()) {
//		int dist = pq.top().first; //현재 노드까지의 거리 
//		int cur = pq.top().second; //현재 노드
//
//		pq.pop();
//		if (d[cur] < dist)
//			continue;
//		for (int i = 0; i < graph[cur].size(); ++i) {
//			int cost = dist + graph[cur][i].second;
//			if (cost < d[graph[cur][i].first]) {
//				d[graph[cur][i].first] = cost;
//				pq.push({ cost, graph[cur][i].first });
//			}
//		}
//	}
//}

//만약 가중치가 모두 정수일때 모든 간선의 가중치들을 *2 해주고 n1-n2 사이의 가중치를 -1 해줘서 홀수로 만든다.
//이후, 다익스트라를 한번해주면 후보지의 가중치가 홀수일때 무조건 n1 - n2를 지난 것으로 손쉽게 확인할 수 있다.
//-1을 해줄경우 만약 원래 간선기준으로 n1 - n2를 지나던 안지나던 최단경로가 같을 경우, 
//무조건 n1 - n2 경로를 지나게 할 수 있어, 중복경로를 걸러낼 수 있다는 장점이 있다.



