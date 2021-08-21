// 서로소 집합(union-find, disjoint set) 문제
// 기존의 서로소 집합 문제와 다른 점은 unionParent()함수에서 Parent를 합칠 때, 
// 부모의 노드 숫자가 작은 것으로 합치는 것이 아닌, 비용이 낮은 순으로 합치는 것이다.

#include <iostream>
#include <vector>

using namespace std;

int N, M, K, Answer;
vector<int> Parent, Costs;

void unionParent(int a, int b);
int findParent(int x);

int main() {
	cin >> N >> M >> K;

	Parent.resize(N + 1, 0);
	Costs.resize(N + 1, 0);
	
	for (int i = 1; i <= N; ++i) {
		cin >> Costs[i];
		Parent[i] = i;
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}
	
	for (int i = 1; i <= N; ++i) {
		int parent = findParent(i);
		if (parent != 0) {
			Answer += Costs[parent];
			unionParent(parent, 0);
		}
	}

	if (K >= Answer) {
		cout << Answer << '\n';
	}
	else {
		cout << "Oh no" << '\n';
	}
	return 0;
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (Costs[a] < Costs[b]) {
		Parent[b] = a;
	}
	else {
		Parent[a] = b;
	}
}

int findParent(int x) {
	if (x != Parent[x]) {
		Parent[x] = findParent(Parent[x]);
	}
	return Parent[x];
}