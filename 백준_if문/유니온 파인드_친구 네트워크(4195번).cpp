//유니온 파인드에 집합의 크기를 구하는 기능을 넣는 문제
#include <iostream>
#include <string>
#include <map>
using namespace std;
int T;
int F;// 친구 관계의 수 F가 주어지며, 이 값은 100,000을 넘지 않는다.
int parent[200002];
int friendCount[200002];
int findParent(int x);
int unionParent(int a, int b);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> F;
		for (int j = 1; j <= (2 * F); ++j) {
			parent[j] = j;
			friendCount[j] = 1;
		}
		map<string, int> friendName;
		string friend1, friend2;
		int idx = 0;
		for (int j = 0; j < F; ++j) {
			cin >> friend1 >> friend2;
			if (friendName.count(friend1) == 0)
				friendName[friend1] = ++idx;
			if (friendName.count(friend2) == 0)
				friendName[friend2] = ++idx;
			cout << unionParent(friendName[friend1], friendName[friend2]) << '\n';
		}
	}
	return 0;
}
int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}
int unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a != b) {
		parent[b] = a;
		friendCount[a] += friendCount[b];
		//friendCount[b] = 1;
	}
	return friendCount[a];
}