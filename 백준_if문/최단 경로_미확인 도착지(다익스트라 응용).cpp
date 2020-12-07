//https://hydroponicglass.tistory.com/69  //���ͽ�Ʈ�� 2�� ���
//https://dev-jk.tistory.com/38  //���ͽ�Ʈ�� 1�� ���
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define inf 1e9
using namespace std;

vector<pair<int, int>> graph[2001]; // graph �ʱ�ȭ
int dstart[2001] = { 0 };
int dg[2001] = { 0 };
int dh[2001] = { 0 };
int n, m, t, start, g, h;
void dijkstra(int start, int *d);

int main() {
	//�׽�Ʈ ���̽� ����
	int t;
	cin >> t;	
	//�׽�Ʈ ���̽� ��ŭ
	for (int i = 0; i < t; ++i) {
		//init(�ʱ�ȭ)
		cin >> n >> m >> t;
		cin >> start >> g >> h;

		int a, b, d;
		int essentaildistance = 0;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> d;
			if ((a == g && b == h) || (b == g && a == h))
				essentaildistance = d;
			graph[a].push_back({ b, d });//a�� b ���̿� ���� d�� ����� ���ΰ� �ִ� �߱� ������
			graph[b].push_back({ a, d });//���⼺�� ���� �׷����̹Ƿ� ��������� ó�����ش�.
		}

		int end = 0;
		vector<int> candidates;
		for (int i = 0; i < t; ++i) {
			cin >> end;
			candidates.push_back(end);
		}
		//dijkstra 3�� ���
		dijkstra(start, dstart); //g, h�� �ʼ��� ������.
		dijkstra(g, dg); //start -> g -> h -> end 
		dijkstra(h, dh); //start -> h -> g -> end

		//�ĺ��ڵ� �������� ����
		sort(candidates.begin(), candidates.end());
		//�ĺ��ڵ� ���ʴ�� �����鼭 �Ÿ� �� ��, ���
		for (int i = 0; i < candidates.size(); ++i) {
			end = candidates[i];
			if (dstart[end] == dstart[g] + essentaildistance + dh[end])
				cout << candidates[i] << ' ';
			else if (dstart[end] == dstart[h] + essentaildistance + dg[end])
				cout << candidates[i] << ' ';
		}
		cout << '\n';

		candidates.clear();//candidates ������ �Ź� ���ŵǱ� ������ vector<int> candidates ��� ���� clear()

		for (int i = 0; i <= n; ++i)//graph ������ �Ź� ���ŵǱ� ������ vector<pair<int, int>> graph[2001] ��� ���� clear()
			graph[i].clear();

	}
	return 0;
}
void dijkstra(int start, int *d) {
	fill(d, d + 2001, inf); //�Ÿ� �迭 �ʱ�ȭ
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

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#define inf 1e9
//using namespace std;
//
//vector<pair<int, int>> graph[2001]; // graph �ʱ�ȭ
//int dstart[2001] = { 0 };
//int dmid[2001] = { 0 };
//int n, m, t, start, g, h;
//void dijkstra(int start, int *d);
//
//int main() {
//	//�׽�Ʈ ���̽� ����
//	int t;
//	cin >> t;	
//	//�׽�Ʈ ���̽� ��ŭ
//	for (int i = 0; i < t; ++i) {
//		//init(�ʱ�ȭ)
//		cin >> n >> m >> t;
//		cin >> start >> g >> h;
//
//		int a, b, d;
//		int essentaildistance = 0;
//		for (int i = 0; i < m; ++i) {
//			cin >> a >> b >> d;
//			if ((a == g && b == h) || (b == g && a == h))
//				essentaildistance = d;
//			graph[a].push_back({ b, d });//a�� b ���̿� ���� d�� ����� ���ΰ� �ִ� �߱� ������
//			graph[b].push_back({ a, d });//���⼺�� ���� �׷����̹Ƿ� ��������� ó�����ش�.
//		}
//
//		int end = 0;
//		vector<int> candidates;
//		for (int i = 0; i < t; ++i) {
//			cin >> end;
//			candidates.push_back(end);
//		}
//		//dijkstra 2�� ���
//		dijkstra(start, dstart); //g, h�� �ʼ��� ������.
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
//		//�ĺ��ڵ� �������� ����
//		sort(candidates.begin(), candidates.end());
//		//�ĺ��ڵ� ���ʴ�� �����鼭 �Ÿ� �� ��, ���
//		for (int i = 0; i < candidates.size(); ++i) {
//			end = candidates[i];
//			if (dstart[end] == dstart[mid1] + essentaildistance + dmid[end])
//				cout << candidates[i] << ' ';
//		}
//		cout << '\n';
//
//		candidates.clear();//candidates ������ �Ź� ���ŵǱ� ������ vector<int> candidates ��� ���� clear()
//
//		for (int i = 0; i <= n; ++i)//graph ������ �Ź� ���ŵǱ� ������ vector<pair<int, int>> graph[2001] ��� ���� clear()
//			graph[i].clear();
//
//	}
//	return 0;
//}
//void dijkstra(int start, int *d) {
//	fill(d, d + 2001, inf); //�Ÿ� �迭 �ʱ�ȭ
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//	pq.push({0, start}); //�Ÿ�, ���� ���
//	d[start] = 0;
//
//	while (!pq.empty()) {
//		int dist = pq.top().first; //���� �������� �Ÿ� 
//		int cur = pq.top().second; //���� ���
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
//vector<pair<int, int>> graph[2001]; // graph �ʱ�ȭ
//int dstart[2001] = { 0 };
//int dmid[2001] = { 0 };
//int n, m, t, start, g, h;
//void dijkstra(int start, int* d);
//
//int main() {
//	//�׽�Ʈ ���̽� ����
//	int t;
//	cin >> t;
//	//�׽�Ʈ ���̽� ��ŭ
//	for (int i = 0; i < t; ++i) {
//		//init(�ʱ�ȭ)
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
//			graph[a].push_back({ b, d });//a�� b ���̿� ���� d�� ����� ���ΰ� �ִ� �߱� ������
//			graph[b].push_back({ a, d });//���⼺�� ���� �׷����̹Ƿ� ��������� ó�����ش�.
//		}
//
//		int end = 0;
//		vector<int> candidates;
//		for (int i = 0; i < t; ++i) {
//			cin >> end;
//			candidates.push_back(end);
//		}
//		//dijkstra 1�� ���
//		dijkstra(start, dstart); //g, h�� �ʼ��� ������.
//	
//		//�ĺ��ڵ� �������� ����
//		sort(candidates.begin(), candidates.end());
//		//�ĺ��ڵ� ���ʴ�� �����鼭 �Ÿ� �� ��, ���
//		for (int i = 0; i < candidates.size(); ++i) {
//			end = candidates[i];
//			if ((dstart[end] % 2) != 0)
//				cout << candidates[i] << ' ';
//		}
//		cout << '\n';
//
//		candidates.clear();//candidates ������ �Ź� ���ŵǱ� ������ vector<int> candidates ��� ���� clear()
//
//		for (int i = 0; i <= n; ++i)//graph ������ �Ź� ���ŵǱ� ������ vector<pair<int, int>> graph[2001] ��� ���� clear()
//			graph[i].clear();
//
//	}
//	return 0;
//}
//void dijkstra(int start, int* d) {
//	fill(d, d + 2001, inf); //�Ÿ� �迭 �ʱ�ȭ
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//	pq.push({ 0, start }); //�Ÿ�, ���� ���
//	d[start] = 0;
//
//	while (!pq.empty()) {
//		int dist = pq.top().first; //���� �������� �Ÿ� 
//		int cur = pq.top().second; //���� ���
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

//���� ����ġ�� ��� �����϶� ��� ������ ����ġ���� *2 ���ְ� n1-n2 ������ ����ġ�� -1 ���༭ Ȧ���� �����.
//����, ���ͽ�Ʈ�� �ѹ����ָ� �ĺ����� ����ġ�� Ȧ���϶� ������ n1 - n2�� ���� ������ �ս��� Ȯ���� �� �ִ�.
//-1�� ���ٰ�� ���� ���� ������������ n1 - n2�� ������ �������� �ִܰ�ΰ� ���� ���, 
//������ n1 - n2 ��θ� ������ �� �� �־�, �ߺ���θ� �ɷ��� �� �ִٴ� ������ �ִ�.



