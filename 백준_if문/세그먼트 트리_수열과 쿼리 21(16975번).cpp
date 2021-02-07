//https://kangwlgns.tistory.com/8
//https://kyu9341.github.io/algorithm/2020/04/06/algorithm16975/
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int N, M;
vector<ll> arr;
vector<ll> rangeSum;

void init(int node, int left, int right) {
	// ���׸�Ʈ Ʈ�� ���� ���� ��带 ������ ������ ���� 0���� �ʱ�ȭ
	if (left == right) { rangeSum[node] = arr[left]; return; }
	rangeSum[node] = 0;
	int mid = (left + right) / 2;
	init(node * 2, left, mid);
	init(node * 2 + 1, mid + 1, right);
}
//ll query(int index, int node, int nodeL, int nodeR, ll answer) {
//	// index�� �´� ���� ������ �̵��ϸ� ��ġ�� ����� ���� ��� �����Ѵ�.
//	if (index < nodeL || nodeR < index) return 0;
//	answer += rangeSum[node];
//	// ���� ��忡 �����ϸ� ������ �� ����
//	if (nodeL==nodeR) return answer;
//	int mid = (nodeL + nodeR) / 2;
//	return query(index, node * 2, nodeL, mid,answer) + query(index, node * 2 + 1, mid + 1, nodeR,answer);
//}
ll query(int index, int node, int nodeL, int nodeR, ll answer) {
	// index�� �´� ���� ������ �̵��ϸ� ��ġ�� ����� ���� ��� �����Ѵ�.
	if (index < nodeL || nodeR < index) return 0;
	// ���� ��忡 �����ϸ� ������ �� ����
	if (nodeL == nodeR) return rangeSum[node];
	int mid = (nodeL + nodeR) / 2;
	return rangeSum[node] + query(index, node * 2, nodeL, mid, answer) + query(index, node * 2 + 1, mid + 1, nodeR, answer);
}
void update(int L, int R, ll newValue, int node, int nodeL, int nodeR) {
	// �� ��忡 ������ newValue������ ��� �����Ͽ� ���� ���� �� ���İ��� ��� ����� ���� ���� �� �ֵ��� ����.
	// ������ ��� ��� ����
	if (R < nodeL || nodeR < L) return;
	// ������ ���� ���� ���� ��� ���� ��忡 newValue�� ����
	if (L <= nodeL && nodeR <= R) { rangeSum[node] += newValue; return; }
	int mid = (nodeL + nodeR) / 2;
	update(L, R, newValue, node * 2, nodeL, mid);
	update(L, R, newValue, node * 2 + 1, mid + 1, nodeR);
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

	init(1, 0, N - 1);
	
	ll Q, a, b, c;
	for (int i = 0; i < M; ++i) {
		cin >> Q;
		if (Q==1) {
			cin >> a >> b >> c;
			update(a - 1, b - 1, c, 1, 0, N - 1);
		}
		else {
			cin >> a;
			cout << query(a-1,1,0,N-1,0) << '\n';
		}
	}

	return 0;
}