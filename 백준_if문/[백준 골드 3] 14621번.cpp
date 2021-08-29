#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N, M, Answer;
vector<int> Parent;
vector<char> Info;
vector<piii> Graph;

int findParent(int x);
void unionParent(int a, int b);

int main() {
	cin >> N >> M;

	Parent.resize(N + 1, 0);
	Info.resize(N + 1);

	for (int i = 1; i <= N; ++i) {
		Parent[i] = i;
	}

	for (int i = 1; i <= N; ++i) {
		cin >> Info[i];
	}

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		Graph.push_back({ c, {a,b} });
		Graph.push_back({ c, {b,a} });
	}

	sort(Graph.begin(), Graph.end());

	int cnt = 0;

	for(int i = 0; i < Graph.size(); ++i) {
		int a = Graph[i].second.first;
		int b = Graph[i].second.second;
		int cost = Graph[i].first;

		if (Info[a] != Info[b]) {
			if (findParent(a) != findParent(b)) {
				++cnt;
				Answer += cost;
				unionParent(a, b);
			}
		}
	}

	if (cnt == N - 1) {
		cout << Answer << '\n';
	}
	else {
		cout << "-1" << '\n';
	}

	return 0;
}

int findParent(int x) {
	if (x != Parent[x]) {
		return Parent[x] = findParent(Parent[x]);
	}
	return Parent[x];
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) {
		Parent[b] = a;
	}
	else {
		Parent[a] = b;
	}
}