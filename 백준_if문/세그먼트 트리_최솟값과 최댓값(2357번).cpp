#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAX 1000000001
vector<ll> arr;
vector<ll> rangeMin;
vector<ll> rangeMax;
int N, M;

ll initMin(int node, int left, int right) {
	if (left == right) return rangeMin[node] = arr[left];
	int mid = (left + right) / 2;
	return rangeMin[node] = min(initMin(node * 2, left, mid), initMin(node * 2 + 1, mid + 1, right));
}
ll queryMin(int L,int R, int node, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return MAX;
	if (L <= nodeL && nodeR <= R) return rangeMin[node];
	int mid = (nodeL + nodeR) / 2;
	return min(queryMin(L, R, node * 2, nodeL, mid), queryMin(L, R, node * 2 + 1, mid + 1, nodeR));
}

ll initMax(int node, int left, int right) {
	if (left == right) return rangeMax[node] = arr[left];
	int mid = (left + right) / 2;
	return rangeMax[node] = max(initMax(node * 2, left, mid), initMax(node * 2 + 1, mid + 1, right));
}
ll queryMax(int L, int R, int node, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return -1;
	if (L <= nodeL && nodeR <= R) return rangeMax[node];
	int mid = (nodeL + nodeR) / 2;
	return max(queryMax(L, R, node * 2, nodeL, mid), queryMax(L, R, node * 2 + 1, mid + 1, nodeR));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	arr.resize(N);
	rangeMin.resize(4 * N);
	rangeMax.resize(4 * N);

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	initMin(1,0,N-1);
	initMax(1,0,N-1);

	ll a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		cout << queryMin(a - 1, b - 1, 1, 0, N - 1) << " " << queryMax(a - 1, b - 1, 1, 0, N - 1) << '\n';
	}

	return 0;
}