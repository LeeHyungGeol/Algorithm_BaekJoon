#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
vector<vector<int>> Tree;

void treeD();
void treeG();

int main() {
	cin >> N;

	Tree.resize(N + 1);

	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}




	return 0;
}

void treeD() {
	
}

void treeG() {
	
}