#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, M, Answer;
vector<int> Parent;
vector<pii> Arr;
void unionParent(int a, int b);
int findParent(int x);

int main() {
	cin >> N >> M;

	Parent.resize(N + 1, 0);

	for (int i = 1; i <= N; ++i) {
		Parent[i] = i;
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		Arr.push_back({ a, b });
	}

	sort(Arr.begin(), Arr.end());

	for (int i = 0; i < Arr.size(); ++i) {
		for (int j = Arr[i].first; j <= Arr[i].second; ++j) {
			unionParent(Arr[i].first, j);
		}
	}

	int parent = Parent[1];

	++Answer;

	for (int i = 1; i <= N; ++i) {
		if (parent != Parent[i]) {
			++Answer;
			parent = Parent[i];
		}
	}
	
	cout << Answer << '\n';

	return 0;
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

int findParent(int x) {
	if (x != Parent[x]) {
		Parent[x] = findParent(Parent[x]);
	}

	return Parent[x];
}