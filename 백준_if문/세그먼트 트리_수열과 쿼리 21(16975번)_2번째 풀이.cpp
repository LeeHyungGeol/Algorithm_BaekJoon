//https://kangwlgns.tistory.com/8
//https://kyu9341.github.io/algorithm/2020/04/06/algorithm16975/
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N, M;
vector<ll> arr;
vector<ll> rangeSum;

ll update(int index, ll newValue, int node, int nodeL, int nodeR) {
	if (index < nodeL || nodeR < index) return rangeSum[node];
	if (nodeL == nodeR) return rangeSum[node] += newValue;
	int mid = (nodeL + nodeR) / 2;
	return rangeSum[node] = update(index, newValue, node * 2, nodeL, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeR);
}
ll query(int L, int R, int node, int nodeL, int nodeR) {
	// [nodeL, nodeR]�� [L, R]�� ���� �� ��ġ�� ���. �ٷ� 0�� ����, 0�� ������ �տ� �����ϱ� ������
	if (nodeR < L || R < nodeL) return 0;
	//[nodeL, nodeR]�� [L, R]�� ������ ���ԵǴ� ���. �ٷ� �ڽ��� ���� ����
	if (L <= nodeL && nodeR <= R) return rangeSum[node];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	arr.resize(N);
	rangeSum.resize(4 * N);

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	cin >> M;

	int Q;
	for (int i = 0; i < M; ++i) {
		cin >> Q;
		if (Q == 1) {
			ll i, j, k;
			cin >> i >> j >> k;
			update(--i, k, 1, 0, N - 1);
			update(j, -k, 1, 0, N - 1);
		}
		else {
			ll x;
			cin >> x;
			cout << query(0, x - 1, 1, 0, N - 1) + arr[x - 1] << '\n';
		}
	}
}