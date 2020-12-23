//https://dev-jk.tistory.com/29
//������ Ư���� Ȱ���Ͽ� ����� ������ ������ �������ν� Ǫ�� ����


//�ּ� ���� Ʈ��: """���� ���� ������ �������� ��� ������ ����""" + """����Ŭ�� �������� �ʴ� �κ� �׷���"""
//�ּ� ���� Ʈ�� ��� ����: ��� ��尡 ����Ǿ� ������, �Ϻ� ������ ������� �ʾƵ� �� ��, �ּ����� ������� �����Ǵ� ���� Ʈ���� ã�ƾ� �� ��
//ũ�罺Į �˰���: ��ǥ���� �ּ� ���� Ʈ�� �˰��� - �׸��� �˰������� �з�
//ũ�罺Į �˰��� ��ü���� ���� ����: 1. ���� �����͸� ��뿡 ���� "��������"���� ����
//										2. ������ �ϳ��� Ȯ���ϸ� ������ ������ ����Ŭ�� �߻���Ű���� Ȯ��
//										- ����Ŭ�� �߻����� �ʴ� ��쿡�� �ּ� ���� Ʈ���� ���Խ�Ų��.
//										3. ��� ������ ���Ͽ� 2�� ������ �ݺ��Ѵ�.
//���������� ��������� �ּ� ���� Ʈ���� ���Ե� ������ ����:"" ��ü ����� ���� - 1""�̴�. Ʈ���� ������ �ִ� Ư��, ����Ŭ ���� X
//ũ�罺Į �˰��� ����: ������ ������ E���� ��, O(ElogE) : ������ �������� ������ ��, ���� �ð��� ���� ���.

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

int N;//�༺�� ���� N�� �־�����. (1 �� N �� 100,000) 
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
	//���� N�� 100,000 �̹Ƿ� N^2 �������� ��� �༺���� ������ �� �����Ű�� �ð� �ʰ� �� �޸� �ʰ��� �߻��Ѵ�.
	//���⼱ ����ġ�� �༺�� �༺���� �Ÿ��� �ƴ� min(|xA-xB|, |yA-yB|, |zA-zB|)���� x,y,z ��ǥ�� �Ÿ��� �ּڰ��̴�.
	//���� x,y,z ��ǥ ������ ���� ������������ ������ ��, �ͳο� �־��ش�.
	//�������� �־��� x,y,z ��ǥ�� �Ÿ��� �ּڰ� ��������(cost��)���� �������� ������, ũ�罺Į(kruskal) �˰��� ����
	//�̷��� �ϸ� O(N^2)�� �ƴ� �ְ�� ������ O(3 * N-1) -> O(N)�� �ȴ�. 
	//������ �̰��� ������ �� ���� ���� �˰���(sort(): �� ����) ������, ���������δ� O(NlogN)�� �ȴ�.
	sort(planet + 1, planet + N + 1, compX);
	for (int i = 1; i <= N - 1; ++i)
		tunnel.push_back({ planet[i].idx, planet[i + 1].idx, abs(planet[i].x - planet[i + 1].x) });
	
	sort(planet + 1, planet + N + 1, compY);
	for (int i = 1; i <= N - 1; ++i)
		tunnel.push_back({ planet[i].idx, planet[i + 1].idx, abs(planet[i].y - planet[i + 1].y) });

	sort(planet + 1, planet + N + 1, compZ);
	for (int i = 1; i <= N - 1; ++i)
		tunnel.push_back({ planet[i].idx, planet[i + 1].idx, abs(planet[i].z - planet[i + 1].z) });

	//sort(tunnel.begin(), tunnel.end(), compWeight);//����ü�� �ݵ�� operator< �Լ��� ���� Ȥ�� compare() �Լ��� sort�Լ� �ȿ� �־���� ���� ����
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