// ���μ� ����(union-find, disjoint set) ����
// ������ ���μ� ���� ������ �ٸ� ���� unionParent()�Լ����� Parent�� ��ĥ ��, 
// �θ��� ��� ���ڰ� ���� ������ ��ġ�� ���� �ƴ�, ����� ���� ������ ��ġ�� ���̴�.

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