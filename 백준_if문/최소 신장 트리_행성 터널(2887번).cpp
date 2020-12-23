//https://dev-jk.tistory.com/29
//문제의 특성을 활용하여 고려할 간선의 개수를 줄임으로써 푸는 문제


//최소 신장 트리: """가장 적은 개수의 간선으로 모든 정점을 연결""" + """사이클이 존재하지 않는 부분 그래프"""
//최소 신장 트리 사용 목적: 모든 노드가 연결되어 있지만, 일부 간선은 사용하지 않아도 될 때, 최소한의 비용으로 구성되는 신장 트리를 찾아야 할 때
//크루스칼 알고리즘: 대표적인 최소 신장 트리 알고리즘 - 그리디 알고리즘으로 분류
//크루스칼 알고리즘 구체적인 동작 과정: 1. 간선 데이터를 비용에 따라 "오름차순"으로 정렬
//										2. 간선을 하나씩 확인하며 현재의 간선이 사이클을 발생시키는지 확인
//										- 사이클이 발생하지 않는 경우에만 최소 신장 트리에 포함시킨다.
//										3. 모든 간선에 대하여 2의 과정을 반복한다.
//최종적으로 만들어지는 최소 신장 트리에 포함된 간선의 개수:"" 전체 노드의 개수 - 1""이다. 트리가 가지고 있는 특성, 사이클 존재 X
//크루스칼 알고리즘 성능: 간선의 개수가 E개일 때, O(ElogE) : 간선을 오름차순 정렬할 때, 가장 시간이 많이 든다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long int ll;
typedef struct tunnel {
	int a, b;
	ll cost;
	/*bool operator < (const tunnel& t) const {
		return cost < t.cost;
	}*/
}Tunnel;
typedef struct Planet {
	int x, y, z, idx;
}Planet;

int N;//행성의 개수 N이 주어진다. (1 ≤ N ≤ 100,000) 
int parent[100001];
Planet planet[100001];
vector<Tunnel> tunnel;
bool compX(const Planet& a, const Planet& b);
bool compY(const Planet& a, const Planet& b);
bool compZ(const Planet& a, const Planet& b);
bool compWeight(const Tunnel& a, const Tunnel& b);
bool operator<(const Tunnel& a, const Tunnel& b) {
	return a.cost < b.cost;
}
int findParent(int x);
void unionParent(int a, int b);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	ll x, y, z;
	for (int i = 1; i <= N; ++i) {
		cin >> planet[i].x >> planet[i].y >> planet[i].z;
		parent[i] = i;
		planet[i].idx = i;
	}
	//정점 N이 100,000 이므로 N^2 연산으로 모든 행성들을 일일이 다 연결시키면 시간 초과 및 메모리 초과가 발생한다.
	//여기선 가중치가 행성과 행성간의 거리가 아닌 min(|xA-xB|, |yA-yB|, |zA-zB|)으로 x,y,z 좌표의 거리의 최솟값이다.
	//따라서 x,y,z 좌표 각각에 대해 오름차순으로 정렬한 후, 터널에 넣어준다.
	//마지막에 넣어준 x,y,z 좌표의 거리의 최솟값 기준으로(cost값)으로 오름차순 정렬후, 크루스칼(kruskal) 알고리즘 적용
	//이렇게 하면 O(N^2)이 아닌 최고로 많으면 O(3 * N-1) -> O(N)이 된다. 
	//하지만 이것을 정렬할 때 쓰는 정렬 알고리즘(sort(): 퀵 정렬) 때문에, 최종적으로는 O(NlogN)이 된다.
	sort(planet + 1, planet + N + 1, compX);
	for (int i = 1; i <= N - 1; ++i)
		tunnel.push_back({ planet[i].idx, planet[i + 1].idx, abs(planet[i].x - planet[i + 1].x) });
	
	sort(planet + 1, planet + N + 1, compY);
	for (int i = 1; i <= N - 1; ++i)
		tunnel.push_back({ planet[i].idx, planet[i + 1].idx, abs(planet[i].y - planet[i + 1].y) });

	sort(planet + 1, planet + N + 1, compZ);
	for (int i = 1; i <= N - 1; ++i)
		tunnel.push_back({ planet[i].idx, planet[i + 1].idx, abs(planet[i].z - planet[i + 1].z) });

	//sort(tunnel.begin(), tunnel.end(), compWeight);//구조체는 반드시 operator< 함수를 구현 혹은 compare() 함수를 sort함수 안에 넣어줘야 정렬 가능
	sort(tunnel.begin(), tunnel.end());
	ll result = 0;
	int cnt = 0;
	for (int i = 0; i < tunnel.size(); ++i) {
		ll cost = tunnel[i].cost;
		int a = tunnel[i].a;
		int b = tunnel[i].b;
		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			result += cost;
			cnt++;
		}
		if (cnt == N - 1) break;
	}
	cout << result << '\n';
	return 0;
}
bool compWeight(const Tunnel& a, const Tunnel& b) {
	return a.cost < b.cost;
}
bool compX(const Planet& a, const Planet& b) {
	return a.x < b.x;
}
bool compY(const Planet& a, const Planet& b) {
	return a.y < b.y;
}
bool compZ(const Planet& a, const Planet& b) {
	return a.z < b.z;
}
int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}