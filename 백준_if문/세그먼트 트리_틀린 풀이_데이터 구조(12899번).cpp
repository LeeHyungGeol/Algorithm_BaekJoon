#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2000001

int N, cnt = 0;
vector<int> arr;
vector<int> rangeMin;

int init(int node, int left, int right) {
	if (left == right) return rangeMin[node] = arr[left];
	int mid = (left + right) / 2;
	return rangeMin[node] = min(init(node * 2, left, mid), init(node * 2 + 1, mid + 1, right));
}
int query(int L, int R, int node, int nodeL, int nodeR) {
	if (nodeR < L || R < nodeL) return MAX;
	if (L <= nodeL && nodeR <= R) return rangeMin[node];
	int mid = (nodeL + nodeR) / 2;
	return min(query(L, R, node * 2, nodeL, mid), query(L, R, node * 2 + 1, mid + 1, nodeR));
}
int update(int index, int node, int nodeL, int nodeR) {
	if (index < nodeL || nodeR < index) return rangeMin[node];
	if (nodeL == nodeR) return rangeMin[node] = MAX;
	int mid = (nodeL + nodeR) / 2;
	return rangeMin[node] = min(update(index, node * 2, nodeL, mid), update(index, node * 2 + 1, mid + 1, nodeR));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	arr.resize(N);
	rangeMin.resize(4 * N);

	int T, X;
	for (int i = 0; i < N; ++i) {
		cin >> T;
		if (T == 1) {
			cin >> X;
			arr[cnt] = X;
			cnt++;
			init(1, 0, cnt - 1);
		}
		else { 
			cin >> X;
			cout << query(X - 1, X - 1, 1, 0, cnt - 1) << '\n';
			update(X - 1, 1, 0, cnt - 1);
			cnt--;
		}
	}

	return 0;
}
